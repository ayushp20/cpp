#include <cmath>
#include<iomanip>
#include <iostream>


using namespace std;


int main(){
    int t;
    cin >> t;
    float g1,g2;
    g1=(1+pow(5,0.5))/2;
    g2=(1-pow(5,0.5))/2;
    for(int a0 = 0; a0 < t; a0++){
        unsigned long long int n,sum=0;
        cin >> n;
        unsigned long long int i=3;
        unsigned long long int f=(pow(g1,i)-pow(g2,i))/pow(5,0.5);
        while(f<n)
        {
        sum+=f;
        i+=3;
        f=(pow(g1,i)-pow(g2,i))/pow(5,0.5);

        }
        cout<<sum<<endl;
    }
    return 0;
}
