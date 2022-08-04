#include <iostream>
#include <fstream>
#include <iomanip>
#include <float.h>
#include "nlohmann/json.hpp"


struct Attribute
{
    std::string name;
    float start;
    float end;
    float step;
    float lastPoint;
};

class GridSearch
{
public:
    GridSearch(const std::string &configFilePath, bool isContinue=true);

    bool start();
    bool next();
    bool stop();
    float getAttributeCurrentValueByName(const std::string &attributeName);
    bool isFinished();
    void printStatus();

private:
    bool m_isContinue;
    std::string m_configFilePath;
    std::vector<std::string> m_attributeNames;
    std::map<std::string, Attribute> m_attributes;
    
    bool readConfig();
    bool saveConfig();

    bool next(int index);
    bool isFinished(const Attribute &attribute);

};