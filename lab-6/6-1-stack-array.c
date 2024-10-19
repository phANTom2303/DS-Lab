#include <stdbool.h>
#include <stdio.h>
#define size 6

int stack[size];
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

void push(int val) {
  if (isFull())
    printf("Stack Overflow.\n");
  else {
    top += 1;
    stack[top] = val;
  }
}

int pop() {
  if (isEmpty()) {
    printf("Stack Underflow.\n");
    return -999;
  } else {
    int val = stack[top];
    top -= 1;
    return val;
  }
}

void traverse() {
  if (isEmpty())
    return;
  else {
    int val = pop();
    traverse();
    printf("%d ", val);
    push(val);
  }
}

int main() {
  int choice = -1;
  while (choice != 6) {
    printf("\nMenu : \n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Is Empty\n");
    printf("4.Is Full\n");
    printf("5. Display Stack elements\n");
    printf("6. Exit\n");
    printf("Your Choice : ");
    scanf("%d", &choice);
    int data, val;

    switch (choice) {
    case 1:
      printf("Enter element to Push : ");
      scanf("%d", &data);
      push(data);
      break;

    case 2:
      val = pop();
      if (val != -999)
        printf("%d popped from stack.\n", val);
      break;

    case 3:
      if (isEmpty())
        printf("Stack is empty .\n");
      else
        printf("Stack is not empty.\n");
      break;

    case 4:
      if (isFull())
        printf("Stack is full.\n");
      else
        printf("Stack is not full.\n");
      break;

    case 5:
      printf("Stack elements : ");
      traverse();
      printf("\n");
      break;

    case 6:
      printf("Exiting ...\n");
      break;

    default:
      printf("Invalid Choice, enter again.\n");
    }
  }
}
