#include<stdio.h>
#include<stdlib.h>

struct node 
{
      int data;
      struct node *link;
};

struct node *f = NULL;
struct node *r =  NULL;

void enqueue(int x)
{
      struct node *ptr= (struct node *)malloc(sizeof(struct node));
      ptr->data = x;
      ptr->link=NULL;
      if(f==NULL && r==NULL)
      {
              f=ptr;
              r=ptr;
      }
      else 
      {
              r->link = ptr;
              r=ptr;
      }
       
}

void dequeue()
{
      if(f==NULL && r==NULL)
      {
              printf("we can't delete as queue is empty\n");
              return; 
      }
      else if(f==r)
      {
              struct node *ptr=f;
              f=NULL;
              r=NULL;
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
              printf("We can't print as empty\n");
              return;
      }
      struct node *tmp=f;
      while(tmp!=NULL)
      {
              printf("%d ",tmp->data);
              tmp=tmp->link;
      }
      printf("\n");
}

int main()
{
      char ch;
      int x,choice;
      do
      {
             printf("Enetr choice\n");
             scanf("%d",&choice);
             switch(choice)
             {
                   case 1:
                             printf("Enter no. to be enqueued\n");
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
                             printf("Invalid input\n");
                   break;
             }
             printf("Do you want to continue\n");
             getchar();
             ch = getchar();
             
      }while(ch=='y');

}

