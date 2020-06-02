//
//  main.cpp
//  周师扬 18040400054
//  编写日期：2020年3月5日
//  oop第一次上机实验第二题

#include <iostream>
#include <string>
#include "ATOI.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    string s,p;
    int change;
    cin>>s;
    Scan(s,p);
    eatspace(&p[0]);
    change=Atoi(&p[0]);
    cout<<change<<endl;
    return 0;
}
