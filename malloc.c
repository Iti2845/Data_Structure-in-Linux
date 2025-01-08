#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr;
	int n,new_size,i;
	printf("Enter the number of elemenets in the array: ");
	scanf("%d",&n);
	ptr=(int* )malloc(n*sizeof(int));
	if(ptr==NULL)
	{
		printf("Memory allocation failed.\n");
	}
	else
	{
		printf("Enter %d number of elements: \n",n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&ptr[i]);
		}
	}
	printf("Enter the new size of the array: ");
	scanf("%d",&new_size);
	ptr=(int* )realloc(ptr,new_size*sizeof(int));
	if(ptr==NULL)
	{
		printf("Memory Allocation Filed.\n");
	}
	else
	{
		if(new_size>n)
		{
			printf("Enter %d number of elements: \n",new_size-n);
			for(i=n;i<new_size;i++)
			{
				scanf("%d",&ptr[i]);
			}
		}
	}
	printf("Elements after reallocation: ");
	for(i=0;i<new_size;i++)
	{
		printf("%d\t",ptr[i]);
	}
	printf("\n");
	free(ptr);
}
