#include <stdio.h>
void sum(int ar, int ai, int br, int bi)
{
    int sum_real = ar + br;
    int sum_iota = ai + bi;
    printf("Sum = %d + %di\n", sum_real, sum_iota);
}

void multiply(int *ar, int *ai, int *br, int *bi)
{
    int prod_real = (*ar * *br) - (*ai * *bi);
    int prod_iota = (*ar * *bi) + (*ai * *br);
    printf("Product = %d + %di\n", prod_real, prod_iota);
}
void main()
{
    int n1_real, n1_iota, n2_real, n2_iota;
    printf("Enter complex number 1 : ");
    scanf("%d %d", &n1_real, &n1_iota);
    printf("Enter complex number 2 : ");
    scanf("%d %d", &n2_real, &n2_iota);

    int choice;
    printf("Enter : \n1. Addition \n2. Multiplication\nYour choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        sum(n1_real, n1_iota, n2_real, n2_iota);
        break;

    case 2:
        multiply(&n1_real, &n1_iota, &n2_real, &n2_iota);
        break;

    default:
        printf("Invalid Choic \n");
    }
}