#ifndef LAB_4_VECTOR_H
#define LAB_4_VECTOR_H


#include <cstdint>
#include <iterator>

template <class T>
class Vector {
private:
    T *data=nullptr;
    int n=0, res_n=0;

public:
    void push_back(T arg) {
        ++n;
        if (res_n < n) {
            T *new_data = new T[n];
            for (int i = 0; i < n - 1 && data != nullptr; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;

            data = new_data;
            res_n = n;
        }

        data[n-1] = arg;
    }

    void reserve(int _n) {
        data = new T[_n];
        res_n = _n;
    }

    void erase(uintptr_t k) {
        k = k - begin();
        for(uintptr_t i=k; i<(n-1); i++) {
            data[i] = data[i+1];
        }
        --n;
    }

    int size()  {
        return n;
    }

    int begin() {
        return 0;
    }

    void clear() {
        delete[] data;
        data = nullptr;
        n = 0;
        res_n = 0;
    }

    int end() {
        return n;
    }

    T& operator[](const int index) { return data[index]; };

    ~Vector() {
        delete[] data;
    }
};

#endif //LAB_4_VECTOR_H
