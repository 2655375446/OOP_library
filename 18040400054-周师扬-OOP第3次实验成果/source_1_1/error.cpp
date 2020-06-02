
//  周师扬 18040400054
//  编写日期：2020年3月29日
//  oop第三次上机实验第一题
//

#include "error.hpp"
#include <iostream>

extern int no_of_errors;
extern int line;

double Error::error(const std::string &s)
{
    no_of_errors++;
    std::cerr<<"error: "<<s<<'\n';
    std::cerr<<"error line : "<<line<<std::endl;//输出错误行数
    return 1;
}
