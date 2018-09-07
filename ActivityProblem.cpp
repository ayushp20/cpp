#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,count=0;
    cout<<"\n Enter the number of activities : ";
    cin>>n;
    int start[n],finish[n];

    for(int i=0;i<n;i++)
        cin>>start[i];

    for(int i=0;i<n;i++)
        cin>>finish[i];

    for(int i=1;i<n;i++)
    {
        int key=finish[i],keystart=start[i];
        int j=i-1;

        while(j>=0&&finish[j]>key)
        {
            finish[j+1]=finish[j];
            start[j+1]=start[j];
            j--;
        }
        finish[j+1]=key;
        start[j+1]=keystart;
    }
    int time_finish=finish[0];
    int time_start=start[0];

    cout<<time_start<<" "<<time_finish<<endl;

    for(int i=1;i<n;i++)
        if(start[i]>=time_finish)
        {
            time_start=start[i];
            time_finish=finish[i];
            count++;
            cout<<time_start<<" "<<time_finish<<endl;
        }

    cout<<count;
    return 0;
}
