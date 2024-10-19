#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct linkedList {
  int data;
  struct linkedList *next;
} node;

void traverse(node **start) {
  if (*start == NULL) {
    printf("Linked List empty. \n");
  } else {
    node *iterator = *start;
    printf("%d", iterator->data);
    iterator = iterator->next;

    while (iterator != NULL) {
      printf(", %d", (iterator->data));
      iterator = iterator->next;
    }
    printf("\n");
  }
}
void insert_start(node **start, int newData) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = newData;
  newNode->next = *start;
  *start = newNode;
}
int delete_start(node **start) {
  if (*start == NULL) {
    printf("Stack Underflow\n");
    return -999;
  }
  node *q = *start;
  int val = q->data;
  *start = (*start)->next;
  free(q);
  return val;
}

bool isEmpty(node **start) {
  if ((*start) == NULL)
    return true;
  else
    return false;
}
int main() {
  node *start = NULL;
  int choice = -1;
  while (choice != 5) {
    printf("\nMenu : \n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Is Empty\n");
    printf("4. Display Stack elements\n");
    printf("5. Exit\n");
    printf("Your Choice : ");
    scanf("%d", &choice);
    int data, val;

    switch (choice) {
    case 1:
      printf("Enter element to Push : ");
      scanf("%d", &data);
      insert_start(&start, data);
      break;

    case 2:
      val = delete_start(&start);
      if (val != -999)
        printf("%d popped from stack.\n", val);
      break;

    case 3:
      if (isEmpty(&start))
        printf("Stack is empty .\n");
      else
        printf("Stack is not empty.\n");
      break;

    case 4:
      printf("Stack elements : ");
      traverse(&start);
      printf("\n");
      break;

    case 5:
      printf("Exiting ...\n");
      break;

    default:
      printf("Invalid Choice, enter again.\n");
    }
  }
}
