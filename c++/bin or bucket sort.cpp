#include<iostream>
using namespace std;
int findMax(int A[],int n)
{
  int max=INT32_MIN;
  int i;
   for(i=0;i<n;i++)
   {
   if(A[i]>max)
   max=A[i];
   }
   return max;
}
struct Node
{
  int data;
  struct Node* next;
};
void insert(struct Node **H ,int x)
{
  struct Node *t,*p=*H,*q=NULL;
  t= new Node();
  t->data=x;
  t->next=NULL;
  if(*H==NULL)
      *H=t;
  else
  {
      while(p)
      {
          q=p;
          p=p->next;
      }
      t->next=q->next;
      q->next=t;
  }
}
void bucketSort(int A[],int n)
{
  int max=findMax(A,n),i,j;
  struct Node* bin[max+1];
  for(int i=0;i<=max;i++)
    bin[i]=NULL;
  for(int i=0;i<n;i++)
    insert(&bin[A[i]],A[i]);
    i=0;j=0;
    while(i<=max)
    {
            struct Node *p=bin[i];
            while(p)
            {
                A[j]=p->data;
                p=p->next;
                j=j+1;
            }
        i++;
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
  bucketSort(a,n);
  cout<<"\nAFTER SORTING:";
  display(a,n);
  cout<<"\n---------------------------------------------------"<<endl;
  return 0;
}
