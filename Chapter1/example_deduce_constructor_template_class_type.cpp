#include <tuple>
#include <utility>
#include <type_traits>

int main()
{
    std::pair my_pair(123,"123");
    static_assert(std::is_same_v<decltype(my_pair), std::pair<int, const char*>>);
    std::tuple my_tuple(123,12.3,"abc");
    static_assert(std::is_same_v<decltype(my_tuple), std::tuple<int, double, const char*>>);
}