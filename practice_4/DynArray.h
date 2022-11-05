//
// Created by musht on 04.11.2022.
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

    double get(int i) const {
        if (i < 0 or size < i) {
            std::cerr << "Out Of boundaries Error\n";
            exit(-55);
        }
        return mem[i];
    }

    static int live_arrays;

public:
    explicit DynArray(int capacity) {
        mem = new double [capacity];
        size = 0;
        this->capacity = capacity;
        live_arrays++;
    }

    DynArray(DynArray &arr) : capacity(arr.capacity), size(arr.size) {
        mem = new double[arr.capacity];
        for (int i = 0; i < size; ++i)
            mem[i] = arr.mem[i];
        live_arrays++;
    }

    DynArray(std::initializer_list<double> ini) {
        size = capacity = (int) ini.size();
        mem = new double[size];
        int i = 0;
        for (auto e : ini) {
            mem[i++] = e;
        }
        live_arrays++;
    }

    ~DynArray() {
        delete[] mem;
        --live_arrays;
    }

    DynArray &operator=(const DynArray &arr) {
        if (this == &arr) {
            return *this;
        }
        capacity = arr.capacity;
        size = arr.size;
        delete[] mem;
        mem = new double[capacity];
        for (int i = 0; i < size; ++i) {
            mem[i] = arr.mem[i];
        }
        ++live_arrays;
        return *this;
    }

    double operator[](int i) const { return get(i); }

    friend std::ostream &operator<<(std::ostream &os, const DynArray &array) {
        os << '[';
        if (array.size > 0)
            os << array[0];
        for (int i = 1; i < array.getSize(); ++i) {
            os << ", " << array[i];
        }
        os << "]";
        return os;
    }

    void append(double val) {
        if (size == capacity) {
            resize();
        }
        mem[size++] = val;
    }

    int getSize() const { return size; }

    static int getCountObjects() { return live_arrays; }
};

int DynArray::live_arrays = 0;

#endif //CPP_TRAININGS_DYNARRAY_H
