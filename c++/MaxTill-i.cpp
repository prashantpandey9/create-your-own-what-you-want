#include <iostream>
using namespace std;

int main() {
     
     int n;
     cin>>n;

     int arr[n];

     for(int i=0;i<n;i++) {
         cin>>arr[i];
        
     }
     
    for(int i=0;i<n;i++) {
        int mx = max(arr[0], arr[i] );
        cout<<mx<<" ";

    }
}