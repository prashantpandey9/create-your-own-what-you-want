// Consider an n × n matrix A = (aij), each of whose elements aij is a nonnegative real
// number, and suppose that each row and column of A sums to an integer value. We wish
// to replace each element aij with either ฀ aij฀ or ฀ aij฀ without disturbing the row and
// column sums. Here is an example:

// Write a program by defining an user defined function that is used to produce the rounded matrix
// as described in the above example. Find out the time complexity of your algorithm/function.
#include<stdio.h>
#include<math.h>
#include<time.h>
float M[4][4];
float floatA[5][5];
float sum_row[5];
float sum_col[5];
float A[5][5];
int n;
void displayinitial() {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%.1lf\t",A[i][j]);
        }
        printf("\n");
    }
}
void displayfinal() {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
          int a = (int)A[i][j];
            printf("%d\t",a);
        }
        printf("\n");
    }
}
void FloatSum() {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        floatA[i][j]=A[i][j]-(int)A[i][j];
      }
    }
     for (int i = 0; i < n; i++)
     {
      for (int j = 0; j < n; j++)
       {
        sum_row[i]=(sum_row[i]+floatA[i][j]);
       }
       sum_row[i]=round(sum_row[i]);
     }
     for (int i = 0; i < n; i++)
     {
       for (int j = 0; j < n; j++)
       {
        sum_col[i]=(sum_col[i]+floatA[j][i]);
       }
        sum_col[i]=round(sum_col[i]);
     }
} 
void algo() {
  printf("\n");
  for(int w=0;w<n;w++){
    for(int q=0;q<n;q++){
      if(sum_col[q]>0 && sum_row[w]>0){
       A[w][q]=ceil(A[w][q]);
       sum_col[q]=sum_col[q]-1;
       sum_row[w]=sum_row[w]-1;
      }
      else A[w][q]=floor(A[w][q]);
    }
  }
}
void main() {
    printf("\nEnter the size of Matrix upto 5x5\n");
    scanf("%d",&n);
    printf("Enter the values of array (rows followed by columns)\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
        {
            scanf("%f",&A[i][j]);
        }
    }
    printf("\nEntered Matrix :\n ");
    displayinitial();
    FloatSum();
    algo();
    printf("\nFinal Matrix :\n");
    displayfinal();

   
}

