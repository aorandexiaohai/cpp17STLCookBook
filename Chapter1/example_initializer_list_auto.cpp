#include <iostream>
#include <typeinfo>
#include <vector>
#include <cassert>
#include <type_traits>
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
        std::vector<int> v1{1, 2, 3};
        std::vector<int> v2 = {1, 2, 3};

        //行为不一致
        std::vector<int> v3{10, 20}; //10,20两个元素
        std::vector<int> v4(10, 20); //20个元素,每个元素都为10
        UT_EXPECT_CURRENT(v3.size() != v4.size());
    }

    {
        auto v1{1}; //v1 is int
        static_assert(std::is_same_v<decltype(v1), int>);

        //auto v2{1,2};//compile error, 只能有一个元素

        auto v3 = {1}; // v3 is std::initializer_list<int>
        static_assert(std::is_same_v<decltype(v3), std::initializer_list<int>>);

        auto v4 = {1, 2}; // v4 is std::initializer_list<int>
        static_assert(std::is_same_v<decltype(v4), std::initializer_list<int>>);

        //auto v5 = {1, 2.0}; // 编译错误: narrow conversion
    }
}