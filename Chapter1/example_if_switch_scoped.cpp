#include <iostream>
#include <map>
#include <string>
int main()
{
    std::map<std::string, int> msi = {
        {"1", 1},
        {"2", 2},
        {"3", 3},
    };

    while (true)
    {
        std::string str;
        std::cin >> str;
        if (auto itr = msi.find(str); itr != msi.end())
        {
            std::cout << itr->second << std::endl;
        }
        else
        {
            std::cout << "itr==msi.end():" << (itr == msi.end()) << std::endl;
        }
    }
}