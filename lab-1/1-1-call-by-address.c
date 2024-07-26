// 1.1 Write a program to read two numbers and compare the numbers using function call by address.
// Sample Input:
// Enter two numbers: 50  80
// Sample Output:
// 50 is smaller than 80
// Sample Input:
// Enter two numbers: 40  10
// Sample Output:
// 40 is greater than 10
// Sample Input:
// Enter two numbers: 50  50
// Sample Output:
// Both numbers are same


#include <stdio.h>

void compare(int *n1, int *n2)
{
    if(*n1 > *n2)
        printf("%d is Greater than %d. \n",*n1,*n2);
    else if(*n1 < *n2)
        printf("%d is Smaller than %d. \n",*n1,*n2);
    else
        printf("Both Numbers are Same. \n");
}
void main()
{
    int n1, n2;
    printf("Enter two numbers : ");
    scanf("%d %d",&n1, &n2);
    int *n1ptr = &n1;
    int *n2ptr = &n2;
    compare(n1ptr,n2ptr);
}