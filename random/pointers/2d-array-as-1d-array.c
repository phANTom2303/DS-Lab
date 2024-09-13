// traversing a 2D array like a 1D array because arrays are stored contiguosly.
#include <stdio.h>
#define m 4
#define n 6
char a[4][6] = {{'A', 'S', 'D', 'U', 'C', 'J'},
                {'P', 'R', 'I', 'J', 'K', 'L'},
                {'M', 'N', 'T', 'W', 'O', 'Y'},
                {'Q', 'S', 'F', 'D', 'B', 'L'}};
int main() {
  char *p = &a[0][0];
  int total = m * n;
  int i, j;
  for (i = 0; i < total; i++) {
    if (p[i] == 'A' || p[i] == 'E' || p[i] == 'I' || p[i] == 'O' ||
        p[i] == 'U') {
      for (j = i + 1; j < total; j++)
        p[j - 1] = p[j];
      total--;
      p[total] = 'X';
    }
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 6; j++)
      printf("%c ", a[i][j]);
    printf("\n");
  }
  return 0;
}
