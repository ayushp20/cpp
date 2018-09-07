#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int value,weight;

    Item(int value,int weight)
    {
        this->value=value;
        this->weight=weight;
    }
};

bool cmp_desc(Item a,Item b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;

    return r1>r2;
}

double fractionalKnapsack(Item *items,int W,int n)
{
    double curWeight=0.0,max_value=0.0;

    sort(items,items+n,cmp_desc);

    for(int i=0;i<n;i++)
    {
        if(curWeight+items[i].weight<=W)
        {

            max_value+=items[i].value;
            curWeight+=items[i].weight;
        }
        else
        {
            int remain=W-curWeight;
            max_value+=items[i].value*((double)remain/items[i].weight);
            break;
        }
    }

    return max_value;
}

int main()
{
    int W = 50;   //    Weight of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

    int n = sizeof(arr) / sizeof(Item);

    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(arr,W,n);
    return 0;
}
