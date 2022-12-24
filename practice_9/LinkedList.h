//
// Created by musht on 23.12.2022.
//

#ifndef CPP_TRAININGS_LINKEDLISTT_H
#define CPP_TRAININGS_LINKEDLISTT_H


template<class T>
class BaseLinkedList {
private:
    // class of nodes that are used in list
    struct Node {
        T value;
        Node *next;
        Node(const T &v, Node *n) : value(v), next(n) {}
    };

    // iterator of linked list
    class Iterator {
    protected:
        Node *node;
    public:
        explicit Iterator(Node *ptr) : node(ptr) {}
        Iterator(const Iterator &it)=default;

        T& operator*() const {  //reference
            return node->value;
        }
        Iterator& operator++() { // prefix-increment
            if (not node)
                exit(-400);
            node = node->next;
            return *this;
        }
        Iterator& operator+(int i) {
            if (i < 0)
                exit(-300);
            for (int k = 0; k < i; ++k)
                ++(*this);
            return *this;
        }
        friend bool operator==(const Iterator& a, const Iterator& b) {
            return a.node == b.node;
        };
        friend bool operator!=(const Iterator& a, const Iterator& b) {
            return a.node != b.node;
        };
    };

    // iterator that supports insertion
    class InsertIterator : public Iterator {
    public:
        explicit InsertIterator(const Iterator it) : Iterator(it) {}
        void insert(const T &value) {
            this->node->next = new Node(this->node->value, this->node->next);
            this->node->value = value;
        }
    };

    // private fields
    Node *head = nullptr;
    Node *tail = nullptr;
    bool moved = false;

public:
    BaseLinkedList()=default;
    // list intializer constructor
    BaseLinkedList(std::initializer_list<T> ini) {
        for (auto e : ini)
            push_back(e);
    }
    // copy constructor
    BaseLinkedList(const BaseLinkedList<T> &bll) {
        for (auto e : bll)
            push_back(e);
    }
    // move constructor
    BaseLinkedList(BaseLinkedList<T> &&bll) noexcept {
        bll.moved = true;
        head = bll.head;
        tail = bll.tail;
    }
    // copy assignment
    BaseLinkedList<T> &operator=(const BaseLinkedList &bll) {
        if (this != &bll) {
            clear();
            head = tail = nullptr;
            for (auto e : bll)
                push_back(e);
        }
        return *this;
    }
    // move assignment
    BaseLinkedList<T> &operator=(BaseLinkedList<T> &&bll) noexcept {
        bll.moved = true;
        head = bll.head;
        tail = bll.tail;
        return *this;
    }
    // destructor
    ~BaseLinkedList() {
        if (not moved)
            clear();
    }

    // methods used by range-based for loop
    Iterator begin() const {
        return Iterator {head};
    }
    Iterator end() const {
        return Iterator{nullptr};
    }

    BaseLinkedList<T> &push_back(const T &v) {
        if (not tail) {
            push_front(v);
        } else {
            auto node = new Node(v, nullptr);
            tail = tail->next = node;
        }
        return *this;
    }

    BaseLinkedList<T> &push_front(const T &v) {
        head = new Node(v, head);
        if (not head->next)
            tail = head;
        return *this;
    }

    T pop_front() {
        if (not head)
            exit(-200);
        auto node = head;
        head = head->next;
        T out = node->value;
        if (not head) {
            tail = nullptr;
        }
        delete node;
        return out;
    }

    // linear time O(n)
    T pop_back() {
        if (head == tail)
            return pop_front();
        auto *cur = head;
        while (cur->next != tail)
            cur = cur->next;
        T out = tail->value;
        delete tail;
        cur->next = nullptr;
        tail = cur;
        return out;
    }

    // inserts element into given position
    void insert(Iterator position, const T &value) {
        if (position == end()) {
            push_front(value);
            return;
        }
        InsertIterator ins(position);
        ins.insert(value);
        if (tail->next)
            tail = tail->next;
    }

    void clear() {
        auto cur = head;
        while (cur) {
            auto next = cur->next;
            delete cur;
            cur = next;
        }
        head = tail = nullptr;
    }

    // linear time O(n)
    T& operator[](int i) {
        if (i == -1)
            return tail->value;
        return *(begin() + i);
    }
};

template<class T>
class LinkedList : public BaseLinkedList<T> {
public:
    LinkedList() : BaseLinkedList<T>() {}
    LinkedList(std::initializer_list<T> ini) : BaseLinkedList<T>(ini) {}
    LinkedList(const LinkedList<T> &bll) : BaseLinkedList<T>(bll) {}
    LinkedList(LinkedList<T> &&bll) noexcept : BaseLinkedList<T>(bll) {}
};

template<>
class LinkedList<char> : public BaseLinkedList<char> {
public:
    LinkedList(std::initializer_list<char> ini) : BaseLinkedList<char>(ini) {}

    explicit LinkedList(const std::string & str) : BaseLinkedList<char>() {
        for (auto c : str) {
            push_back(c);
        }
    }

    LinkedList<char> &operator=(const std::string &str) {
        *this = LinkedList<char>(str);
        return *this;
    }
};


#endif //CPP_TRAININGS_LINKEDLISTT_H
