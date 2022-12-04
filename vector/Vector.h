#ifndef LAB_4_VECTOR_H
#define LAB_4_VECTOR_H


template <class T>
class Vector {
private:
    T *data=nullptr;
    int n=0, res_n=0;

public:
    void push_back(T arg);
    void reserve(int _n);
    void erase(int k);
    int size();
    int begin();
    int& operator[](const int index) { return data[index]; };

    ~Vector();
};

#endif //LAB_4_VECTOR_H
