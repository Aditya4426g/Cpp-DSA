#include <iostream>
#include <string>
using namespace std;

class S {
public:
    static int x;

    void count() {
        x++;
    }
};

int S::x = 0;

int main() {
    S s1, s2;
    s1.count();
    cout << s1.x << endl; 
    s2.count();
    cout << s2.x << endl;
    return 0;
}
