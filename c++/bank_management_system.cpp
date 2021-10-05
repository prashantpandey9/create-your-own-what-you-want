#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<dos.h>
class bank{int accno;
float balance;
char n[20],actype,mno[11],add[30];

public:

void accept()
{cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter the account no."<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>accno;
cout<<'\t'<<'\t'<<'\t'<<'\t';

cout<<"Enter the name"<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin.get();
cin.getline(n,20);
       cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"enter the account type as S/C"<<endl;

while(1)
{cout<<'\t'<<'\t'<<'\t'<<'\t';
 cin>>actype;
 if(toupper(actype)=='S'||toupper(actype)=='C')
 break;
 else
 {cout<<'\t'<<'\t'<<'\t'<<'\t';
 cout<<"Enter S or C only"<<endl;
 }

 }
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter the balance"<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>balance;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter the mobile no."<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>mno;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter address"<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin.getline(add,30);
}
void display()
{cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Account no. -"<<accno<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Name-"<<n<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Account type-"<<actype<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Balance-"<<balance<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Mobile no."<<mno<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Address"<<add<<endl;
}



void deposite(float a)
{balance+=a;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Your ammount is deposited";
}

void withdraw(float a)
{ if(balance-a>=100)
{balance-=a;
       cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Your ammount is withdrawn";
}
else
{cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Withdrawal is not possible";
}}


int search(int acc)
{if(accno==acc)
return(1);
else
return(0);

}

      };
 class bank1{int acno,time;
float amount, rate;
public:
void accept1(int a)
{acno=a;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter the time";
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>time;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter amount";
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>amount;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter rate";
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>rate;
       cout<<'\t'<<'\t'<<'\t'<<'\t';
}

void display1()
{cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Account n o.-"<<acno;
       cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"timne-"<<time;
       cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"rate of intrest-"<<rate;
       cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Principal amouint-"<<amount;
float in=amount*rate*time/100;
       cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"INtreast is-"<<in;
       cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Total amount to be repaid-"<<amount+in;
}

int search1(int a)
{if(acno==a)
return 1;
else
return 0;
}

void returnl()
{float intt=amount*rate*time/100;

 cout<<"Intrest-"<<intt<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Principal amount-"<<amount<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"total loan to be repaid-"<<amount+intt<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"press 1 to confirm repayment"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"press 2 to exit"<<endl<<endl;
int choice;
cin>>choice;
if(choice==1)
{amount=0;
intt=0;
}
if(choice==2)
exit(0);

}
};




void main()
{clrscr();
char pass[]="tiger";
 char password[30];
 do{
   cout<<'\t'<<'\t'<<'\t'<<'\t';
 cout<<'\n'<<"Enter the Password";
 int i=0;
 char tp;
 while((tp=getch())!='\r')
 {cout<<"*";
  password[i]=tp;
  i++;
 }
 password[i]='\0';
 if(strcmpi(password,pass)==0)
 break;
 else
   cout<<'\t'<<'\t'<<'\t'<<'\t';
 cout<<'\n'<<"Wrong Password";
 }while(1);


    fstream obj,obj1,obj2,obj3;
bank b;
bank1 b1;
int l,a,ch,c=0;
float amt;
int i,j;
char chmain;
textmode(C40);
textcolor(5);
gotoxy(17,11);

char y1[]="Loading...";
cputs(y1);
char y2='_ ';
textcolor(12);
for(i=0;i<3;i++)
{
 for(j=17;j<28;j++)
 {
  gotoxy(j,14);
  clreol();
  putch(y2);
  delay(200);
  }
  clreol();
  delay(250);
 }
 textcolor(3);

 char z[]="       WELCOME TO";
 char z1[]="............................................................................";
 for(i=1;i<12;i++)
 {
 clrscr();
 gotoxy(10,i);
 cputs(z);
 gotoxy(10,i+1);
 cputs(z1);
 sound(i*50);
 delay(150);
 }
 nosound();
 for(i=4;i<39;i+=2)
 {
  gotoxy(i,17);
  cout<<char(2);
 }
 for(i=1;i<200;i=i+10)
 {
  sound(i*20);
  delay(175);
  nosound();
  }
  nosound();
  clrscr();
  do{
    main:
    textmode(3);
    textmode(C4350);
    textbackground(WHITE);
    textcolor(GREEN);

  cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Main Menu"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"1-Add account"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"2-modiefy an account"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"3-delete an account"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"4-Deposite"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"5-withdraw"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"6-issue a loan"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"7-return a loan"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"8-modefy a loan"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"9-delete a loan account"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"10-display single account"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"11-display all accounts"<<endl<<endl;

cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"12-display single loan account"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"13-display all loan accounts"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"14-Exit"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter your choice"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>ch;


switch(ch)
{case 1:
 clrscr();
obj.open("bank.dat", ios::binary|ios::app);
b.accept();
obj.write((char*)&b,sizeof(b));
obj.close();
cout<<'\t'<<'\t'<<'\t'<<'\t';
      cout<<”Press any key “<<endl;
      getch();
break;
case 2:
obj.open("bank.dat",ios::binary|ios::in|ios::out);
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"enter the account no."<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>a;
cout<<endl<<endl<<endl;
while(!obj.eof())
{obj.read((char*)&b,sizeof(b));
l=b.search(a);
c++;
if(l==1)
{cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter the new details"<<endl<<endl;
b.accept();
obj.seekp((c-1)*sizeof(b),ios::beg);
obj.write((char*)&b,sizeof(b));
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"account is modefied"<<endl;

break;
}
}
if(l==0)
{cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Account no not found"<<endl<<endl;
}
obj.close();

cout<<'\t'<<'\t'<<'\t'<<'\t';
      cout<<”Press any key “<<endl;
      getch();
break;
case 3:
obj.open("bank.dat",ios::binary|ios::in);
obj1.open("bank1.dat",ios::binary|ios::out);
       cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter the account no to be deleted"<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>a;
cout<<endl<<endl<<endl;
while(!obj.eof())
{obj.read((char*)&b,sizeof(b));
l=b.search(a);
if(l==0)
obj1.write((char*)&b,sizeof(b));
}
if(l==1)
cout<<"Account not found"<<endl;

obj.close();
obj1.close();
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Account is deleted"<<endl<<endl<<endl<<endl;
remove ("bank.dat");
rename ("bank1.dat","bank.dat");cout<<'\t'<<'\t'<<'\t'<<'\t';
      cout<<”Press any key “<<endl;
      getch();
break;






case 4:
obj.open("bank.dat",ios::binary|ios::in|ios::out);

cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"enter the account no."<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>a;
cout<<endl<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter the ammount to be deposited"<<endl<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>amt;
       cout<<endl<<endl<<endl;
while(!obj.eof())
{obj.read((char*)&b,sizeof(b));
l=b.search(a);
c++;

if(l==1)
{b.deposite(amt);
obj.seekp((c-1)*sizeof(b),ios::beg);
obj.write((char*)&b,sizeof(b));
break;
}
}
if(l==0)
       { cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"the ginve account no. is not found"<<endl<<endl<<endl;
}
obj.close();

cout<<'\t'<<'\t'<<'\t'<<'\t';
      cout<<”Press any key “<<endl;
      getch();



break;



case 5:
obj.open("bank.dat",ios::binary|ios::in|ios::out);
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter the account no."<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>a;
cout<<endl<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Enter the amount to be withdrawan"<<endl<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>amt;
cout<<endl<<endl<<endl;
c=0;

while(!obj.eof())
{obj.read((char*)&b,sizeof(b));
l=b.search(a);
c++;
if(l==1)
{b.withdraw(amt);
obj.seekp((c-1)*sizeof(b),ios::beg);
obj.write((char*)&b,sizeof(b));
break;

       }
       }
       if(l==0)
      { cout<<'\t'<<'\t'<<'\t'<<'\t';
       cout<<'\t'<<'\t'<<"The given account no. is not found"<<endl<<endl<<endl<<endl;
      }
       obj.close();

cout<<'\t'<<'\t'<<'\t'<<'\t';
      cout<<”Press any key “<<endl;
      getch();
       break;


      case 6:
obj.open("bank.dat",ios::binary|ios::in|ios::out);
obj2.open("bank2.dat",ios::binary|ios::in|ios::out);
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"enter the account no."<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>a;
cout<<endl<<endl<<endl;
while(!obj.eof())
{obj.read((char*)&b,sizeof(b));
l=b.search(a);
if(l==1)
{b1.accept1(a);
obj2.write((char*)&b1,sizeof(b1));
clrscr();
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<endl<<endl<<endl<<"Loan is issued"<<endl;
break;
}
}
if(l==0)
{cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<'\t'<<'\t'<<"account not found"<<endl<<endl<<endl<<endl;
}
obj.close();
obj2.close();


cout<<'\t'<<'\t'<<'\t'<<'\t';
      cout<<”Press any key “<<endl;
      getch();


break;



case 7:

obj2.open("bank2.dat",ios::binary|ios::in);
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<'\t'<<'\t'<<"enter the account no."<<endl<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>a;
cout<<endl<<endl<<endl;
while(!obj2.eof())
{obj2.read((char*)&b1,sizeof(b1));
l=b1.search1(a);
c++;
if(l==1)
{b1.returnl();
obj2.seekp((c-1)*sizeof(b1),ios::beg);
obj2.write((char*)&b1,sizeof(b1));
cout<<"Loan is returned"<<endl;
break;
}
}
if(l==0)
{cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<'\t'<<'\t'<<"Account no not found"<<endl<<endl<<endl;
}
obj2.close();


cout<<'\t'<<'\t'<<'\t'<<'\t';
      cout<<”Press any key “<<endl;
      getch();



break;



case 8:
obj2.open("bank.dat",ios::binary|ios::in|ios::out);
       cout<<'\t'<<'\t'<<'\t'<<'\t';
       cout<<"enter the account no."<<endl<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>a;
cout<<endl<<endl<<endl;
while(!obj2.eof())
{obj2.read((char*)&b1,sizeof(b1));
l=b1.search1(a);
c++;
if(l==1)
{cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<endl<<endl<<endl<<"Enter the new details"<<endl<<endl<<endl;
b1.accept1(a);
obj2.seekp((c-1)*sizeof(b1),ios::beg);
obj2.write((char*)&b1,sizeof(b1));
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Account is modefied"<<endl;
break;
}
}
if(l==0)
{cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<'\t'<<'\t'<<"Account not found"<<endl;
 }
obj2.close();


cout<<'\t'<<'\t'<<'\t'<<'\t';
      cout<<”Press any key “<<endl;
      getch();


break;


case 9:
obj2.open("bank2.dat",ios::binary|ios::in|ios::out);
obj3.open("bank3.dat",ios::binary|ios::in|ios::out);

cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<endl<<endl<<"enter the account no."<<endl<<endl<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>a;
cout<<endl<<endl<<endl;
while(!obj2.eof())
{obj2.read((char*)&b1,sizeof(b1));
l=b1.search1(a);
c++;
if(l==0)
obj3.write((char*)&b1,sizeof(b1));
}
remove ("bank2.dat");
rename ("bank3.dat","bank2.dat");

cout<<'\t'<<'\t'<<'\t'<<'\t';
      cout<<”Press any key “<<endl;
      getch();
break;



       case 10:
obj.open("bank.dat",ios::binary|ios::in);
cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<endl<<endl<<endl<<"enter the account no."<<endl<<endl<<endl<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>a;
while(!obj.eof())
{obj.read((char*)&b,sizeof(b));
l=b.search(a);
c++;
if(l==1)
{obj.seekp((c-1)*sizeof(b),ios::beg);
obj.read((char*)&b,sizeof(b));
b.display();
break;
}
}
if(l==0)
{cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<"Account no not found"<<endl<<endl<<endl<<endl;
 }
obj.close();


cout<<'\t'<<'\t'<<'\t'<<'\t';
      cout<<”Press any key “<<endl;
      getch();


break;


case 11:
obj.open("bank.dat",ios::binary|ios::in);
while(!obj.eof())
{obj.read((char*)&b,sizeof(b));
b.display();

}

break;

case 12:
obj2.open("bank2.dat",ios::binary|ios::in);
 cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<'\t'<<'\t'<<"enter the account no."<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>a;
while(!obj2.eof())
{obj2.read((char*)&b1,sizeof(b1));
l=b1.search1(a);
 c++;
 }
if(l==1)
{ {obj.seekp((c-1)*sizeof(b1),ios::beg);
obj.read((char*)&b1,sizeof(b1));
b1.display1();
break;
}
}
if(l==0)
       cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<'\t'<<'\t'<<"Account no not found"<<endl<<endl<<endl;
obj2.close();


cout<<'\t'<<'\t'<<'\t'<<'\t';
      cout<<”Press any key “<<endl;
      getch();

break;

case 13:
 obj2.open("bank2.dat",ios::binary|ios::in|ios::out);
       cout<<'\t'<<'\t'<<'\t'<<'\t';
cout<<endl<<endl<<endl<<"enter the account no."<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>a;
while(!obj2.eof())
{obj2.read((char*)&b1,sizeof(b1));

b1.display1();


}

obj2.close();

break;






       case 14:
       exit(0);
default:
cout<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<"Wrong choice"<<endl;
 }

       } while(1);
}