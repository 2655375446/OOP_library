//
//  main.cpp
//  周师扬 18040400054
//  编写日期：2020年3月6日
//  oop第一次上机实验第三题

#include <iostream>
#include <stack>//stack头文件
#include <sstream>
using namespace std;

void Trans(int n,char &a);
char* Itoa(int i,char b[],int base);

int main(int argc, const char * argv[])
{
    char a[100];
    int integer;
    int base;
    cin>>integer;
    cin>>base;
    Itoa(integer,a,base);
    for(int i=0;a[i]!='\0';i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}

char* Itoa(int i,char b[],int base)//base用来标记以什么进制转换
{
    int n;
    int j=0;
    char change;
    char m;
    int ts=0;
    int flag;
    stack<char> s;
    if(i>=0)
    {
        flag=0;
    }
    else
    {
        flag=1;
    }
    if(i==-2147483648)
    {
        i=2147483647;
        ts=1;
    }
    else
    {
        i=abs(i);//绝对值化
    }
    while(i>0)
    {
        n=i%base;
        i=i/base;
        switch(n)
        {
            case 10:change='A';break;
            case 11:change='B';break;
            case 12:change='C';break;
            case 13:change='D';break;
            case 14:change='E';break;
            case 15:change='F';break;
            default:Trans(n,change);break;
        }
        s.push(change);
    }
    if(base==8)
    {
        s.push('0');
    }
    if(base==16)
    {
        s.push('x');
        s.push('0');
    }
    if(flag==1)
    {
        s.push('-');
    }
    while(!s.empty())
    {
        m=s.top();
        b[j]=m;
        s.pop();
        j++;
    }
    if(ts==1)
    {
        b[j-1]='8';//对于边界值特殊处理
    }
    return &b[0];
}

void Trans(int n,char & a)//把数字转换成字符
{
    a=n+'0';
}

