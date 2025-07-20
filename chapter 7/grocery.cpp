#include <iostream>
#include <cstdlib>
using namespace std;

class Counter{
    public:
    Counter(int maxValue);
    Counter(); //default constructor
    void reset();
    void incr1(int num);
    void incr10(int num);
    void incr100(int num);
    void incr1000(int num);
    void checkOverFlow();
    void output();
    bool getOverFlow();
    private:
    int max;
    int counter;
    bool is_overflow;
    void setMax(); //helper function
};
Counter::Counter(int maxValue):max(maxValue),counter(0),is_overflow(false){
    if(maxValue<=0){
        cout<<"money cannot be negative and zero error!!!"<<endl;
        exit(1);
    }
}
Counter::Counter(){}
void Counter::reset(){
    counter = 0;
}
void Counter::incr1(int num){
    counter += 1*num;
}
void Counter::incr10(int num){
    counter += 10*num;
}
void Counter::incr100(int num){
    counter += 100*num;
}
void Counter::incr1000(int num){
    counter += 1000*num;
}
void Counter::output(){
    int dolar,cent;
    dolar = counter / 100;
    cent = counter % 100;
    cout<<"counter: "<<dolar<<".";
    if (cent < 10)
    cout << "0"; // so that it prints like 0.5
    cout << cent << endl;
    setMax();
}
void Counter::checkOverFlow(){
    if(counter > max){
        cout<<"oops it is overflow!!"<<endl;
        is_overflow = true;
        
    }
}
bool Counter::getOverFlow(){
        return is_overflow;
}
void Counter::setMax(){
    int num1,num2;
    int temp = max;
    num1 = temp % 10;
    temp/=10;
    num2 = temp % 10;
    temp/=10;
    cout<<"max limit: "<<temp<<"."<<num2<<num1<<endl;
}
int main(){
    char key;
    int num;
    Counter grocery(9999);
    do{
        cout<<"enter choice key: ";
        cin>>key>>num;
        switch(key){
            case 'a': //a for cents
            grocery.incr1(num);
            break;
            case 's': // s for dimes
            grocery.incr10(num);
            break;
            case 'd': // d for dollars
            grocery.incr100(num);
            break;
            case 'f': // f for tens of dollar
            grocery.incr1000(num);
            break;
            case 'r': //to reset
            grocery.reset();
            break;
            default:
            cout<<"invalid entry try again!!!";
        }
        grocery.checkOverFlow();
        grocery.output();

    }while(!(grocery.getOverFlow()));
    return 0;
}