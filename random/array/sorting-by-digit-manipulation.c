
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  int n1, n2;
  printf("Enter size of array 1 : ");
  scanf("%d", &n1);
  int *arr1 = (int *)malloc(n1 * sizeof(int));
  printf("Enter elements of array  1 :");
  for (int i = 0; i < n1; i++) {
    int e;
    scanf("%d", &e);
    arr1[i] = e;
  }
}
