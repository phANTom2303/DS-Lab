#include <stdio.h>
#include <stdlib.h>
int main() {
  int row, col;
  printf("Enter rows & Columns of both sparse matrices : ");
  scanf("%d %d", &row, &col);

  int **arr = (int **)malloc(row * sizeof(int *));
  for (int i = 0; i < row; i++) {
    arr[i] = (int *)malloc(col * sizeof(int));
  }

  int sum_total;
  int total;
  printf("Enter number of elements in 1st Matrix : ");
  scanf("%d", &total);
  sum_total = total;

  printf("Enter Elements of Matrix 1 in 3-Tuple Format : \n");
  for (int i = 1; i <= total; i++) {
    int r, c, v;
    scanf("%d %d %d", &r, &c, &v);
    arr[r][c] += v;
  }

  printf("\nEnter number of elements in 2nd Matrix : ");
  scanf("%d", &total);

  printf("Enter Elements of Matrix 2 in 3-Tuple Format : \n");
  for (int i = 1; i <= total; i++) {
    int r, c, v;
    scanf("%d %d %d", &r, &c, &v);
    if (arr[r][c] == 0)
      sum_total += 1;
    arr[r][c] += v;
  }

  printf("\nResultant Array in 3-Tuple Format : \n");
  printf("R C Element\n%d %d %d\n", row, col, sum_total);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (arr[i][j] != 0) {
        printf("%d %d %d\n", i, j, arr[i][j]);
      }
    }
  }
}
