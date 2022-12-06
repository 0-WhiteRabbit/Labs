#ifndef LAB_4_VECTOR_H
#define LAB_4_VECTOR_H


template <class T>
class Vector {
private:
    T *data=nullptr;
    int n=0, res_n=0;

public:
    void push_back(T arg) {
        ++n;
        if (res_n < n) {
            int *new_data = new int[n];
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
        data = new int[_n];
        res_n = _n;
    }

    void erase(int k) {
        for(int i=k; i<n-1; ++i) {
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

    int& operator[](const int index) { return data[index]; };

    ~Vector() {
        delete[] data;
    }
};

#endif //LAB_4_VECTOR_H
