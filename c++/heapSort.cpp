#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
  int t=*a;
  *a=*b;
  *b=t;
}
void insertion(int A[],int i)
{
  int temp;
  temp=A[i];
  while(i>1&&temp>A[i/2])
  {
    A[i]=A[i/2];
    i=i/2;
  }
  A[i]=temp;
}
void heapSort(int A[],int n)
{
  int i,j,x,temp;
  x=A[n];
  swap(&A[n],&A[1]);
  i=1;
  j=i*2;
  while(j<=n-1)
  {
    if(j<n-1 && A[j+1]>A[j])
      j++;
    if(A[i]<A[j])
    {
      swap(&A[i],&A[j]);
      i=j;
      j=2*j;
    }
    else
      break;
  }
}
void display(int a[],int n)
{
  for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
}
int main() {
  int n;
  cout<<"---------------------------------------------------"<<endl;
  cout << "ENTER THE NO OF ELEMENTS:";
  cin>>n;
  int a[n+1]={0};
  cout<<"ENTER THE ELEMENTS:"<<endl;
  for(int i=1;i<=n;i++)
  {
    cout<<"ELEMENT "<<i<<":";
    cin>>a[i];
  }
  cout<<"---------------------------------------------------"<<endl;
  cout<<"BEFORE SORTING:";
  display(a,n);
  for(int i=2;i<=n;i++)
  insertion(a,i);
  for(int i=n;i>1;i--)
  heapSort(a,i);
  cout<<"\nAFTER SORTING:";
  display(a,n);
  cout<<"\n---------------------------------------------------"<<endl;
  return 0;
}
