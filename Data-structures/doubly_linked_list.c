#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *header = NULL;

struct node *create_node(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->llink = NULL;
    newnode->rlink = NULL;
    return newnode;
}

void insert_at_front(int data)
{
    struct node *newnode;
    newnode = create_node(data);

    if (header == NULL)
    {
        header = newnode;
    }
    else
    {
        newnode->rlink = header;
        header->llink = newnode;
        header = newnode;
    }
    printf("Inserted %d at position 1\n", data);
}

void insert_at_end(int data)
{
    struct node *newnode;
    newnode = create_node(data);
    struct node *ptr = header;
    int position = 1;

    if (header == NULL)
    {
        header = newnode;
        printf("Inserted %d at position %d\n", data, position);
        return;
    }

    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
        position++;
    }

    ptr->rlink = newnode;
    newnode->llink = ptr;
    position++;
    printf("Inserted %d at position %d\n", data, position);
}
void insert_at_any(int data, int key)
{
    struct node *newnode, *ptr;
    newnode = create_node(data);

    if (header == NULL)
    {
        printf("List is empty, inserting at the front.\n");
        header = newnode;
        return;
    }

    ptr = header;
    while (ptr != NULL && ptr->data != key)
    {
        ptr = ptr->rlink;
    }

    if (ptr == NULL)
    {
        printf("Key %d not found in the list.\n", key);
        free(newnode);
    }
    else
    {
        newnode->rlink = ptr->rlink;
        newnode->llink = ptr;
        if (ptr->rlink != NULL)
        {
            ptr->rlink->llink = newnode;
        }
        ptr->rlink = newnode;
        printf("Inserted %d after key %d\n", data, key);
    }
}


void insert_at_any2(int data, int position)
{
    struct node *newnode, *ptr;
    newnode = create_node(data);

    if (position == 1)
    {
        insert_at_front(data);
        return;
    }

    ptr = header;
    for (int i = 1; i < position - 1 && ptr != NULL; i++)
    {
        ptr = ptr->rlink;
    }

    if (ptr == NULL)
    {
        printf("Position out of bounds\n");
        free(newnode);
    }
    else
    {
        newnode->rlink = ptr->rlink;
        newnode->llink = ptr;
        if (ptr->rlink != NULL)
        {
            ptr->rlink->llink = newnode;
        }
        ptr->rlink = newnode;
        printf("Inserted %d at position %d\n", data, position);
    }
}

void delete_at_front()
{
    struct node *ptr;
    if (header == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = header;
    header = ptr->rlink;
    if (header != NULL)
    {
        header->llink = NULL;
    }
    free(ptr);
}

void delete_at_end()
{
    struct node *ptr;
    if (header == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = header;
    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
    }
    if (ptr->llink != NULL)
    {
        ptr->llink->rlink = NULL;
    }
    else
    {
        header = NULL;
    }
    free(ptr);
}
void delete_at_any(int key)
{
    struct node *ptr;

    if (header == NULL)
    {
        printf("List is empty\n");
        return;
    }

    ptr = header;
    while (ptr != NULL && ptr->data != key)
    {
        ptr = ptr->rlink;
    }

    if (ptr == NULL)
    {
        printf("Key %d not found in the list.\n", key);
    }
    else
    {
        if (ptr->rlink != NULL)
        {
            ptr->rlink->llink = ptr->llink;
        }
        if (ptr->llink != NULL)
        {
            ptr->llink->rlink = ptr->rlink;
        }
        else
        {
            header = ptr->rlink;
        }
        printf("Deleted node with key %d\n", key);
        free(ptr);
    }
}
void delete_at_any2(int position)
{
    struct node *ptr = header;

    if (header == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position == 1)
    {
        delete_at_front();
        return;
    }

    for (int i = 1; i < position && ptr != NULL; i++)
    {
        ptr = ptr->rlink;
    }

    if (ptr == NULL)
    {
        printf("Position out of bounds\n");
    }
    else
    {
        if (ptr->rlink != NULL)
        {
            ptr->rlink->llink = ptr->llink;
        }
        if (ptr->llink != NULL)
        {
            ptr->llink->rlink = ptr->rlink;
        }
        free(ptr);
    }
}

int search(int value)
{
    struct node *ptr = header;
    int position = 1;
    int found = 0;

    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            printf("Element %d found at position %d\n", value, position);
            found = 1;
        }
        ptr = ptr->rlink;
        position++;
    }

    if (!found)
    {
        printf("Element %d not found in the list.\n", value);
    }

    return found;
}

void traversal()
{
    struct node *ptr = header;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->rlink;
    }
    printf("\n");
}

int main()
{
    int choice,data,key;

    do
    {

        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete at front\n");
        printf("5. Delete at end\n");
        printf("6. Delete at any position\n");
        printf("7. Search\n");
        printf("8. Traversal\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_at_front(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Key : ");
                scanf("%d", &key);
                insert_at_any(data,key);
                break;
            case 4:
                delete_at_front();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                printf("Enter key: ");
                scanf("%d", &key);
                delete_at_any(key);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 8:
                traversal();
                break;
            case 9:
                break;
            default:
                printf("Invalid choice\n");
        }
    }while( choice !=9);

    return 0;
}
