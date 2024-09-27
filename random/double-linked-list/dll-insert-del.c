#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct dll {
  int data;
  struct dll *next;
  struct dll *prev;
} node;

void insert_begin(node **start, int newData) {
  node *temp = (node *)malloc(sizeof(node));
  temp->data = newData;
  temp->prev = NULL;
  temp->next = *start;

  if ((*start) != NULL)
    (*start)->prev = temp;
  (*start) = temp;
}

void insert_end(node **start, int newData) {
  node *temp = (node *)malloc(sizeof(node));
  temp->data = newData;
  temp->prev = NULL;
  temp->next = NULL;

  if (*start == NULL) {
    (*start) = temp;
    return;
  }

  node *ptr = (*start);
  for (; ptr->next != NULL; ptr = ptr->next)
    ;

  ptr->next = temp;
  temp->prev = ptr;
}

void insert_after(node **start, int newData, int pos) {
  node *temp = (node *)malloc(sizeof(node));
  temp->data = newData;
  temp->prev = NULL;
  temp->next = NULL;

  if ((*start) == NULL && pos != 1) {
    printf("Invalid Position .\n");
    return;
  }

  if (pos == 0) {
    temp->prev = NULL;
    if ((*start) != NULL) {
      (*start)->prev = temp;
      temp->next = (*start);
    }
    (*start) = temp;
  }

  int i = 1;
  node *ptr = (*start);
  for (; i < pos; i++) {
    if (ptr->next == NULL) {
      printf("Invalid Position. \n");
      return;
    }
    ptr = ptr->next;
  }

  if (ptr->next == NULL) {
    ptr->next = temp;
    temp->prev = ptr;
  } else {
    temp->prev = ptr;
    temp->next = ptr->next;
    ptr->next->prev = temp;
    ptr->next = temp;
  }
}

void traverse(node **start) {
  if ((*start) == NULL) {
    printf("Linked List Empty.\n");
    return;
  }

  node *ptr = (*start);
  printf("\n%d ", (ptr->data));
  ptr = ptr->next;

  while (ptr != NULL) {
    printf("-> %d ", (ptr->data));
    ptr = ptr->next;
  }

  printf("\n");
}

int main() {
  node *start = NULL;

  for (int i = 1; i <= 4; i++)
    insert_end(&start, i);

  traverse(&start);

  int pos;
  printf("Enter pos to insert After : ");
  scanf("%d", &pos);
  insert_after(&start, 69, pos);

  traverse(&start);
}
