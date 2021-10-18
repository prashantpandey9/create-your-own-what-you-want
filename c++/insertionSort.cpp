#include<iostream>
using namespace std;
void insertionSort(int a[],int n)
{
  int x;
  for(int i=1;i<n;i++)
  {
    x=a[i];
    int j=i-1;
    while(j>=0 && a[j]>x)
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=x;
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
  insertionSort(a,n);
  cout<<"\nAFTER SORTING:";
  display(a,n);
  cout<<"\n---------------------------------------------------"<<endl;
  return 0;
}
