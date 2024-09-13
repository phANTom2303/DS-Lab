#include <stdio.h>
#include <stdlib.h>

struct node {
  int row;
  int col;
  int ele;
  struct node *next;
};

struct head {
  int tot_row;
  int tot_col;
  int tot_ele;
  struct node *next;
};

struct head *sparse_input() {
  int r, c, te;
  printf("Enter number of rows, columns and total elements : ");
  scanf("%d %d %d", &r, &c, &te);

  struct head *hd = (struct head *)malloc(sizeof(struct head));
  struct node *last = NULL;
  hd->tot_row = r;
  hd->tot_col = c;
  hd->tot_ele = te;
  hd->next = NULL;
  printf("Enter elements of sparse matrix in triplet format : \n");
  for (int i = 0; i < te; i++) {
    int ri, ci, ele;
    scanf("%d %d %d", &ri, &ci, &ele);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->row = ri;
    temp->col = ci;
    temp->ele = ele;

    if (hd->next == NULL)
      hd->next = temp;

    else
      last->next = temp;

    last = temp;
  }
  return hd;
}

void sparse_display(struct head *hd) {
  printf("%d %d %d\n", (hd->tot_row), (hd->tot_col), (hd->tot_ele));
  for (struct node *iterator = hd->next; iterator != NULL;
       iterator = iterator->next) {
    printf("%d %d %d\n", (iterator->row), (iterator->col), (iterator->ele));
  }
}

int sparse_add(struct head **h1, struct head *h2) {
  if (((*h1)->tot_row != (h2)->tot_row) || ((*h1)->tot_col != (h2)->tot_col)) {
    printf("Order of matrices is not same, cannot add.\n");
    return 0;
  }

  struct node *q;
  if ((*h1)->next == NULL)
    (*h1)->next = (h2)->next;
  else {
    for (q = (*h1)->next; q->next != NULL; q = q->next)
      ;
    q->next = (h2->next);
  }

  int count = (*h1)->tot_ele + (h2)->tot_ele;
  struct node *prev;

  for (struct node *p1 = (*h1)->next; p1->next != NULL; p1 = p1->next) {
    for (struct node *p2 = p1->next; p2 != NULL; prev = p2, p2 = p2->next) {
      if (p1->row == p2->row && p1->col == p2->col) {
        p1->ele += (p2->ele);
        prev->next = p2->next;
        free(p2);
        p2 = prev->next;
        count--;
      }
    }
  }

  (*h1)->tot_ele = count;
  return 1;
}

int main() {
  struct head *h1 = sparse_input();
  struct head *h2 = sparse_input();

  printf("Entered Sparse Matrix 1 : \n");
  sparse_display(h1);
  printf("Entered Sparse Matrix 2 : \n");
  sparse_display(h2);

  int result = sparse_add(&h1, h2);
  if (result == 1) {
    printf("Resultant sparse matrix is : \n");
    sparse_display(h1);
  }

  return 0;
}
