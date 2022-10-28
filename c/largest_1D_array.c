#include <stdio.h>

int largest(int a);

int main()
{

    int x;
    printf("Enter the Size of arrya :- ");
    scanf("%d", &x);
    int result = largest(x);
    return 0;
}

int largest(int a)
{

    int ar[a];
    int max = 0 ;
    printf("\nEnter the elements ofan arrya:- ");
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &ar[i]);
    }

    printf("\n Display of arrya elements :- \n");
    for (int i = 0; i < a; i++)
    {
        printf("%d \t", ar[i]);

        
    }

    for (int i = 0; i < a; i++)
    {

        if (ar[i] > max)
        {
            max = ar[i];
        }
    }

    printf("\nThe largest element is :- %d", max);
    return 0;
}