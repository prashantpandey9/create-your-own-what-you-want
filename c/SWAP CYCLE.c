// Write a program that takes three variable (a, b, c) as separate parameters and rotates the
// values stored so that value a goes to be, b, b to c and c to a by using SWAP(x,y)
// function that swaps/exchanges the numbers x & y.
#include <stdio.h>
#include<time.h>
void Swap(int *a, int *b, int *c);
int main() {
    int a, b, c;
    printf("Enter a, b and c respectively: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Value before swapping:\n");
    printf("a = %d \nb = %d \nc = %d\n", a, b, c);

    Swap(&a, &b, &c);


    printf("Value after swapping:\n");
    printf("a = %d \nb = %d \nc = %d", a, b, c);

    return 0;
}

void Swap(int *x, int *y, int *z) {
    int temp;
    // swapping in cyclic order
    temp = *y;
    *y = *x;
    *x = *z;
    *z = temp;
}
