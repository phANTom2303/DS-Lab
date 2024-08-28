#include <stdio.h>
#include <stdlib.h>
int *convert(int **arr, int row, int col) {
  int total = row * col;
  int *res = (int *)malloc(total * sizeof(int));
  int k = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      res[k] = arr[i][j];
      k++;
    }
  }
  return res;
}

void sort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    int pos = i;
    for (int j = i; j < size; j++) {
      if (arr[j] < arr[pos])
        pos = j;
    }

    int t = arr[pos];
    arr[pos] = arr[i];
    arr[i] = t;
  }
}
int main() {
  int row, col;
  printf("Enter number of rows and columns : ");
  scanf("%d %d", &row, &col);
  int **arr = (int **)malloc(row * sizeof(int *));
  for (int i = 0; i < row; i++) {
    arr[i] = (int *)malloc(col * sizeof(int));
  }

  printf("Enter array elements : ");
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int e;
      scanf("%d", &e);
      arr[i][j] = e;
    }
  }

  int *linear = convert(arr, row, col);
  sort(linear, (row * col));

  int k = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d ", linear[k]);
      k++;
    }
    printf("\n");
  }
}
