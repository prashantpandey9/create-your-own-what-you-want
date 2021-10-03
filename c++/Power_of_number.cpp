#include <iostream>
using namespace std;

int power(int x, int n){
    
    int res=1,i;
    for(i=0;i<n;i++){
        res = res * x;
    }
    return res;
}

int main(){
    int n,x;
    cin>>x>>n;
    cout<<power(x,n);
}
