#include <stdio.h>

struct temp

{

  int a;

  int b;

  int c;

} p[] = {0};

int main()

{

  printf("%lu", sizeof(p));
}
