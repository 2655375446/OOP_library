//
// Created by 周师扬 on 2020/4/17.
//

#ifndef UNTITLED9_TNODE_H
#define UNTITLED9_TNODE_H

#include <iostream>

using namespace std;

class Tnode {
    string word;
    int count;
    Tnode *left;
    Tnode *right;
public:
    Tnode(string data = "=0");

    void showTnode();

    Tnode *get_Left();

    Tnode *get_Right();

    string get_Word();

    void set_Left(Tnode *);

    void set_Right(Tnode *);

    void add_Count();
};


#endif //UNTITLED9_TNODE_H
