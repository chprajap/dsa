                   /* Priority queue using linked list */
#include<stdio.h>
#include<stdlib.h>

struct node
{
       int data;
       int pr;
       struct node *link;
};

void insert(struct node **head,int x,int p)
{
       struct node *ptr=malloc(sizeof(struct node));
       ptr->data=x;
       ptr->pr=p;
       ptr->link=*head;
       *head=ptr;
}

void enqueue(struct node **head,int x,int p)
{
        if(*head==NULL || p<(*head)->pr)
        {
               insert(head,x,p);
               return;
        }
        else
        {
               enqueue(&(*head)->link,x,p);
        }
}

void dequeue(struct node **head)
{
        if(*head==NULL)
        {
               printf("Queue is empty so can't delete\n");
               return;
        }
        else
        {
               struct node *tmp=*head;
               *head=tmp->link;
               free(tmp);
        }
}

void print(struct node **head)
{
        if(*head==NULL)
        {
               printf("Queue is empty so can't delete\n");
               return;
        }
        else
        {
               struct node *ptr=*head;
               while(ptr!=NULL)
               {
                        printf("%d %d\n",ptr->data,ptr->pr);
                        ptr=ptr->link;
               }
        }
}

void main()
{
       struct node *head=NULL;
       int choice,x,p;
       char ch;
       do
       {
              printf("Enter choice 1.to enqueue 2.to dequeue 3.to print\n");
              scanf("%d",&choice);
              switch(choice)
              {
                       case 1:
                                  printf("Enter no. & priority to enqueue\n");
                                  scanf("%d %d",&x,&p);
                                  enqueue(&head,x,p);
                       break;
                       case 2:
                                  dequeue(&head);
                       break;
                       case 3:
                                  print(&head);
                       break;
                       default:
                                  printf("Invalid choice\n");
                       break;
              }
              printf("Do you want to continue('y' or 'n')?\n");
              getchar();
              ch=getchar();
       }while(ch=='y');
}
