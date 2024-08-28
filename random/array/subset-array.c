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

  printf("Enter size of array 2 : ");
  scanf("%d", &n2);
  int *arr2 = (int *)malloc(n2 * sizeof(int));
  printf("Enter elements of array  2 :");
  for (int i = 0; i < n2; i++) {
    int e;
    scanf("%d", &e);
    arr2[i] = e;
  }
  int *bigArray;
  int *smolArray;
  int bigSize;
  int smolSize;
  if (n1 > n2) {
    bigArray = arr1;
    bigSize = n1;
    smolArray = arr2;
    smolSize = n2;
  } else {
    bigArray = arr2;
    bigSize = n2;
    smolArray = arr1;
    smolSize = n1;
  }

  bool isSubset = true;
  for (int i = 0; i < smolSize; i++) {
    bool elementExists = false;
    for (int j = 0; j < bigSize; j++) {
      if (bigArray[j] == smolArray[i]) {
        elementExists = true;
        break;
      }
    }
    if (elementExists == false) {
      isSubset = false;
      break;
    }
  }

  if (isSubset)
    printf("Subset is present\n");
  else
    printf("Subset is not present\n");
  return 0;
}
