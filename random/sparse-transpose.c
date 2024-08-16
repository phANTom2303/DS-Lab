#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rows, cols, vals;
    printf("Enter Rows, Columns, and Values : ");
    scanf("%d %d %d", &rows, &cols, &vals);

    int **sparse = (int **)malloc((vals + 1) * sizeof(int *));
    for (int i = 0; i <= vals; i++)
        sparse[i] = (int *)malloc(3 * sizeof(int));

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = vals;

    printf("Enter Row index, column index, Value for %d elements : \n", vals);
    for (int i = 1; i <= vals; i++)
    {
        int r, c, v;
        scanf("%d %d %d", &r, &c, &v);
        sparse[i][0] = r;
        sparse[i][1] = c;
        sparse[i][2] = v;
    }

    printf("Entered Sparse Matrix : \n");
    for (int i = 0; i <= vals; i++)
    {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    int **transpose = (int **)malloc(vals * sizeof(int *));
    for (int i = 0; i <= vals; i++)
        transpose[i] = (int *)malloc(3 * sizeof(int));
    
    transpose[0][0] = cols;
    transpose[0][1] = rows;
    transpose[0][2] = vals;

    int k = 1;
    for(int j = 0; j < cols; j++)
    {
        for(int i = 0; i <= vals; i++)
        {
            if(sparse[i][1] == j)
            {
                transpose[k][0] = sparse[i][1];
                transpose[k][1] = sparse[i][0];
                transpose[k][2] = sparse[i][2];

                k++;
            }
        }
    }

    printf("Transpose of Sparse Matrix : \n");
    for (int i = 0; i <= vals; i++)
    {
        printf("%d %d %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }
}