#include <stdio.h>

int largest(int a, int b);

int main()
{

    int m, n, result;

    printf("Enter the number of rows :- ");
    scanf("%d", &m);
    printf("\nEnter the number of columns :- ");
    scanf("%d", &n);

    result = largest(m, n);
    printf("\n The largest element is :- %d", result) ;
    return 0;
}

int largest(int a, int b)
{

    int arr[a][b];
    int max = arr[0][0];

    printf("\nEnter the Elements for rows :- ");
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the column elements :- ");
    for (int j = 0; j < b; j++)
    {
        scanf("%d", &arr[j]);
    }
    printf("Display of array elemets :- \n");

    for(int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<b;i++)
    {
        for (int j=0;j<b;j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return 0;
}