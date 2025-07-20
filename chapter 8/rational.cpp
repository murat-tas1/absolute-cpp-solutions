#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Rational{
    public:
    Rational(int numVal,int denomVal);
    Rational(int wholeNumber);
    Rational(); //default constructor
    friend ostream& operator <<(ostream& os,const Rational& ration); //overloading insertion operator
    friend istream& operator >>(istream& is,Rational&);       // overloading extraction operator
    friend bool operator ==(const Rational& lhs,const Rational& rhs);
    friend bool operator <(const Rational& lhs,const Rational& rhs);
    friend bool operator <=(const Rational& lhs,const Rational& rhs);
    friend bool operator >(const Rational& lhs,const Rational& rhs);
    friend bool operator >=(const Rational& lhs,const Rational& rhs);
    const Rational operator +(const Rational& other);
    const Rational operator -(const Rational& other);
    const Rational operator *(const Rational& other); //I defined these as member function.Just because I felt like it
    const Rational operator /(const Rational& other);
    private:
    int numerator;
    int denominator;
    //helper functions
    void checkData();
    void equalizeDenoms(Rational& lhs,Rational& rhs); //equalize the denominator
    void normalizeValues();
    static int gcd(int num1,int num2);

};
 void Rational::checkData(){
    if(denominator ==0){
        cerr<<"undefined entry!!!"<<endl<<"you are exiting the program"<<endl;
        exit(1);
    }
 }
int Rational::gcd(int num1,int num2){
    if(num2 == 0){
        return num1;
    }
    return gcd(num2,num1 % num2);
}
void Rational::normalizeValues(){
    int div = gcd(abs(numerator),abs(denominator));
    numerator/=div;
    denominator /= div;
    if(denominator < 0){
        numerator *=-1;
        denominator*=-1;
    }
}

Rational::Rational(int numVal,int denomVal):numerator(numVal),denominator(denomVal){
    checkData();
    normalizeValues();
}
Rational::Rational(int wholeNumber):numerator(wholeNumber),denominator(1){
    checkData();
}
Rational::Rational():numerator(0),denominator(1){}

void Rational::equalizeDenoms(Rational& lhs, Rational& rhs) {
    int commonDenom = lhs.denominator * rhs.denominator;
    lhs.numerator *= rhs.denominator;
    rhs.numerator *= lhs.denominator;
    lhs.denominator = commonDenom;
    rhs.denominator = commonDenom;
}

const Rational Rational:: operator+(const Rational& other){
    Rational left = *this;
    Rational right = other;
    if(denominator != other.denominator){
        equalizeDenoms(left,right);
    }
    return Rational(left.numerator + right.numerator,left.denominator);
}

const Rational Rational::operator -(const Rational& other){
    Rational left = *this;
    Rational right = other;
    if(denominator != other.denominator){
        equalizeDenoms(left,right);
    }
    return Rational(left.numerator - right.numerator,left.denominator);
}

const Rational Rational::operator*(const Rational& other){
    return Rational(numerator*other.numerator,denominator*other.denominator);
}
const Rational Rational::operator /(const Rational& other){
    return Rational(numerator*other.denominator,denominator*other.numerator);
}
bool operator ==(const Rational& lhs,const Rational& rhs){
    return ((lhs.numerator * rhs.denominator) == (lhs.denominator *rhs.numerator));
}
bool operator <(const Rational& lhs,const Rational& rhs){
    return ((lhs.numerator * rhs.denominator) < (lhs.denominator *rhs.numerator));
}
bool operator <=(const Rational& lhs,const Rational& rhs){
    return ((lhs.numerator * rhs.denominator) <= (lhs.denominator *rhs.numerator));
}
bool operator >(const Rational& lhs,const Rational& rhs){
    return ((lhs.numerator * rhs.denominator) > (lhs.denominator *rhs.numerator));
}
bool operator >=(const Rational& lhs,const Rational& rhs){
    return ((lhs.numerator * rhs.denominator) >= (lhs.denominator *rhs.numerator));
}
ostream& operator <<(ostream& os,const Rational& ration){
    os<<ration.numerator<<"/"<<ration.denominator;
    return os;
}
istream& operator>>(istream& is,Rational& ration){
    cout<<"enter numerator value: ";
    is>>ration.numerator;
    cout<<"enter denominator value: ";
    is>>ration.denominator;
    ration.checkData();
    ration.normalizeValues();
    return is;
}
