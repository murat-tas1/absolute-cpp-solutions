#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Constants
const int DEEP_DISH = 1;
const int HAND_TOSSED = 2;
const int PAN = 3;

const int SMALL = 1;
const int MEDIUM = 2;
const int LARGE = 3;

class Pizza {
public:
    // Constructor
    Pizza();

    // Mutators (setters)
    void setType(int t);
    void setSize(int s);
    void setCheeseToppings(int c); //number of cheese toppings
    void setPepperoniToppings(int p); //number of pepperoni toppings

    // Accessors (getters)
    int getType() const;
    int getSize() const;
    int getCheeseToppings() const;
    int getPepperoniToppings() const;

    // Member functions
    void outputDescription() const;
    void computePrice();

private:
    int type;
    int size;
    int cheeseToppings;
    int pepperoniToppings;
    int totalPrice;
};
Pizza::Pizza() {
    type = HAND_TOSSED;
    size = MEDIUM;
    cheeseToppings = 0;
    pepperoniToppings = 0;
}

// Setters
void Pizza::setType(int t) {
    type = t;
}

void Pizza::setSize(int s) {
    size = s;
}

void Pizza::setCheeseToppings(int c) {
    cheeseToppings = c;
}

void Pizza::setPepperoniToppings(int p) {
    pepperoniToppings = p;
}

// Getters
int Pizza::getType() const {
    return type;
}

int Pizza::getSize() const {
    return size;
}

int Pizza::getCheeseToppings() const {
    return cheeseToppings;
}

int Pizza::getPepperoniToppings() const {
    return pepperoniToppings;
}
// Price calculator
void Pizza::computePrice() {
    int basePrice = 0;

    switch (size) {
        case SMALL: basePrice = 10; break;
        case MEDIUM: basePrice = 14; break;
        case LARGE: basePrice = 17; break;
    }

    int totalToppings = cheeseToppings + pepperoniToppings;
    totalPrice =  basePrice + (2 * totalToppings);
}
// Description printer
void Pizza::outputDescription() const {
    string typeStr, sizeStr;

    switch (type) {
        case DEEP_DISH: typeStr = "Deep Dish"; break;
        case HAND_TOSSED: typeStr = "Hand Tossed"; break;
        case PAN: typeStr = "Pan"; break;
        default: typeStr = "Unknown"; break;
    }

    switch (size) {
        case SMALL: sizeStr = "Small"; break;
        case MEDIUM: sizeStr = "Medium"; break;
        case LARGE: sizeStr = "Large"; break;
        default: sizeStr = "Unknown"; break;
    }

    cout << "Pizza Description:\n";
    cout << "Type: " << typeStr << endl;
    cout << "Size: " << sizeStr << endl;
    cout << "Cheese Toppings: " << cheeseToppings << endl;
    cout << "Pepperoni Toppings: " << pepperoniToppings << endl;
    cout << "Total price: "<<totalPrice<<endl;
}

class Order{
    public:
    void setOrder();
    void output(int i) const;
    private:
    vector<Pizza> p;
};

void Order::setOrder(){
    Pizza p1;
    int n;
    cout<<"pizza type(press: deepfish(1),handtossed(2),pan(3)): ";
    cin>>n;
    p1.setType(n);
    cout<<"pizza size(press: small(1),medium(2),large(3)): ";
    cin>>n;
    p1.setSize(n);
    cout<<"how many would you like add cheese toppings: ";
    cin>>n;
    p1.setCheeseToppings(n);
    cout<<"how many would you like add pepperoni toppings: ";
    cin>>n;
    p1.setPepperoniToppings(n);
    p1.computePrice();
    p.push_back(p1);
}
void Order::output(int i) const{
    p[i].outputDescription();
}

int main(){
    int i = 0; //customer's first order
    char ch;
    Order o;
    cout<<"welcome to Murat Pizza"<<endl;
    cout<<"chose a menu: "<<endl;
    o.setOrder();
    o.output(i);
    while(1){
        cout<<"Would you like to order anything else?(y/n): ";
        cin>>ch;
        if(ch =='y' || ch == 'Y'){
            ++i;
            o.setOrder();
            o.output(i);
        }
        else if(ch == 'n' || ch == 'N'){
            cout<<"thank you,enjoy your meal!!!"<<endl;
            return 1;
        }
        else{
            cout<<"invalid entry.try again!!!"<<endl;
        }
    }
    return 0;
}