#include <iostream>
#include <cstdlib>
using namespace std;
class CharPair{
    public:
    CharPair();
    CharPair(int sz);
    CharPair(int sz,char array[]);
    char& operator[](int index);
    int getSize() const;
    private:
    char a[100];
    int size;
};
CharPair::CharPair():size(10){
    int i;
    for(i=0;i<size;++i)
    a[i] = '#';
}
CharPair::CharPair(int sz){
    int i;
    for(i=0;i<sz;++i)
    a[i] = '#';
}
CharPair::CharPair(int sz,char array[]){
    int i;
    for(i=0;i<sz;++i)
    a[i] = array[i];
}
char& CharPair::operator[](int index){
    if(index<0 || index>=100)
    exit(1);
    return a[index];
}
int CharPair::getSize() const{
    return size;
}