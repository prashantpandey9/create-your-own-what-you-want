#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
  int t=*a;
  *a=*b;
  *b=t;
}
int partition(int a[],int low,int high)
{
  int pivot=a[low];
  int i=low;
  int j=high;
  while(i<j)
  {
    while(a[i]<=pivot)i++;
    while(a[j]>pivot)j--;
    if(i<j)swap(&a[i],&a[j]);
  }
  swap(&a[low],&a[j]);
  return j;
}
void quickSort(int arr[],int low,int high)
{
  if(low<high)
  {
    int pos=partition(arr,low,high);
    quickSort(arr,low,pos-1);
    quickSort(arr,pos+1,high);
  }
}
void display(int a[],int n)
{
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main() {
  int n;
  cout<<"---------------------------------------------------"<<endl;
  cout << "ENTER THE NO OF ELEMENTS:";
  cin>>n;
  int a[n]={0};
  cout<<"ENTER THE ELEMENTS:"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<"ELEMENT "<<i+1<<":";
    cin>>a[i];
  }
  cout<<"---------------------------------------------------"<<endl;
  cout<<"BEFORE SORTING:";
  display(a,n);
  quickSort(a,0,n-1);
  cout<<"\nAFTER SORTING:";
  display(a,n);
  cout<<"\n---------------------------------------------------"<<endl;
  return 0;
}
