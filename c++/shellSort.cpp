#include<iostream>
using namespace std;
void shellSort(int a[],int n)
{
  int x,gap;
  for(gap=n/2;gap>=1;gap/=2)
  {
    for(int i=gap;i<n;i++)
    {
      x=a[i];
      int j=i-gap;
      while(j>=0 && a[j]>x)
      {
        a[j+gap]=a[j];
        j-=gap;
      }
      a[j+gap]=x;
    }
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
  shellSort(a,n);
  cout<<"\nAFTER SORTING:";
  display(a,n);
  cout<<"\n---------------------------------------------------"<<endl;
  return 0;
}
