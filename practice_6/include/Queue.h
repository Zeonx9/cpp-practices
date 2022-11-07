//
// Created by musht on 07.11.2022.
//

#ifndef CPP_TRAININGS_QUEUE_H
#define CPP_TRAININGS_QUEUE_H

#include <vector>
#include <ostream>

template<class T>
class Queue {
private:
    std::vector<T> values;
public:
   explicit Queue(int capacity);
   Queue(std::initializer_list<T> li);

   void enqueue(T value);
   T dequeue();
   int size() const;
   bool isEmpty() const;

    template<class V>
   friend std::ostream &operator<<(std::ostream &os, const Queue<V> &q);
};

template<class V>
std::ostream &operator<<(std::ostream &os, const Queue<V> &q) {
    os << "{";
    if (not q.isEmpty()) os << q.values[0];
    for (int i = 0; i < q.size(); ++i)
        os << ", " << q.values[i];
    os << "}";
    return os;
}


#endif //CPP_TRAININGS_QUEUE_H
