#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct circularList {
  int data;
  struct circularList *next;
} node;

void traverse(node **last) {
  if ((*last) == NULL) {
    printf("Linked List Empty.\n");
    return;
  }

  node *ptr = (*last)->next;

  printf("\n%d ", (ptr->data));
  ptr = ptr->next;

  while (ptr != (*last)->next) {
    printf("-> %d ", (ptr->data));
    ptr = ptr->next;
  }

  printf("\n");
}
void insert_begin(node **last, int newData) {

  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = newData;

  if ((*last) == NULL) {
    // printf("Found last as NULL\n");
    (*last) = newNode;
    newNode->next = newNode;
  } else if ((*last)->next == (*last)) {
    (*last)->next = newNode;
    newNode->next = (*last);
  } else {
    // printf("Did not find last node as NULL.\n");
    node *first = (*last)->next;
    newNode->next = first;
    (*last)->next = newNode;
  }
}

void insert_end(node **last, int newData) {

  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = newData;
  if ((*last) == NULL) {
    newNode->next = newNode;
    (*last) = newNode;
  } else {
    node *first = (*last)->next;
    newNode->next = first;
    (*last)->next = newNode;
    (*last) = newNode;
  }
}

int delete_beginning(node **last) {
  int val;
  if ((*last) == NULL) {
    printf("Linked List is empty.\n");
    val = -999;
  } else if ((*last)->next == (*last)) {
    int val = (*last)->data;
    free(*last);
    (*last) = NULL;
  } else {
    int val = (*last)->next->data;
    node *toDelete = (*last)->next;
    (*last)->next = (*last)->next->next;
    free(toDelete);
  }
  return val;
}

int delete_end(node **last) {
  int val;
  if ((*last) == NULL) {
    printf("Linked List is empty.\n");
    val = -999;
  } else if ((*last)->next == (*last)) {
    val = (*last)->data;
    free(*last);
    (*last) = NULL;
  } else {
    val = (*last)->data;
    node *prev = (*last)->next;
    while (prev->next != (*last))
      prev = prev->next;
    prev->next = (*last)->next;
    free(*last);
    (*last) = prev;
  }
  return val;
}

void input(node **last) {
  int n;
  printf("Enter number of elements in the linked List : ");
  scanf("%d", &n);
  printf("Enter Linked List elements : \n");
  for (int i = 0; i < n; i++) {
    int ele;
    scanf("%d", &ele);
    insert_end(last, ele);
  }
  printf("Elements Added.");
}
int main() {
  node *last = NULL;
  insert_end(&last, 1);
  insert_end(&last, 2);
  insert_end(&last, 3);
  traverse(&last);
  printf("Deletes : \n");
  int v;
  v = delete_end(&last);
  traverse(&last);
  v = delete_end(&last);
  traverse(&last);
  v = delete_end(&last);
  traverse(&last);
  return 0;
}
