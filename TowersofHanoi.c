#include<stdio.h>
void hanoi(int n,char from,char to,char aux)
{
    if(n==1)
       {
         printf("\nMove disk 1 from %c to %c.",from,to);
         return;
       }
    else
        hanoi(n-1,from,aux,to);
        printf("\nMove disk %d from %c to %c.",n,from,to);
        hanoi(n-1,aux,to,from);
    return;
}
int main()
{
    printf("Enter the No. of disks : ");
    int n;
    scanf("%d",&n);

    hanoi(n,'A','C','B');
return 0;
}
