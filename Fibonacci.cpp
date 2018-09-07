#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    float g1,g2;
    g1=(1+pow(5,0.5))/2;
    cout<<g1;
    g2=(1-pow(5,0.5))/2;
    cout<<" "<<g2<<endl;
    float f;
    for(int i=3;i<30;i++)
    {
        f=(pow(g1,i)-pow(g2,i))/pow(5,0.5);
        cout<<setprecision(0)<<(int)f<<" ";
    }
    return 0;
}
