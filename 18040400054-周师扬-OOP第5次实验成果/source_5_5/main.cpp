#include <iostream>
#include "Interger.h"

int main() {
    Interger n1("2");
    cout << n1;
    Interger n2(3);
    cout << n2;
    n1 += n2;
    cout << n1;
    string c_str = n1.toString();
    for (char i : c_str) {
        cout << i;
    }
    cout << endl;
    return 0;
}
