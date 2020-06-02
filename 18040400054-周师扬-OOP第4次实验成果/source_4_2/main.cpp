#include <iostream>2+@
#include "Expr.h"

using namespace std;

int main() {
    char str[100];
    cin >> str;
    Expr a(str);    //分析式子
    a.print_tree(1);    //前序遍历
    cout << "\n";
    a.print_tree(2);    //中序遍历
    cout << "\n";
    a.print_tree(3);    //后续遍历
    cout << "\n";
    cout << "\n" << a.eval();
}

