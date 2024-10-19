#include <stdio.h>
#include <stdlib.h>

struct queue {
  int data;
  struct queue *next;
} *f = NULL, *r = NULL;

void enqueue(int val) {
  struct queue *t = (struct queue *)malloc(sizeof(struct queue));
  t->data = val;
  t->next = NULL;
  if (f == NULL && r == NULL) {
    f = t;
    t->next = r;
    r = t;
  } else {
    r->next = t;
    r = t;
  }
}

int dequeue() {
  if (f == NULL) {
    printf("Stack Underflow\n");
    return -999;
  }
  struct queue *t;
  t = f;
  int x = t->data;
  f = f->next;
  free(t);
  return x;
}

void IsEmpty() {
  if (f == NULL && r == NULL) {
    printf("Queue empty\n");
  } else {
    printf("Queue not empty\n");
  }
}

void Traverse() {
  if (f == NULL && r == NULL) {
    printf("Queue empty\n");
    return;
  }
  struct queue *t;
  t = f;
  while (t) {
    printf("%d ", t->data);
    t = t->next;
  }
  printf("\n");
}

int main() {
  int value, choice;
  while (1) {
    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. IsEmpty\n");
    printf("4. Traverse\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the value: ");
      scanf("%d", &value);
      enqueue(value);
      break;
    case 2:
      value = dequeue();
      if (value < 0)
        printf("%d", -999);
      else
        printf("The value dequeued is: %d \n", value);
      break;
    case 3:
      IsEmpty();
      break;
    case 4:
      Traverse();
      break;
    case 5:
      exit(0);
      break;
    default:
      printf("Invalid Input");
      break;
    }
  }
}
