#include <iostream>
#include "Vec4.h"

int main() {
    Vec4 a, b;
    cin >> a >> b;
    a += b;
    cout << a;
    a = b + 1;
    a -= 2.0;
    a = b * 2;
    a = a * b;
    a /= b;
    cout << a;
    a[0] = 3.1415926E+5;
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
    return 0;
}
