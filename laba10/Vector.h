#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include "Error.h"
using namespace std;

const int MAX_SIZE = 20;

template <class T>
class Vector {
    int size;
    T* beg;
public:
    Vector();
    Vector(int s, T* mas = nullptr);
    Vector(const Vector<T>& v);
    ~Vector();

    const Vector<T>& operator=(const Vector<T>& v);
    T& operator[](int i);
    int operator()() const;
    Vector<T>& operator--();     // prefix
    Vector<T> operator--(int);   // postfix

    template<class U>
    friend ostream& operator<<(ostream& out, const Vector<U>& v);
};

// ================= Реалізація =====================

template <class T>
Vector<T>::Vector() : size(0), beg(nullptr) {}

template <class T>
Vector<T>::Vector(int s, T* mas) {
    if (s > MAX_SIZE) throw error("Vector length exceeds MAX_SIZE.");
    size = s;
    beg = new T[size];
    if (mas) {
        for (int i = 0; i < size; ++i)
            beg[i] = mas[i];
    }
    else {
        for (int i = 0; i < size; ++i)
            beg[i] = static_cast<T>(i + 1); // тип T повинен підтримувати це
    }
}

template <class T>
Vector<T>::Vector(const Vector<T>& v) {
    size = v.size;
    beg = new T[size];
    for (int i = 0; i < size; ++i)
        beg[i] = v.beg[i];
}

template <class T>
Vector<T>::~Vector() {
    delete[] beg;
}

template <class T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
    if (this == &v) return *this;
    delete[] beg;
    size = v.size;
    beg = new T[size];
    for (int i = 0; i < size; ++i)
        beg[i] = v.beg[i];
    return *this;
}

template <class T>
T& Vector<T>::operator[](int i) {
    if (i < 0 || i >= size) throw error("Index out of range.");
    return beg[i];
}

template <class T>
int Vector<T>::operator()() const {
    return size;
}

template <class T>
Vector<T>& Vector<T>::operator--() {
    if (size == 0) throw error("Cannot remove element from empty vector (prefix).");
    T* new_beg = new T[size - 1];
    for (int i = 1; i < size; ++i)
        new_beg[i - 1] = beg[i];
    delete[] beg;
    beg = new_beg;
    size--;
    return *this;
}

template <class T>
Vector<T> Vector<T>::operator--(int) {
    if (size == 0) throw error("Cannot remove element from empty vector (postfix).");
    Vector<T> temp(*this);
    delete[] beg;
    size--;
    if (size > 0) {
        beg = new T[size];
        for (int i = 0; i < size; ++i)
            beg[i] = temp.beg[i];
    }
    else {
        beg = nullptr;
    }
    return *this;
}

template <class U>
ostream& operator<<(ostream& out, const Vector<U>& v) {
    if (v.size == 0) out << "Vector is empty." << endl;
    else {
        for (int i = 0; i < v.size; ++i)
            out << v.beg[i] << " ";
        out << endl;
    }
    return out;
}

#endif
