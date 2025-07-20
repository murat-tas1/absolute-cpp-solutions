#include <iostream> 
#include <string>
#include <cctype>
using namespace std;

// we will operate character by character in a loop
int main(){
    string inp,outp;
    getline(cin,inp);
    int i;
    char ch;
    bool previousWasSpace = false;
    for(i = 0; i<inp.length();++i){
        ch = inp[i];
        if(isspace(ch)){
            if(!previousWasSpace){
                outp+=' ';
                previousWasSpace = true; //by doing this we skip more than one spaces e
            }                            // between every words must be only one space
        }
        else{
            if(isupper(ch)){
                ch = tolower(ch);
                outp+=ch;
            }
            else
            outp+=ch;

            previousWasSpace = false;
        }
    }
    outp[0] = toupper(outp[0]); //the first char must be capital letter
    cout<<outp;
    return 0;
}