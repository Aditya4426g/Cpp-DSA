#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
    string name;
    double *cgpaPtr;

    Student(string name,double cgpa)
    {
        this->name=name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    Student(Student &stud){//Deep Copy
        this->name=stud.name;
        cgpaPtr = new double;
        *cgpaPtr=*stud.cgpaPtr;
    }

    void getInfo(){
        cout<<"Name : "<<name<<endl;
        cout<<"CGPA : "<<*cgpaPtr<<endl;
    }
};
int main(){
    Student s1("Adi",8.81);
    s1.getInfo();
    Student s2(s1);//default copy constructor give shallow Copy
    *(s2.cgpaPtr)=10;
    s1.getInfo();
    s2.getInfo();
    return 0;
}