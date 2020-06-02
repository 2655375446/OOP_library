
//  周师扬 18040400054
//  编写日期：2020年3月29日
//  oop第三次上机实验第一题
//

#include "parser.hpp"
#include "lexer.hpp"
#include "error.hpp"
#include <map>

extern Lexer::Token_value curr_tok;
extern double number_value;
extern std::string string_value;
extern std::map<std::string, double> table;


double Parser::expr(bool get)
{
    double left=Parser::term(get);
    for(;;) {
        switch(curr_tok)
        {
            case Lexer::PLUS: {
                left+=Parser::term(true);
                break;
            }
            case Lexer::MINUS: {
                left-=Parser::term(true);
                break;
            }
            default:
                return left;
        }
    }
}

// 函数term处理乘除，采用的方式与expr()处理方法一样
double Parser::term(bool get)
{
    double left=Parser::prim(get);
    for(;;)
    {
        switch(curr_tok)
        {
            case Lexer::MUL:{
                left *= Parser::prim(true);
                break;
            }
            case Lexer::DIV:
                if (double d=Parser::prim(true))
                {
                    left/=d;
                    break;
                }
                return Error::error((std::string &) "divide by 0");
            default:
                return left;
        }
    }
}

double Parser::prim(bool get)
{
    if (get) Lexer::get_token();

    switch(curr_tok)
    {
        case Lexer::NUMBER:{
            double v=number_value;
            Lexer::get_token();
            return v;
        }
        case Lexer::NAME: {
            double & v=table[string_value];
            if (Lexer::get_token()==Lexer::ASSIGN) v=Parser::expr(true);
            return v;
        }
        case Lexer::MINUS:
            return -Parser::prim(true);
        case Lexer::LP: {
            double e=Parser::expr(true);
            if (curr_tok!= Lexer::RP) return Error::error(" ) expected");
            Lexer::get_token();
            return e;
        }
        default:
            Error::error("primary expected");
            while(true)
            {
                if((Lexer::get_token()==Lexer::PRINT)||(Lexer::get_token()==Lexer::END))
                    break;
            }
            return 999999999;

    }
}

