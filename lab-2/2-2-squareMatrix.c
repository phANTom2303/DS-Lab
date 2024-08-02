#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n;
    printf("Enter size of matrix : ");
    scanf("%d",&n);

    int **arr = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i ++)
    {  
        arr[i] = (int*)malloc(n*sizeof(int));
    }

    int count = 0;
    printf("Enter matrix Elements : \n");
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            int input;
            scanf("%d",&input);
            arr[i][j] = input;

            if(input > 0)
                count ++;
        }
    }

    printf("\nNumber of Non Zero Elements is : %d\n",count);
    printf("\nUpper Triangular Matrix is : \n");
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            if(i <= j)
                printf("%d",arr[i][j]);
            else
                printf(" ");
            printf(" ");
        }
        printf("\n");
    }
    printf("\nElements above and below the main diagonal : \n");
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            if(i != j)
                printf("%d",arr[i][j]);
            else
                printf(" ");
            printf(" ");
        }
        printf("\n");
    }
    free(arr);
}