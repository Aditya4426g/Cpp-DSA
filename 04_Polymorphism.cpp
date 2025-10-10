#include <iostream>
#include <string>
using namespace std;

class Print{
public:
    void show(int x){
        cout << x <<endl;
    }
    void show(char ch){
        cout<< ch <<endl;
    }
};
class Number {
public:
    int value;
    Number(int v) : value(v) {}
    Number operator+(const Number &n) {
        return Number(value + n.value);
    }
};


int main(){
    // Print p;
    // p.show(1);
    // p.show('a');
    Number n1(5), n2(10);
    Number n3 = n1 + n2;  // n3.value will be 15

    
    return 0;
}