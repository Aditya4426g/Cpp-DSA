#include <iostream>
#include <string>
using namespace std;

class Shape{//abstract class
public:
    virtual void Draw(){}; //pure Virtual Function

};
class Circle : public Shape{
public:
    void Draw(){
        cout<<"Circle"<<endl;
    };
};

int main(){
    Shape *ptr;
    Circle c;
    ptr=&c;
    ptr->Draw();
    return 0;
}