#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){ //if you want to store this to a string then you have to create one more strings exp called string result
            // then line to read,word to seperate words and resul to store would be
    string line,word;
    getline(cin,line);
    for(int i = 0; i<line.length();++i){
        if(isalpha(line[i])){
            word+=line[i];
        }
        else{
            if(word.length() == 4){
                if(isupper(word[0]))
                cout<<"Love";
                else
                cout<<"love";
            }
            else if(!word.empty()){
                cout<<word;
            }
            cout<<line[i];
            word = "";
        }
    }
    return 0;
}