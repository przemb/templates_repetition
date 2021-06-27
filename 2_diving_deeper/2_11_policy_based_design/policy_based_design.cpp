#include <iostream>


#define NAME_OF( v ) #v

// --- Locking
class LockingPolicy {
public:
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

class Lock : public LockingPolicy {
public:
    void lock()     { std::cout << " Locking \n"; }
    void unlock()   { std::cout << " Unlocking \n"; } 
};

class NoLock : public LockingPolicy {
public:
    void lock() { }
    void unlock() { }
};


// --- Deletion
template <typename T>
class DeletionPolicy {
public:
    virtual void deleter(T* obj, 
                         const std::string& name) = 0;
};

template <typename T>
class NoDelete : public DeletionPolicy<T> {
public: 
    void deleter(T* obj,
                 const std::string& name) { }
};

template <typename T>
class Delete : public DeletionPolicy<T> {
public:
    void deleter(T* obj, 
                 const std::string& name) {
        std::cout << name << " deleting data...\n";        
        delete obj;
    }
};

template <typename T>
class ArrayDelete : public DeletionPolicy<T> {
public:
    void deleter(T* obj,
                 const std::string& name) {
        std::cout << name << " deleting array...\n";
        delete [] obj;
    }
};

// --- Client
template<typename T, 
         typename Locking, 
         template <typename> class Deletion>
class Data : public Locking, public Deletion<T> {
    T* data_;
    std::string name_;
public:
    Data(T* data, std::string name) : data_{data}, name_{name}
                                      {}
    ~Data() {
        this->deleter(data_, name_);
    }
    void do_something() {
        std::cout << "Using " << name_ << ": \n";
        this->lock();
        std::cout << "Data: " << *data_ << "\n";
        this->unlock();
    }
};

int main() {
    std::cout << "Policy example: \n\n";

    int* p1 = new int {10};
    Data<int, Lock, Delete> d1  {p1, NAME_OF(d1)};
    Data<int, NoLock, NoDelete> d2 {p1, NAME_OF(d2)};

    char* p2 = new char[5] {'s', 'o', 'm', 'e', '\0'};
    Data<char, Lock, Delete> d3 {p2, NAME_OF(d3)};

    d1.do_something();
    d2.do_something();
    d3.do_something();

    return 0;
}