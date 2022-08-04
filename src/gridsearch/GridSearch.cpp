#include "GridSearch.h"


GridSearch::GridSearch(const std::string &configFilePath, bool isContinue)
{
    m_configFilePath = configFilePath;
    m_isContinue = isContinue;
}

bool GridSearch::isFinished()
{
    auto currentAttributeName = m_attributeNames.back();
    auto currentAttribute = m_attributes[currentAttributeName];
    return isFinished(currentAttribute);
}

bool GridSearch::start()
{
    return readConfig();
}

bool GridSearch::next()
{
    bool isNext = next(0);
    return isNext;
}

bool GridSearch::next(int index)
{
    auto currentAttributeName = m_attributeNames[index];
    auto &currentAttribute = m_attributes[currentAttributeName];
    currentAttribute.lastPoint += currentAttribute.step;
    if (isFinished(currentAttribute))
    {
        if (index + 1 < m_attributeNames.size())
        {
            bool isNext = next(index + 1);
            currentAttribute.lastPoint = currentAttribute.start;
            return isNext;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool GridSearch::isFinished(const Attribute &attribute)
{
    return attribute.lastPoint > attribute.end;
}

bool GridSearch::stop()
{
    return saveConfig();
}

float GridSearch::getAttributeCurrentValueByName(const std::string &attributeName)
{
    return m_attributes[attributeName].lastPoint;
}

bool GridSearch::readConfig()
{
    m_attributeNames.clear();
    m_attributes.clear();
    std::ifstream configFile(m_configFilePath.c_str());
    if(configFile)
    {
        nlohmann::json configJson;
        configFile >> configJson;
        for (auto &it : configJson["attributes"].items())
        {
            auto v = it.value();
            Attribute attribute;
            attribute.name = v["name"];
            attribute.start = v["start"].get<float>();
            attribute.end = v["end"].get<float>();
            attribute.step = v["step"].get<float>();

            attribute.lastPoint = attribute.start;
            if (m_isContinue)
            {
                attribute.lastPoint = v["lastPoint"].get<float>();
            }
            m_attributeNames.push_back(v["name"]);
            m_attributes[v["name"]] = attribute;
        }
        configFile.close();
        return true;
    }
    return false;
}

bool GridSearch::saveConfig()
{
    std::ofstream configFile(m_configFilePath.c_str());
    if(configFile)
    {
        nlohmann::json configJson;
        configJson["attributes"] = nlohmann::json::array();
        for (auto &attributeName : m_attributeNames)
        {
            nlohmann::json attributeJson;
            attributeJson["name"] = m_attributes[attributeName].name;
            attributeJson["start"] = m_attributes[attributeName].start;
            attributeJson["end"] = m_attributes[attributeName].end;
            attributeJson["step"] = m_attributes[attributeName].step;
            attributeJson["lastPoint"] = m_attributes[attributeName].lastPoint;
            configJson["attributes"].push_back(attributeJson);
        }
        configFile << std::setw(4) << configJson << std::endl;
        configFile.close();
        return true;
    }
    return false;
}

void GridSearch::printStatus()
{
    std::cout << "==========================" << std::endl;
    for(auto attributeName : m_attributeNames)
    {
        auto attribute = m_attributes[attributeName];
        int size = (((int)(attribute.end - attribute.start) / attribute.step) + 1 );
        int temp = (((int)(attribute.lastPoint - attribute.start) / attribute.step));
        float ratio = (float) temp / size;
        std::cout << attribute.name << " | start :" << attribute.start << " | end :" << attribute.end << " | step :" << attribute.step << " | lastPoint :" << attribute.lastPoint << " | ratio :" << ratio << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
    std::cout << "==========================" << std::endl;
}