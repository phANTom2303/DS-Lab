// function to reverse a singly linked list
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
void input(node **start) {
  int n;
  printf("Enter Number of elements in the List : ");
  scanf("%d", &n);

  printf("Enter Linked List elements : \n");
  for (int i = 0; i < n; i++) {
    int e;
    scanf("%d", &e);
    insert_end(start, e);
  }
}
void reverseList(node **head) {
  node *prev = NULL;
  node *curr = (*head);
  node *next = NULL;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  (*head) = prev;
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

int searchList(node **start, int target) {
  int pos = 0;
  for (node *p = (*start); p->next != NULL; p = p->next) {
    pos += 1;
    if (p->data == target) {
      return pos;
    }
  }
  return -1;
}
int main() {
  node *start = NULL;
  input(&start);

  printf("Entered Linked List : \n");
  traverse(&start);

  int choice = -1;
  while (choice != 4) {
    printf("\nEnter: \n1.Sort the Linked List. \n2. Reverse the linked "
           "List.\n3.Search for an element in the linked list.\n4. Exit.\n "
           "Your Choice : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      sort_list(&start);
      printf("Sorted List : \n ");
      traverse(&start);
      break;

    case 2:
      reverseList(&start);
      printf("Reversed List : \n");
      traverse(&start);
      break;

    case 3:
      int target;
      printf("Enter element to search for  :");
      scanf("%d", &target);
      int res = searchList(&start, target);
      if (res != -1)
        printf("Element found at position %d \n", res);
      else
        printf("Element Does not exist in the Linked List. \n");
      break;

    case 4:
      printf("Exiting ...\n ");
      break;

    default:
      printf("Invalid Input, enter again.\n");
    }
  }
}
