//
// Created by musht on 06.11.2022.
//

#ifndef CPP_TRAININGS_DYNARRAY_H
#define CPP_TRAININGS_DYNARRAY_H

#include <vector>
#include <ostream>

template <class T>
class DynArray {
private:
    std::vector<T> values;
    static int obj_count;
public:
    explicit DynArray(int capacity);
    DynArray(std::initializer_list<T> li);
    DynArray(const DynArray<T> &array);
    ~DynArray();

    DynArray<T> &operator=(const DynArray &other);

    T &operator[](int index);

    void append(T value);

    int size() const;

    template<class V>
    friend std::ostream &operator<<(std::ostream &o, DynArray<V> &array);

    DynArray<T> &operator+=(const DynArray<T> &other);

    DynArray<T> operator+(const DynArray<T> &other);

    DynArray<T> operator*(int k);

    static int getObjectCount();
};

template<class T>
int DynArray<T>::obj_count = 0;

template<class T>
std::ostream &operator<<(std::ostream &o, DynArray<T> &array) {
    o << '[';
    if (array.size() > 0)
        o << array.values[0];
    for (int i = 1; i < array.size(); ++i)
        o << ", " << array.values[i];
    o << ']';
    return o;
}


#endif //CPP_TRAININGS_DYNARRAY_H
