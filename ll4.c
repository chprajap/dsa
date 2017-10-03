                   /* Reverse a linked list */
#include<stdio.h>
#include<stdlib.h>

struct node
{
      int data;
      struct node *link;
};

void insert(struct node **head,int x)
{
      struct node *ptr=(struct node *)malloc(sizeof(struct node));
      ptr->data=x;
      ptr->link=*head;
      *head=ptr;
}

void delete(struct node **head,int x)
{
      struct node *tmp=*head,*tmp1;
      int c=1;
      if(*head==NULL)
      {
             printf("No element to be deleted as it is empty\n");
             return;
      }
      if(c==x)
      {
             *head=(*head)->link;
             free(tmp);
             return;
      }
      while(tmp!=NULL)
      {
             if(c==x)
             {
                    tmp1->link=tmp->link;
                    free(tmp);
                    return;
             }
             c++;
             tmp1=tmp;
             tmp=tmp->link;
      }
      if(tmp==NULL)
      {
             printf("Element not found enter valid element\n");
      }
}

void print(struct node **head)
{
      if(*head==NULL)
      {
             printf("list is empty so can't print\n");
      }
      struct node *ptr=*head;
      while(ptr!=NULL)
      {
             printf("%d ",ptr->data);
             ptr=ptr->link;
      }
      printf("\n");
}

void reverse(struct node **head)
{
      struct node *ptr=*head,*prev=NULL,*next;
      if(*head==NULL)
      {
             printf("List is empty so can't reverse\n");
             return;
      } 
      while(ptr!=NULL)
      {
             next=ptr->link;
             ptr->link=prev;
             prev=ptr;
             ptr=next;
      }
      *head=prev;
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
                             printf("Enter pos. to be deleted\n");
                             scanf("%d",&x);
                             delete(&head,x);
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
             printf("Do you want to continue\n");
             getchar();
             ch = getchar();
             
      }while(ch=='y');

}
