#include<iostream>
using namespace std;
class complex {
	int real,imag;
	public:
		void input() {
			cout<<"Enter real and imag values"<<endl;
			cin>>real>>imag;
		}
		void display() {
			cout<<"Real and Imag values are "<<endl;
			cout<<real<<endl;
			cout<<imag<<endl;
		}
		void add(complex c1, complex c2) {
			real = c1.real + c2.real;
			imag = c1.imag + c2.imag;
			cout<<"After adding 2 complex objects\t"<<endl;
			cout<<real<<" + "<<imag<<"i"<<endl;
		}
			void subtract(complex c1, complex c2) {
			real = c1.real - c2.real;
			imag = c1.imag - c2.imag;
			cout<<"After subtract 2 complex objects\t"<<endl;
			cout<<real<<" + "<<imag<<"i"<<endl;
		}
			void multiply(complex c1, complex c2) {
			real = c1.real*c2.real - c1.imag*c2.imag;
			imag = c1.imag*c2.real + c1.real*c2.imag;
			cout<<"After multiply 2 complex objects\t"<<endl;
			cout<<real<<" + "<<imag<<"i"<<endl;
		}
};
int main()
{
	complex c1,c2,c3;
	c1.input();
	c1.display();
	c2.input();
	c2.display();
	c3.add(c1,c2);
	c3.subtract(c1,c2);
	c3.multiply(c1,c2);
	return 0;
}
