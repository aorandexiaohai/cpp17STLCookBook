#include <map>
#include <iostream>

#include "ColorConsole.h"

// Note that both the insert and emplace functions of std::map
// work exactly the same way. A crucial difference is that
// try_emplace will not construct the object associated with the
// keyÂ if the key already exists. This boosts the performance in
// case objects of that type are expensive to create.

struct CInsert
{
    CInsert(int i)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
};
struct CEmplace
{
    CEmplace(int i)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
};

struct CTryEmplace
{
    CTryEmplace(int i)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
};

int main()
{
    {
    CCGREEN << "'try_emplace' will not construct object if the key has exist, while 'insert' and 'emplace' will"  << std::endl;
    {
        std::map<int, CInsert> tmp = {{0, 1}};
        tmp.insert(tmp.end(), {0, 1});
    }
    {
        std::map<int, CEmplace> tmp = {{0, 1}};
        tmp.emplace(0,1);
    }

    {
        std::map<int, CTryEmplace> tmp = {{0, 1}};
        tmp.try_emplace(0, 1);
    }
    }
}