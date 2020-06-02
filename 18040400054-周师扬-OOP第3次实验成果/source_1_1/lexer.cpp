
//  周师扬 18040400054
//  编写日期：2020年3月29日
//  oop第三次上机实验第一题
//

#include"lexer.hpp"
#include<string>
#include<vector>
#include"error.hpp"

extern Lexer::Token_value curr_tok;
extern int line;
extern double number_value;
extern std::string string_value;
extern int no_of_errors;

std::istream *Lexer::input=NULL;
std::vector<std::string> Lexer::fileNames;

int Lexer::parseCommandLine(int argc,char* argv[])
{
    if(argc==1)
    {
        Lexer::input=&std::cin;
        return 0;
    }
    else
    {
        for(int i=1;i<argc;i++)
        {
            fileNames.push_back(argv[i]);
            Lexer::input=new std::ifstream(fileNames[0].c_str());
            Lexer::input->good();
            fileNames.erase(fileNames.begin());
        }
        
    }
    return 0;
}

int Lexer::switch_input()
{
    if(fileNames.empty() )
    {return 1;}  /*没有文件了*/
    else
    {
        delete Lexer::input; //关闭上个文件，接着打开下个文件
        Lexer::input=new std::ifstream(fileNames[0].c_str());
        Lexer::input->good();
        fileNames.erase(fileNames.begin());
    }
    return 0;
}

Lexer::Token_value Lexer::get_token()
{
    char ch;
    do{ // 这里是跳过空白字符
        if(!(input->get(ch)))
        {
            if(ch=='\n'||ch==';'||ch==' ')line++;
            if(Lexer::PRINT!=curr_tok )
                return curr_tok=PRINT;
            // 当前文件结束了，尝试打开下一文件
            if(0!=switch_input())
                return curr_tok=END;
            else
            {ch=' ';continue;}
        }
    } while(ch!='\n'&&isspace(ch));

    switch(ch)
    {
        case 0:
            return curr_tok=END;
        case '\n':
            return curr_tok=PRINT;
        case '+':
        case '-':
        case '*':
        case '/':
        case ';':
        case '(':
        case ')':
        case '=':
            return curr_tok=Token_value(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            Lexer::input->putback(ch);
            *Lexer::input>>number_value;
            return curr_tok=NUMBER;
        default:
            if(isalpha(ch))
            {
                string_value=ch;
                while(Lexer::input->get(ch) &&isalnum(ch))string_value.push_back(ch);
                Lexer::input->putback(ch);
                return curr_tok=NAME;
            }
            Error::error("bad token");
            return curr_tok=ERR;
    }
}

void Lexer::skip()
{
    no_of_errors++;
    while(*input)
    {
        char ch;
        input->get(ch);
        switch(ch)
        {
            case '\n':
            case ';':
                input->get(ch);
                return ;//返回但是无返回值
        }
    }
}
