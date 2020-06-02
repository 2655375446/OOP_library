#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    Tree *myTree;
    myTree = new Tree;
    myTree->regist("peach");
    myTree->regist("banana");
    myTree->regist("apple");
    myTree->regist("pear");
    myTree->regist("apple");
    myTree->regist("pineapple");
    myTree->print();
    return 0;
}
