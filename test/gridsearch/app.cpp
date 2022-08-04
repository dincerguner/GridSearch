#include <string>
#include "GridSearch.h"


void dummyProcess(float a, float b, float c, float d)
{
    std::cout << "attribute a: " << a << std::endl;
    std::cout << "attribute b: " << b << std::endl;
    std::cout << "attribute c: " << c << std::endl;
    std::cout << "attribute d: " << d << std::endl;
}

int main(int argc, char *argv[])
{
    std::string configFilePath = argv[1];

    GridSearch gridSearch = GridSearch(configFilePath, false);
    gridSearch.start();
    while (!gridSearch.isFinished())
    {
        float a = gridSearch.getAttributeCurrentValueByName("a");
        float b = gridSearch.getAttributeCurrentValueByName("b");
        float c = gridSearch.getAttributeCurrentValueByName("c");
        float d = gridSearch.getAttributeCurrentValueByName("d");
        
        dummyProcess(a, b, c, d);

        gridSearch.printStatus();
        gridSearch.next();
    }
    gridSearch.stop();

    return 0;
}