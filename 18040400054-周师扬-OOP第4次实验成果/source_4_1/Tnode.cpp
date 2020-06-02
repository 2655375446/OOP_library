//
// Created by 周师扬 on 2020/4/17.
//

#include "Tnode.h"

Tnode::Tnode(string data) : word(data) {    //初始化
    count = 1;
    left = NULL;
    right = NULL;
}

void Tnode::showTnode() {
    cout << word << " " << count << endl;
}

Tnode *Tnode::get_Left() {
    return left;
}

Tnode *Tnode::get_Right() {
    return right;
}

string Tnode::get_Word() {
    return word;
}

void Tnode::set_Left(Tnode *pNew) {
    left = pNew;
}

void Tnode::set_Right(Tnode *pNew) {
    right = pNew;
}

void Tnode::add_Count() {
    count += 1;
}


