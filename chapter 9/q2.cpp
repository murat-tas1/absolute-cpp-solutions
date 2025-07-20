#include <iostream>
#include <string>
#include <cctype>

using namespace std;
const int alp_size = 26;
int main(){
    string word;
    getline(cin,word);
    int occur[alp_size] = {0};
    int countWord = 0;
    bool inWord = false;
    for(int i = 0;i<word.length();++i){
      if(isalpha(word[i])){
        char ch = tolower(word[i]);
        ++occur[ch - 'a'];
        if(!inWord){ // is it word beginning ?
            ++countWord;
            inWord = true;
        }
      }
      else if(isspace(word[i]) || word[i] == '.' || word[i] == ','){
        inWord = false;
      }
    }
    cout<<countWord<<"  words"<<endl;
    for(int i = 0; i<alp_size;++i){
        if(occur[i]!=0)
        cout<<occur[i]<<"  "<<static_cast<char>('a' + i)<<endl;
    }
    return 0;
}