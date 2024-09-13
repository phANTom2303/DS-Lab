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

void insert_start(node **start, int newData) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = newData;
  newNode->next = *start;
  *start = newNode;
}

void insert_pos(node **start, int newData, int pos) {
  if (*start == NULL && pos != 1) {
    printf("Invalid Position \n");
    return;
  }

  node *q;
  node *temp = (node *)malloc(sizeof(node));
  temp->data = newData;

  if (pos == 1) {
    temp->next = *start;
    *start = temp;
  } else {
    q = (*start);
    for (int i = 1; i < pos; i++) {
      q = q->next;
      if (q == NULL) {
        printf("Invalid Position.\n");
        return;
      }
    }

    temp->next = q->next;
    q->next = temp;
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

void delete_start(node **start) {
  if (*start == NULL) {
    printf("Linked List is empty.\n");
    return;
  }

  node *q = *start;
  *start = (*start)->next;
  free(q);
}

void delete_pos(node **start, int pos) {
  node *q, *prev;
  if (*start == NULL) {
    printf("Linked List is empty.\n");
    return;
  } else if (pos == 1) {
    q = *start;
    *start = (*start)->next;
    free(q);
  } else {
    q = *start;
    for (int i = 1; i < pos; i++) {
      prev = q;
      q = q->next;
      if (q == NULL) {
        printf("Invalid Position.\n");
        return;
      }
    }
    prev->next = q->next;
    free(q);
  }
}
int main() {
  node *start = NULL;
  int choice = -1;
  do {
    printf("\nMENU : \n");
    printf("1. Enter elements at end \n");
    printf("2. Insert Element at beginning.\n");
    printf("3. Insert element at a position. \n");
    printf("4. Traverse Linked List\n");
    printf("5. Delete Element from beginning.\n");
    printf("6. Delete Element from end.\n");
    printf("7. Delete Element at a position.\n");
    printf("8. Exit.\n");
    printf("Your Choice : ");
    scanf("%d", &choice);
    int element, pos;
    switch (choice) {
    case 1:
      int n;
      printf("Enter number of elements you want to add : ");
      scanf("%d", &n);
      printf("Enter the elements : \n");
      for (int i = 1; i <= n; i++) {
        scanf("%d", &element);
        insert_end(&start, element);
      }
      printf("Elements Added.\n");
      break;

    case 2:
      printf("Enter element to add : ");
      scanf("%d", &element);
      insert_start(&start, element);
      break;

    case 3:
      printf("Enter element to add : ");
      scanf("%d", &element);
      printf("Enter Postion to insert at : ");
      scanf("%d", &pos);
      insert_pos(&start, element, pos);
      break;

    case 4:
      traverse(&start);
      break;

    case 5:
      delete_start(&start);
      break;

    case 6:
      delete_end(&start);
      break;

    case 7:
      printf("Enter Postion to delete from : ");
      scanf("%d", &pos);
      delete_pos(&start, pos);
      break;

    case 8:
      printf("Exiting...\n");
      break;

    default:
      printf("Invalid input, enter again : ");
    }
  } while (choice != 8);
}
