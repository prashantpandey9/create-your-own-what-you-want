#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void selectionSort(int *array, int size) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;  
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;
        
         swap(array[i], array[imin]);
   }
}
int main() {
  int n=6;
  int arr[6]={3,2,1,5,4,6};
    selectionSort(arr, n);
   for(int i = 0; i<n; i++)
      cout << arr[i] << " ";
    
}