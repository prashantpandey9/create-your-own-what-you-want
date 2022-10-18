#include<iostream>
using namespace std;

int main()
{
    char s[100];
    cout<<"Enter String: ";
    cin.getline(s,100);

    int count;

    for(int i=0; s[i]!='\0';i++){
        count=i+1;
    }
    cout<<count<<endl;

    int start=0, end=count-1;

    while(start<=end){
        swap(s[start],s[end]);
        start++;
        end--;
    }

    cout<<s<<endl;

    return 0;
}
