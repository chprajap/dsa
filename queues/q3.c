                       /* queue using stacks */
#include<stdio.h>
#include<stdlib.h>

struct node
{
      int data;
      struct node *link;
};

struct queue
{
      struct node *s1;
      struct node *s2;
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
     struct node *ptr=*head;
     int d=ptr->data; 
     *head=(*head)->link;
     return d;
}

void enqueue(struct queue *q,int x)
{
      push(&q->s1,x);
}

void dequeue(struct queue *q)
{
      if(q->s1==NULL && q->s2==NULL)
      {
               printf("queue is empty so can't dequeue\n");
               return;
      }
      else if(q->s2==NULL)
      {
               while(q->s1!=NULL)
               {
                        push(&q->s2,pop(&q->s1));
               }
      }
      int e= pop(&q->s2);
      printf("Dequeued element is %d\n",e);
}

void main()
{
      struct queue *q=malloc(sizeof(struct node));
      q->s1=NULL;
      q->s2=NULL;
      int choice,x;
      char ch;
      do
      {
              printf("Enter choice 1.to enqueue 2.to dequeue\n");
              scanf("%d",&choice);
              switch(choice)
              {
                       case 1:
                                  printf("Enter no. to enqueue\n");
                                  scanf("%d",&x);
                                  enqueue(q,x);
                       break;
                       case 2:
                                  dequeue(q);
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
