#include "UnitTest.h"

#include <list>
#include <vector>

template<typename T>
class addable{
private:
    T val;
public:    
    addable(T v) : val{v} {}
    template<typename U>
    T add(U x) const{
        if constexpr (std::is_same_v<T, std::vector<U>>)
        {
            auto copy {val};
            for(auto& data :copy)
                data += x;
            return copy;
        }
        else if constexpr (std::is_same_v<T, std::list<U>>)
        {
            auto copy {val};
            for(auto& data :copy)
                data += x;
            return copy;
        }
        else{
            return val + x;
        }
    }
};


int main()
{
    UT_EXPECT_TRUE(addable{1}.add(2)==3);
    UT_EXPECT_TRUE(addable{1.0}.add(2)==3);
    UT_EXPECT_TRUE(addable<std::string>("aa").add("bb") == "aabb");

    UT_EXPECT_TRUE((addable{std::vector{1,2,3}}.add(10) == std::vector{11, 12, 13}));
    UT_EXPECT_TRUE((addable{std::vector<std::string>{"a","b","c"}}.add(std::string("z")) == std::vector<std::string>{"az","bz","cz"}));

    UT_EXPECT_TRUE((addable{std::list{0,1,2,3}}.add(1) == std::list{1,2,3,4}));


}