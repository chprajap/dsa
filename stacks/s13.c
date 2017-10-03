                          /* Two stacks in an array*/
#include<stdio.h>

int f=-1,r=10,a[10]={0};

int isfull()
{
         if(r==(f+1))
               return 1;
         else
               return 0; 
}

void push(int choice,int x)
{
        if(isfull())
        {
               printf("Both stacks are full so can't push\n");
               return;
        }
        else if(choice==1)
        {
               f++;
               a[f]=x;
               return;
        }
        else if(choice==2)
        {
               r--;
               a[r]=x;
               return;
        }
}

int isempty()
{
        if(f==-1 && r==10)
               return 1;
        else
               return 0;
}

void pop(int choice)
{
        if(isempty())
        {
               printf("Both stacks are empty so can't pop\n");
               return;
        }
        else if(choice==1)
        {
               a[f]=0;
               f--;
        }
        else if(choice==2)
        {
                a[r]=0;
                r++;
        }
}

void print(int choice)
{
        int i; 
        if(isempty())
        {
               printf("Both stacks are empty so can't print\n");
               return;
        }
        else if(choice==1)
        {
               printf("Stack-1 is\n");
               for(i=f;i>=0;i--)
                      printf("%d ",a[i]);
               printf("\n");
        }
        else if(choice==2)
        {
               printf("Stack-2 is\n");
               for(i=r;i<=9;i++)
                      printf("%d ",a[i]);
               printf("\n");
        }
}

void main()
{
       char c;
       int x,ch,ch1,ch2;
       do
       {
              printf("Enter choice 1.to perform operations in stack1 2.to perform operations in stack2\n");
              scanf("%d",&ch);
              switch(ch)
              {
                      case 1:
                                  printf("you are in stack1! Enter 1.to push 2.to pop 3.to print\n");
                                  scanf("%d",&ch1);
                                  switch(ch1)
                                  {
                                         case 1:
                                                    printf("Enter no. to be pushed\n");
                                                    scanf("%d",&x);
                                                    push(ch,x);
                                         break;
                                         case 2:
                                                    pop(ch);
                                         break; 
                                         case 3:
                                                    print(ch);
                                         break; 
                                  }
                      break;
                      case 2:
                                  printf("you are in stack2! Enter 1.to push 2.to pop 3.to print\n");
                                  scanf("%d",&ch2);
                                  switch(ch2)
                                  {
                                         case 1:
                                                    printf("Enter no. to be pushed\n");
                                                    scanf("%d",&x);
                                                    push(ch,x);
                                         break;
                                         case 2:
                                                    pop(ch);
                                         break; 
                                         case 3:
                                                    print(ch);
                                         break; 
                                  }
                      break;
                      default:
                                  printf("Invalid choice\n");
                      break;
              }
              printf("Do you want to continue('y' or 'n')?\n");
              getchar();
              c=getchar();
       }while(c=='y');
}
