#include<iostream>
#include<limits>
using  namespace std;

void merge(int a[],int low,int mid,int high)
{
    int n1,n2,i,j,k;
    n1=mid-low+1;
    n2=high-mid;
    int L[n1+1],R[n2+1];

    for(i=0;i<n1;i++)
        L[i]=a[low+i];
    for(j=0;j<n2;j++)
        R[j]=a[mid+j+1];

    L[i]=numeric_limits<int>::max();
    R[j]=numeric_limits<int>::max();

    i=0;j=0;

    for(k=low;k<=high;k++)
    {
        if(i>n1||j>n2)
            break;
        else if(L[i]<=R[j])
            a[k]=L[i++];
        else
            a[k]=R[j++];

    }
}

void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(high+low)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }

}
int main()
{int a[]={6,5,7,4,2,3,23,10,12,0,34,45,32,21,78,76,97};
mergesort(a,0,16);
cout<<"Sorted Array\n";
 for(int i=0;i<17;i++)
        cout<<a[i]<<" ";

    return 0;
}
