#include<stdio.h>

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
  int temp;
  if (isEmpty())
  {
    printf("UNDERFLOW \n");
    return -1;
  }
  temp=Stack[top--];
  return temp;
}
int peek()
{
  int temp;
  if (isEmpty())
  {
    printf("UNDERFLOW \n");
    return -1;
  }
  temp=Stack[top];
  return temp;
}

int isOperand(char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (isdigit(ch));
}

int checkPrecedence(char ch)
{
  switch (ch)
  {
    case '+':
    case '-':      return 1;
    case '*':
    case '/':      return 2;
    case '^':      return 3;
  }
  return -1;
}

int infixToPostfix(char* exp, char* output)
{
  int i=0, k=0;
  while(exp[i])
  {
    if (isOperand(exp[i]))	// If the scanned character is an operand, add it to output.
      output[k++] = exp[i];
    else if (exp[i] == '(')	// If the scanned character is an ‘(‘, push it to the stack.
      push(exp[i]);
    else if (exp[i] == ')')	// If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
    {
      while (!isEmpty() && peek() != '(')
        output[k++] = pop();
      if (!isEmpty() && peek() != '(')
        return -1; // invalid expression             
      else
        pop();  // Discard the '(' on stack
    }
    else // an operator is encountered
    {
      while (!isEmpty() && checkPrecedence(exp[i]) <= checkPrecedence(peek()))
        output[k++] = pop();
      push(exp[i]);
    }
    i++;
  }

  while (!isEmpty())	  // pop all the operators from the stack
    output[k++] = pop();

  output[k++] = '\0';	// Place an ending string terminator.
}

int main()
{
  char exp[] = "6/(3^2)-8";
  char output[20];
  infixToPostfix(exp, output);
  printf("Given infix expression is : %s\n",exp);
  printf("Equivalent postfix expression is : %s\n", output);
  return 0;
}
