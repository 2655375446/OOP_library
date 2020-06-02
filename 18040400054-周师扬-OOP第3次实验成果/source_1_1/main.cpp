//
//  main.cpp
//  周师扬 18040400054
//  编写日期：2020年3月29日
//  oop第三次上机实验第一题
//

#include <iostream>
#include <map>
#include "lexer.hpp"
#include "parser.hpp"
#include "error.hpp"

using namespace std;

Lexer::Token_value  curr_tok=Lexer::PRINT;
int line=1;//标记错误行号,有错误时输出行号
map<string, double> table;
int no_of_errors;
double number_value;
string string_value;

int main(int argc,char *argv[])
{
    table["pi"]=3.1415924535;
    table["e"]=2.178;
    if(argc>2)
    {
        cout<<"Too many arguments !"<<endl;
        return 0;
    }
    if (Lexer::parseCommandLine(argc, argv)!=0) {cout<<"error ! "<<endl;return 1;}  //报告文件无法打开
    while (Lexer::END != Lexer::get_token()) {
        if (curr_tok==Lexer::PRINT) continue; //空表达式
        if (curr_tok==Lexer::ERR) {   //当遇到表达式有错误，则丢弃错误表达式的剩余部分
            Lexer::skip();
            continue;
        }

        double value=Parser::expr(false);
        switch (curr_tok)//表达式分析结束后，再判断
        {
            case Lexer::PRINT:// 表达式正常结束
            case Lexer::END: // 最后一个表达式之后无换行或分号时
                cout<<"Result is " << value << endl;
                continue;

            case Lexer::ERR: // 表达式有错误，则丢弃尚未读取的剩余部分
                Lexer::skip();
                continue;
            default:
                Error::error(reinterpret_cast<string &>(curr_tok));
                Lexer::skip();
                continue;
            }
        }
    if (Lexer::input!= &std::cin)
        delete Lexer::input;
    return 0;
}





