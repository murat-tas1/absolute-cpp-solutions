#include <iostream>
#include <cstdlib>
using namespace std;

class HotDogStand{
    public:
    HotDogStand(); //default constructor
    HotDogStand(int idNum,int sell);
    void justSold();
    int getSold();
    static int getTotalSell();
    private:
    int id;
    int countSell;
    static int totalSell;
};
int HotDogStand::totalSell = 0;
HotDogStand::HotDogStand():countSell(0){}
HotDogStand::HotDogStand(int idNum,int sell):id(idNum),countSell(sell){
    if(id < 0 || countSell<0){
        cout<<"invalid values exiting the program bye bye!!!"<<endl;
        exit(1);
    }
    totalSell +=countSell;
}
void HotDogStand::justSold(){
    ++countSell;
    ++totalSell;
}
int HotDogStand::getSold(){
    return countSell;
}
int HotDogStand::getTotalSell(){
    return totalSell;
}
int main() {
    HotDogStand stand1(101, 3); // Stand 1 with ID 101 starts with 3 hot dogs sold
    HotDogStand stand2(102, 5); // Stand 2 with ID 102 starts with 5 hot dogs sold
    HotDogStand stand3(103, 0); // Stand 3 with ID 103 starts with 0 hot dogs sold

    stand1.justSold(); // Stand 1 sells one more hot dog
    stand2.justSold(); // Stand 2 sells one more
    stand2.justSold(); // Stand 2 sells another one
    stand3.justSold(); // Stand 3 sells one hot dog

    cout << "Stand 1 Sales: " << stand1.getSold() << endl;
    cout << "Stand 2 Sales: " << stand2.getSold() << endl;
    cout << "Stand 3 Sales: " << stand3.getSold() << endl;

    cout << "Total Hot Dogs Sold: " << HotDogStand::getTotalSell() << endl;

    return 0;
}