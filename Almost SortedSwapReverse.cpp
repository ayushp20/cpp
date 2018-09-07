#include<iostream>
#include<vector>

using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){

    int n;
    cin>>n;
    int i=0,a[n],start=0,end=0,flag=1,j;
    while(i<n)
    {
        cin>>a[i++];
    }

    for(i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            start=i;flag=0;break;
        }
    }
    if(flag==1)
    {
        cout<<"yes";
        return 0;
    }

    for(i=n-1;i>0;i--)
    {
        if(a[i]<a[i-1])
        {
            end=i;break;
        }
    }

    swap(&a[start],&a[end]);

    flag=1;
     for(i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            flag=0;break;
        }
    }
    if(flag==1)
    {
        cout<<"yes\n"<<"swap "<<start+1<<" "<<end+1;
        return 0;
    }
   // for(i=0;i<n;i++)
     //   cout<<a[i]<<" ";
    for(i=start+1,j=end-1;i<=((start+end)/2);i++,j--)
        swap(&a[i],&a[j]);

    /*cout<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";*/
    flag=1;
     for(i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            flag=0;break;
        }
    }

    if(flag==1)
    {
        cout<<"yes\n"<<"reverse "<<start+1<<" "<<end+1;
        return 0;
    }

    cout<<"no";

return 0;
}
