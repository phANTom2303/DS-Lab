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

int main() {
  int r, c;
  printf("Enter rows and columns of  array : ");
  scanf("%d %d", &r, &c);

  int **arr = (int **)malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++)
    arr[i] = (int *)malloc(c * sizeof(int));

  printf("Enter 2d array of %d rows and %d columns : \n", r, c);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int e;
      scanf("%d", &e);
      arr[i][j] = e;
    }
  }

  struct head *hd = (struct head *)malloc(sizeof(struct head));
  struct node *last = NULL;
  hd->tot_row = r;
  hd->tot_col = c;
  hd->next = NULL;
  int count = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int e = arr[i][j];
      if (e > 0) {
        count++;
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->row = i;
        temp->col = j;
        temp->ele = e;

        if (hd->next == NULL)
          hd->next = temp;

        else
          last->next = temp;

        last = temp;
      }
    }
  }

  hd->tot_ele = count;

  printf("Entered Matrix : \n");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }

  printf("Entered Matrix in triplet Sparse matrix format :\n");

  printf("%d %d %d\n", (hd->tot_row), (hd->tot_col), (hd->tot_ele));
  for (struct node *iterator = hd->next; iterator != NULL;
       iterator = iterator->next) {
    printf("%d %d %d\n", (iterator->row), (iterator->col), (iterator->ele));
  }

  free(arr);
  return 0;
}
