#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100

int Stack[SIZE];
int top=-1;

int isFull()
{
  return top==(SIZE-1);
}

int isEmpty()
{
  return top==-1;
}

// Function to add an item to stack.  It increases top by 1
int push(char item)
{
  if (isFull())
  {
    printf("OVERFLOW");
    return -1;
  }
 
  Stack[++top] = item;

}

// Function to remove an item from stack.  It decreases top by 1
int pop()
{
  char temp;
  if (isEmpty())
  {
    printf("UNDERFLOW \n");
    return -1;
  }
  temp=Stack[top--];
  return temp;
}

int minReversal(char* expr)
{
  int i=0;
  int size=strlen(expr);
  //printf("--%d",size);
  if(size%2!=0)
    return -1;
  else
  {
    int c=0;//count of bracket reversals
    int op=0;//op is count of left paranthesis
    int clos=0;//clos is count of right paranthesis
    while(expr[i]!='\0')
    {
      if(expr[i]=='[')
        op++;
      else
        clos++;
      if(clos>op)
      {
        clos-=1;
        op+=1;
        c++;
      }
      i++;
    }
    op-=clos;
    c+=op/2;
    return c;
  }
  
}

int main()
{
  char expression[] = "[[[[";
  printf("minimum reversals required = %d", minReversal(expression));
  return 0;
}

