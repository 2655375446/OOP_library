//
// Created by 周师扬 on 2020/4/17.
//

#include "Tree.h"

Tree::Tree() {
    root = NULL;
}

Tree::~Tree() {     // 实现树的自动销毁
    if (root == NULL) {
        return;
    }
    Tnode *p = root;
    stack<Tnode *> s;
    while (p != NULL || !s.empty()) {
        while (p != NULL) {
            s.push(p);
            p = p->get_Left();
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            delete p;
            p = p->get_Right();
        }
    }
    delete root;
}

bool Tree::searchNode(Tnode *bst, string key, Tnode *f, Tnode **p) {
    if (!bst) {
        *p = f;
        return false;
    }
    if (bst->get_Word() == key) {
        *p = bst;
        return true;
    } else if (bst->get_Word() < key) {
        return searchNode(bst->get_Right(), key, bst, p);
    }
    return searchNode(bst->get_Left(), key, bst, p);
}

bool Tree::regist(string key) {
    if (root == NULL) {
        Tnode *t = new Tnode(key);
        root = t;
        return true;
    }
    Tnode *p;
    if (!searchNode(root, key, NULL, &p)) {
        Tnode *t = new Tnode(key);
        if (key < p->get_Word()) {
            p->set_Left(t);
        } else if (key > p->get_Word()) {
            p->set_Right(t);
        }
        return true;
    } else {
        p->add_Count();
    }
}

void Tree::print() {
    if (root == NULL) {
        cout << "Tree is empty ! " << endl;
        return;
    }
    Tnode *p = root;
    stack<Tnode *> s;
    while (p != NULL || !s.empty()) {
        while (p != NULL) {
            s.push(p);
            p = p->get_Left();
        }
        if (!s.empty()) {
            p = s.top();
            p->showTnode();
            s.pop();
            p = p->get_Right();
        }
    }
}










