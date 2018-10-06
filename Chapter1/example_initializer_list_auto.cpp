#include <iostream>
#include <typeinfo>
#include <vector>
#include <cassert>
#include "UnitTest.h"
int main()
{
    {
        //行为一致
        int x1 = 1;
        int x2{1};
        int x3(1);

        int x4(1.0);
        // int x5{1.0};//编译错误//narrow conversion:double转换为int
    }
    {
        //行为一致
        std::vector<int> v1 {1, 2, 3};
        std::vector<int> v2={1, 2, 3};

        //行为不一致
        std::vector<int> v3{10,20};
        std::vector<int> v4(10,20);
        UT_EXPECT_CURRENT(v3.size() != v4.size());
    }
}