#include <stdbool.h>
#include <stdio.h>
#define size 100

char stack[size];
int top = -1;

bool isEmpty() {
  if (top == -1)
    return true;
  else
    return false;
}

bool isFull() {
  if (top == size - 1)
    return true;
  else
    return false;
}

void push(char val) {
  if (isFull())
    printf("Stack Overflow.\n");
  else {
    top += 1;
    stack[top] = val;
  }
}

char pop() {
  if (isEmpty()) {
    printf("Stack Underflow.\n");
    return '\0';
  } else {
    char val = stack[top];
    top -= 1;
    return val;
  }
}

void traverse() {
  if (isEmpty())
    return;
  else {
    char val = pop();
    traverse();
    printf("%c ", val);
    push(val);
  }
}

bool isSameOrHigherThan(char peeped, char curr) {
  if (peeped == curr)
    return true;
  else if (curr == '^')
    return false;
  else if (curr == '+' &&
           (peeped == '-' || peeped == '*' || peeped == '/' || peeped == '^'))
    return true;
  else if (curr == '-' &&
           (peeped == '+' || peeped == '*' || peeped == '/' || peeped == '^'))
    return true;
  else if (curr == '*' && (peeped == '/' || peeped == '^'))
    return true;
  else if (curr == '/' && (peeped == '*' || peeped == '^'))
    return true;
  else
    return false;
}

int main() {

  char infix[100];
  printf("Enter infix expression : ");
  scanf("%s", infix);

  // adding a ')' to the end of infix expression
  int i = 0;
  for (; infix[i] != '\0'; i++)
    ;
  infix[i++] = ')';
  infix[i] = '\0';

  char postfix[100];
  int post_end = -1;

  push('('); // initial push of '('

  for (int k = 0; k < i; k++) {
    char curr = infix[k];

    if (curr >= 'a' && curr <= 'z')
      postfix[++post_end] = curr;
    else if (curr == '(')
      push(curr);
    else if (curr == ')') {
      while (true) {
        char popped = pop();
        if (popped != '(')
          postfix[++post_end] = popped;
        else
          break;
      }
    } else {
      while (true) {
        char peeped = stack[top];
        if (isSameOrHigherThan(peeped, curr))
          postfix[++post_end] = pop();
        else {
          push(curr);
          break;
        }
      }
    }
  }

  postfix[++post_end] = '\0';
  printf("Final Postfix : %s \n", postfix);
}
