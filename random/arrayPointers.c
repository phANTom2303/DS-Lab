#include <stdio.h>
void main()
{
    int n;
    printf("Enter Size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array Elements : \n");
    for (int i = 0; i < n; i++)
    {
        int e;
        scanf("%d", &e);
        arr[i] = e;
    }

    printf("Array is: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Array is : \n");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");

    int *p = arr;
    printf("Array is : \n");
    for (int i = 0; i < n; i++)
        printf("%d ", *(p + i));
    printf("\n");

    int *q = &arr[0];
    printf("Array is : \n");
    for (int i = 0; i < n; i++)
        printf("%d ", *(q + i));
    printf("\n");
}