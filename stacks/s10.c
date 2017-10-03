                     /* Reverse stack using recursion*/
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
     int ch=tmp->data;
     *head=tmp->link;
     free(tmp);
     return ch;
}

int isempty(struct node **head)
{
     if(*head==NULL)
             return 1;
     else
             return 0;
}

void insert(struct node **head,int d)
{
     if(isempty(head))
     {
             push(head,d);
             return;
     }
     else
     {
             int f=pop(head);
             insert(head,d);
             push(head,f);
             return;
     }
}

void reverse(struct node **head)
{
     if(isempty(head))
              return;
     else
     {
              int d=pop(head);
              reverse(head);
              insert(head,d);
              return;
     }
}

void print(struct node **head)
{
     struct node *tmp=*head;
     while(tmp!=NULL)
     {
              printf("%d ",tmp->data);
              tmp=tmp->link;
     }
     printf("\n");
}

void main()
{
     struct node *head=NULL;
     int x,choice;
     char c;
     do
     {
            printf("Enter choice 1.to push 2.to pop 3.to print 4.to reverse\n");
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
                               reverse(&head);
                      break;
                      default:
                               printf("Invalid input\n");
                      break; 
            }
            printf("Do you want to continue('y' or 'n')?\n");
            getchar();
            c=getchar();
     }while(c=='y');
}
