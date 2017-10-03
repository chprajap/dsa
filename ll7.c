                               /* Check for a loop */
#include<stdio.h>
#include<stdlib.h>

struct node
{
           int data;
           struct node *link;
};

void insert(struct node **head,int x)
{
           struct node *ptr=malloc(sizeof(struct node));
           ptr->data=x;
           ptr->link=*head;
           *head=ptr;
}

void makecircular(struct node **head)
{
           struct node *tmp=*head;
           while(tmp->link!=NULL)
           {
                       tmp=tmp->link;
           }
           tmp->link=*head;
}

void detectloop(struct node **head)
{
           struct node *f=*head,*s=*head;
           int c=0;
           do
           {
                   if(f==s && c)
                   {
                               printf("Loop detected\n");
                               return;
                   }
                   if(f==NULL || f->link==NULL)
                   {
                               printf("Loop not detected\n");
                               return;
                   }
                   f=f->link->link;
                   s=s->link;
                   c=1;
           }while(s!=NULL);
}


void main()
{
          struct node *head=NULL;
          char ch;
          int x,choice;
          do
          {
                   printf("Enter choice 1.to insert 2.to make circular loop 3.to detect loop\n");
                   scanf("%d",&choice);
                   switch(choice)
                   {
                          case 1:
                                    printf("Enter no. to be inserted\n");
                                    scanf("%d",&x);
                                    insert(&head,x);
                          break;
                          case 2:
                                    makecircular(&head);
                          break;
                          case 3:
                                    detectloop(&head);
                          break;
                          default:
                                    printf("Invalid choice\n");
                          break;
                   }
                   printf("Do you wnat to continue('y' or 'n')?\n");
                   getchar();
                   ch=getchar();
          }while(ch=='y');
}
