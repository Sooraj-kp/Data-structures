#include<stdio.h>
#define max 5
int stack[max];
int top=-1;

void push()
{
	int item;

	if((top==max-1))
	{
	printf("Stack is full\n");
	}
	else
	{
		printf("enter the item to be pushed: ");
		scanf("%d",&item);
		top=top+1;
		stack[top]=item;
		printf("pushed item : %d",item);
	}
}

void pop()
{
	if(top<0)
	{
		printf("Stack is empty, No item to pop\n");
	}
	else
	{
		int poppeditem=stack[top];
		printf("popped item : %d\n",poppeditem);
		top--;
	}
}
void traversal()
{
	if(top<0)
	{
		printf("stack is empty ,No item to show\n");
	}
	else
	{
		printf("Stack items are : ");
		for(int i=top;i>=0;i--)
		{
			printf("%d  ",stack[i]);
		}
	}
}
int main()
{      
	int choice;

	do
	{
		printf("\n1: PUSH\n");
		printf("2: POP\n");
		printf("3: TRAVERSAL\n");
		printf("4: EXIT\n");
		
		
		printf("\n\tENTER THE CHOICE FROM 1 TO 4 : ");


		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				printf("\n");
				break;
			case 2:
				pop();
				printf("\n");
				break;
			case 3:
				traversal();
				printf("\n");
				break;
			case 4: 
				break;
			default:
				printf(" you have chosen wrong choice");
				
		}

	}while(choice !=4);
	return(0);
}


			


