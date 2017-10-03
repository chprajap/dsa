                          /* Stack using linked list*/
 
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

void pop(struct node **head)
{
      if(*head==NULL)
      {
              printf("Stack is empty so can't pop\n");
              return;
      }
      struct node *tmp=*head;
      *head=tmp->link;
      free(tmp);       
}

void print(struct node **head)
{
      if(*head==NULL)
      {
              printf("Stack is empty so can't pop\n");
              return;
      }
      struct node *tmp=*head;
      while(tmp!=NULL)
      {
              printf("%d ",tmp->data);
              tmp=tmp->link;
      }
      printf("\n");
}

void top(struct node **head)
{
      if(*head==NULL)
      {
              printf("Stack is empty so can't pop\n");
              return;
      }
      printf("Top of stack is %d\n",(*head)->data);
}

void main()
{
      struct node *head=NULL;
      char ch;
      int x,choice;
      do
      {
             printf("Enter choice 1.to push 2.to pop 3.to print 4.top\n");
             scanf("%d",&choice);
             switch(choice)
             {
                   case 1:
                             printf("Enter no. to be pushed onto stack\n");
                             scanf("%d",&x);
                             push(&head,x);
                   break;
                   case 2:
                          
                             pop(&head);
                   break;
                   case 3:
                             print(&head);
                   break;
                   case 4:
                             top(&head);
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
