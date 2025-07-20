#include <iostream>
using namespace std;

class MyInteger{
    public:
    int getValue() const;
    void setValue(int val);
    MyInteger();
    int operator[](int index);
    private:
    int num;
    int findDigits() const; //helper function
};
MyInteger::MyInteger():num(0){}
int MyInteger::findDigits()const{
    int count = 0;
    int temp = num;
    if(num ==0){
        return 1;
    }
    while(temp != 0){
        temp/=10;
        ++count;
    }
    return count;
}
int MyInteger::operator[](int index){
    int digitCount = findDigits();
    if(index<0 || index>=digitCount)
    return -1;
    int temp = num;
    for(int i = 0; i < index;++i){
        temp/=10;
    }
    return temp % 10;
}
int MyInteger::getValue()const{
    return num;
}
void MyInteger::setValue(int val){
    num = val;
}

