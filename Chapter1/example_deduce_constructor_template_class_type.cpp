#include <tuple>
#include <utility>
#include <type_traits>
#include <string>

template<class T>
struct sum
{
    T value;
    using SumType = T;
    template<typename ... Ts>
    sum(Ts&& ... values) : value{(values + ...)} {} // constructor
};

template <typename ... Ts>
sum(Ts&& ... ts) -> sum<std::common_type_t<Ts...>>;  // deduction guide



int main()
{
    std::pair my_pair(123,"123");
    static_assert(std::is_same_v<decltype(my_pair), std::pair<int, const char*>>);
    std::tuple my_tuple(123,12.3,"abc");
    static_assert(std::is_same_v<decltype(my_tuple), std::tuple<int, double, const char*>>);

    static_assert(std::is_same_v<decltype(sum(1,2.0f, 3.0))::SumType, double>);
    static_assert(std::is_same_v<decltype(sum("1", std::string("2")))::SumType, std::string>);

}