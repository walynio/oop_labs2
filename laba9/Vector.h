#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

class Vector {
    int size;
    int* beg;
public:
    Vector();
    Vector(int s, int* mas = nullptr);
    Vector(const Vector& v);
    ~Vector();
    const Vector& operator=(const Vector& v);

    int& operator[](int i);
    int operator()() const;
    Vector& operator--();
    Vector operator--(int);

    friend ostream& operator<<(ostream& out, const Vector& v);
};

#endif