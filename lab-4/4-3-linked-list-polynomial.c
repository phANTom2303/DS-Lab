#include <stdio.h>
#include <stdlib.h>
typedef struct linky {
  int data;
  struct linky *next;
} node;
void display_poly(node **poly, int degree) {
  if (*poly == NULL) {
    printf("No Polynomial \n");
  } else {
    node *iterator = *poly;
    while (degree > 0) {
      printf("%d x ^ %d + ", (iterator->data), degree);
      iterator = iterator->next;
      degree--;
    }
    printf("%d", (iterator->data));
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

void input(node **poly, int degree) {
  for (int i = degree; i >= 0; i--) {
    int coeff;
    printf("Enter coeff. of degree %d : ", i);
    scanf("%d", &coeff);
    insert_end(poly, coeff);
  }
}

void addition(node **sum, node **p1, node **p2, int d1, int d2) {
  while (d1 > d2) {
    insert_end(sum, (*p1)->data);
    d1--;
    *p1 = (*p1)->next;
  }

  while (d2 > d1) {
    insert_end(sum, (*p2)->data);
    d2--;
    *p2 = (*p2)->next;
  }

  while (d1 >= 0) {
    int res = ((*p1)->data) + ((*p2)->data);
    insert_end(sum, res);
    d1--;
    d2--;
    *p1 = (*p1)->next;
    *p2 = (*p2)->next;
  }
}
int main() {
  int d1, d2;
  printf("Polynomial 1 : \n");
  printf("Enter Maximum power of x : ");
  scanf("%d", &d1);
  node *poly_1 = NULL;
  input(&poly_1, d1);

  printf("Polynomial 2 : \n");
  printf("Enter Maximum power of x : ");
  scanf("%d", &d2);
  node *poly_2 = NULL;
  input(&poly_2, d2);

  printf("Polynomial 1 : ");
  display_poly(&poly_1, d1);
  printf("Polynomial 2 : ");
  display_poly(&poly_2, d2);

  node *sum = NULL;
  addition(&sum, &poly_1, &poly_2, d1, d2);
  int max_degree = (d1 > d2) ? d1 : d2;
  printf("Sum : ");
  display_poly(&sum, max_degree);
}
