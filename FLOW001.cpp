#include<iostream>
#include<algorithm>

#define p m
#define q a
#define r i
#define s n
#define xstr(s) str(s)
#define str(s) #s
#define foo 4
#define sum  int p##q##r##s() \
                            { int \
                            t; cin>>t; while(t--){ int a,b; cin>>a>>b; cout<< a+b <<endl; } return \
                            0;}

using namespace std;

template <class T>
void swap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

int main(){
    cout<< xstr(foo)<<endl;
    cout<<str(foo)<<endl;
    return 0;
}


