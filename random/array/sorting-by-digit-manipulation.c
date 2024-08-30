
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int countDigits(int n) {
  int count = 0;
  if (n == 0)
    return 1;
  else {
    while (n > 0) {
      count += 1;
      n /= 10;
    }
  }
  return count;
}

int makeBiggestNumber(int n) {
  if (n <= 9)
    return n;

  int size = countDigits(n);
  int *arr = (int *)malloc(size * sizeof(int));
  int dup = n;
}
int main() {
  int n;
  printf("Enter size of array  : ");
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  printf("Enter elements of array : ");
  for (int i = 0; i < n; i++) {
    int e;
    scanf("%d", &e);
    arr[i] = e;
  }

  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
    }
  }
}
