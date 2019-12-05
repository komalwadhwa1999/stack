#include<stdio.h>

#define SIZE 10

int Stack[SIZE], top=-1;

int isFull()
{
  return top==(SIZE-1);
}

int isEmpty()
{
  return top==-1;
}

// Function to add an item to stack.  It increases top by 1
int push(int item)
{
  if (isFull())
  {
    printf("OVERFLOW");
    return -1;
  }
  printf("%d pushed to stack\n",item);
  Stack[++top] = item;
  printf("Top is now at %d\n", top);
}

// Function to remove an item from stack.  It decreases top by 1
int pop()
{
  int temp;
  if (isEmpty())
  {
    printf("UNDERFLOW \n");
    return -1;
  }
  temp=Stack[top--];
  printf("%d popped from stack\n", temp);
  printf("Top is now at %d\n", top);
  return temp;
}

int main()
{
  int temp;
  push(12);
  push(23);
  temp=pop();
  push(54);
  temp=pop();
  temp=pop();
  temp=pop();
  return 0;
}
