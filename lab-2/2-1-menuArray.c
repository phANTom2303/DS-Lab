#include <stdio.h>
#include <stdlib.h>

int getChoice(int low, int high)
{
    int choice = -1;
    for (;;)
    {
        scanf("%d", &choice);
        if (choice < low || choice > high)
            printf("Invalid input, Enter again : ");
        else
            break;
    }
    return choice;
}


void main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter array elements : \n");
    for (int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);
        arr[i] = input;
    }

    printf("Array elements : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int choice = 0;
    while (choice != 5)
    {
        printf("\n*****MENU******\n");
        printf("1. Insert \n2. Delete\n3. Linear Search\n4. Traverse\n5.Exit\nYour Choice : ");
        choice = getChoice(1,5);
        if (choice == 1)
        {
            int insert_element;
            int insert_position;
            printf("Enter element to insert : ");
            scanf("%d",&insert_element);
            printf("Enter position to be inserted into : ");
            insert_position = getChoice(0,(n-1));

            n = n + 1;//increasing size as we are inserting an element.
            arr = (int *)realloc(arr, (n) * sizeof(int));

            for(int i = n -1; i > insert_position; i--)
            {
                arr[i] = arr[i-1];//shifting elements to the right
            }

            arr[insert_position] = insert_element;
            printf("\nInserted.\n");
        }
        else if(choice == 2)
        {
            int delete_position;
            printf("Enter position of element to delete  : ");
            delete_position = getChoice(0, (n-1));

            for(int i = delete_position; i < n -1; i++)
            {
                arr[i] = arr[i+1];//overwriting the delete position and shifting left.
            }
            
            n = n-1;
            arr = (int *)realloc(arr, (n) * sizeof(int));
            printf("\nDeleted.\n");
        }
        else if(choice == 3)
        {
            int target;
            printf("Enter Element to Search for : ");
            scanf("%d",&target);

            int target_position = -1;
            for(int i = 0; i < n; i ++)
            {
                if(arr[i] == target)
                {
                    target_position = i;
                    break;
                }
            }

            if(target_position > -1)
                printf("Element found at %d \n",target_position);
            else
                printf("Element Not Found.\n");
        }
        else if(choice == 4)
        {
            printf("Array Elements : ");
            for(int i = 0; i < n; i ++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
        }
        else if(choice == 5)
        {
            printf("\nExited...\n");
        }
    }

}