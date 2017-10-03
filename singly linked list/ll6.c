                          /* Xor linked list */
#include<stdio.h>
#include<stdlib.h>

struct node
{
          int data;
          struct node *link;
};

struct node* XOR(struct node *a,struct node *b)
{
          return (struct node*)((unsigned int)a ^ (unsigned int)b);
}

void insert(struct node **head,int x)
{
          struct node *ptr=malloc(sizeof(struct node));
          ptr->data=x;
          ptr->link=XOR(*head,NULL);
          if(*head!=NULL)
          {
                    struct node *nxt=XOR((*head)->link,NULL);
                    (*head)->link=XOR(nxt,ptr);
          }
          *head=ptr;
}

void print(struct node **head)
{
          struct node *curr=*head,*prev=NULL,*tmp;
          while(curr!=NULL)
          {
                    printf("%d ",curr->data);
                    tmp=XOR(prev,curr->link);
                    prev=curr;
                    curr=tmp;
          }
          printf("\n");
}

void main()
{
          struct node *head=NULL;
          char ch;
          int x,choice;
          do
          {
                   printf("Enter choice 1.to insert 2.to print\n");
                   scanf("%d",&choice);
                   switch(choice)
                   {
                          case 1:
                                    printf("Enter no. to be inserted\n");
                                    scanf("%d",&x);
                                    insert(&head,x);
                          break;
                          case 2:
                                    print(&head);
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
