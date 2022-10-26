#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int fib(int n);

int main(){

    int n;
    

    printf(" \n ************************  FIBONACCI SERIES ********************** \n\n \n ");

    print(" \n Enter the number :- ");
    scanf("%d",&n);

    printf("%d %d ", 0,1);

    fib(n-2);
    
}

int fib(int n){

    int n1=0, n2=1,n3=1;
    if(n>0){

        n3=n1+n2;
        printf("%d",n3);

        fib(n-1);

    }
}
