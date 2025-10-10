#include <iostream>
#include <string>
using namespace std;

class Parent{
public:
    void show() {
        cout <<"Parent class"<<endl;
    }
    virtual void hello(){
        cout<<"Hello p";
    }; //Virtual Function

};
class Child : public Parent{
public:
    void show() //Override
    {
        cout <<"Child class"<<endl;
    }
    void hello(){
        cout<<"Hello"<<endl;
    };
};

int main(){
    Child c1;
    c1.show();
    c1.hello();
    Parent *p1;
    p1=&c1;
    p1->hello();
    return 0;
}