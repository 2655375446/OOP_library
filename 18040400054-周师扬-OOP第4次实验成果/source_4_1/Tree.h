//
// Created by 周师扬 on 2020/4/17.
//

#ifndef UNTITLED9_TREE_H
#define UNTITLED9_TREE_H

#include <iostream>
#include "Tnode.h"
#include <stack>

using namespace std;

class Tree {
    Tnode *root;
public:
    Tree();

    ~Tree();

    bool searchNode(Tnode *bst, string key, Tnode *f, Tnode **p);

    bool regist(string key);

    void print();
};


#endif //UNTITLED9_TREE_H
