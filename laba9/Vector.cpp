#include "Vector.h"
#include "Error.h"

Vector::Vector() : size(0), beg(nullptr) {}

Vector::Vector(int s, int* mas) {
    if (s > MAX_SIZE) throw error("Vector length exceeds MAX_SIZE.");
    size = s;
    beg = new int[size];

    if (mas) {
        for (int i = 0; i < size; ++i)
            beg[i] = mas[i];
    }
    else {
        for (int i = 0; i < size; ++i)
            beg[i] = i + 1;
    }
}

Vector::Vector(const Vector& v) {
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; ++i)
        beg[i] = v.beg[i];
}

Vector::~Vector() {
    delete[] beg;
}

const Vector& Vector::operator=(const Vector& v) {
    if (this == &v) return *this;
    delete[] beg;
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; ++i)
        beg[i] = v.beg[i];
    return *this;
}

int& Vector::operator[](int i) {
    if (i < 0 || i >= size) throw error("Index out of range.");
    return beg[i];
}

int Vector::operator()() const {
    return size;
}

Vector& Vector::operator--() {
    if (size == 0) throw error("Cannot remove element from an empty vector (prefix).");
    int* new_beg = new int[size - 1];
    for (int i = 1; i < size; ++i)
        new_beg[i - 1] = beg[i];
    delete[] beg;
    beg = new_beg;
    size--;
    return *this;
}

Vector Vector::operator--(int) {
    if (size == 0) throw error("Cannot remove element from an empty vector (postfix).");
    Vector temp(*this);
    delete[] beg;
    size--;
    if (size > 0) {
        beg = new int[size];
        for (int i = 0; i < size; ++i)
            beg[i] = temp.beg[i];
    }
    else {
        beg = nullptr;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Vector& v) {
    if (v.size == 0) out << "Vector is empty." << endl;
    else {
        for (int i = 0; i < v.size; ++i)
            out << v.beg[i] << " ";
        out << endl;
    }
    return out;
}