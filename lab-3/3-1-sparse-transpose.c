#include <stdio.h>
#include <stdlib.h>
void main()
{
    int row, col, tot;
    printf("Enter rows, columns, total values of sparse matrix : ");
    scanf("%d %d %d", &row, &col, &tot);

    int **arr = (int **)malloc(col * sizeof(int *));
    for (int i = 0; i < col; i++)
    {
        arr[i] = (int *)malloc(row * sizeof(int));
    }

    printf("Enter %d elements in 3 tuple format : \n", tot);
    for (int i = 1; i <= tot; i++)
    {
        int r, c, v;
        scanf("%d %d %d", &r, &c, &v);
        arr[c][r] = v;
    }

    printf("\nTranspose of Sparse Matrix in 3 Tuple Format : \n");
    printf("R C Element\n%d %d %d\n", col, row, tot);
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (arr[i][j] != 0)
            {
                printf("%d %d %d\n", i, j, arr[i][j]);
            }
        }
    }
}