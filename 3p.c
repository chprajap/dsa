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
    struct node *ptr= malloc(sizeof(struct node));
    ptr->data=x;
    ptr->link=*head;
    *head=ptr;
}

int pop(struct node **head)
{
    struct node *temp=*head;
    *head=temp->link;
    int x=temp->data;
    free(temp);
    return x;
}

void enqueue(struct queue *q,int x)
{
    push(&q->s1,x);
}

void dequeue(struct queue *q)
{
    if(q->s1==NULL && q->s2==NULL)
    {
            printf("Queue is empty so can't delete\n");
            return;
    }
    else
    {
            if(q->s2==NULL)
            {
                 while(q->s1!=NULL)
                 {
                  int t=pop(&q->s1);
                  push(&q->s2,t);
                 }
            }
            printf("Deleted element is %d\n",pop(&q->s2));
    }
}





int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->s1=NULL;
    q->s2=NULL;
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
                             enqueue(q,x);
                   break;
                   case 2:
                             dequeue(q);
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
