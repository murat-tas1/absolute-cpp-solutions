#include <iostream>
using namespace std;
//This is second part of question 1
//member functions are virtual

class Figure{
    public:
   virtual void erase();
   virtual void draw();
   virtual void center();
};
class Rectangle:public Figure{
    public:
    virtual void  erase();
    virtual void  draw();
    virtual  void center();
};
class Triangle:public Figure{
    public:
    virtual void erase();
    virtual void draw();
    virtual void center();
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
    Figure* fig1 = new Rectangle();
    Figure* fig2 = new Triangle();
    Figure* fig3 = new Figure();

    cout << "Calling center() on Rectangle object via Figure pointer:" << endl;
    fig1->center();

    cout << "\nCalling center() on Triangle object via Figure pointer:" << endl;
    fig2->center();

    cout << "\nCalling center() on Figure object directly:" << endl;
    fig3->center();

    return 0;
}
