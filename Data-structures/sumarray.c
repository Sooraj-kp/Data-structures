#include<stdio.h>
int main()
{
		int a[10];
		int elements,i,sum=0;
		printf("enter the size :");
		scanf("%d",&elements);
		for(i=0;i<elements;i++)
		{
			printf(" Enter element %d:",i+1);
			scanf("%d",&a[i]);
		}
		for(i=0;i<elements;i++)
		{
			sum=sum+a[i];
		}

		printf("sum is %d",sum);
		return 0;
}
		
