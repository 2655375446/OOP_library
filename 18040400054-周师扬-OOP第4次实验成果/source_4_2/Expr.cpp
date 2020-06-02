//
// Created by 周师扬 on 2020/5/5.
//

#include "Expr.h"

void Expr::change(string const str) {
    Tnode temp;
    char number[15];
    int count_t = 0;
    for (int i = 0; i < str.size(); count_t++, i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')') {
            temp.set_char(str[i]);
        }
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
            int j;
            for (j = 0; (str[i] >= '0' && str[i] <= '9') || str[i] == '.'; j++, i++) {
                number[j] = str[i];
            }
            number[j] = '\0';
            i--;
            temp.set_number(atof(number));
        }

        translation[count_t] = temp;

        temp.set_char(0);
        temp.set_number(0);
    }
    this->count = count_t;
}

Tnode *Expr::build_tree(int begin, int end) {

    if (end == begin) {
        return &translation[end];
    }
    bool first_mul = false;
    bool brackets = false;
    int mul_place = 0;
    int add_place = 0;
    for (int i = begin; i <= end; i++) {
        switch (translation[i].get_char()) {
            case '(': {
                int temp = i;
                brackets = true;
                while (translation[i].get_char() != ')') {
                    i++;
                }
                break;
            }
            case '+':
            case '-': {
                add_place = i;
                break;
            }
            case '*':
            case '/': {
                if (first_mul == false) {
                    mul_place = i;
                    first_mul = true;
                }
                break;
            }
        }
    }
    if (first_mul == false && brackets == false) {
        translation[add_place].set_Lchild(build_tree(begin, add_place - 1));
        translation[add_place].set_Rchild(build_tree(add_place + 1, end));
        return &translation[add_place];
    }

    if (first_mul) {
        translation[mul_place].set_Lchild(build_tree(begin, mul_place - 1));
        translation[mul_place].set_Rchild(build_tree(mul_place + 1, end));
        return &translation[mul_place];
    }
    if (brackets) {
        return build_tree(begin + 1, end - 1);
    }
}

void Expr::cal(stack<double> &num, Tnode *T) {
    if (T != NULL) {
        cal(num, T->get_Lchild());

        cal(num, T->get_Rchild());

        if (T->get_char() == 0)
            num.push(T->get_number());
        else {
            double temp;
            temp = num.top();
            num.pop();
            switch (T->get_char()) {
                case '+': {
                    temp = temp + num.top();
                    num.pop();
                    num.push(temp);
                    break;
                }
                case '-': {
                    temp = num.top() - temp;
                    num.pop();
                    num.push(temp);
                    break;
                }
                case '*': {
                    temp = temp * num.top();
                    num.pop();
                    num.push(temp);
                    break;
                }
                case '/': {
                    temp = num.top() / temp;
                    num.pop();
                    num.push(temp);
                    break;
                }

            }

        }
    }
}

string Expr::lexer(char s[]) {
    string str = s;
    bool flag = true;
    for (int i = 0; i < str.size(); i++) {

        switch (str[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (str[i + 1] == '(') {
                    cout << "error" << endl;
                    return "";
                }
                break;
            case '+':
            case '-': {
                if (str[i - 1] == '(' || str[i - 1] == NULL) {
                    str.insert(i, 1, '0');
                    i++;
                }
            }
            case '*':
            case '/':
                if (str[i + 1] == ')' || str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' ||
                    str[i + 1] == '/') {
                    cout << "error" << endl;
                    return "";
                }
                break;
            case '(':
                if (str[i + 1] == ')' || str[i + 1] == '*' || str[i + 1] == ';') {
                    cout << "error" << endl;
                    return "";
                }
                break;
            case ')':
                if ((str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == '(') {
                    cout << "error" << endl;
                    return "";
                }
                break;
            case ' ':
            case '\n': {
                str.erase(str.begin() + i);
                i--;
                break;
            }
            case '.': {
                if (!(str[i + 1] >= '0' && str[i + 1] <= '9')) {
                    cout << "error" << endl;
                    return "";
                }
                break;
            }

            default: {
                cout << "error" << endl;
                return "";
            }
        }

    }

    return str;
}

void Expr::print() {
    for (int i = 0; i < count; i++) {
        if (translation[i].get_char() == 0) {
            cout << translation[i].get_number();
        } else {
            cout << translation[i].get_char();
        }
    }
}

void Expr::print_tree(int n) {
    switch (n) {

        case 1:
            print_Proorder_tree(head->get_Lchild());
            break;
        case 2:
            print_Midorder_tree(head->get_Lchild());
            break;
        case 3:
            print_Postorder_tree(head->get_Lchild());
            break;
    }

}

void Expr::print_Postorder_tree(Tnode *T) {
    if (T != NULL) {
        print_Postorder_tree(T->get_Lchild());

        print_Postorder_tree(T->get_Rchild());

        if (T->get_char() == 0)
            cout << T->get_number();
        else
            cout << T->get_char();
    }
}

void Expr::print_Proorder_tree(Tnode *T) {
    if (T != NULL) {
        if (T->get_char() == 0)
            cout << T->get_number();
        else
            cout << T->get_char();
        print_Proorder_tree(T->get_Lchild());

        print_Proorder_tree(T->get_Rchild());


    }
}

void Expr::print_Midorder_tree(Tnode *T) {
    if (T != NULL) {
        cout << "(";
        print_Midorder_tree(T->get_Lchild());

        if (T->get_char() == 0)
            cout << T->get_number();
        else
            cout << T->get_char();

        print_Midorder_tree(T->get_Rchild());
        cout << ")";


    }
}
