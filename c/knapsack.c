//Write a C program to solve Knapsack problem using 0/1 method.
#include<stdio.h>
#include <time.h>
int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
   return K[n][W];
}
int main()
{
    double total_time;
    clock_t start, end;
    int i, n, val[20], wt[20], W;
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    printf("Enter profit and weight of items: \n");
    for(i = 0;i < n; ++i){
     scanf("%d%d", &val[i], &wt[i]);
    }
 
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);
    
    printf("Total profit :%d", knapSack(W, wt, val, n));
    end = clock();
    total_time = ((double) (end - start)) / CLK_TCK;
    printf("\nTime taken : %f seconds\n", total_time);
    printf("\nSaurabh_20051702\n");
    return 0;
}