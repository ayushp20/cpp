#include<iostream>
using namespace std;
class Base{
protected:
public:
    virtual const char* myChar(){return "Char";}
};

class Derived:public Base{
public:
    virtual const char* myChar(){return "One";}
};

int main(){
    Derived cDerived;
    Base &sTat = cDerived;
    cout<<"sTat is "<<sTat.myChar()<<endl;
    return 0;

}
