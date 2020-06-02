//
// Created by 周师扬 on 2020/5/15.
//

#ifndef UNTITLED19_INTERGER_H
#define UNTITLED19_INTERGER_H

#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Interger {
    int ii;
public:
    Interger(int v = 0) : ii(v) {};                      //构造函数
    Interger(const char *c_str) {
        ii = atoi(c_str);
    };                   //构造函数
    Interger(const Interger &rhs) {
        ii = rhs.ii;
    }                  //复制操作
    Interger &operator=(const Interger &rhs) {
        this->ii = rhs.ii;
        return *this;
    }       //复制操作
    Interger &operator=(int n) {
        this->ii = n;
        return *this;
    }

    std::string toString() const {
        string c_str;
        stringstream ss;
        ss << this->ii;
        ss >> c_str;
        return c_str;
    }                   //转换字符串函数

    int value() const {
        return int(this->ii);
    }                              //获取值函数

    operator int() const {
        return int(this->ii);
    }                           //int类型转换

    operator double() const {
        return double(this->ii);
    }                        //double类型转换

    operator char() const {
        return char(this->ii);
    }                          //char类型转换

    int cmp(const Interger &rhs) {
        if (this->ii < rhs.ii) {
            return -1;
        } else if (this->ii = rhs.ii) {
            return 0;
        } else {
            return 1;
        }
    }                   //cmp比较函数

    friend bool operator<(Interger a, const Interger &b) {
        return a.cmp(b) == -1;
    }   //重载二元运算符6种

    friend bool operator<=(Interger a, const Interger &b) {
        return a.cmp(b) != 1;
    }

    friend bool operator>(Interger a, const Interger &b) {
        return a.cmp(b) == 1;
    }

    friend bool operator>=(Interger a, const Interger &b) {
        return a.cmp(b) != -1;
    }

    friend bool operator==(Interger a, const Interger &b) {
        return a.cmp(b) == 0;
    }

    friend bool operator!=(Interger a, const Interger &b) {
        return a.cmp(b) != 0;
    }

    Interger &operator+=(const Interger &a) {
        ii += a.ii;
        return *this;
    }           //重载一元运算符8种

    Interger &operator-=(const Interger &a) {
        ii -= a.ii;
        return *this;
    }

    Interger &operator*=(const Interger &a) {
        ii *= a.ii;
        return *this;
    }

    Interger &operator/=(const Interger &a) {
        ii /= a.ii;
        return *this;
    }

    Interger &operator+=(const int &a) {
        ii += a;
        return *this;
    }

    Interger &operator-=(const int &a) {
        ii -= a;
        return *this;
    }

    Interger &operator*=(const int &a) {
        ii *= a;
        return *this;
    }

    Interger &operator/=(const int &a) {
        ii /= a;
        return *this;
    }

    friend Interger &operator+(Interger a, const Interger &b) {
        a.ii += b.ii;
        return a;
    }       //重载二元运算符4种

    friend Interger &operator-(Interger a, const Interger &b) {
        a.ii -= b.ii;
        return a;
    }

    friend Interger &operator*(Interger a, const Interger &b) {
        a.ii *= b.ii;
        return a;
    }

    friend Interger &operator/(Interger a, const Interger &b) {
        a.ii /= b.ii;
        return a;
    }

    friend istream &operator>>(istream &in, Interger &object) {
        in >> object.ii;
        return in;
    }       //重载输入输出流函数

    friend ostream &operator<<(ostream &out, Interger &object) {
        out << object.ii << endl;
        return out;
    }
};


#endif //UNTITLED19_INTERGER_H
