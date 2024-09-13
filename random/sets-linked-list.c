#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
struct Node *create(int data) {
  struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
  curr->data = data;
  curr->next = NULL;
  return curr;
}

void insertEnd(struct Node **head, int data) {
  struct Node *newNode = create(data);
  if (*head == NULL) {
    *head = newNode;
    return;
  }

  struct Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}
int existsInList(struct Node *head, int data) {
  struct Node *temp = head;
  while (temp != NULL) {
    if (temp->data == data) {
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}
/*
void delete(struct node **head, intersection(&list1, &list2)) {
  struct Node *ptr = *head;
  struct Node *prev = NULL;

  if (ptr != NULL && ptr->data == intersectionlist) {

    *head = ptr->next;
    free(ptr);
    return;
  }

  while (ptr != NULL && ptr->data != intersectionlist) {
    prev = ptr;
    ptr = ptr->next;
  }

  if (ptr == NULL)
    return;

  prev->next = ptr->next;
  free(ptr);
}
*/
// UNION

struct Node *Union(struct Node *list1, struct Node *list2) {
  struct Node *unionList = NULL;

  struct Node *temp = list1;
  while (temp != NULL) {
    if (!existsInList(unionList, temp->data)) {
      insertEnd(&unionList, temp->data);
    }
    temp = temp->next;
  }

  temp = list2;
  while (temp != NULL) {
    if (!existsInList(unionList, temp->data)) {
      insertEnd(&unionList, temp->data);
    }
    temp = temp->next;
  }

  return unionList;
}

void itersection_of_lists(struct Node *list1, struct Node *list2,
                          struct Node **intersectionList) {
  struct Node *temp = list1;
  while (temp != NULL) {
    if (existsInList(list2, temp->data) &&
        !existsInList(*intersectionList, temp->data)) {
      insertEnd(intersectionList, temp->data);
    }
    temp = temp->next;
  }
}

// COMPLIMENT
/*
struct node *compliment(struct Node *list1, struct Node *list2) {
  struct Node *complement = NULL;
  if (existsInList(list2, temp->data) &&
      existsInList(intersectionList, temp->data)) {
    deletedata(&list1, intersectionlist(&list1, &list2));
  }
  complement = deletedata(&list1, intersectionlist(&list1, &list2));
  return complement;
}
*/

void printList(struct Node *head) {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d  ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main() {
  struct Node *list1 = NULL;
  struct Node *list2 = NULL;

  // List 1: 10 -> 15 -> 20 -> NULL
  insertEnd(&list1, 10);
  insertEnd(&list1, 15);
  insertEnd(&list1, 20);

  // List 2: 15 -> 20 -> 25 -> 30 -> NULL
  insertEnd(&list2, 15);
  insertEnd(&list2, 20);
  insertEnd(&list2, 25);
  insertEnd(&list2, 30);

  printf("List 1: ");
  printList(list1);

  printf("List 2: ");
  printList(list2);

  struct Node *unionList = Union(list1, list2);

  printf("Union of List 1 and List 2: ");
  printList(unionList);

  struct Node *intersectionList = NULL;
  intersection_of_lists(list1, list2, &intersectionList);

  printf("Intersection of List 1 and List 2: ");
  printList(intersectionList);

  return 0;
}
