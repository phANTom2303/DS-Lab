#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int arr[MAX_SIZE];
  int cs; // current size
} arraylist;

#define SUCCESS 0
#define FAILURE 1

void init(arraylist *b) {
  b->cs = 0;
  for (int i = 0; i < 5; i++) {
    b->arr[i] = rand() % 100;
    b->cs++;
  }
}

void gin(arraylist *b) {
  b->cs = 0;
  int n;
  printf("Enter the number of elements you want in another arraylist: ");
  scanf("%d", &n);
  printf("Enter the data: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &b->arr[i]);
    b->cs++;
  }
}

int insert(arraylist *b, int val, int ind) {
  if (b->cs == MAX_SIZE) {
    printf("Array is full\n");
    return FAILURE;
  } else if (ind < 0 || ind > b->cs) {
    printf("Invalid index\n");
    return FAILURE;
  } else {
    for (int i = b->cs - 1; i >= ind; i--) {
      b->arr[i + 1] = b->arr[i];
    }
    b->arr[ind] = val;
    b->cs++;
    return SUCCESS;
  }
}

int del(arraylist *b, int ind, int *t) {
  if (b->cs <= ind || ind < 0) {
    printf("Invalid index\n");
    return FAILURE;
  } else {
    *t = b->arr[ind];
    for (int i = ind + 1; i < b->cs; i++) {
      b->arr[i - 1] = b->arr[i];
    }
    b->cs--;
    return SUCCESS;
  }
}

void dis(arraylist b) {
  for (int i = 0; i < b.cs; i++) {
    printf("%d\n", b.arr[i]);
  }
  printf("\n");
}

void copy(arraylist *dest, arraylist src) {
  // Assuming dest has enough space to hold all elements
  dest->cs = src.cs;
  for (int i = 0; i < src.cs; i++) {
    dest->arr[i] = src.arr[i];
  }
}

int main() {
  arraylist a, g;
  init(&a);
  int val, in, ind, d;

  printf("First Array:\n");
  dis(a);

  printf("Enter the data and the index the data needs to be entered: ");
  scanf("%d %d", &val, &ind);
  if (insert(&a, val, ind) == FAILURE) {
    printf("Insertion failed\n");
  } else {
    printf("Inserted Array:\n");
    dis(a);
  }

  printf("Enter the index the data needs to be deleted: ");
  scanf("%d", &in);
  if (del(&a, in, &d) == FAILURE) {
    printf("Deletion failed\n");
  } else {
    printf("Deleted Array:\n");
    dis(a);
  }

  copy(&g, a); // Copy a to g
  printf("Copied Array:\n");
  dis(g);

  gin(&g);
  printf("New Array is : \n");
  dis(g);

  return 0;
}
