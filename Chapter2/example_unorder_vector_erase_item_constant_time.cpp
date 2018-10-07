#include <vector>
#include <algorithm>

#include "UnitTest.h"

template <typename T>
void quick_remove_at(std::vector<T> &v, typename std::vector<T>::iterator it)
{
    if (it != v.end() && v.size() > 0)
    {
        *it = std::move(v.back());
        v.pop_back();
    }
}

template <typename T>
void quick_remove_at(std::vector<T> &v, size_t index)
{
    if (index < v.size() && v.size() > 0)
    {
        v[index] = std::move(v.back());
        v.pop_back();
    }
}

int main()
{
    {
        std::vector<int> vi1{1, 2, 3, 4};
        quick_remove_at(vi1, vi1.begin() + 1);
        UT_EXPECT_TRUE((vi1 == std::vector{1, 4, 3}));
    }
    {
        std::vector<int> vi1{1, 2, 3, 4};
        quick_remove_at(vi1,1);
        UT_EXPECT_TRUE((vi1 == std::vector{1, 4, 3}));
    }
}
