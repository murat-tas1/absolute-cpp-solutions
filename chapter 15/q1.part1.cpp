#include <iostream>
using namespace std;
//This is first part of question 1
//member functions are non virtual
class Figure{
    public:
    void erase();
    void draw();
    void center();
};
class Rectangle:public Figure{
    public:
    void erase();
    void draw();
    void center();
};
class Triangle:public Figure{
    public:
    void erase();
    void draw();
    void center();
};
void Figure::erase() {
    cout << "Figure's member function erase called" << endl;
}
void Figure::draw() {
    cout << "Figure's member function draw called" << endl;
}
void Figure::center() {
    cout << "Figure's member function center called" << endl;
    erase();
    draw();
}
void Rectangle::erase(){
    cout<<"Rectangle's member function erase called"<<endl;
}
void Triangle::erase(){
 cout<<"Triangle's member function erase called"<<endl;
}
void Rectangle::draw(){
    cout<<"Rectangle's member function draw called"<<endl;
}
void Triangle::draw(){
     cout<<"Triangle's member function draw called"<<endl;
}
void Rectangle::center(){
    erase();
    draw();
}
void Triangle::center(){
    erase();
    draw();
}
int main() {
    Rectangle r;
    Triangle t;
    Figure f;

    cout << "Calling center() on Rectangle object:" << endl;
    r.center();

    cout << "\nCalling center() on Triangle object:" << endl;
    t.center();

    cout << "\nCalling center() on Figure object:" << endl;
    f.center();

    return 0;
}
