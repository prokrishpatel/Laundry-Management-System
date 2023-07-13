#include<iostream>
#include<fstream>
using namespace std;
class registration
{
protected:
int who;
int l_no=0;
char name[100];
int registration_no;
int hostel_no;
int room_no;
char block;
long int mobile_no;
int password;
public:
void input()
{
cout<<"enter the following details for registration\n";    
cout<<"Press 1 If you are Student\n";
cout<<"Press 2 If you are Laundry Man\n";
cin>>who;
if(who==1)
{
 cout<<"Registration No.: ";
 cin>>registration_no;
 cout<<"\nStudent Name: ";
 cin.ignore();
 cin.getline(name,99);
 cout<<"\nHostel_no.: ";
 cin>>hostel_no;
 cout<<"\nBlock Code: ";
 cin>>block;
 cout<<"\nRoom No.: ";
 cin>>room_no;
 cout<<"\nMobile No.: ";
 cin>>mobile_no;
}
}   
void get_register()
{
    registration r1;
    int last_r;
   fstream book;
   book.open("laundary_book",ios::in|ios::binary|ios::ate);
   int loc=(book.tellg()-sizeof(r1));
   book.seekg(loc);
   book.read((char*)&r1,sizeof(r1));
   last_r=r1.l_no;
   l_no=last_r+1;
   book.close();
   book.open("laundary_book",ios::app|ios::binary);
   book.write((char*)this,sizeof(*this));
   book.close();
   cout<<"Congratulations!! your are succfully registred your laundary no is "<<l_no<<"\n please do not forgot it\n";
}
void set_pass()
{
    int repin;
    cout<<"\nPlease set a strong password to protect your Laundry Account\nyour laundary number will be your user name\n";
    cout<<"Password: ";
    cin>>password;
    cout<<"\nConform Password: ";
    cin>>repin;
    while(password!=repin)
    {
        cout<<"\npassword AND repin and not match try again\n";
        cout<<"Password: ";
        cin>>password;
        cout<<"\nConform Password: ";
        cin>>repin;
    }
    cout<<"\nYour Password saved succfully\n";
    
}

};
class login: protected registration
{
  int pin;
  int lnumber;
  public:
  login(){
      cout<<"Welcome Back\nPlease Enter the requared creadentials";
      cout<<"\nLaundary Number: ";
      cin>>lnumber;
      cout<<"\nPassword : ";
      cin>>pin;
      }
    int check()
    {
        registration r;
        fstream check_book
        int i=0,c=0;
        check_book.open("laundary_book",ios::in|ios::ate|ios::binary);
        int tobject=(check_book.tellg)/(sizeof(r));
        while(c!=1)
        {   
            if(lnumber==l_no&&pin==password)
            {
               c=1;
               
            }
        }
    }
  
};
int main()
{
int who,x;
cout<<"Welcome To Lundary Managment System\n";
cout<<"press 1 for login\n";
cout<<"press 2 for Registration\n";
cin>>x;
/*if(x==1)//login
{
cout<<"Press 1 If you are Student\n";
cout<<"Press 2 If you are Laundry Man\n";
cin>>who;
if(who==1)
{
 
}
else if(who==2)
{

}
}*/
if(x==2)//registration
{
registration s1;
s1.input();
s1.get_register();
s1.set_pass();
}

}


