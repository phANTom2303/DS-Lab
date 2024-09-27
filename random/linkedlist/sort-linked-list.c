// function to sort a given linked list
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

void sort_list(node **start) {
  for (node *p1 = (*start); p1->next != NULL; p1 = p1->next) {
    for (node *p2 = p1; p2 != NULL; p2 = p2->next) {
      if (p2->data < p1->data) {
        int t = p1->data;
        p1->data = p2->data;
        p2->data = t;
      }
    }
  }
}

int main() {
  node *start = NULL;
  insert_end(&start, 1);
  insert_end(&start, 10);
  insert_end(&start, 6);
  insert_end(&start, 98);
  insert_end(&start, 2);
  insert_end(&start, 3);
  insert_end(&start, 4);
  insert_end(&start, 5);

  traverse(&start);

  sort_list(&start);

  traverse(&start);
}
