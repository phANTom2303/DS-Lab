// function to insert element at a sorted position in linked list.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct linky {
  int data;
  struct linky *next;
} node;
void traverse(node **start) {
  if (*start == NULL) {
    printf("Linked List empty. \n");
  } else {
    node *iterator = *start;
    printf("%d", iterator->data);
    iterator = iterator->next;

    while (iterator != NULL) {
      printf(" -> %d", (iterator->data));
      iterator = iterator->next;
    }
    printf("\n");
  }
}
void insert_end(node **start, int newData) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = newData;
  newNode->next = NULL;
  if (*start == NULL) {
    *start = newNode;
  } else {
    node *iterator; // declaring a pointer of node type to traverse the linked
                    // list
    for (iterator = *start; iterator->next != NULL; iterator = iterator->next)
      ; // loop to traverse until the end of the for loop
    iterator->next = newNode;
  }
}

void insert_sorted(node **start, int newData) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = newData;
  newNode->next = NULL;

  if ((*start) == NULL || ((*start)->data) >= newData) {
    newNode->next = (*start);
    *start = newNode;

  } else {
    node *q = (*start);
    node *prev;
    while (q != NULL && q->data < newData) {
      prev = q;
      q = q->next;
    }

    if (q != NULL)
      newNode->next = q;

    prev->next = newNode;
  }
}

int main() {
  node *start = NULL;

  for (int i = 1; i <= 5; i++) {
    insert_end(&start, (i * 2));
  }

  traverse(&start);

  insert_sorted(&start, 20);

  traverse(&start);
}
