                       /* Double ended queue using arrays */
#include<stdio.h>

int a[5]={0},f=-1,r=-1;

void insertFront(int x)
{
        if(f==(r+1)%5)
        {
               printf("Queue is full so can't insert\n");
               return;
        }
        else if(f==-1 && r==-1)
        {
               f=r=0;
        }
        else if(f==0)
        {
               f=4;
        }
        else
        {
               f=f-1;
        }
        a[f]=x;
}

void insertEnd(int x)
{
        if(f==(r+1)%5)
        {
               printf("Queue is full so can't insert\n");
               return;
        }
        else if(f==-1 && r==-1)
        {
               f=r=0;
        }
        else if(r==4)
        {
               r=0;
        }
        else
        {
               r=r+1;
        }
        a[r]=x;
}

void deleteFront()
{
        if(f==-1 && r==-1)
        {
               printf("Queue is empty so can't delete\n");
               return;
        }
        else if(f==r)
        {
               a[f]=0;
               f=-1;
               r=-1;
               return;
        }
        else if(f==4)
        {
               a[f]=0;
               f=0;
        }
        else
        {
               a[f]=0;
               f=f+1;
        }
}

void deleteEnd()
{
        if(f==-1 && r==-1)
        {
               printf("Queue is empty so can't delete\n");
               return;
        }
        else if(f==r)
        {
               a[r]=0; 
               f=-1;
               r=-1;
               return;
        }
        else if(r==0)
        {
               a[r]=0;
               r=4;
        }
        else
        {
               a[r]=0;
               r=r-1;
        }
}

void print()
{
        int i;
        for(i=0;i<5;i++)
        { 
               printf("%d ",a[i]);
        }
        printf("\n");
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
