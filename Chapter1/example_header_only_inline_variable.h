#pragma once
#include <string>
class process_monitor{
public:
    //直接编译不通过
    // error: non-constant in-class initialization invalid for non-inline static member 'process_monitor::standard_string'
    // static const std::string standard_string{"1"};

    inline static const std::string standard_string{"1"};
};

//编译不通过,多重定义
// process_monitor global_process_monitor;


inline process_monitor global_process_monitor;

