#include <stdio.h>
#include <stdlib.h>
void main()
{
    int degree;
    printf("Enter Highest degree of x:");
    scanf("%d", &degree);
    int *arr = (int *)malloc((degree + 1) * sizeof(int));
    printf("Enter Polynomial 1 from lowest to highest degree : ");
    for (int i = 0; i <= degree; i++)
    {
        int coeff;
        scanf("%d", &coeff);
        arr[i] = coeff;
    }

    printf("\nEnter Polynomial 2 from lowest to highest degree : ");
    for (int i = 0; i <= degree; i++)
    {
        int coeff;
        scanf("%d", &coeff);
        arr[i] += coeff;
    }

    printf("Resultant Polynomial = ");
    int i;
    for (i = degree; i >= 0; i--)
    {
        if (arr[i] != 0)
        {
            printf("%dx^%d ", arr[i], i);
            i--;
            break;
        }
    }
    while (i >= 0)
    {
        if (arr[i] > 0)
        {
            printf(" + %dx^%d ", arr[i], i);
        }
        else if (arr[i] < 0)
        {
            printf("%dx^%d ", arr[i], i);
        }
        i--;
    }
    printf("\n");
}