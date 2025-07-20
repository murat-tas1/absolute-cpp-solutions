#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
using namespace std;

class BoxOfProduce{
    public:
    BoxOfProduce(vector<string>& v);
    string getProduces();
    void setProduces(vector<string>& v);
    void output() const;
    void outputRecipe() const;
    void determineTomatillo();
    private:
    void testData(int n);
    vector<string> p;
    static int countRecipeFly;
    bool hasRecipeFly;
};
int BoxOfProduce::countRecipeFly = 5; 
void print_list(vector<string>& v){
    int i;
    for(i = 0; i<5;++i)
    cout<<i+1<<")  "<<v[i]<<endl;
}
int main() {
    srand(time(0));

    ifstream inFile("produce.txt");
    vector<string> s;
    string line;

    while (getline(inFile, line)) {
        if (!line.empty())
            s.push_back(line);
    }
    inFile.close();
    cout << "Available produce:\n";
    print_list(s);
    while(1){
    BoxOfProduce box(s);

    cout << "\ncurrent box:\n";
    box.output();

    char choice;
    cout << "\nWould you like to make a substitution? (y/n): ";
    cin >> choice;

    while (choice == 'y' || choice == 'Y') {
        box.setProduces(s);
        cout << "\nUpdated box:\n";
        box.output();
        cout << "\nAnother substitution? (y/n): ";
        cin >> choice;
    }

    cout << "\nFinal box to be delivered:\n";
    box.output();
    box.determineTomatillo();
    box.outputRecipe();
    cout<<"Do you want another order of boxes? (y)/(n)";
    cin>>choice;
    if(choice == 'n' || choice == 'N'){
        cout<<"exiting the program bye bye"<<endl;
        break;
    }
    else if(!(choice == 'y' || choice == 'Y')){
        cout<<"Wrong entry exiting the program bye bye"<<endl;
    }
};

    return 0;
}
BoxOfProduce::BoxOfProduce(vector<string>& v):hasRecipeFly(false){
    int i,index;
    for(i = 0;i<3;++i){
        index = rand() % 5;
        p.push_back(v[index]);
    }

}
void BoxOfProduce::testData(int n){
    if(!(n>=1 && n<=3)){
        cout<<"wrong entry!!! exiting the program"<<endl;
        exit(1);
    }
}
string BoxOfProduce::getProduces(){
    int choice;
    cout << "Which item would you like to view? (1-3): ";
    cin>>choice;
    testData(choice);
    return p[choice - 1];
}
void BoxOfProduce::setProduces(vector<string>& v){
    int choice,n;
    cout<<"which item would you like to replace? (1-3): ";
    cin>>choice;
    testData(choice);
    cout<<"with what?: press 1,2,3,4,5 according to the list: ";
    cin>>n;
    p[choice - 1] = v[n-1];

}
void BoxOfProduce::output() const{
    int i;
    cout<<"contents of the box:"<<endl;
    for(i = 0;i<3;++i)
    cout<<p[i]<<endl;
}
void BoxOfProduce::determineTomatillo(){
    int i;
    for(i=0;i<3;++i){
        if(p[i] == "Tomatillo" && countRecipeFly>0){
        hasRecipeFly = true;
        --countRecipeFly;
        break;
        }
    }
}
void BoxOfProduce::outputRecipe() const{
    if(hasRecipeFly)
    cout<<"salsa verde recipe flyer"<<endl;
}