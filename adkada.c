#include<stdio.h>
#include<malloc.h>

int main()
{
	int i,n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int *a=(int*)malloc(sizeof(int)*n);
	int *b=(int*)malloc(sizeof(int)*m);

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(i=0;i<m;i++)
		scanf("%d",&b[i]);

	for(i=0;i<n;i++)
		printf("%d ",a[i]);


	return 0;
}
