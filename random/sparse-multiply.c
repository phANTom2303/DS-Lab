#include <stdio.h>
#include <stdlib.h>
int search(int **arr, int size, int r, int c) {
  for (int i = 1; i <= size; i++) {
    if (arr[i][0] == r && arr[i][1] == c)
      return i;
  }
  return -1;
}
int main() {
  int r1, c1, v1;
  printf("Enter sparse Matrix 1 : \n");
  scanf("%d %d %d", &r1, &c1, &v1);

  int **m1 = (int **)malloc((v1 + 1) * sizeof(int *));
  for (int i = 0; i <= v1; i++) {
    m1[i] = (int *)malloc(3 * sizeof(int));
  }

  m1[0][0] = r1;
  m1[0][1] = c1;
  m1[0][2] = v1;
  for (int i = 1; i <= v1; i++) {
    int r, c, v;
    scanf("%d %d %d", &r, &c, &v);
    m1[i][0] = r;
    m1[i][1] = c;
    m1[i][2] = v;
  }

  int r2, c2, v2;
  printf("Enter sparse Matrix 2 : \n");
  scanf("%d %d %d", &r2, &c2, &v2);

  int **m2 = (int **)malloc((v2 + 1) * sizeof(int *));
  for (int i = 0; i <= v1; i++) {
    m2[i] = (int *)malloc(3 * sizeof(int));
  }

  m2[0][0] = r2;
  m2[0][1] = c2;
  m2[0][2] = v2;
  for (int i = 1; i <= v2; i++) {
    int r, c, v;
    scanf("%d %d %d", &r, &c, &v);
    m2[i][0] = r;
    m2[i][1] = c;
    m2[i][2] = v;
  }

  if (m1[0][1] != m2[0][0]) {
    printf("Matrices don't have the valid order to be multiplied.\n");
    return 0;
  }

  int r3 = m1[0][0];
  int c3 = m2[0][1];

  int k = 1;
  int **m3 = (int **)malloc((r3 * c3 + 1) * sizeof(int *));
  for (int i = 0; i <= r3 + c3 + 1; i++)
    m3[i] = (int *)malloc(3 * sizeof(int));

  for (int i = 1; i <= v1; i++) {
    for (int j = 1; j <= v2; j++) {
      if (m1[i][1] == m2[j][0]) {
        int r = m1[i][0];
        int c = m2[j][1];
        int val = m1[i][2] * m2[i][2];
        int pos = search(m3, r3 * c3, r, c);
        if (pos == -1) {
          m3[k][0] = r;
          m3[k][1] = c;
          m3[k][2] = val;

          k++;
        } else {
          m3[pos][2] += val;
        }
      }
    }
  }
  m3[0][2] = k - 1;
  m3 = realloc(m3, k * sizeof(int *));

  printf("Resultanct multiplied sparse matrix is : \n");
  for (int i = 0; i < k; i++)
    printf("%d %d %d \n", m3[i][0], m3[i][1], m3[i][2]);
}
