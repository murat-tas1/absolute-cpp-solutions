#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Blog{
    public:
    void menu();
    void list();//list and display all messages
    protected:
    vector<string> messages;
};
void Blog::list(){
        cout<<"all messages are listed numerically"<<endl;
        for(int i = 0; i < messages.size(); ++i)
        cout<<i<<")"<<messages[i]<<endl;
}
class Owner:public Blog{
    public:
    void menu();
    private:
    void deleteMessage();

};
class Viewer:public Blog{
    public:
    void menu();
};
void Blog::menu(){
    cout<<"this is actually just an interface"<<endl;
}
void Owner::menu(){
    char choice;
    do{
    cout<<"select a choice: "<<endl;
    cout<<"enter a for posting new message"<<endl;
    cout<<"enter b for listing all messages"<<endl;
    cout<<"enter c for deleting specific message"<<endl;
    cout<<"enter e for exiting"<<endl;
    cin>>choice;
    string newMessage;
        switch(choice){
        case 'a':
        cout<<"post a new message: ";
        cin.ignore();//for deleting previous new line character
        getline(cin,newMessage);
        messages.push_back(newMessage);
        break;
        case 'b':
        list();
        break;
        case 'c':
        int num;
        cout<<"select a message for deleting: ";
        cin>>num;
        messages.erase(messages.begin() + num - 1);
        break;
        case 'e':
        cout<<"you are exiting"<<endl;
        break;
        default:
        cout<<"invalid choice!!!"<<endl;
        cout<<"try again!!!"<<endl;

    }

}while(choice!='e');
}
void Viewer::menu(){
    char choice;
     cout<<"enter b for listing all messages"<<endl;
     cin>>choice;
     list();
}

int main() {
    Owner owner;       
    Viewer viewer;     

    char userType;

    cout << "=== Welcome to the Blog System ===\n";
    cout << "Are you an (o)wner or a (v)iewer? ";
    cin >> userType;

    if (userType == 'o' || userType == 'O') {
        owner.menu();  
    } 
    else if (userType == 'v' || userType == 'V') {
        viewer.menu();
    } 
    else {
        cout << "Invalid input. Please enter 'o' or 'v'.\n";
    }

    return 0;
}
