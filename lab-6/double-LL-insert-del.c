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
    printf("<-> %d ", (ptr->data));
    ptr = ptr->next;
  }

  printf("\n");
}

int delete_begin(node **start) {
  if ((*start) == NULL) {
    printf("Linked List is empty. \n");
    return -999;
  } else {
    int val;
    if ((*start)->next == NULL) {
      val = (*start)->data;
      free(*start);
      *start = NULL;
    } else {
      val = (*start)->data;
      node *q = (*start);
      (*start)->next->prev = NULL;
      (*start) = (*start)->next;

      free(q);
    }
    return val;
  }
}

int delete_end(node **start) {
  if ((*start) == NULL) {
    printf("Linked List is empty . \n");
    return -999;
  } else {
    int val;
    if ((*start)->next == NULL) {
      val = (*start)->data;
      free(*start);
      (*start) = NULL;
    } else {
      node *iterator;
      for (iterator = (*start); iterator->next != NULL;
           iterator = iterator->next)
        ;

      val = iterator->data;
      iterator->prev->next = NULL;
      free(iterator);
    }
    return val;
  }
}

int delete_pos(node **start, int pos) {
  if ((*start) == NULL) {
    printf("Linked List is empty. \n");
    return -999;
  } else if ((*start)->next == NULL && pos > 1) {
    printf("Invalid Position. \n");
    return -999;
  } else if (pos == 1) {
    return delete_begin(start);
  } else {
    int count = 1;
    node *iterator;

    for (iterator = (*start); iterator->next != NULL;
         iterator = iterator->next, count += 1) {
      if (count == pos)
        break;
    }

    if (count < pos) {
      printf("Invalid Position. \n");
      return -999;
    }

    if (iterator->next == NULL)
      return delete_end(start);
    else {
      iterator->prev->next = iterator->next;
      iterator->next->prev = iterator->prev;
      int val = iterator->data;
      free(iterator);
      return val;
    }
  }
}

void input(node **start) {
  int n;
  printf("Enter number of elements in Linked List : ");
  scanf("%d", &n);

  printf("Enter link list elements : \n");
  for (int i = 1; i <= n; i++) {
    int ele;
    scanf("%d", &ele);

    insert_end(start, ele);
  }
}

int main() {
  node *start = NULL;
  input(&start);
  printf("Entered Linked List : \n");
  traverse(&start);

  int choice = -1;
  do {
    printf("\nMENU : \n");
    printf("1. Enter elements at end \n");
    printf("2. Insert Element at beginning.\n");
    printf("3. Insert element after a position. \n");
    printf("4. Traverse Linked List\n");
    printf("5. Delete Element from beginning.\n");
    printf("6. Delete Element from end.\n");
    printf("7. Delete Element at a position.\n");
    printf("8. Exit.\n");
    printf("Your Choice : ");
    scanf("%d", &choice);
    int element, pos, deleted;
    switch (choice) {
    case 1:
      int n;
      printf("Enter new element : ");
      scanf("%d", &n);
      insert_end(&start, n);
      printf("Element Added.\n");
      break;

    case 2:
      printf("Enter element to add : ");
      scanf("%d", &element);
      insert_begin(&start, element);
      break;

    case 3:
      printf("Enter element to add : ");
      scanf("%d", &element);
      printf("Enter Postion to insert after : ");
      scanf("%d", &pos);
      insert_after(&start, element, pos);
      break;

    case 4:
      traverse(&start);
      break;

    case 5:
      deleted = delete_begin(&start);
      if (deleted != -999) {
        printf("%d deleted from linked List. \n", deleted);
      }
      break;

    case 6:
      deleted = delete_end(&start);

      if (deleted != -999) {
        printf("%d deleted from linked List. \n", deleted);
      }
      break;

    case 7:
      printf("Enter Postion to delete from : ");
      scanf("%d", &pos);
      deleted = delete_pos(&start, pos);

      if (deleted != -999) {
        printf("%d deleted from linked List. \n", deleted);
      }
      break;

    case 8:
      printf("Exiting...\n");
      break;

    default:
      printf("Invalid input, enter again : ");
    }
  } while (choice != 8);
}
