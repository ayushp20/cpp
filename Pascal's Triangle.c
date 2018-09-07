#include<stdio.h>
int pascal(int row,int col)
{
    if(row==col||col==0)
        return 1;
    else
        return pascal(row-1,col-1)+pascal(row-1,col);

}
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
     printf("%d ",pascal(i,j));
    }
    printf("\n");
}

}

/*#include<stdio.h>
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
*/
