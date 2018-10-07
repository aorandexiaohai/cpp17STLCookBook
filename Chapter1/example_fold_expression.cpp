#include <iostream>
#include <vector>
#include <algorithm>

#include "UnitTest.h"

//example
//sum(1,2,3,4,5)
//1+(2+(3+(4+5)))
template <typename... Ts>
auto sum(Ts &&... ts)
{
    return (ts + ...);
}

//sum_1() return 0
template <typename... Ts>
auto sum_1(Ts &&... ts)
{
    return (ts + ... + 0);
}

//example
//sum1(1,2,3,4,5)
//(((1+2)+3) + 4) + 5
template <typename... Ts>
auto sum1(Ts &&... ts)
{
    return (... + ts);
}

template <typename... Ts>
auto sum1_1(Ts &&... ts)
{
    return (0 + ... + ts);
}

template <typename... Ts>
auto product(Ts&&... ts)
{
    return (ts * ... * 1);
}

template <typename R, typename... Ts>
auto matches(const R &range, Ts&&... ts)
{
    return (std::count(std::begin(range), std::end(range), ts) + ...);
}

// Let's write a helper thatÂ inserts an arbitrary number of variadic parameters
// into an std::set and returns if all the insertions are successful:

template <typename T, typename... Ts>
bool insert_all(T &set, Ts&&... ts)
{
    return (set.insert(ts).second && ...);
}

template <typename T, typename... Ts>
bool within(T min, T max, Ts&&... ts)
{
    return ((min <= ts && ts <= max) && ...);
}

template <typename T, typename... Ts>
void insert_vec_inner(std::vector<T> &vec, Ts&&... ts)
{
    (vec.push_back(ts), ...);
}

template <typename... Ts>
auto insert_vec(Ts&&... ts)
{
    std::vector<std::common_type_t<Ts...>> result;
    insert_vec_inner(result, ts...);
    return result;
}





int main()
{
    UT_EXPECT_TRUE((sum(1, 1.0f, 1.0) == 3));
    UT_EXPECT_TRUE((sum(std::string("1"), "1.0") == "11.0"));
    UT_EXPECT_TRUE((sum_1() == 0));

    UT_EXPECT_TRUE((sum1(1, 1.0f, 1.0) == 3));
    UT_EXPECT_TRUE((sum1(std::string("1"), "1.0") == "11.0"));
    UT_EXPECT_TRUE((sum1_1() == 0));

    UT_EXPECT_TRUE((product(2, 3, 4) == 24));
    UT_EXPECT_TRUE((product() == 1));

    std::vector<int> vi{1, 2, 3, 3, 4};
    UT_EXPECT_TRUE((matches(vi, 2, 3) == 3));

    std::set<int> si1;
    UT_EXPECT_TRUE((insert_all(si1, 1, 2, 3) == true));

    std::set<int> si2;
    UT_EXPECT_TRUE((insert_all(si2, 1, 2, 2) == false));

    UT_EXPECT_TRUE((within(10, 20, 1, 15, 30) == false));      // --> false
    UT_EXPECT_TRUE((within(10, 20, 11, 12, 13) == true));      // --> true
    UT_EXPECT_TRUE((within(5.0, 5.5, 5.1, 5.2, 5.3) == true)); // --> true

    UT_EXPECT_TRUE((insert_vec(1,2,3,4) == std::vector{1,2,3,4}));
}