//
//  main.cpp
//  周师扬 18040400054
//  编写日期：2020年3月20日
//  oop第二次上机实验第三题

#include <iostream>
#include <cstdarg>

using namespace std;

void error(const char *instruction,...);

int main(int argc, const char * argv[])
{
    error("My name is zsy . \n");
    error("%s %d %s\n","I'm",19,"year's old . ");
    error("%c %s\n",'I',"love China ! ");
    return 0;
}

void error(const char *instruction,...)//接收可变参数的函数--error
{
    va_list ap;//宏定义一个指针
    va_start(ap,instruction);
    int len=strlen(instruction);
    
    for(int i=0;i<len;i++)
    {
        if(instruction[i]!='%')
        {
            cout<<instruction[i];
        }
        else
        {
            i++;//跳过百分号
            switch(instruction[i])
            {
                case 's':
                {
                    char *tp;
                    tp=va_arg(ap,char *);//讲下一个可变参数按照字符串的形式读如
                    cout<<tp;
                    break;
                }
                case 'c':
                {
                    int ch=va_arg(ap,int);
                    cout<<char(ch);
                    break;
                }
                case 'd':
                {
                    int k=va_arg(ap,int);
                    cout<<k;
                    break;
                }
            }
        }
    }
    va_end(ap);//结束ap
}
