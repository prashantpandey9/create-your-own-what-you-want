#include<stdio.h>

int main(){
int a=20;

int* ptra;
ptra=&a;
printf("The address of A is %x\n",&ptra);
printf("\n The value of A stored in pointer is :- %d",*ptra);
printf("\n The value of A as original value is  :- %d",a);

return(0);

}