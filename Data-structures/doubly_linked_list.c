#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *llink;	
	struct Node *rlink;	
};
struct Node *header=NULL;
struct Node *create_Node(int data)
{
	struct Node*Newnode;
	Newnode=malloc(sizeof(struct Node));
	Newnode->data=data;
	Newnode->llink=NULL;
	Newnode->rlink=NULL;
	return(Newnode);
}

void insertAtfront(int data)
{
	struct Node*Newnode;
	if(header==NULL)
	{	
		Newnode=create_Node(data);
		header=Newnode;
	}
	else
	{
		Newnode=create_Node(data);
		Newnode->rlink=header;
		header->llink=Newnode;
		header=Newnode;
	}
}

void insertAtend(int data)
{
	struct Node *Newnode;
	struct Node *ptr;
	Newnode=create_Node(data);
	while(ptr->rlink!=NULL)
	{
		ptr=ptr->rlink;
		
	}
	if(Newnode==NULL)
	{
		printf("NOT ENOUGH MEMORY");
	}
	else
	{
		ptr->rlink=Newnode;
		Newnode->llink=ptr;
	}	
}

void insert_at_any(int data,int position)
{
	struct Node *ptr;
	struct Node *Newnode;
	Newnode=create_Node(data);
	
	if(position==1)
	{
		insertAtfront(data);
		return;
	}
	ptr=header;
	for (int i=1; i < position-1 && ptr != NULL; i++)
	{
		ptr=ptr->rlink;
	}
	if (ptr == NULL)
	{
		printf("position out of bounds \n");
		free(Newnode);
	}
	else
	{
		Newnode->rlink=ptr->rlink;
		Newnode->llink=ptr;
		if(ptr->rlink != NULL)
		{
			ptr->rlink->llink=Newnode;
		}
		ptr->rlink=Newnode;
	}
}

void deleteAtfront()
{
	struct Node  *ptr;
	ptr=header;
	header=ptr->rlink;
	free(ptr);
}

void delete_At_end()
{
	struct Node *ptr;
	struct Node *ptr1;
	ptr=header;
	
	while(ptr->rlink != NULL)
	{
		ptr1=ptr;
		ptr=ptr->rlink;
	}
	ptr1->rlink=NULL;
	free(ptr);

}

void traversal()
{
	struct Node *ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->rlink;
	}
	
}

int main()
{
	struct Node*Node;
	insertAtfront(20);
	insertAtfront(90);
	
	insertAtend(96);
	insertAtend(30);
	
	insert_at_any(33,4);
	

	deleteAtfront();
	delete_At_end();
	
	
	traversal();
	return 0;
}	
