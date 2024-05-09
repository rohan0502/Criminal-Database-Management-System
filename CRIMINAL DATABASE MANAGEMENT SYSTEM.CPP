#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>

class cbi
{
 


//---------------------
//private data members
//---------------------

long cno; int age;
char name[20]; char gen[10]; char off[20]; char fname[25];

public:

//-------------------
//public data members
//-------------------

//function declaration to enter the records from the user//

void getdata();
 


//function declaration to display records//

void dispdata();



//function to make indirect use of private data member"cno"//

long retcno()
{

return cno;
}





//functions for modifying different categories of a particular record//

void modcno()
{



cout<<"\n enter the new criminal no. : "; cin>>cno;
}
 




void modfname()
{

cout<<"\n enter the new father's name: "; gets(fname);


}

void modcname()
{

cout<<"\ enter the new criminal name: "; gets(name);

}

void modage()
{

cout<<"\ enter the new criminal age: "; cin>>age;
 
}



void modgen()
{

cout<<"\ enter the new criminal gender: "; gets(gen);

}



void modoff()
{

cout<<"\ enter the new criminal offence: "; gets(off);

}



char *retname()
 
{

return name;

}

}c; //'c' is used as the object of class 'cbi'//

// 	
//END OF CLASS DEFINITION//
// 	



void cellprison();	// function prototype

// 	
//function definition to get records from the user
// 	



void cbi::getdata()
{
cellprison();
 
cout<<"\n\n\t\t Please enter the details of the criminal...";

cout<<"\n\n Criminal Number: "; cin>>cno;
cout<<"\n Name: "; gets(name); cout<<"\n Age: "; cin>>age;
cout<<"\n Offence: "; gets(off);
cout<<"\n Gender: "; cin>>gen;
cout<<"\n Father's Name: "; gets(fname);

}



// 	
//function definition to display records to the user
// 	
 
void cbi:: dispdata()
{
cellprison();

cout<<"\n Criminal Number: "<<cno; cout<<"\n Name: "<<name; cout<<"\n Age: "<<age;
cout<<"\n Gender: "<<gen; cout<<"\n Offence: "<<off; cout<<"\n Father's Name: "<<fname;

cout<<"\n\n\t\t\t Press any key to continue!";

getch();
}

// 	
//function to enter records in the file
// 	



void insert()
{
 


clrscr();

fstream fil; fil.open("cbi.dat",ios::app|ios::binary);

char ans;

do
{
clrscr();

c.getdata(); fil.write((char*)&c,sizeof(c));

cout<<"\n\n\t\t Do you want to enter more records(y/n): "; cin>>ans;
}
while(ans=='y'||ans=='Y');

fil.close();
 
}

// 	
//function to display records from the file
// 	



void disp()
{

clrscr();

int f=0;

fstream fil; fil.open("cbi.dat",ios::in|ios::binary);

while(fil.read((char*)&c,sizeof(c)))
{

f=1;
c.dispdata();



}
 




if(f!=1)
cout<<"\n file is empty";

fil.close();

}

// 	
//function to search records from the file
// 	



void search()
{
clrscr();

long cno,ch; char cname[25]; char ans;

fstream fil;
 


do
{
ch=0;
int found=0;

fil.open("cbi.dat",ios::in|ios::binary);

clrscr();
cout<<"\n\t On what basis do you want to search the criminal record	";

cout<<"\n\n\n On the basis of criminal name, enter 1";

cout<<"\n\n On the basis of criminal code, enter 2";

cout<<"\n\n enter your choice: "; cin>>ch;

switch(ch)
{
 
case 1: cout<<"\n criminal name: "; //searching on the basis of criminal name//
gets(cname); while(fil.read((char*)&c,sizeof(c)))
if(strcmpi(c.retname(),cname)==0)
{
clrscr();
c.dispdata(); found=1;
}

if(found!=1)
{
clrscr();
cout<<"\n\n record not found";
}

fil.close();

break;
 
case 2: cout<<"\n criminal number : ";	//searching on the basis of criminal no.//
cin>>cno; while(fil.read((char*)&c,sizeof(c)))
if(c.retcno()==cno)
{
clrscr();
c.dispdata(); found=1;
}

if(found!=1)
{
clrscr();
cout<<"\n record not found";
}

fil.close();

break;

default: cout<<"\n\n You have entered wrong choice";
 
break;



}

cout<<"\n\n\t Do you want to search for any more records(y/n): "; cin>>ans;
}
while(ans=='y'|| ans=='Y');

fil.close();
}



// 	
//function to modify records in the file
// 	



void modify()
{

clrscr();
 
int cno,ch,found; char cname[20]; char ans;

fstream fil;

do
{
found=0,ans=0;

fil.open("cbi.dat",ios::in|ios::out|ios::binary);

clrscr();
cout<<"\n\t On what basis you want to search and modify the criminal record...";
cout<<"\n\n On the basis of criminal name, enter 1"; cout<<"\n\n On the basis of criminal code, enter 2";

cout<<"\n\n\t enter your choice: "; cin>>ch;

switch(ch)
 
{
case 1: //searching and modifying on the basis of name// cout<<"\n enter name: ";
gets(cname);

while(fil.read((char*)&c,sizeof(c))) if(strcmpi(c.retname(),cname)==0)
{
c.dispdata(); found=1;
cout<<"\n are you sure you want to modify this record(y/n): ";
cin>>ans; break;
}

if(ans=='y'|| ans=='Y')
{
do
{
clrscr();
cout<<"\n\t\t What would you like to modify ";
 
cout<<"\n\n for criminal no.,	press 1 "; cout<<"\n\n for criminal name,			press 2 "; cout<<"\n\n for criminal gender,				press 3 "; cout<<"\n\n for criminal offence,			press 4 "; cout<<"\n\n for criminal age,		press 5 "; cout<<"\n\n for criminal father's name, press 6 "; cout<<"\n enter your choice plz: ";
cin>>ch; if(ch==1)
c.modcno(); else if(ch==2)
c.modcname(); else if(ch==3)
c.modgen(); else if(ch==4)
c.modoff(); else if(ch==5)
c.modage(); else if(ch==6)
c.modfname();

else
cout<<"\n\n You have entered the wrong choice";
 


int n=fil.tellg(); fil.seekp(n-sizeof(c));
fil.write((char*)&c,sizeof(c));

cout<<"\n\n\t Do you wish to change any other category(y/n): ";
cin>>ans;
}
while(ans=='y'|| ans=='Y');

cout<<"\n\n\t Do you wish to see the modified record(y/n): "; cin>>ans;
if(ans=='y'| ans=='Y') c.dispdata();
}

if(found!=1)
cout<<"\n record not found";

fil.close(); break;
 


case 2: //searching and modifying on the basis of criminal number//

cout<<"\n criminal no.: "; cin>>(cno); while(fil.read((char*)&c,sizeof(c)))
if(c.retcno()==cno)
{
cout<<"\n Record you have chosen for modification is: "; c.dispdata();
found=1;
cout<<"\n\n\t\t Are you sure you want to modify this record: ";
 

cin>>ans; break;
}
 

if(ans=='y'|| ans=='Y')
{
clrscr();
cout<<"\n\t\t What would you like to modify "; cout<<"\n\n for criminal no.,	press 1 "; cout<<"\n\n for criminal name,		press 2 ";
 
cout<<"\n\n for criminal gender,		press 3 "; cout<<"\n\n for criminal offence,		press 4 "; cout<<"\n\n for criminal age,	press 5 "; cout<<"\n\n for criminal father's name, press 6 ";

do
{
cout<<"\n enter your choice plz: "; cin>>ch;
if(ch==1)
c.modcno(); else if(ch==2)
c.modcname(); else if(ch==3)
c.modgen(); else if(ch==4)
c.modoff(); else if(ch==5)
c.modage(); else if(ch==6)
c.modfname();

else
 
cout<<"\n\n You have entered the wrong choice";

int n=fil.tellg(); fil.seekp(n-sizeof(c));
fil.write((char*)&c,sizeof(c));



cout<<"\n\n\t Do you wish to change any other category(y/n):";
cin>>ans;
}while(ans=='y'|| ans=='Y');

cout<<"\n\n\t\t Do you wish to see the modified record(y/n):";
cin>>ans; if(ans=='y'| ans=='Y') c.dispdata();
}

if(found!=1)
cout<<"\n Record not found!";

fil.close();
 
break;

default: cout<<"\n you have entered wrong choice"; break;
}

cout<<"\n\n\t\t Do you want to modify any more records(y/n): "; cin>>ans;
}
while(ans=='y'|| ans=='Y');

fil.close();
}

// 	
//function to delete records from the file
// 	



void dlt()
{
char ans;
 
fstream fil; fil.open("cbi.dat",ios::in|ios::binary);

ofstream temp; temp.open("temp.dat",ios::out|ios::binary);

int cno,f=0;

cout<<"\n enter the criminal no. whose details are to be deleted: "; cin>>cno;

while(fil.read((char*)&c,sizeof(c)))
{
if(c.retcno()==cno)
{
c.dispdata();
cout<<"\n are you sure you want to delete this record(y/n):";
cin>>ans;
if(ans=='y' || ans=='Y') f=1;
else if(ans=='n' || ans=='N');

}
 
temp.write((char*)&c,sizeof(c));

{
temp.write((char*)&c,sizeof(c)); f=10;
}
 

temp.write((char*)&c,sizeof(c));
}



if(f==1)
cout<<"\n record deleted"; else if(f==10)
cout<<"\n you have entered wrong choice"; else if(f==0)
{}

else
cout<<"\n record not found";

fil.close();
temp.close();
 


remove("cbi.dat"); rename("temp.dat","cbi.dat");

}

// 	
//function to display "cellular prison"
// 	



void cellprison()
{
clrscr(); cout<<endl<<endl;
cout<<"\n\t\t	=======================================";
cout<<"\n\t\t	CELLULAR PRISON	";
cout<<"\n\t\t	=======================================";

cout<<endl<<endl;
}
 
//==============================
//MAIN FUNCTION DEFINITION
//==============================
void main()
{
clrscr(); cout<<endl<<endl<<endl;
cout<<"\n \t\t ** 	**"; cout<<"\n \t\t ** C0102 PROJECT **";
cout<<"\n \t\t ** 	**"; cout<<endl<<endl<<endl<<endl<<endl;
cout<<"\n \t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";

cout<<"\n \t\t *** CREATED BY***";

cout<<"\n \t\t ***	ROHAN SHARMA	***"<<endl;
 
cout<<"\n \t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";

getch();
clrscr();

cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl; cout<<"\n\t\t	***---------------***	***";
cout<<"\n\t\t	*** CRIMINAL DATABASE MANAGEMENT ***"; cout<<"\n\t\t	***---------------***	***";

getch();

cellprison();

int ch; char ans;
char passw[4];

cout<<endl<<endl<<"\t\t\t"<<"If you are ADMIN - PRESS 1"<<endl ; cout<<endl<<endl<<"\t\t\t"<<"If you are GUEST - PRESS 2"<<endl ; cout<<endl<<endl<<"Enter your choice: ";
 
cin>>ch; clrscr() ;

switch(ch)
{
case 1: char a,b,c,d,e; cout<<"\n\n\t\tEnter the Password: " ; a=getch();
cout<<"*"; b=getch(); cout<<"*"; c=getch(); cout<<"*"; d=getch(); cout<<"*"; e=getch(); cout<<"*"; getch();

if(a=='a' && b=='d'&& c=='m' && d=='i' && e=='n')
{
clrscr();
 
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t	WELCOME";


do
{
cellprison();

cout<<"\n\t\t\t Enter 1 to add records "; cout<<"\n\t\t\t Enter 2 to display records "; cout<<"\n\t\t\t Enter 3 to delete records"; cout<<"\n\t\t\t Enter 4 to search records"; cout<<"\n\t\t\t Enter 5 to edit records"; cout<<"\n\t\t\t Enter 6 to exit the program"<<endl; cout<<"\n\t\t\t	Enter your choice: ";
cin>>ch; switch(ch)
{
case 1: insert();
break;

case 2: disp();
break;
 


case 3: dlt();
break;

case 4: search(); break;

case 5: modify(); break;

default: cout<<"\n wrong choice";

}
cout<<"\n\n\t\t Do you want to return to main menu(y/n): ";
cin>>ans;
}
while(ans=='y' || ans=='Y');
 
break;
}



else
{
clrscr();

cout<<"\n\n\n\t\t	Wrong Password...Aborting program!";
}



case 2:
do
{
cellprison();
cout<<"\n\t\t\t Enter 1 to search records"; cout<<"\n\t\t\t Enter 2 to display records"; cout<<"\n\t\t\t Enter 3 to exit the program"<<endl; cout<<"\n\t\t\t	Enter your choice: ";
cin>>ch;
 


switch(ch)
{

case 1: search(); break;

case 2: disp();
break;

default: cout<<"\n Wrong choice";

}

cout<<"\n\n\t\t Do you want to return to main menu(y/n): "; cin>>ans;
}
while(ans=='y' || ans=='Y');
 
break;

default:cout<<"\n\n\t\t Wrong Choice! "; break ;

}

getch();
}

// 	
//END OF MAIN
// 	

