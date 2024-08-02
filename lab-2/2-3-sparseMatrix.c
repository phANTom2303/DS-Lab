#include <stdio.h>
#include <stdlib.h>
void main()
{
    int row, col;
    printf("\nEnter Size of sparse Matrix : ");
    scanf("%d %d",&row,&col);
    int** arr = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i < row; i ++)
    {
        arr[i] = (int*)malloc(col*sizeof(int));
    }

    printf("\nEnter Elements of sparse Matrix : \n"); 
    for(int i =0; i < row; i ++)
    {
        for(int j = 0; j < col; j++)
        {
            int input;
            scanf("%d",&input);
            arr[i][j] = input;
        }
    }

    printf("\nSparse Matrix in 3-tuple Format : \n");
    for(int i = 0; i < row; i ++)
    {
        for(int j = 0; j < col; j ++)
        {
            if(arr[i][j] > 0)
                printf("%d %d %d \n",i,j,arr[i][j]);
        }
    }
    printf("\n");
    free(arr);
}