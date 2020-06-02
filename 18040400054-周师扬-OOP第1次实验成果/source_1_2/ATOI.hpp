//
//  ATOI.hpp
//  周师扬 18040400054
//  编写日期：2020年3月5日
//  oop第一次上机实验第二题
//

#ifndef ATOI_hpp
#define ATOI_hpp

#include <iostream>
#include <string>
using namespace std;

int Atoi(const char *s);
void Trans(const char a,int &n);
void Decimal(const char *ptr,int &change);
void Octonary(const char *ptr,int &change);
void Hexadecimal(const char *ptr,int &change);
void qTrans(int n,char &a);
void Scan(string a,string &b);
char *eatspace(char *str);


#endif /* ATOI_hpp */
