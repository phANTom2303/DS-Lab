// Manjit's code
#include <stdio.h>
#include <stdlib.h>
#define max 5
int queue_arr[max];
int f = -1, r = -1;

void enqueue(int val) {
  if (r == max - 1) {
    printf("Queue full");
    return;
  }
  if (f == -1)
    f = 0;
  r++;
  queue_arr[r] = val;
}

int dequeue() {
  if (f == -1 || f > r) {
    printf("Queue empty\n");
    return -999;
  }
  int val = queue_arr[f];
  f++;
  return val;
}

void IsEmpty() {
  if (f == -1 || f > r)
    printf("Queue empty\n");
  else
    printf("Queue not empty\n");
  printf("\n");
}

void IsFull() {
  if (r == max - 1)
    printf("Queue full");
  else
    printf("Queue not full");
  printf("\n");
}

void Traverse() {
  if (f == -1 || f > r) {
    printf("Queue empty\n");
    return;
  }
  for (int i = f; i <= r; i++) {
    printf("%d ", queue_arr[i]);
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
    printf("4. IsFull\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");
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
      if (value != -999)
        printf("The value dequeued is: %d \n", value);
      break;
    case 3:
      IsEmpty();
      break;
    case 4:
      IsFull();
      break;
    case 5:
      Traverse();
      break;
    case 6:
      exit(0);
      break;
    default:
      printf("Invalid Input");
      break;
    }
  }
}
