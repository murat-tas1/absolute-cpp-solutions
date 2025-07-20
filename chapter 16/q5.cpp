#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


template<class T>
class Set{
    public:
    Set();// it initalizes array size 10
    Set(int sizeVal);
    Set(const Set<T>& object); //copy constructor
    Set<T>& operator=(const Set<T>& rhs);
    void addNewItem(T object);
    int getUsed () const;
    T* getPointer() const;
    virtual ~Set();
    private:
    T* items;
    int size; //capacity
    int used;
};

template<class T>
Set<T>::Set():size(10),used(0){
    items = new T[10];
}

template<class T>
Set<T>::Set(int sizeVal):size(sizeVal),used(0){
    items = new T[size];
}

template<class T>
 Set<T>::Set(const Set<T>& object):size(object.size),used(object.used){
    items = new T[object.size];
    for(int i = 0; i < used; ++i){
        items[i] = object.items[i];
    }
}

template<class T>
Set<T>& Set<T>::operator=(const Set<T>& rhs){
    if(size != rhs.size){
        delete[] items;
        items = new T[rhs.size];
    }
    for(int i = 0; i<rhs.used;++i){
        items[i] = rhs.items[i];
    }
    return *this;
}

template<class T>
void Set<T>::addNewItem(T object){
    if(used != size){
        items[used] = object;
        ++used;
    }
    else{
        cout<<"Set is completely full!!!"<<endl;
        cout<<"you cannot add this item to the set"<<endl;
    }
}

template<class T>
int Set<T>::getUsed () const{
    return used;
}
template<class T>
T* Set<T>::getPointer() const{
    return items;
}
template<class T>
Set<T>::~Set(){
    delete[] items;
}
