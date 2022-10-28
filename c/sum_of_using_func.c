# include<stdio.h>

int sum_of_digit(int a);

int main(){
    
    int x,res;
    
    printf("\nEnter the number:- \t");
    scanf("%d",&x);
    
   res=sum_of_digit(x);
   printf("\nThe sum of digits are :- \t %d", res);
   
   return 0;
   
}

int sum_of_digit(int a){
    
    int result=0;
    
    while(a!=0){
        int b=a%10;
        result+=b;
        a/=10;
    }
    return result;
}