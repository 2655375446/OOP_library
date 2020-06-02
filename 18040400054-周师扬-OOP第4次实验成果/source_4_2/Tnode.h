//
// Created by 周师扬 on 2020/5/5.
//

#ifndef UNTITLED12_TNODE_H
#define UNTITLED12_TNODE_H

#include <iostream>

class Tnode {
private:
    Tnode *Lchild;
    Tnode *Rchild;
    char sign;
    double num;
public:
    Tnode() {
        sign = 0;
        num = 0;
        Lchild = NULL;
        Rchild = NULL;

    }

    Tnode(char c, double n, Tnode *L, Tnode *R) {
        sign = c;
        num = n;
        Lchild = L;
        Rchild = R;
    }

    void set_Lchild(Tnode *L) {
        Lchild = L;
    }

    void set_Rchild(Tnode *R) {
        Rchild = R;
    }

    Tnode *get_Lchild() {
        return Lchild;
    }

    Tnode *get_Rchild() {
        return Rchild;
    }

    void set_char(char c) {
        sign = c;
    }

    void set_number(double n) {
        num = n;
    }

    char get_char() {
        return sign;
    }

    double get_number() {
        return num;

    }
};


#endif //UNTITLED12_TNODE_H
