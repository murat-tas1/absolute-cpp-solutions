#include <iostream>
#include <string>
using namespace std;
//U.S POSTAL SERVICE USING FORMAT POSTNET

class ZipCode{
    public:
    ZipCode(int inZip);
    ZipCode(string inBar);
    int getZipCode();
    string getBarCode();
    private:
    int zipCode;
    int countDigit;
    string convertZipToBar(int inZip);
    int convertBarToZip(string inBar);
    void findCountDigit();
};

ZipCode::ZipCode(int inZip):zipCode(inZip){}
ZipCode::ZipCode(string inBar){
    zipCode = convertBarToZip(inBar);
}
int ZipCode::getZipCode(){
    return zipCode;
}
string ZipCode::getBarCode(){
    string barCode = convertZipToBar(zipCode);
    return barCode;
}
void ZipCode::findCountDigit(){
    int temp = zipCode;
    int i = 1;
    while((temp/10) != 0){
        ++i;
        temp/=10;
    }
    countDigit = i;
}
string ZipCode::convertZipToBar(int inZip){
    string bar;
    bar.resize(27);
    bar[0] = '1';
    bar[27] = '1';
    int index = 1;
    int i,j,num,div;
    string temp = to_string(inZip);
    for(i=0;i<countDigit;++i){
        num = temp[i];
        div = num / 7;
        bar[index++] = div;
        num = num % 7;
        div = num / 4;
        bar[index++] = div;
        num = num % 4;
        div = num / 2;
        bar[index++] = div;
        num = num % 2;
        div = num / 1;
        bar[index++] = div;
        num = num % 1;
        bar[index++] = 0;
    }
    return bar;
}
int main(){

    return 0;
}