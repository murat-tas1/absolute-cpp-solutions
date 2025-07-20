#include <iostream>
#include <vector>
using namespace std;
void print_vector(vector<int>& v){
    int i;
    for(i = 0; i<v.size();++i)
    cout<<v[i];
    cout<<"      ";
}
void findLuckyWinner(vector<int>& v){
    int elem,index = 0;
    print_vector(v);
    cout<<"initial list of suitors,start counting from 1"<<endl;
    while(v.size() !=1){
        index = (index+2) % v.size();
        elem = v[index];
        v.erase(v.begin() + index);
        print_vector(v);
        cout<<"suitor "<<elem<<" eleminated,";
        if(v.size() ==1)
        cout<<v[0]<<" is the lucky winner"<<endl;
        else
        cout<<"continue counting from "<<v[index]<<endl;

    }

}
int main(){
    int n;
    cout<<"enter how many suitors there are:  ";
    cin>>n;
    vector<int> s(n); //pre:n>1
    int i;
    for(i=0;i<n;++i)
    s[i] = i+1;
    findLuckyWinner(s);
    return 0;
}