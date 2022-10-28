
// Implemenatation of QuickSort 

# include<stdio.h>
# include<stdlib.h>

int partition(int a[], int l, int h) {
// l= low or starting index
//h = high or end index
    int pivot = a[h];
    int i = (l -1);

for (int j=l;j<=h-1;j++)
{

if(a[i]<pivot){
    int t = a[i];
    a[i] =a[j];
    a[j]= t;

}   

 }
 int t = a[i+1];
a[i+1] = a[h];
a[h] = t;

return(i+1);

}

void quick(int a[],int l,int h){

    if (l<h){
        int p =partition(a,l,h); // making partition
        quick(a,l,p-1);
        quick(a,p+1,h);

    }
}

void display(int a[],int n){
    int i;
    for(i =0;i<n;i++)
    
        printf("%d",a[i]);
    printf("\n");

}

int main(){

    int m;
    printf("\n \n ************** QUICK_SORT ALGORITHM  *************\n");
    printf("Enter the Size of array :- ");
    scanf("%d",&m);

    int a[m];
    for(int i =0;i< m;i++){
        a[i]= rand();

    }

    int n = sizeof(a)/sizeof(a[0]);
    printf("\n The elements before sorting are :-\n\n ");
    display(a,n);
    
    quick(a,0,n-1);

printf("\n The elements after sorting are :-\n\n ");
    display(a,n);

    return 0;


}