#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(int n)
{
    if(n <= 1)
        return false;
    else
    {
        if(n==2)
            return true;
        else if(n%2 == 0)
            return false;
        
        for(int i = 3; i <= n/2; i += 2)
        {
            if(n%i == 0)
                return false;
        }

        return true;
    }
}

void main()
{
    int n;
    int sum = 0;
    printf("Enter size of the array:");
    scanf("%d",&n);
    int *arr = malloc(n);
    printf("Enter N Numbers : \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        
        if(isPrime(arr[i]))
            sum += arr[i];
    }

    printf("Sum of prime numbers = %d \n",sum);
    free(arr);
}