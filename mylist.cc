/* A sequence container type implemented as a doubly-linked list */
#include <stdlib.h>
#include <iostream>
/*
 * List() --> constructor.
 * ~List() --> desctructor.
 * front() --> access the first element.
 * back() --> access the last element.
 * push_back() --> adds an element to the end.
 * push_front() --> inserts an element to the beginning.
 * pop_back() --> removes the last element.
 * pop_front() --> removes the first element.
 * insert_after(value, element) --> inserts an element after value.
 * insert_before(value, element) --> inserts an element before value.
 * clear() --> erases all the elements from the container.
 * remove() --> removes elements satisfying specific criteria.
 * reverse() --> reverses the order of the elements.
 * merge() --> merges two lists
 * operator=(other) --> copy assignment operator.
 */

template<typename T>
class List {
public:
    List();
    ~List();

    void PushBack(const T &value);
    void PushFront(const T &value);
    void InsertAfter(const T &value, const T &newvalue);
    void InsertBefore(const T &value, const T &newvalue);
    void Clear();
    void Reverse();
    void Merge(List &other);
    void Remove(const T &value);

    void PrintAll();

    int size() const { return size_; }
    
private:
    void ClearInternal();
    
    int size_;
    class Node { // member class
        T value_;
        Node *next_;
        Node *prev_;
    public:
        Node(T value)
            : value_(value),
              next_(nullptr),
              prev_(nullptr) {}
        T value() const { return value_; }
        void set_prev(Node *prev) { prev_ = prev; }
        Node *prev() const { return prev_; }
        void set_next(Node *next) { next_ = next; }
        Node *next() const { return next_; }
    };
    Node *head_;
    Node *tail_;
};

template<typename T>
List<T>::List()
    : size_(0), head_(nullptr), tail_(nullptr)
{
    std::cout << "List()" << std::endl;
}

template<typename T>
List<T>::~List()
{
    std::cout << "~List()" << std::endl;
    ClearInternal();
}

template<typename T>
void List<T>::PrintAll()
{
    Node *p;
    
    for (p = head_; p != nullptr; p = p->next())
        std::cout << p->value() << std::endl;
}

template<typename T>
void List<T>::PushBack(const T &value)
{
    Node *nodep;

    nodep = new Node(value);
    nodep->set_prev(tail_);
    if (tail_ != nullptr)
        tail_->set_next(nodep);
    tail_ = nodep;
    if (head_ == nullptr)
        head_ = nodep;
    ++size_;
}

template<typename T>
void List<T>::PushFront(const T &value)
{
    Node *nodep;

    nodep = new Node(value);
    nodep->set_next(head_);
    if (head_ != nullptr)
        head_->set_prev(nodep);
    head_ = nodep;
    if (tail_ == nullptr)
        tail_ = nodep;
    ++size_;
}

// Uses operator= to compare.
template<typename T>
void List<T>::InsertAfter(const T &value, const T &newvalue)
{
    Node *p;

    for (p = head_; p != nullptr; p = p->next())
        if (p->value() == value) {
            Node *newp = new Node(newvalue);
            newp->set_next(p->next());
            if (p->next() == nullptr)
                tail_ = newp;
            else
                p->next()->set_prev(newp);
            p->set_next(newp);
            newp->set_prev(p);
            ++size_;
            break;
        }
}

template<typename T>
void List<T>::InsertBefore(const T &value, const T &newvalue)
{
    Node *p;

    for (p = head_; p != nullptr; p = p->next())
        if (p->value() == value) {
            Node *newp = new Node(newvalue);
            newp->set_next(p);
            newp->set_prev(p->prev());
            if (p->prev() == nullptr)
                head_ = newp;
            else
                p->prev()->set_next(newp);
            p->set_prev(newp);
            ++size_;
            break;
        }
}

template<typename T>
void List<T>::ClearInternal()
{
    Node *next;

    for ( ; head_ != nullptr; head_ = next) {
        next = head_->next();
        delete head_;
    }
}

template<typename T>
void List<T>::Clear()
{
    ClearInternal();
    size_ = 0;
    head_ = nullptr;
    tail_ = nullptr;
}

template<typename T>
void List<T>::Reverse()
{
    Node *p, *next, *prev;

    tail_ = head_;
    for (p = head_ ; p != nullptr; p = next) {
        next = p->next();
        prev = p->prev();
        p->set_prev(next);
        p->set_next(prev);
        head_ = p;
    }
}

template<typename T>
void List<T>::Merge(List &other)
{
}

template<typename T>
void List<T>::Remove(const T &value)
{
    Node *p;

    for (p = head_; p != nullptr; p = p->next())
        if (p->value() == value) {
            if (p->prev() == nullptr)
                head_ = p->next();
            else
                p->prev()->set_next(p->next());

            if (p->next() == nullptr)
                tail_ = p->prev();
            else
                p->next()->set_prev(p->prev());
            delete p;
            --size_;
            break;
        }
}


int main(int argc, char *argv[])
{
    List<double> list;

    list.PushBack(1.05);
    list.PushBack(1.04);
    list.PushBack(1.03);
    list.PushBack(1.02);
    list.PushBack(1.1);
    list.PushBack(1.2);

    list.PrintAll();

    list.InsertBefore(1.05, 100.22);
    list.InsertBefore(1.03, 55);
    list.InsertAfter(1.03, 77);
    list.InsertAfter(1.2, 99.22);
    std::cout << "-----" << std::endl;
    list.PrintAll();

    std::cout << "size == " << list.size() << std::endl;

    list.Remove(100.22);
    list.Remove(1.03);
    list.Remove(99.22);
    list.PrintAll();
    std::cout << "size == " << list.size() << std::endl;
    list.Reverse();
    list.PrintAll();

    std::cout << "Clear()" << std::endl;
    list.Clear();
    list.PrintAll();
    std::cout << "size == " << list.size() << std::endl;
    return EXIT_SUCCESS;
}



