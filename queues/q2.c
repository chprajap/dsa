                        /* Circular Queue using linked list */
#include<stdio.h>
#include<stdlib.h>

struct node
{
       int data;
       struct node *link;
};

struct node *f=NULL,*r=NULL;

void enqueue(int x)
{
       struct node *ptr=malloc(sizeof(struct node));
       ptr->data=x;
       ptr->link=NULL;
       if(f==NULL && r==NULL)
       {
               f=r=ptr;
               return;
       }
       else
       {
               r->link=ptr;
               r=ptr;
               return;
       }
}

void dequeue()
{
       if(f==NULL && r==NULL)
       {
               printf("Queue is empty so can't dequeue\n");
               return;
       }
       else if(f==r)
       {
              struct node *ptr=f;
              f=r=NULL;
              free(ptr);
              return; 
       }
       else
       {
              struct node *ptr=f;
              f=f->link;
              free(ptr);
              return;
       }
}

void print()
{
       if(f==NULL && r==NULL)
       {
               printf("Queue is empty so can't print\n");
               return;
       }
       else
       {
               struct node *ptr=f;
               while(ptr!=NULL)
               {
                          printf("%d ",ptr->data);
                          ptr=ptr->link;
               }
               printf("\n");
       }
}

void main()
{
       int choice,x;
       char ch;
       do
       {
              printf("Enter choice 1.to enqueue 2.to dequeue 3.to print\n");
              scanf("%d",&choice);
              switch(choice)
              {
                       case 1:
                                  printf("Enter no. to enqueue\n");
                                  scanf("%d",&x);
                                  enqueue(x);
                       break;
                       case 2:
                                  dequeue();
                       break;
                       case 3:
                                  print();
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
