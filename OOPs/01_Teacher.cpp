#include <iostream>
#include <string>
using namespace std;
//Encapsulation  
class Teacher{
        double salary;
    public:

    //constructor
    
    Teacher() //Non parameterized
    {
        cout<<"Hi i am constructor"<<endl;
        dept="Computer Science";
    }

    Teacher(string name,string dept,string subject,double salary)//parameterized
    {
        this->name=name;
        this->dept=dept;
        this->subject=subject;
        this->salary=salary;
    }

    Teacher(Teacher &org)//copy constructor
    {
        this->name=org.name;
        this->dept=org.dept;
        this->subject=org.subject;
        this->salary=org.salary;
    }
    
    //properties
    string name;
    string dept;
    string subject;


    //methods
    void changeDept(string newDept){
        dept =newDept;
    }
    //setter
    void setSalary(double s){
        salary=s;
    }
    //getter
    double getSalary(){
        return salary;
    }
};
int main(){
    Teacher t1("Adi","CS","C++",60000);//constructor call 
    Teacher t2;//constructor overloading
    Teacher t3(t1);//default copy constructor

    // t1.name="Adi";
    // t1.subject="C++";
    // // t1.dept = "Computer Science";
    // t1.setSalary(50000);

    cout<<t1.name<<endl;
    cout<<t1.dept<<endl;
    cout<<t1.subject<<endl;
    cout<<t1.getSalary()<<endl;
    cout <<endl;
    cout<<t3.name<<endl;
    cout<<t3.dept<<endl;
    cout<<t3.subject<<endl;
    cout<<t3.getSalary()<<endl;
    return 0;
}