#include <iostream>
#include <iomanip>

using namespace std;

class Complex {
public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {};

    ~Complex() {};

    Complex(const Complex &c) : re(c.re), im(c.im) {};

    Complex &operator+=(Complex a);

    Complex &operator-=(Complex a);

    Complex &operator+=(double b);

    Complex &operator-=(double b);

    Complex operator-() {
        return Complex(-re, -im);
    }

    friend ostream &operator<<(ostream &out, Complex &object) {
        out << setiosflags(ios::showpos) << object.re << setiosflags(ios::showpos) << object.im << 'i' << endl;
        return out;
    }

private:
    double re, im;
};


Complex &Complex::operator+=(Complex a) {
    this->re += a.re;
    this->im += a.im;
    return *this;
}

Complex &Complex::operator-=(Complex a) {
    this->re -= a.re;
    this->im -= a.im;
    return *this;
}

Complex &Complex::operator+=(double b) {
    this->re += b;
    return *this;
}

Complex &Complex::operator-=(double b) {
    this->re -= b;
    return *this;
}

Complex operator+(Complex a, Complex b) {
    Complex r = a;
    return r += b;
}

Complex operator+(Complex a, double b) {
    Complex r = a;
    return r += b;
}

Complex operator+(double b, Complex a) {
    Complex r = a;
    return r += b;
}

Complex operator-(Complex a, Complex b) {
    Complex r = a;
    return r -= b;
}

Complex operator-(Complex a, double b) {
    Complex r = a;
    return r -= b;
}

Complex operator-(double b, Complex a) {
    Complex r = a;
    return r -= b;
}

int main(int argc, char const *argv[]) {
    Complex a = Complex(2.1, 5.2);
    Complex b(5);
    Complex c = a + 2.3;
    Complex d = 2 + b;
    Complex e = -b - c;
    cout << a << b << c << d << e;
    return 0;
}