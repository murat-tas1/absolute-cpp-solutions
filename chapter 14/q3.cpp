#include <iostream>
#include <string>
using namespace std;

class Doctor:public SalariedEmployee {
    public:
    Doctor();
    Doctor(string& field,double fee);
    Doctor(const Doctor& obj); // copy constructor
    string getField() const;
    double getFee() const;
    Doctor& operator=(const Doctor& rhs);
    private:
    string specialty;
    double officeFee;
};
int main(){

    return 0;
}