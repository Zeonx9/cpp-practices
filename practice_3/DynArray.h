//
// Created by musht on 15.10.2022.
//

#ifndef CPP_TRAININGS_DYNARRAY_H
#define CPP_TRAININGS_DYNARRAY_H

#include <iostream>

class DynArray {
private:
    double *mem;
    int size;
    int capacity;

    void resize() {
        auto newmem = new double[capacity * 2 + 1];
        for (int i = 0; i < size; ++i) {
            newmem[i] = mem[i];
        }
        delete[] mem;
        mem = newmem;
    }

public:
    explicit DynArray(int capacity) {
        mem = new double [capacity];
        size = 0;
        this->capacity = capacity;
    }

    DynArray(DynArray &arr) : capacity(arr.capacity), size(arr.size) {
        mem = new double[arr.capacity];
        for (int i = 0; i < size; ++i)
            mem[i] = arr.mem[i];
    }

    DynArray(std::initializer_list<double> ini) {
        size = capacity = (int) ini.size();
        mem = new double[size];
        int i = 0;
        for (auto e : ini) {
            mem[i++] = e;
        }
    }

    ~DynArray() {
        delete[] mem;
    }

    void append(double val) {
        if (size == capacity) {
            resize();
        }
        mem[size++] = val;
    }

    int getSize() const { return size; }

    double get(int i) const {
        if (i < 0 or size < i) {
            std::cerr << "Out Of boundaries Error\n";
            exit(-55);
        }
        return mem[i];
    }

    friend std::ostream &operator<<(std::ostream &os, const DynArray &array) {
        os << '[';
        if (array.size > 0)
            os << array.get(0);
        for (int i = 1; i < array.getSize(); ++i) {
            os << ", " << array.get(i);
        }
        os << "]";
        return os;
    }
};

#endif //CPP_TRAININGS_DYNARRAY_H
