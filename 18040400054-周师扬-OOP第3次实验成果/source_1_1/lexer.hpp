
//  周师扬 18040400054
//  编写日期：2020年3月29日
//  oop第三次上机实验第一题
//

#ifndef UNTITLED_LEXER_H
#define UNTITLED_LEXER_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

namespace Lexer{
    enum Token_value{
        NAME, NUMBER, END, PLUS='+',
        MINUS='-', MUL='*', DIV='/',
        PRINT=';', ASSIGN='=', LP='(', RP=')',
        ERR,
    };

    Token_value get_token();
    extern std::istream *input;
    int parseCommandLine(int argc,char *argv[]);
    extern std::vector<std::string> fileNames;
    int switch_input();
    void skip();

}

#endif //UNTITLED_LEXER_H
