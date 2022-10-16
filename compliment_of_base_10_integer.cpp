#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int binary=0,place=1,n2=0,place2=0;
    if(n==0)
    {
        cout << 1;
    }
    else{
    while(n!=0)
    {
        int rem=n%2;
        n=n/2;
        binary=binary+rem*place;
        place=place*10;
}
cout<<binary<<endl;
while(binary!=0)
{
    int rem2=binary%10;
    binary=binary/10;
    n2=n2 + (abs(rem2-1))*pow(2,place2);
    place2++;
}
cout<<n2;
    }
return 0;
}
