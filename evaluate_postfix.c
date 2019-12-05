#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100

char Stack[SIZE];
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
int push(int item)
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
  int temp;
  if (isEmpty())
  {
    printf("UNDERFLOW \n");
    return -1;
  }
  temp=Stack[top--];
  return temp;
}


int evaluatePostfix(char* exp)
{
  int i, op1, op2, answer;
  for (i = 0; exp[i]; ++i)
  {
    // If the scanned character is an operand (number here), push it to the stack.
    if (isdigit(exp[i]))
      push(exp[i] - '0');

    // If the scanned character is an operator, pop two elements from stack apply the operator
    else
    {
      op2 = pop();
      op1 = pop();
      switch (exp[i])
      {
        case '+': push(op1 + op2); break;
        case '-': push(op1 - op2); break;
        case '*': push(op1 * op2); break;
        case '/': push(op1 / op2); break;
      }
    }
  }
  answer = pop();
  return answer;
}

int main()
{
  char expression[] = "632+7*+";
  printf("Value of %s postfix expression is %d", expression, evaluatePostfix(expression));
  return 0;
}

