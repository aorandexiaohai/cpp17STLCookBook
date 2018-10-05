#include <utility>
#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <map>

std::pair<int, int> divide_remainder(int x, int y)
{
    return std::make_pair(x / y, x % y);
}

std::tuple<int, int, int> mk_date(int y, int m, int d)
{
    return {y, m, d};
}

struct employee
{
    unsigned id;
    std::string name;
    std::string role;
    unsigned salary;
};

int main()
{
    auto [fraction, remainder] = divide_remainder(16, 3);
    std::cout << "fraction:" << fraction << std::endl;
    std::cout << "remainder:" << remainder << std::endl;

    auto [y, m, d] = mk_date(2018, 10, 6);
    std::cout << y << "-" << m << "-" << d << std::endl;

    std::vector<employee> ve{
        {1, "1", "1", 1}};
    for (const auto &[id, name, role, salary] : ve)
    {
        std::cout << id << " " << name << " " << role << " " << salary << std::endl;
    }

    std::map<std::string, size_t> animal_count = {
        {"humans", 7000000},
        {"chickens", 17863300},
        {"camels", 24291},
        {"sheep", 1086528}};
    for (const auto &[species, count] : animal_count)
    {
        std::cout << species << "\t" << count << std::endl;
    }
}