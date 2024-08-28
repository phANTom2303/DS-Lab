#include <stdio.h>
int main() {
  int a = 5;
  int *ptr = &a;
  printf("%p", ptr);
  if (ptr == NULL)
    printf("null");
}
