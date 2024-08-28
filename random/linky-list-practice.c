#include <stdio.h>
#include <stdlib.h>
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

void insert_start(node **start, int newData) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = newData;
  newNode->next = *start;
  *start = newNode;
}

void insert_pos(node **start, int newData, int pos) {
  if (pos == 1) {
    insert_start(start, newData);
  } else {
    int count = 0;
    node *iterator = *start;
    node *newNode = (node *)malloc(sizeof(node));
    while (count != pos && iterator != NULL) {
      count += 1;
      iterator = iterator->next;
    }
    if (count < pos && iterator == NULL) {
      printf("Invalid Position entered");
      return;
    }
  }
}

void delete_end(node **start) {
  // function to delete the last node from the linked list.
  if (*start == NULL)
    printf("Linked List is empty.\n");
  else if ((*start)->next == NULL) {

    *start = NULL;
  } else {
    node *iterator;
    node *prev;
    for (iterator = *start; iterator->next != NULL;
         prev = iterator, iterator = iterator->next)
      ;
    prev->next = NULL;
    free(iterator);
    printf("Element Deleted.\n");
  }
}
int main() {
  node *start = NULL;
  int choice = -1;
  do {
    printf("\nMENU : \n");
    printf("1. Enter elements at end \n");
    printf("2. Delete element from end. \n");
    printf("3. Traverse Linked List\n");
    printf("4. Exit\n");
    printf("5. Insert Element at beginning.\n");
    printf("Your Choice : ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      int n;
      printf("Enter number of elements you want to add : ");
      scanf("%d", &n);
      printf("Enter the elements : \n");
      for (int i = 1; i <= n; i++) {
        int element;
        scanf("%d", &element);
        insert_end(&start, element);
      }
      printf("Elements Added.\n");
      break;

    case 2:
      delete_end(&start);
      break;

    case 3:
      traverse(&start);
      break;

    case 4:
      printf("Exiting...\n");
      break;

    case 5:
      int element;
      printf("Enter element to add : ");
      scanf("%d", &element);
      insert_start(&start, element);
      break;

    default:
      printf("Invalid input, enter again : ");
    }
  } while (choice != 4);
}
