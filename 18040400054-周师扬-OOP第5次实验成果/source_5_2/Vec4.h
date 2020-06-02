//
// Created by 周师扬 on 2020/5/7.
//

#ifndef UNTITLED15_VEC4_H
#define UNTITLED15_VEC4_H

#include <iostream>

using namespace std;

class Vec4 {
private:
    float floats[4] = {0};
public:
    Vec4();

    Vec4(const Vec4 &);

    explicit Vec4(float *);

public:
    Vec4 &operator=(Vec4);

    friend Vec4 &operator+(Vec4, float);

    friend Vec4 &operator+(Vec4, Vec4);

    friend Vec4 &operator-(Vec4, float);

    friend Vec4 &operator-(Vec4, Vec4);

    friend Vec4 &operator*(Vec4, float);

    friend Vec4 &operator*(Vec4, Vec4);

    friend Vec4 &operator/(Vec4, float);

    friend Vec4 &operator/(Vec4, Vec4);

    Vec4 &operator+=(float);

    Vec4 &operator+=(Vec4);

    Vec4 &operator-=(float);

    Vec4 &operator-=(Vec4);

    Vec4 &operator*=(float);

    Vec4 &operator*=(Vec4);

    Vec4 &operator/=(float);

    Vec4 &operator/=(Vec4);

    float &operator[](int);

    friend istream &operator>>(istream &, Vec4 &);

    friend ostream &operator<<(ostream &, Vec4 &);


};


#endif //UNTITLED15_VEC4_H
