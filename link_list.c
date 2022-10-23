#include <stdio.h>
#include <stdlib.h>
// linked list definition
struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    printf("\nNew Linked List:\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertAtfirst(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node *insertBetween(struct Node *head, int data, int index)
{
    struct Node *ptr, *p;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
//to insert
struct Node *insertAtend(struct Node *fourth, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    fourth->next = ptr;
    ptr->next = NULL;
    return ptr;
}

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteBetween(struct Node *head, int index)
{
    int i = 0;
    struct Node *p = head;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node *deleteValue(struct Node *head, int value)
{
    int i = 0;
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
}

int main()
{
    int a, c, index;
    struct Node *head, *second, *third, *fourth;

    // memory allocation
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = NULL;

    traversal(head);

    while (1)
    {
        printf("\nEnter choice:-\n1:Insert at beginning\n2:Insert in between\n3:Insert at end\n4:Delete first\n5:Delete in between\n6:Delete Last node\n7:Delete a node with given index\n8:Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("enter the data of node:\n");
            scanf("%d", &a);
            head = insertAtfirst(head, a);
            printf("\n");
            traversal(head);
            break;

        case 2:
            printf("enter the data of node:\n");
            scanf("%d", &a);
            printf("Enter the index:\n");
            scanf("%d", &index);
            head = insertBetween(head, a, index);
            printf("\n");
            traversal(head);
            break;

        case 3:
            printf("enter the data of node:\n");
            scanf("%d", &a);
            fourth = insertAtend(fourth, a);
            printf("\n");
            traversal(head);
            break;

        case 4:
            head = deleteFirst(head);
            printf("\n");
            traversal(head);
            break;

        case 5:
            printf("Enter the index:\n");
            scanf("%d", &index);
            deleteBetween(head, index);
            printf("\n");
            traversal(head);
            break;

        case 6:
            head = deleteEnd(head);
            printf("\n");
            traversal(head);
            break;
        case 7:
            printf("enter the value:\n");
            scanf("%d", &a);
            deleteValue(head, a);
            printf("\n");
            traversal(head);
            break;
        case 8:
            printf("Exiting the program......");
            exit(0);
            break;

        default:
            printf("Invalid choice!!!!");
            break;
        }
    }

    return 0;
}
