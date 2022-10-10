#include<iostream>
using namespace std;
class complex;

class calculator
{
public:
    int add(int x , int y)
        {
            return x + y; 
        }

    static int sumRealComplex(complex , complex);
    static int sumCompComplex(complex , complex);

};

class complex{
    int a,b;
    friend int calculator :: sumRealComplex(complex, complex);
    friend int calculator :: sumCompComplex(complex, complex);

public:
        void setNumber(int n1, int n2){
            a=n1;
            b=n2;
        }
        void printNumber(){
            cout<<"Your number is : "<<a<<"+"<<b<<"i"<<endl;
        }
}; 

int calculator ::sumRealComplex(complex o1, complex o2){
    
        return (o1.a + o2.a);
    
}
int calculator ::sumCompComplex(complex o1, complex o2){
    
        return (o1.b + o2.b);
    
}
int main()
{
    int a;
complex c1,c2;
c1.setNumber(1,2);
c1.printNumber();
c2.setNumber(3,4);
c2.printNumber();
// c2.setNumber(4,2);
// c.printNumber();
int res = calculator::sumRealComplex(c1,c2);
int res1 = calculator::sumCompComplex(c1,c2);
cout<<"The sum of real part of the complex numbers is"<<endl;
cout<<res<<endl;
cout<<"The sum of imaginary part of the complex numbers is"<<endl;
cout<<res1<<endl;
return 0;
}
