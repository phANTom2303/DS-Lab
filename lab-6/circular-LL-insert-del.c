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

int delete_begin(node **last) {
  int val;
  if ((*last) == NULL) {
    printf("Linked List is empty.\n");
    val = -999;
  } else if ((*last)->next == (*last)) {
    val = (*last)->data;
    free(*last);
    (*last) = NULL;
  } else {
    val = (*last)->next->data;
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
  input(&last);
  printf("Entered Linked List : \n");
  traverse(&last);

  int choice = -1;
  do {
    printf("\nMENU : \n");
    printf("1. Enter elements at end \n");
    printf("2. Insert Element at beginning.\n");
    printf("3. Traverse Linked List\n");
    printf("4. Delete Element from beginning.\n");
    printf("5. Delete Element from end.\n");
    printf("6. Exit.\n");
    printf("Your Choice : ");
    scanf("%d", &choice);
    int element, pos, deleted;
    switch (choice) {
    case 1:
      int n;
      printf("Enter new element : ");
      scanf("%d", &n);
      insert_end(&last, n);
      printf("Element Added.\n");
      break;

    case 2:
      printf("Enter element to add : ");
      scanf("%d", &element);
      insert_begin(&last, element);
      break;
    case 3:
      traverse(&last);
      break;

    case 4:
      deleted = delete_begin(&last);
      if (deleted != -999) {
        printf("%d deleted from linked List. \n", deleted);
      }
      break;

    case 5:
      deleted = delete_end(&last);
      if (deleted != -999) {
        printf("%d deleted from linked List. \n", deleted);
      }
      break;

    case 6:
      printf("Exiting...\n");
      break;

    default:
      printf("Invalid input, enter again : ");
    }
  } while (choice != 6);
}
