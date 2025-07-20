#include <iostream>
#include <cstdlib>
using namespace std;
typedef double* DoublePtr;

class TwoD{
    public:
    TwoD();
    TwoD(int rowVal,int colVal);
    TwoD(const TwoD& object); //copy constuctor
    void setEntry(int rowEnt,int colEnt,double val);
    double getEntry(int rowEnt,int colEnt) const;
    TwoD& operator=(const TwoD& other);
    friend TwoD operator+(const TwoD& lhs,const TwoD& rhs);//we assume row and column numbers of these two objcets must be same                                                         
    ~TwoD(); //destructor                                  //if they are not same exit the program
    private:
    DoublePtr* a;//this is pointer to pointer
    unsigned int row;
    unsigned int col;
    void dealloc(); //helper function for code-reuse
    void alloc(); //helper function for code-reuse
};
TwoD::TwoD():row(10000),col(10000){
    alloc();
}
TwoD::TwoD(int rowVal,int colVal):row(rowVal),col(colVal){
    if(rowVal<=0 || colVal<=0){
        cout<<"wrong entry for size!!!"<<endl;
        cout<<"exiting the program"<<endl;
        exit(1);
    }
    alloc();
}
TwoD::TwoD(const TwoD& object){ // copy constructor
    row = object.row;
    col = object.col;
    alloc();
    for(int i = 0; i < row;++i){
        for(int j = 0; j < col;++j){
            a[i][j] = object.a[i][j];
        }
    }
}
void TwoD::alloc(){
    a = new DoublePtr[row];
    for(int i = 0; i < row; ++i){
        a[i] = new double[col];
    }
}
void TwoD::setEntry(int rowEnt,int colEnt,double val){
    a[rowEnt][colEnt] = val;
}
double TwoD::getEntry(int rowEnt,int colEnt) const{
    return a[rowEnt][colEnt];
}
TwoD& TwoD::operator=(const TwoD& other){ //assign existing objects to each other
    if(this == &other){
        return *this;
    }
    dealloc();
    row = other.row;
    col = other.col;
    alloc();
    for(int i = 0; i < row;++i){
        for(int j = 0; j < col;++j){
            a[i][j] = other.a[i][j];
        }
    }
    return *this;
}
void TwoD::dealloc(){
    for(int i = 0; i < row; ++i){
        delete[] a[i];
    }
    delete[] a;
}
TwoD operator+(const TwoD& lhs,const TwoD& rhs){
    if(lhs.row != rhs.row || lhs.col !=rhs.col){
        cout<<"sizes is inconsistence"<<endl;
        exit(1);
    }
    TwoD result(lhs.row,lhs.col);
    for(int i = 0; i < rhs.row;++i){
        for(int j = 0; j < rhs.col;++j){
            result.a[i][j] = lhs.a[i][j] + rhs.a[i][j];
        }
    }
    return result;
}
TwoD::~TwoD(){
    dealloc();
}

int main() {
    // 1. Create two 2x2 matrices
    TwoD mat1(2, 2);
    TwoD mat2(2, 2);

    // 2. Assign values to mat1
    mat1.setEntry(0, 0, 1.0);
    mat1.setEntry(0, 1, 2.0);
    mat1.setEntry(1, 0, 3.0);
    mat1.setEntry(1, 1, 4.0);

    // 3. Assign values to mat2
    mat2.setEntry(0, 0, 5.0);
    mat2.setEntry(0, 1, 6.0);
    mat2.setEntry(1, 0, 7.0);
    mat2.setEntry(1, 1, 8.0);

    // 4. Add mat1 and mat2
    TwoD sum = mat1 + mat2;

    // 5. Print the result matrix
    cout << "Sum of mat1 and mat2:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << sum.getEntry(i, j) << " ";
        }
        cout << endl;
    }

    // 6. Test the assignment operator
    TwoD mat3(2, 2);
    mat3 = mat1;

    cout << "\nmat3 after assignment from mat1:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << mat3.getEntry(i, j) << " ";
        }
        cout << endl;
    }

    // 7. Test the copy constructor
    TwoD mat4 = mat2;

    cout << "\nmat4 copied from mat2 (copy constructor):" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << mat4.getEntry(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
