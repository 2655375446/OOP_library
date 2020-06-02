#include <iostream>

using namespace std;

template<class M>
struct T {
    M m;

    T() {};

    T(M v) { m = v; }
};

template<class M>
class Ptr_to_T {
    T<M> *p;
    T<M> *array;
    int size;
    int index = 0;
public:
    Ptr_to_T(T<M> *, T<M> *, int);

    T<M> *operator->() { return p; }

    T<M> &operator*() {
        return *p;
    }

    T<M> &operator[](int i) { return p[i]; }

    void operator--() {
        this->p--;
        this->index--;
        if (index < 0) {
            throw 1;
        }
    }

    void operator++() {
        this->p++;
        this->index++;
        if (index > size - 1) {
            throw 2;
        }
    }
};

template<class M>
Ptr_to_T<M>::Ptr_to_T(T<M> *a, T<M> *b, int Size) {
    p = a;
    array = b;
    size = Size;
    index = (a - b) / sizeof(b);
}

int main() {
    T<int> v[200];
    Ptr_to_T<int> P(&v[0], v, 200);
    try {
        --P;
        T<int> a = *P;
    }
    catch (int) {
        cerr << "Overflow!" << endl;
    }
    *P = T<int>(0);
    P = Ptr_to_T<int>(&v[10], v, 200);
    P->m = 10;
    return 0;
}
