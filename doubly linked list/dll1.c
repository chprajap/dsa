                 /* Doubly linked list insertion & deletion */

#include<stdio.h>
#include<stdlib.h>

struct node
{
      int data;
      struct node *prev;
      struct node *next;
};

void insert(struct node **head,int x)
{
      struct node *ptr=(struct node *)malloc(sizeof(struct node));
      ptr->data=x;
      ptr->prev=NULL;
      ptr->next=*head;
      if(*head!=NULL)
      {
              (*head)->prev=ptr;
      }
      *head=ptr;
}

void print(struct node **head)
{
      struct node *ptr=*head,*ptr1;
      if(*head==NULL)
      {
              printf("Empty list so can't print\n");
              return;
      }
      printf("Doubly linked list in forward direction\n");
      while(ptr!=NULL)
      {
              printf("%d ",ptr->data);
              ptr1=ptr;
              ptr=ptr->next;
      }
      printf("\n");
      printf("Doubly linked list in backward direction\n");
      while(ptr1!=NULL)
      {
              printf("%d ",ptr1->data);
              ptr1=ptr1->prev;
      }
      printf("\n");
}

void delete(struct node **head,int x)
{
      if(*head==NULL)
      {
              printf("We can't delete as list is empty\n");
              return;
      }
      struct node *tmp=*head;
      if(tmp->next==NULL)
      { 
              if(tmp->data==x)
              {
                      *head=NULL;
                      free(tmp);
                      return;
              }
              else
              {
                      printf("Element not found\n");
                      return;
              }
      }
      if(tmp->data==x)
      {
              *head=tmp->next;
              tmp->next->prev=NULL;
              free(tmp);
              return;
      }
      while(tmp->next!=NULL)
      {
              if(tmp->data==x)
              {
                      tmp->prev->next=tmp->next;
                      tmp->next->prev=tmp->prev;
                      free(tmp);
                      return;
              }
              tmp=tmp->next;
      }
      if(tmp->next==NULL)
      {
               if(tmp->data==x)
               {
                       tmp->prev->next=NULL;
                       free(tmp);
                       return;
               }
               else
               {
                       printf("Element not found so can't delete\n");
                       return;
               }
      }
}

void main()
{
      struct node *head=NULL;
      char ch;
      int x,choice;
      do
      {
             printf("Enter choice\n");
             scanf("%d",&choice);
             switch(choice)
             {
                   case 1:
                             printf("Enter no. to be insert in list\n");
                             scanf("%d",&x);
                             insert(&head,x);
                   break;
                   case 2:
                             printf("Enter no. to be deleted\n");
                             scanf("%d",&x);
                             delete(&head,x);
                   break;
                   case 3:
                             print(&head);
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
