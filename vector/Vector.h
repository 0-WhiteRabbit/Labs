#ifndef LAB_4_VECTOR_H
#define LAB_4_VECTOR_H


#include <cstdint>

template <class T>
class Vector {
private:
    T *data=nullptr;
    int n=0, res_n=0;

public:
    class iterator;

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

    void erase(Vector<T>::iterator k) {
        while (k != end()) {
            *k = *(k+1);
            ++k;
        }
        --n;
    }

    int size()  {
        return n;
    }

    iterator begin() {
        return iterator(data);
    }

    void clear() {
        delete[] data;
        data = nullptr;
        n = 0;
        res_n = 0;
    }

    iterator end() {
        return iterator(&data[n]);
    }

    T& operator[](const int index) { return data[index]; };

    ~Vector() {
        delete[] data;
    }
};

template<class T>
class Vector<T>::iterator {
public:
    explicit iterator(T* p) : _curr(p) {}

    iterator& operator++() {
        _curr++;
        return *this;
    }

    friend iterator operator+(const iterator b, const int t) {
        return iterator(b._curr + t);
    }

    T& operator*() {
        return *_curr;
    }

    bool operator==(const iterator& b) const {
        return *_curr == *b._curr;
    }

    bool operator!=(const iterator& b) const {
        if (_curr == nullptr)
            return false;
        return *_curr != *b._curr;
    }

private:
    T* _curr;
};


#endif //LAB_4_VECTOR_H
