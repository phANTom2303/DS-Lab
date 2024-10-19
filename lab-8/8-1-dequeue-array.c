#include <stdio.h>
#define max 8
int dequeue[max];
int left = -1, right = -1;

void display() {
  if (left <= right) {
    for (int i = left; i <= right; i++)
      printf("%d ", dequeue[i]);
  } else {
    for (int i = left; i < max; i++)
      printf("%d ", dequeue[i]);
    for (int i = 0; i <= right; i++)
      printf("%d ", dequeue[i]);
  }
  printf("\n");
}

void insert_right(int data) {
  if (left == (right + 1) % max) {
    printf("Overflow\n");
    return;
  } else if (left == -1) {
    left = 0;
    right = 0;
  } else {
    right = (right + 1) % max;
  }

  dequeue[right] = data;
}

int delete_left() {
  int val;
  if (left == -1) {
    printf("Underflow.\n");
    val = -999;
  } else if (left == right) {
    val = dequeue[left];
    left = -1;
    right = -1;
  } else {
    val = dequeue[left];
    left = (left + 1) % max;
  }
  return val;
}

void insert_left(int data) {
  if (left == (right) + 1 % max) {
    printf("Overflow.\n");
    return;
  } else if (right == -1) {
    left = 0;
    right = 0;
  } else {
    left = (left - 1 + max) % max;
  }
  dequeue[left] = data;
}

int delete_right() {
  int val;
  if (left == -1) {
    val = -999;
    printf("Underflow.\n");
  } else if (left == right) {
    val = dequeue[right];
    left = 0;
    right = 0;
  } else {
    val = dequeue[right];
    right = (right - 1 + max) % max;
  }
  return val;
}

void inputRestricted() {
  int choice = -1;
  while (choice != 5) {
    printf("Menu.\n");
    printf("1. Insert Right\n");
    printf("2. Delete Left\n");
    printf("3. Delete Right\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("Your Choice : ");
    scanf("%d", &choice);
    int value;
    switch (choice) {
    case 1:
      printf("Enter element to insert : ");
      scanf("%d", &value);
      insert_right(value);
      break;

    case 2:
      value = delete_left();
      if (value != -999)
        printf("%d dequeued from left.\n", value);
      break;

    case 3:
      value = delete_right();
      if (value != -999)
        printf("%d dequeued from left.\n", value);
      break;

    case 4:
      display();
      break;

    case 5:
      printf("Exiting ...\n");
      break;

    default:
      printf("Invalid Input, Enter again : ");
    }
  }
}

void outputRestricted() {
  int choice = -1;
  while (choice != 5) {
    printf("Menu.\n");
    printf("1. Insert Right\n");
    printf("2. Delete Left\n");
    printf("3. Insert Left\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("Your Choice : ");
    scanf("%d", &choice);
    int value;
    switch (choice) {
    case 1:
      printf("Enter element to insert : ");
      scanf("%d", &value);
      insert_right(value);
      break;

    case 2:
      value = delete_left();
      if (value != -999)
        printf("%d dequeued from left.\n", value);
      break;

    case 3:
      printf("Enter element to insert : ");
      scanf("%d", &value);
      insert_left(value);
      break;

    case 4:
      display();
      break;

    case 5:
      printf("Exiting ...\n");
      break;

    default:
      printf("Invalid Input, Enter again : ");
    }
  }
}
int main() {
  int choice;
  printf("Enter 1 for I/P Restricted, 2 for O/P Restricted  : ");
  scanf("%d", &choice);

  if (choice == 1)
    inputRestricted();
  else if (choice == 2)
    outputRestricted();
  else
    printf("Invalid Input.\n");
}
