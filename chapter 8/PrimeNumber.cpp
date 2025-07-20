#include <iostream>
#include <cmath>
using namespace std;

class PrimeNumber{
    public:
    PrimeNumber();
    PrimeNumber(int val);
    int getNumber()const;
    PrimeNumber& operator++(); //prefix increment
    PrimeNumber operator++(int marker); //postfix increment
    PrimeNumber& operator--(); //prefix decrement
    PrimeNumber operator--(int marker); //postfix decrement
    private:
    int num;
    bool isPrime(int prime); //helper function
};

PrimeNumber::PrimeNumber():num(1){}
PrimeNumber::PrimeNumber(int val):num(val){}
int PrimeNumber::getNumber()const{
    return num;
}
bool PrimeNumber::isPrime(int prime){
    int i;
    if(prime <=1){
        return false;
    }
    for(i = 2; i <= sqrt(prime);++i){
        if(prime % i ==0){
            return false;
        }
    }
    return true;
}
PrimeNumber& PrimeNumber::operator++(){
    ++num;
    while(!isPrime(num)){
        ++num;
    }
    return *this;
}
PrimeNumber PrimeNumber::operator++(int marker){
    PrimeNumber temp = *this;
    ++num;
    while(!isPrime(num)){
        ++num;
    }
    return temp;
}

PrimeNumber& PrimeNumber::operator--(){
    --num;
    while(!isPrime(num)){
        --num;
    }
    return *this;
}
PrimeNumber PrimeNumber::operator--(int marker){
    PrimeNumber temp = *this;
    --num;
    while(!isPrime(num)){
        --num;
    }
    return temp;
}

