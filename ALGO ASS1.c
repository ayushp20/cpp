//Insertion Sort
#include<bits/stdc++.h>
#define SIZE 1000000

using namespace std;
void input()
{

     for(int i=0;i<SIZE;i++)
    {
        array[i]=rand()%SIZE;
    }
}

void output(int *a)
{

     for(int i=0;i<SIZE;i++)
    {
        cout<<a[i]<<" " ;
    }
    cout<<"\n\n";
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insertion_sort(int array[])
{
    int i,j,key;

    for(i=1;i<SIZE;i++)
    {
        key=array[i];
        j=i-1;
        while(j>=0 && array[j]>key)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
}
void merge(int *a,int first,int mid,int last)
{
    int n1=mid-first+1;
    int n2=last-mid;

    int *L=new int[n1],*R=new int[n2];
    int i=0,j=0,k=first;

    for(;i<n1;i++)
        L[i]=a[first+i];

    for(;j<n2;j++)
        R[j]=a[mid+1+j];

    i=0;j=0;

    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
            a[k++]=L[i++];
        else
            a[k++]=R[j++];
    }

    while(i<n1)
        a[k++]=L[i++];
    while(j<n2)
        a[k++]=R[j++];



}
void merge_sort(int *a,int first,int last)
{
    if(first<last)
    {
        int mid=(first+last)/2;
        merge_sort(a,first,mid);
        merge_sort(a,mid+1,last);
        merge(a,first,mid,last);
    }
}
int partition(int *a,int low, int high)
{
    int pivot=a[high]; //last element pivot
    int i=low-1;

    for(int j=low;j<=high-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    i++;
    int temp=a[i];
    a[i]=a[high];
    a[high]=temp;

    return i;

}

void quicksort(int *a,int low,int high)
{
    if(low<high)
    {
        int pi=partition(a,low,high);

        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}
void bubble_sort(int a[])
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j+1],&a[j]);

            }

        }
    }
}
void selection_sort(int a[])
{
    for(int i=0;i<SIZE;i++)
        for(int j=i;j<SIZE;j++)
        {
            if(a[j]<a[i])
                swap(&a[i],&a[j]);
        }
}
int main()
{
    int *array=new int[SIZE];
    int i,j,key;
    clock_t time_taken;
    cout<<"Enter the values : ";


    srand(time(NULL));

    input();


    cout<<"\n     TIME TAKEN FOR SORTING ARRAY OF 100,000 INTEGER TYPE NUMBERS : \n\n";
/*
    time_taken=clock();
    insertion_sort(array);
    time_taken=(clock()-time_taken);
    cout<<"     Time Taken (INSERTION SORT) :"<<(double)(time_taken)/CLOCKS_PER_SEC<<" seconds"<<endl;

    input(array);
    time_taken=clock();
    selection_sort(array);
    time_taken=(clock()-time_taken);
    cout<<"     Time Taken (SELECTION SORT) :"<<(double)(time_taken)/CLOCKS_PER_SEC<<" seconds"<<endl;

    input(array);
    time_taken=clock();
    bubble_sort(array);
    time_taken=(clock()-time_taken);
    cout<<"     Time Taken (BUBBLE SORT)    :"<<(double)(time_taken)/CLOCKS_PER_SEC<<" seconds"<<endl;

*/
    input(array);
    time_taken=clock();
    merge_sort(array,0,SIZE-1);
    time_taken=(clock()-time_taken);
    cout<<"     Time Taken (MERGE SORT)     :"<<(double)(time_taken)/CLOCKS_PER_SEC<<" seconds"<<endl;


    input(array);
    time_taken=clock();
    quicksort(array,0,SIZE-1);
    time_taken=(clock()-time_taken);
    cout<<"     Time Taken (QUICK SORT)     :"<<(double)(time_taken)/CLOCKS_PER_SEC<<" seconds"<<endl;


   return 0;
}

