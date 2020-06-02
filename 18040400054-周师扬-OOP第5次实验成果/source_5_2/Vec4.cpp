//
// Created by 周师扬 on 2020/5/7.
//

#include "Vec4.h"

Vec4 &Vec4::operator=(Vec4 a) {
    for (int i = 0; i < 4; ++i) {
        this->floats[i] = a.floats[i];
    }
    return *this;
}

Vec4 &operator+(Vec4 a, float det) {
    for (int i = 0; i < 4; ++i) {
        a.floats[i] += det;
    }
    return a;
}

Vec4 &operator+(Vec4 a, Vec4 b) {
    for (int i = 0; i < 4; ++i) {
        a.floats[i] += b.floats[i];
    }
    return a;
}

Vec4 &operator-(Vec4 a, float det) {
    for (int i = 0; i < 4; ++i) {
        a.floats[i] -= det;
    }
    return a;
}

Vec4 &operator-(Vec4 a, Vec4 b) {
    for (int i = 0; i < 4; ++i) {
        a.floats[i] -= b.floats[i];
    }
    return a;
}

Vec4 &operator*(Vec4 a, float det) {
    for (int i = 0; i < 4; ++i) {
        a.floats[i] *= det;
    }
    return a;
}

Vec4 &operator*(Vec4 a, Vec4 b) {
    for (int i = 0; i < 4; ++i) {
        a.floats[i] *= b.floats[i];
    }
    return a;
}

Vec4 &operator/(Vec4 a, float det) {
    for (int i = 0; i < 4; ++i) {
        a.floats[i] /= det;
    }
    return a;
}

Vec4 &operator/(Vec4 a, Vec4 b) {
    for (int i = 0; i < 4; ++i) {
        a.floats[i] /= b.floats[i];
    }
    return a;
}

Vec4 &Vec4::operator+=(float det) {
    for (int i = 0; i < 4; ++i) {
        this->floats[i] += det;
    }
    return *this;
}

Vec4 &Vec4::operator+=(Vec4 a) {
    for (int i = 0; i < 4; ++i) {
        this->floats[i] += a.floats[i];
    }
    return *this;
}

Vec4 &Vec4::operator-=(float det) {
    for (int i = 0; i < 4; ++i) {
        this->floats[i] -= det;
    }
    return *this;
}

Vec4 &Vec4::operator-=(Vec4 a) {
    for (int i = 0; i < 4; ++i) {
        this->floats[i] -= a.floats[i];
    }
    return *this;
}

Vec4 &Vec4::operator*=(float det) {
    for (int i = 0; i < 4; ++i) {
        this->floats[i] *= det;
    }
    return *this;
}

Vec4 &Vec4::operator*=(Vec4 a) {
    for (int i = 0; i < 4; ++i) {
        this->floats[i] *= a.floats[i];
    }
    return *this;
}

Vec4 &Vec4::operator/=(float det) {
    for (int i = 0; i < 4; ++i) {
        this->floats[i] /= det;
    }
    return *this;
}

Vec4 &Vec4::operator/=(Vec4 a) {
    for (int i = 0; i < 4; ++i) {
        this->floats[i] /= a.floats[i];
    }
    return *this;
}

istream &operator>>(istream &in, Vec4 &object) {
    in >> object.floats[0] >> object.floats[1] >> object.floats[2] >> object.floats[3];
    return in;
}

ostream &operator<<(ostream &out, Vec4 &object) {
    out << object.floats[0] << " " << object.floats[1] << " " << object.floats[2] << " " << object.floats[3] << endl;
    return out;
}

Vec4::Vec4() {
    for (int i = 0; i < 4; ++i) {
        this->floats[i] = 0;
    }
}

Vec4::Vec4(const Vec4 &object) {
    for (int i = 0; i < 4; ++i) {
        this->floats[i] = object.floats[i];
    }
}

Vec4::Vec4(float *a) {
    for (int i = 0; i < 4; ++i) {
        this->floats[i] = a[i];
    }
}

float  &Vec4::operator[](int a) {
    return this->floats[a];
}






