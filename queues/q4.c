                        /* double ended queue using linked list */
#include<stdio.h>
#include<stdlib.h>

struct node
{
         int data;
         struct node *link;
};

struct node *f=NULL,*r=NULL;

void insertFront(int x)
{
         struct node *ptr=malloc(sizeof(struct node));
         ptr->data=x;
         ptr->link=f;
         if(f==NULL && r==NULL)
         {
                f=r=ptr;
                return;
         }
         f=ptr;
}

void insertEnd(int x)
{
         struct node *ptr=malloc(sizeof(struct node));
         ptr->data=x;
         ptr->link=NULL;
         if(f==NULL && r==NULL)
         {
                 f=r=ptr;
                 return;        
         }
         r->link=ptr;
         r=ptr;
}

void deleteFront()
{
         if(f==NULL && r==NULL)
         {
                 printf("Queue is empty so can't delete\n");
                 return;
         }
         else if(f==r)
         {
                 struct node *tmp=f;
                 f=r=NULL;
                 free(tmp);
                 return;
         }
         else
         {
                 struct node *tmp=f;
                 f=f->link;
                 free(tmp);
                 return;
         } 
}

void deleteEnd()
{
         if(f==NULL && r==NULL)
         {
                 printf("Queue is empty so can't delete\n");
                 return;
         }
         else if(f==r)
         {
                 struct node *tmp=r;
                 f=r=NULL;
                 free(tmp);
                 return;
         }
         else
         {
                 struct node *tmp=r,*tmp1=f;
                 while(tmp1->link!=r)
                 {
                           tmp1=tmp1->link;
                 }
                 tmp1->link=NULL;
                 r=tmp1;
                 free(tmp);
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
                 struct node *tmp=f;
                 while(tmp!=NULL)
                 {
                           printf("%d ",tmp->data);
                           tmp=tmp->link;
                 }
                 printf("\n");
                 return;
         }
}

void main()
{
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
                                  insertFront(x);
                      break;
                      case 2:
                                  printf("Enter no. to insert at end\n");
                                  scanf("%d",&x);
                                  insertEnd(x);
                      break; 
                      case 3:
                                  deleteFront();
                      break;
                      case 4:
                                  deleteEnd();
                      break;
                      case 5:
                                  print();
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
