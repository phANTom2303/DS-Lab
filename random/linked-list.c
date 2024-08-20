// Manjit ka bheja hua code
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct LinkedList {
  Node *head;
} LinkedList;

LinkedList *create_list() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  list->head = NULL;
  return list;
}

void append(LinkedList *list, int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  if (list->head == NULL)
    list->head = new_node;
  else {
    Node *current = list->head;
    while (current->next != NULL)
      current = current->next;
    current->next = new_node;
  }
  // printf("Node appended\n");
}

void insert_at_position(LinkedList *list, int data, int position) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (position == 1) {
    new_node->next = list->head;
    list->head = new_node;
  } else {
    Node *current = list->head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
      current = current->next;
    }
    if (current == NULL) {
      free(new_node);
      printf("Position out of range\n");
      return;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
  printf("Node inserted\n");
}

void delete_at_position(LinkedList *list, int position) {
  if (position == 1) {
    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
  } else {
    Node *current = list->head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
      current = current->next;
    }
    if (current == NULL || current->next == NULL) {
      printf("Position out of range\n");
      return;
    }
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
  }
  printf("Node deleted\n");
}

void count_nodes(LinkedList *list) {
  int count = 0;
  Node *current = list->head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  printf("The total number of nodes: %d\n", count);
}

void traverse(LinkedList *list) {
  Node *current = list->head;
  while (current != NULL) {
    printf("%d->", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void search(LinkedList *list, int element) {
  Node *current = list->head;
  while (current != NULL) {
    if (current->data == element) {
      printf("Element found\n");
      return;
    }
    current = current->next;
  }
  printf("Element not found\n");
}

int main() {
  LinkedList *list = create_list();
  int n, element, position, choice;

  printf("Enter number of nodes: ");
  scanf("%d", &n);

  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &element);
    append(list, element);
  }
  printf("Nodes appended\n");

  while (1) {
    printf("\nMENU:\n");
    printf("1. Insert the node at a position\n");
    printf("2. Delete a node from specific position\n");
    printf("3. Count\n");
    printf("4. Traversal\n");
    printf("5. Search an element\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter element: ");
      scanf("%d", &element);
      printf("Enter position: ");
      scanf("%d", &position);
      insert_at_position(list, element, position);
      break;
    case 2:
      printf("Enter position: ");
      scanf("%d", &position);
      delete_at_position(list, position);
      break;
    case 3:
      count_nodes(list);
      break;
    case 4:
      traverse(list);
      break;
    case 5:
      printf("Enter element to search: ");
      scanf("%d", &element);
      search(list, element);
      break;
    case 6:
      Node *current = list->head;
      while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
      }
      free(list);
      return 0;
    default:
      printf("Invalid choice\n");
    }
  }
}
