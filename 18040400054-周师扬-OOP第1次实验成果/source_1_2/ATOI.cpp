//
//  ATOI.cpp
//  周师扬 18040400054
//  编写日期：2020年3月5日
//  oop第一次上机实验第二题

#include "ATOI.hpp"
#include <iostream>


int Atoi(const char * s)
{
    int flag=1;//用来判断正负
    int change;
    const char *ptr=&s[0];
    if(*ptr=='+')ptr++;
    if(*ptr=='-')//扫描第一位是不是'-'
    {
        flag=-1;
        ptr++;//向后扫描一位
    }
    if(*ptr=='0')//判断'0'开头
    {
        ptr++;
        if((*ptr=='x')||(*ptr=='X'))//判断"0x"开头
        {
            ptr++;
            Hexadecimal(ptr,change);
            change*=flag;
            return change;
        }
        Octonary(ptr,change);//不是以“0x”开头
        change*=flag;
        return change;
    }
    else
    {
        Decimal(ptr,change);//十进制函数
    }
    change*=flag;
    if((change>=2004318069)||(change<-2147483648))
    {
        change=-1;
        cout<<"OUT!"<<endl;
    }
    return change;
}

void Decimal(const char * ptr,int &change)//十进制转换函数
{
    int n,m;
    Trans(*ptr,n);
    while((*++ptr)!='\0')
    {
        Trans(*ptr,m);
        n=n*10+m;
    }
    change=n;
}

void Octonary(const char *ptr,int &change)//八进制转换函数
{
    int n,m;
    Trans(*ptr,n);
    while((*++ptr)!='\0')
    {
        Trans(*ptr,m);
        n=n*8+m;
    }
    change=n;
}

void Hexadecimal(const char *ptr,int &change)//十六进制转换函数
{
    int n,m;
    Trans(*ptr,n);
    while((*++ptr)!='\0')
    {
        Trans(*ptr,m);
        n=n*16+m;
    }
    change=n;
}

void Trans(const char a,int &n)//把字符转换成数字
{
    n=a-'0';
}

void qTrans(int n,char &a)//把数字转换成字符
{
    a=n+'0';
}

void Scan(string a,string &b)//扫描函数
{
    int i=0,j=0;
    string c;
    char * ptr=&c[0];
    int change;
    while(i<a.size())
    {
        b[j]=a[i];
        while(a[i+1]=='\\')
        {
            i+=2;
            if(a[i+1]=='0')
            {
                i++;
                c[0]=a[i+1];
                i++;
                c[1]=a[i+1];//c已验证没有错误
                Octonary(ptr,change);
                j++;
                b[j]=char(change);
                i++;
            }
            if((a[i+1]=='x')||(a[i+1]=='X'))
            {
                i++;
                c[0]=a[i+1];
                i++;
                c[1]=a[i+1];
                Hexadecimal(ptr,change);
                j++;
                b[j]=char(change);
                i++;
            }
        }
        i++;
        j++;
    }
}

char *eatspace(char *str)
{
    char *p=str;
    char *q=str;
    while(*q++);
    q-=2;
    while(p<=q&&isspace(*q))q--;
    while(p<=q&&isspace(*p))p++;
    while(p<=q) *str++=*p++;
    *str='\0';
    return str;
}
