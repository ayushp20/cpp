#include<stdio.h>
#include<math.h>
int main()
{
int n,i,j,value;
printf("Enter the levels of Pascal's Triangle : ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
    for(j=n-i;j>0;j--)
        printf(" ");

    for(j=0;j<=i;j++)
    {
        if(i==j||j==0)
            value=1;
        else
            value=value*(i-j+1)/j;

    printf("%d ",value);
   }
    printf("\n");

}
}
