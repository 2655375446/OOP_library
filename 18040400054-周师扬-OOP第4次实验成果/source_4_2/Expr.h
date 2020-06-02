//
// Created by 周师扬 on 2020/5/5.
//

#ifndef UNTITLED12_EXPR_H
#define UNTITLED12_EXPR_H

#include "Tnode.h"
#include <stack>
#include <string>

using namespace std;

class Expr {
private:
    Tnode translation[100];
    int count;
    Tnode *head = new Tnode;
    stack<double> num;
    char str[100];
public:
    Expr(char str[]) {
        change(lexer(str));
        head->set_Lchild(build_tree(0, count - 1));
    }

    void change(string const str);

    Tnode *build_tree(int begin, int end);

    double eval() {
        cal(num, head->get_Lchild());
        return num.top();
    }

    void cal(stack<double> &num, Tnode *T);

    void print();


    void print_tree(int n);

    void print_Postorder_tree(Tnode *T);

    void print_Proorder_tree(Tnode *T);

    void print_Midorder_tree(Tnode *T);

    string lexer(char str[]);

};


#endif //UNTITLED12_EXPR_H
