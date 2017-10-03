                            /* double ended queue using stacks */
#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *link;
};


void push(struct node **head,int x)
{
        struct node *ptr=malloc(sizeof(struct node));
        ptr->data=x;
        ptr->link=*head;
        *head=ptr;
}

int pop(struct node **head)
{
        struct node *tmp=*head;
        int f=tmp->data;
        *head=tmp->link;
        free(tmp);
        return f;
}

int isempty(struct node **head)
{
        if(*head==NULL)
            return 1;
        else
            return 0;
}

void insertFront(struct node **head,int x)
{
        push(head,x);
}

void insertEnd(struct node **head,int x)
{
        if(isempty(head))
        {      
                push(head,x);
                return;
        }
        else
        {
                int d=pop(head);
                insertEnd(head,x);
                push(head,d);
                return;
        }
}

void deleteFront(struct node **head)
{
        if(isempty(head))
        {      
                printf("Queue is empty so can't delete\n");
                return;
        }
        int d=pop(head);
        printf("Element dequeued from front is %d\n",d);
}

void deleteEnd(struct node **head)
{
        if(isempty(head))
        {      
                printf("Queue is empty so can't delete\n");
                return;
        }
        if((*head)->link==NULL)
        {
                int d=pop(head);
                printf("Element dequeued from front is %d\n",d);
                return;
        }
        else
        {
                int e=pop(head);
                deleteEnd(head);
                push(head,e);
                return;
        }
}

void print(struct node **head)
{
        if(isempty(head))
        {      
                printf("Queue is empty so can't print\n");
                return;
        }
        struct node *q1=*head;
        while(q1!=NULL)
        {
                printf("%d ",q1->data);
                q1=q1->link;
        }
        printf("\n");
}

void main()
{
        struct node *head=NULL;
        char ch;
        int choice,x;
        do
        {
               printf("Enter choice 1.to insert at front 2.to insert at end 3.to delete at front 4.to delete at end 5.to print\n");
               scanf("%d",&choice);
               switch(choice)
               {
                      case 1:
                                  printf("Enter no. to insert at front\n");
                                  scanf("%d",&x);
                                  insertFront(&head,x);
                      break;
                      case 2:
                                  printf("Enter no. to insert at end\n");
                                  scanf("%d",&x);
                                  insertEnd(&head,x);
                      break; 
                      case 3:
                                  deleteFront(&head);
                      break;
                      case 4:
                                  deleteEnd(&head);
                      break;
                      case 5:
                                  print(&head);
                      break;
                      default:
                                  printf("Invalid input\n");
                      break;
               }
               printf("Do you want to continue('y' or 'n')?\n");
               getchar();
               ch=getchar();
        }while(ch=='y');
}
