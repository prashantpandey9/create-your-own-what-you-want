#include<iostream>
using namespace std;
void calculator(); 
void kmTom();
void mToyard();
void hpTokw();
void DegToRad();

int main(){
	string name; 
	int option; 
	
	
	cout<<"Hi, Welcome to universal convertor \n";
	cout<<"Enter your name : ";
	cin>>name;
	cout<<"Hello "<<name<<"\n"; 
	cout<<"choose your option "<<endl;
	
	cout<< "1: calculator"<<endl; 
	cout<< "2: Kilometer to Meter convertor"<<endl;
	cout<< "3: Meter to Yard convertor"<<endl;
	cout<< "4: Horsepower to kilowatt convertor"<<endl;
	cout<< "5: Degree to Radian convertor"<<endl;
	cin>>option;
	
	switch(option){
		case 1:
			calculator();
			break;
		case 2:
			kmTom();
			break;
		case 3:
		    mToyard();
		    break;
		case 4:
		    hpTokw();
		    break;		    
		case 5:
		    DegToRad();
		    break;		   		    
		default:
			cout<<"Wrong option";
			break;
	}
}

void calculator(){ 
	int select;
	int num_1, num_2, answer;
	
	cout<<"choose your option "<<endl;
	cout<< "1: Addition "<<endl;
	cout<< "2: subtraction"<<endl;
	cout<< "3: Multiplication "<<endl;
	cout<< "4: Division "<<endl;
	cin>>select;
	switch(select){
		case 1:
		cout<<" Addition"<<endl;
			cout<<"Enter First number: " <<endl;
			cin>>num_1;
			cout<<"Enter second number: "<<endl;
			cin>>num_2;
			answer = num_1 + num_2;
			cout<<"Answer : "<<answer<<endl;
			break;
		case 2:
		cout<<" Subtraction"<<endl;
			cout<<"Enter First number: " <<endl;
			cin>>num_1;
			cout<<"Enter second number: "<<endl;
			cin>>num_2;
			answer = num_1 - num_2;
			cout<<"Answer : "<<answer<<endl;
			break;
		case 3:
		cout<<" Multiplication"<<endl;
			cout<<"Enter First number: " <<endl;
			cin>>num_1;
			cout<<"Enter second number: "<<endl;
			cin>>num_2;
			answer = num_1 * num_2;
			cout<<"Answer : "<<answer<<endl;
			break;
		case 4:
		cout<<" Division"<<endl;
			cout<<"Enter First number: " <<endl;
			cin>>num_1;
			cout<<"Enter second number: "<<endl;
			cin>>num_2;
			answer = num_1 / num_2;
			cout<<"Answer : "<<answer<<endl;
			break;
		default:
			break;
	}
}

void kmTom(){
	float km;
	float meter;
	cout<<"\n Enter value in Kilometre: ";
	cin>>km;
	meter = km * 1000;
	cout<<km<<" KM is equal to "<<meter << " Meter ";
}

void mToyard(){
	double m;
	double yard;
	cout<<"\n Enter value in Meter: ";
	cin>>m;
	yard = m * 1.0936132983;
	cout<<m<<" M is equal to "<<yard << " Yard ";
}

void hpTokw(){
	float hp;
	float kw;
	cout<<"\n Enter value in horsepower: ";
	cin>>hp;
	kw = hp * 0.73549875;
	cout<<hp<<" hp is equal to "<<kw << " kilowatt ";
}

void DegToRad(){
	float Deg;
	float Rad;
	cout<<"\n Enter value in Degree: ";
	cin>>Deg;
	Rad = Deg * 0.0174532925;
	cout<<Deg<<" Degree is equal to "<<Rad << " Radian ";
}