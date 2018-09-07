#include<iostream>
using namespace std;

class Student
{
    int a;
public:
    Student()
    {
        a=0;
    }
    Student(int b)
    {
        a=b;
    }
    Student (Student &s)
    {
        a=s.a;
    }
    void display()
    {
        cout<<a<<" ";
    }

};
int main()
{
    Student obj1[3];
    for(int i=0;i<3;i++)
    {
            obj1[i].display();
    }
    return 0;
}
