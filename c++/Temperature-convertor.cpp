//Code created by @hakxcore [https://github.com/hakxcore]

#include <iostream>
using namespace std;
int main()
{
 float temp=0,f=0,c=0,k=0;
 int tmpinpt;
 cout<<"TEMPERATURE CONVERTOR CALCULATOR\n";
 cout<<"Enter Your temperature in \n";
 cout<<"1: for fahrenheit\n";
 cout<<"2: for celsius\n";
 cout<<"3: for kelvin\n";
 cin>>tmpinpt;
 if(tmpinpt==1)
 {
  cout<<"Enter Temperature: ";
  cin>>temp;
  c=(temp-32)/1.8;
  cout<<"Temperature in Celsius: "<<c<<endl;
  k=(temp+459.67)*1.8;
  cout<<"Temperature in Kelvin: "<<k<<endl;
 }
 else if(tmpinpt==2)
 {
  cout<<"Enter Temperature: ";
  cin>>temp;
  f=(1.8*temp)+32;
  cout<<"Temperature in Fahrenheit: "<<f<<endl;
  k=(273.15+temp);
  cout<<"Temperature in Kelvin: "<<k<<endl;
 }
 else if(tmpinpt=3)
 {
  cout<<"Enter Temperature: ";
  cin>>temp;
  f=(827.406-temp);
  cout<<"Temprature in Fahrenheit: "<<f<<endl;
  cout<<"Temperature in Celsius: "<<c<<endl;
 }
 else
 {
  cout<<"***You Entered Wrong Input***";
 }
 return 0;
}
