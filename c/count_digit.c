# include<stdio.h>

//int sum(int a);
int main(){

    int x;
    int add=0;
    printf("Enter the number :- ");
    scanf("%d",&x);

    while(x!=0)
{
    int y =x%10;
    add=add+y;
    x=x/10;
}
 //add = sum(x);
printf("\n The sum of digits is :- %d",add);
return 0;
}