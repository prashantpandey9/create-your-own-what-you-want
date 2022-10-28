#include <stdio.h>

int main()
{

    int x;
    int rev = 0;

    printf("Enter the number:- ");
    scanf("%d", &x);
    int original = x;

    printf("\nThe Entered number is :- %d",x);
    while (x!=0)
    {
        int y = x % 10;
        rev = (rev * 10) + y;
        x = x / 10;
    }
    // printf("\nThe revesre number is :- %d",rev);

    if(rev==original)
    
        printf("\nThe number is palindrome :- %d",rev); //The Number is :- %d", rev);
    
    else
    
        printf("\nThe Entered number is not a palindrome :- %d ", original);
    
    return (0);
}
