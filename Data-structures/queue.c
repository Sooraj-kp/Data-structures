#include<stdio.h>
#define  max 5
int queue[max];
int rear=-1;
int front=-1;
int item;


void enqueue()
{
	if (rear==max-1)
	{
		printf(" QUEUE IS FULL" );
	}
	else
	{
		if (front==-1)
		{
			
			front=0;
			
		}
		printf("INSERT ELEMENT :  ");
		scanf("%d",&item);
		rear++;
		queue[rear]=item;
		printf(" %d Enqueued to queue " ,item);
		
	}
	
}
void dequeue()
{
	if(front==-1  || front>rear)
	{
		printf("QUEUE IS EMPTY");
	}
	else
	{
		
		printf(" %d DEQUEUED FROM THE QUEUE  : ",queue[front]);
		front=front+1;
		
	}
	
}
void traversal()
{
	if(front==-1 || front>rear)
	{
		printf("QUEUE IS EMPTY  \n ");
		
	}
	else
	{
		printf("ELEMENTS IN QUEUE ARE : ");
	
	
		for(int i=front; i<=rear;i++)
		{
			printf("%d\n" , queue[i]);
		}	
		printf("\n");
	}
}
int main()
{
	int choice;
	
	do
	{
		printf("\n1: ENQUEUE\n");
		printf("2: DEQUEUE\n");
		printf("3: TRAVERSAL\n");
		printf("4: BREAK\n");
		
		
		printf("\n\tENTER THE CHOICE FROM 1 TO 4 : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:traversal();
				break;
			case 4:
				break;
			default:
				printf("Wrong choice enterred");
		}
	

	}while(choice !=4);
	return(0);
}
