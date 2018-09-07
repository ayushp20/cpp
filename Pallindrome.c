#include<stdio.h>
#include<string.h>
void main()
{
    char n[20],flag=1;
    scanf("%s",&n);
    int i;
    for(i=0;i<strlen(n)/2;i++)
    {
        if(n[i]!=n[strlen(n)-i-1])
        {
            flag=0;break;
        }
    }

    if(flag==1)
        printf("\nPallindrome");
    else
        printf("\nNot Pallindrome");

}



