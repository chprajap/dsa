                  /* stack using arrays*/
#include<stdio.h>
#include<stdlib.h>

int s[10],t=-1;

void push(int x)
{
      if(t==9)
      {
              printf("stack is full so can't push\n");
              return;
      }
      else
          t++;
      s[t]=x;
}

void pop()
{
      if(t==-1)
      {
              printf("Stack is empty so can't pop\n");
              return;
      }
      else
           t--;
}

void print()
{
      if(t==-1)
      {
              printf("Stack is empty so can't print\n");
              return;
      }
      int i=t;
      while(i>=0)
             printf("%d ",s[i--]);
      printf("\n");
}

void top()
{
      if(t==-1)
      {
              printf("Stack is empty so can't find top\n");
              return;
      }
      printf("Top of stack is %d\n",s[t]);
}

void main()
{
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
                             push(x);
                   break;
                   case 2:
                          
                             pop();
                   break;
                   case 3:
                             print();
                   break;
                   case 4:
                             top();
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
