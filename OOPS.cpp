#include <bits/stdc++.h>

using namespace std;

class abc
{
    int a;
public:
    abc()
    {
        cout<<"Enter values : ";
        cin>>a;
    }
    abc operator +(abc &o)
    {
        o.a-=a;

        return o;
    }
    void operator --()
    {
        a--;
    }
    friend ostream &operator<<( ostream &output, const abc &D ) {
         output << "a= " << D.a ;
         return output;
      }

      /*friend istream &operator>>( istream  &input, abc &D ) {
         input >> D.a >> D.b;
         return input;
      }*/
    ~abc()
    {
        cout<<a<<endl;
    }
};

int main()
{
    abc obj1,obj2;
    abc obj3=obj1+obj2;

    cout<<obj1<<obj2<<obj3;

    return 0;
}
