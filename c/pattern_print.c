#include<stdio.h>
#include<conio.h>
void main()
{
  int i,j,n,k;
  clrscr();
  printf("Enter the number");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    for{j=1;j<=i;j++)
    {
      printf("*");
    }
    for(k=n;k>i;k--)
    {
      printf("  ");
    }
    for(j=1;j<=i;j++)
    {
      printf("*");
    }
    printf("\n");
  }
   for(i=1;i<=n;i++)
  {
     for(j=n;j>i;j--)
     {
       printf("*");
     }
     for(k=1;k<=i;k++)
     {
       printf("  ");
     }
     for(j=n;j>i;j--)
     {
       printf("*");
     }
     printf("\n");
  }
   gerch();
}
