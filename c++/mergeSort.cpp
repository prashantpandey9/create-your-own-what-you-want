#include<iostream>
using namespace std;
void merge(int a[],int low,int mid,int high,int n)
{
  int i=low;
  int j=mid+1;
  int k=low;
  int b[n];
  while(i<=mid && j<=high)
  {
    if(a[i]<a[j])
      b[k++]=a[i++];
    else
      b[k++]=a[j++];
  }
  for(;i<=mid;i++)
    b[k++]=a[i];
  for(;j<=high;j++)
    b[k++]=a[j];
  for(int i=low;i<=high;i++)
    a[i]=b[i];
}
void mergeSort(int arr[],int low,int high,int n)
{
  int mid;
  if(low<high)
  {
    mid=(low+high)/2;
    mergeSort(arr,low,mid,n);
    mergeSort(arr,mid+1,high,n);
    merge(arr,low,mid,high,n);
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
  mergeSort(a,0,n-1,n);
  cout<<"\nAFTER SORTING:";
  display(a,n);
  cout<<"\n---------------------------------------------------"<<endl;
  return 0;
}
