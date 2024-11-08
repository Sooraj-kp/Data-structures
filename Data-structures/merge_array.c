#include<stdio.h>

void insert_elements(int arr[], int size)
{
	printf(" Enter %d elements of array : ",size);
	for(int i=0; i<size; i++)
	{
		scanf("%d",&arr[i]);
	}
}

void sort(int arr[], int size)
{
	for(int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void merge_array(int arr1[], int arr2[], int size1, int size2, int merged[])
{
	int i=0;
	int j=0;
	int k=0;
	while(i<size1 && j<size2)
	{
		if(arr1[i]<arr2[j])
		{
			merged[k++]=arr1[i++];
		}
		else
		{
			merged[k++]=arr2[j++];
		}
	}
	while(i<size1)
	{
		merged[k++]=arr1[i++];
	}
	while(j<size2)
	{
		merged[k++]=arr2[j++];
	}
}
int main()
{
	int size1, size2;
	printf("Enter size of the first array : ");
	scanf("%d",&size1);
	int arr1[size1];
	insert_elements(arr1,size1);

	printf("Enter size of the second array : ");
	scanf("%d",&size2);
	int arr2[size2];
	insert_elements(arr2,size2);

	printf("Elements of first array before sorting: ");
	for(int i=0; i<size1; i++)
	{
		printf("%d ",arr1[i]);
	}
	printf("\n");

	printf("Elements of second array before sorting: ");
	for(int i=0; i<size2; i++)
	{
		printf("%d ",arr2[i]);
	}
	printf("\n");

	sort(arr1,size1);
	sort(arr2,size2);

	printf("Elements of first array after sorting: ");
	for(int i=0; i<size1; i++)
	{
		printf("%d ",arr1[i]);
	}
	printf("\n");
	printf("Elements of second array after sorting: ");
	for(int i=0; i<size2; i++)
	{
		printf("%d ",arr2[i]);
	}
	printf("\n");

	int merge[size1+size2];
	merge_array(arr1,arr2,size1,size2,merge);

	printf("Elements of merged array: ");
	for(int i=0; i<size1+size2; i++)
	{
		printf("%d ",merge[i]);
	}
	printf("\n");
	
	return(0);
}
