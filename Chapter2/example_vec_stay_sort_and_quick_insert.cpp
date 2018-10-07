
#include <vector>
#include "UnitTest.h"
#include <algorithm>
using namespace std;


template <typename C, typename T>
std::vector<int> & insert_sorted(C &v, const T &item)
{
    //v is sorted
    const auto insert_pos(lower_bound(begin(v), end(v), item));
    v.insert(insert_pos, item);
    return v;
}

int main()
{
    std::vector<int> vi{1, 3, 4, 2};
    std::sort(vi.begin(), vi.end());

    UT_EXPECT_TRUE((vi == std::vector{1, 2, 3, 4}));
    UT_EXPECT_TRUE((insert_sorted(vi, 5) == std::vector{1, 2, 3, 4, 5}));
}