#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

void max_heapify(float a[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;

    if(l<n&& a[l] > a[largest])
        largest=l;

    if(r<n && a[r]> a[largest])
        largest = r;

    if(largest!=i)
    {
        float temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;

        max_heapify(a,n,largest);
    }
}

void min_heapify(float a[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int smallest=i;

    if(l<n&& a[l] < a[smallest])
        smallest=l;

    if(r<n && a[r] < a[smallest])
        smallest = r;

    if(smallest!=i)
    {
        float temp=a[i];
        a[i]=a[smallest];
        a[smallest]=temp;

        min_heapify(a,n,smallest);
    }
}
void buildminheap(float a[],int n,int j)
{
    for(int i=n/2-1+j;i>=j;i--)
        min_heapify(a,n,i);

}
void buildmaxheap(float a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        max_heapify(a,n,i);

}

int main(){
    int n;
    cin >> n;
    float a[n];
    cout<<fixed<<setprecision(1);
    for(int i = 0;i < n;i++){
       cin >> a[i];

        buildmaxheap(a,i/2+1);
        buildminheap(a,(i+1)/2,i/2+1);

        if(i%2==0)
            cout<<a[0];
        else
            cout<<(float)((a[0]+a[i/2+1])/2);
       cout<<endl;

       }


    return 0;
}

