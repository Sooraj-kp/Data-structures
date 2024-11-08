#include<stdio.h>
#define max 5

int circularq[max];
int front=-1;
int rear=-1;
int item;

void enqueue()
{
    if((rear+1)%max==front)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear=(rear+1)%max;
        printf("enter item : ");
        scanf("%d",&item);
        circularq[rear]=item;
        printf("Inserted item : %d",circularq[rear]);
    }
    printf("\n");
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        if(front==rear)
        {
            printf("Deleted item : %d",circularq[front]);
            front=rear=-1;
        }
        else
        {
            printf("Deleted item : %d",circularq[front]);
            front=(front+1)%max;
        }
    }
    printf("\n");
}
void traversal()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i=front;
        printf("Elements in queue: ");
        while(i!=rear)
        {
            printf("%d  ",circularq[i]);
            i=(i+1)%max;
        }
        printf("%d ", circularq[rear]);
    }
    printf("\n");
}

int main()
{

    int choice;
    do
    {
        printf(" 1-Enqueue \n 2-Dequeue \n 3-Trversal \n 4-Exit \n");
        printf("Enter one of 4 choices : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traversal();
            break;
        case 4:
            break;
        default:
            printf("Wrong choice entered \n");
        }
    }while(choice !=4);
return 0;
}


