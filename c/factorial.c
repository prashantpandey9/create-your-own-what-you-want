# include<stdio.h>
// Initilizing the Function "fact"
int fact(int a);
// main Function initilizing
int main(){

    int x, result;

    printf(" Enter the number :-");
    scanf("%d",&x);

    result=fact(x);
    printf("\n The factorial of the number is :- \n Factorial :- %d",result);
    return 0;
}

int fact(int a){

    int fac=1;
    while(a!=0){
        fac=fac*a;
        a--;
    }
    return fac;
}