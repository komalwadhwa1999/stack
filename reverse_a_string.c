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


char* reverseString(char *s)
{
  for(int i=0;i<strlen(s);i++)
    push(s[i]);
  for(int i=0;i<strlen(s);i++)
  	s[i]=pop();
  return s;

}

int main()
{
  char expression[] = "stringreverse";
  printf("reversed string is %s", reverseString(expression));
  return 0;
}

