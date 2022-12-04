#include "Vector.h"
#include <stdexcept>

template<class T>
Vector<T>::~Vector() {
    delete[] data;
}

template<class T>
int Vector<T>::begin() {
    return 0;
}

template<class T>
void Vector<T>::reserve(int _n) {
    data = new int[_n];
    if (data == nullptr) {
        data = new int[n];
        throw std::invalid_argument;
    }
    res_n = _n;
}

template<class T>
void Vector<T>::push_back(T arg) {
    ++n;
    if (res_n < n) {
        int *new_data = new int[n];
        for (int i = 0; i < n - 1; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;

        data = new_data;
        res_n = n;
    }

    data[n] = arg;
}

template<class T>
void Vector<T>::erase(int k) {
    for(int i=k; i<n-1; ++i) {
        data[i] = data[i+1];
    }
    --n;
}

template<class T>
int Vector<T>::size() {
    return n;
}
