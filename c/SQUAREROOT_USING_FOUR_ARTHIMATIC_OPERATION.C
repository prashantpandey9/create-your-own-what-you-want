#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


double sqrt(double x) {
    if (x <= 0)
        return 0;      
    int exp = 0;
    x = frexp(x, &exp); 
    if (exp & 1) {     
        exp--;
        x *= 2;
    }
    double y = (1+x)/2; 
    double z = 0;
    while (y != z) {    
        z = y;
        y = (y + x/y) / 2;
    }
    return ldexp(y, exp/2); 
}

int main()
{
    double n=3;
    printf("SQUARE ROOT OF %.2f =%.2f",n,sqrt(n));
    return 0;
}
