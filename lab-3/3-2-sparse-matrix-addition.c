#include <stdio.h>
#include <stdlib.h>
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

  if (r1 != r2 || c1 != c2) {
    printf("Matrices have different order, cannot add. \n");
    return 0;
  }

  int v3 = v1 + v2;
  int **m3 = (int **)malloc((v3 + 1) * sizeof(int *));
  for (int i = 0; i <= v3; i++)
    m3[i] = (int *)malloc(3 * sizeof(int));

  m3[0][0] = r1;
  m3[0][1] = c1;

  int i1 = 1, i2 = 1, i3 = 1;

  while (i1 <= v1 && i2 <= v2) {
    if (m1[i1][0] == m2[i2][0] && m1[i1][1] == m2[i2][1]) {
      m3[i3][0] = m1[i1][0];
      m3[i3][1] = m1[i1][1];
      m3[i3][2] = m1[i1][2] + m2[i2][2];

      i1++;
      i2++;
      i3++;
    } else if (m1[i1][0] == m2[i2][0] && m1[i1][1] < m2[i2][1]) {
      m3[i3] = m1[i1];
      i1++;
      i3++;
    } else if (m1[i1][0] == m2[i2][0] && m1[i1][1] > m2[i2][1]) {
      m3[i3] = m2[i2];
      i2++;
      i3++;
    } else if (m1[i1][0] < m2[i2][0]) {
      m3[i3] = m1[i1];
      i1++;
      i3++;
    } else if (m1[i1][0] > m2[i2][0]) {
      m3[i3] = m2[i2];
      i2++;
      i3++;
    }
  }

  while (i1 <= v1) {
    m3[i3] = m1[i1];
    i1++;
    i3++;
  }

  while (i2 <= v2) {
    m3[i3] = m2[i2];
    i2++;
    i3++;
  }

  m3[0][2] = i3 - 1;
  m3 = realloc(m3, i3 * sizeof(int *));
  printf("Sum of sparse Matrices is : \n");
  for (int i = 0; i < i3; i++) {
    printf("%d %d %d\n", m3[i][0], m3[i][1], m3[i][2]);
  }
}
