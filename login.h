#include<iostream>
using namespace std;
#include<stdlib.h>
#include<fstream>
#include"movie.h"
#include "user.h"
#include "seat.h"
#include "show.h"
#include "hall.h"

void mainMenu(string cusern);



void manageUser(string cusern){

 int n;
 char ch;

 RegisterUser user;

do{
  system("clear");
   cout<<"**********************************************************Multiplxer**************************************************\n\n\n\n";
 
  cout<<"WELCOME ADMIN : "<<cusern<<endl;
   cout<<endl;
  cout<<endl;
   cout<<endl;
  cout<<endl;

   cout<<"1.ADD USER \n";
   cout<<"2.UPDATE USER \n";
   cout<<"3.DELETE USER\n";
   cout<<"4.SHOW PARTICULAR USER\n";
   cout<<"5.SHOW ALLL USERS\n";
 cout<<"6.Go To Menu\n\n\n";

   cout<<"\nPress Any Integer Key\n";
    cin>>n;
   
  

   cout<<"\n\n";
   switch(n){
    case 1: user.adduser(); break;
    case 2: user.updateuser(); break;
    case 3: user.deluser(); break;
    case 4: user.showcuser(); break;
    case 5: 
            system("clear");
            cout<<"**************************************************Multiplxer***********************************************************\n\n\n\n";
            cout<<"WELCOME ADMIN : "<<cusern<<endl;
            user.showuser();break;

    case 6:mainMenu("admin");
             break;
    default: cout<<"invalid input\n";

   }

cout<<"\n\nTry Again with Y/N  : ";
cin>>ch;
}while(ch=='y'||ch=='Y');

cout<<"                                                   HAVE NICE DAY! SEE YOU SOON        \n\n\n\n\n";




 }


void manageHall(string cusern){

system("clear");
   cout<<"**********************************************************Multiplxer**************************************************\n\n\n\n";
 
  cout<<"WELCOME ADMIN : "<<cusern<<endl;
   cout<<endl;
  cout<<endl;
   cout<<endl;
  cout<<endl;

int choice=0;
	do
	{

	cout<<"1.Add Hall"<<endl;
	cout<<"2.Update Hall"<<endl;
	cout<<"3.Delete Hall"<<endl;
	cout<<"4.list Hall"<<endl;
	cout<<"5.List All Halls"<<endl;
	cout<<"6.BACK TO MAINMENU"<<endl;
	cout<<"\nenter ur choice:"<<endl;
	cin>>choice;

switch(choice)
{
case 1:
	cout<<"Enter a hall to add"<<endl;
		addHall();
		break;

case 2:
	cout<<"Update Hall"<<endl;
	updateHall();
	break;
case 3:
	cout<<"Delete Hall"<<endl;
	deleteHall();
	break;
case 4:
	cout<<"List Hall"<<endl;
	listHall();
	break;

case 5:
	cout<<"List All Hall"<<endl;
	listAllHall();
	break;
case 6:
	    mainMenu("admin");
	break;
default:cout<<"invalid"<<endl;	
}

}while(choice>=1 && choice<=6);
	cout<<"u entered an invalid number"<<endl;


}


void manageSeat(string cusern){

system("clear");
   cout<<"**********************************************************Multiplxer**************************************************\n\n\n\n";
 
  cout<<"WELCOME ADMIN : "<<cusern<<endl;
   cout<<endl;
  cout<<endl;
   cout<<endl;
  cout<<endl;

 int choice;
 char check;
do{
		
		cout << "1.ADD SEAT" << endl;
		cout << "2.UPDATE SEAT" << endl;
		cout << "3.DELETE SEAT" << endl;
		cout << "4.LIST SEAT" << endl;
		cout << "5.LIST ALL SEATS" << endl;
		cout << "6.BCAK TO MAIN Menu" << endl;
		cout << "\nenter your choice" << endl;
	    cin >> choice;
	
	switch(choice)
	{
		
	
		case 1:
			cout << "1.ADD SEAT" << endl;
			addseat();
			break;

		case 2:
			cout << "2.UPDATE SEAT" << endl;
			updateseat();
			break;
	
		case 3:
			cout << "3.DELETE SEAT" << endl;
			deleteseat();
			break;

		case 4:
			cout << "4.LIST SEAT" << endl;
			listseat();
			break;
	
		case 5:
			cout << "5.LIST ALL SEATS" << endl;
			listallseats();
			break;

		case 6:
			     mainMenu(cusern);
			break;
	}

	cout<<"Do want to run again Y/N"<<endl;
	cin>>check;
	}while(check=='y'||check=='Y');



}


void manageMovies(string cusern){

system("clear");
   cout<<"**********************************************************Multiplxer**************************************************\n\n\n\n";
 
  cout<<"WELCOME ADMIN : "<<cusern<<endl;
   cout<<endl;
  cout<<endl;
   cout<<endl;
  cout<<endl;


 int choice=0;
	do
	{
	cout<<"1.Add Movies"<<endl;
	cout<<"2.Update Movies"<<endl;
	cout<<"3.Delete Movies"<<endl;
	cout<<"4.List Movies"<<endl;
	cout<<"5.List Movie All"<<endl;
	cout<<"6.Go To Menu"<<endl;
	cout<<"\nenter  our choice"<<endl;
		cin>>choice;
	 switch(choice)
	{
	case 1:addMovies();
	     cout<<"Movie Added successfully"<<endl;
		break;
	case 2:updateMovie();
	     cout<<"Movie Updated successfully"<<endl;
		break;
	case 3:deleteMovie();
		break;
	case 4:listMovies();
	      cout<<"Movie List"<<endl;
		break;
	case 5:listallMovies();
	     cout<<"List All Movies"<<endl;
		break;
   case 6:mainMenu("admin"); break;
	}
}
while(choice>=1 &&choice<=5);

   }


 void  manageShow(string cusern){


system("clear");
   cout<<"**********************************************************Multiplxer**************************************************\n\n\n\n";
 
  cout<<"WELCOME ADMIN : "<<cusern<<endl;
   cout<<endl;
  cout<<endl;
   cout<<endl;
  cout<<endl;


int ch;
	do
	{

		cout<<"1.Add Show:"<<endl;
		cout<<"2.Delete Show:"<<endl;
		cout<<"3.Update Show:"<<endl;
		cout<<"4.List Show:"<<endl;
		cout<<"5.List All Show:"<<endl;
		cout<<"6.BACK TO MAIN:"<<endl;
		cout<<"\nenter a valid choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"1.Add Shows:"<<endl;
				addshows();
				break;
			case 2:
				cout<<"2.Delete Shows:"<<endl;
				deleteshows();
				break;
			case 3:
				cout<<"3.Update Shows:"<<endl;
				updateshows();
				break;
			case 4:
				cout<<"4.List Shows"<<endl;
				listshows();
				break;
			case 5:
				cout<<"5.List All Shows"<<endl;
				listallshows();
				break;
			case 6:
				cout<<"6.BACK TO MAIN"<<endl;
				mainMenu("admin");
				break;
		}
	}while(ch>=1&&ch<=6);




 }


void mainMenu(string cusern){

system("clear");
   cout<<"**********************************************************Multiplxer**************************************************\n\n\n\n";
 
  cout<<"WELCOME ADMIN : "<<cusern<<endl;
   cout<<endl;
  cout<<endl;
   cout<<endl;
  cout<<endl;

int n;
char ch;
   
do{
  

  	cout<<"1.Manage Users"<<endl;
	cout<<"2.Manage Show"<<endl;
	cout<<"3.Manage Movies"<<endl;
	cout<<"4.Manage Hall"<<endl;
	cout<<"5.Manage Seat"<<endl;
	cout<<"6.EXIT"<<endl;

   cout<<"\nPress Any Integer Key\n";
    cin>>n;
   
  

   cout<<"\n\n";
   switch(n){
    case 1: manageUser("admin"); break;
    case 2: manageShow("admin"); break;
    case 3: manageMovies("admin"); break;
    case 4: manageHall("admin"); break;
    case 5: manageSeat("admin"); break;

    case 6:cout<<"                                                   HAVE NICE DAY! SEE YOU SOON        \n\n\n\n\n";
            exit(0); break;
    default: cout<<"invalid input\n";

   }

cout<<"\n\nTry Again with Y/N IN MAIN MENU  : ";
cin>>ch;
}while(ch=='y'||ch=='Y');

cout<<"                                                   HAVE NICE DAY! SEE YOU SOON        \n\n\n\n\n";



}


void login()
{
	
   system("clear");
   cout<<"*****************************************************Multiplxer*******************************************************\n\n\n\n";

    string cusern,cuserp;

   int adm=0;

	cout<<"Enter username : ";
	cin>>cusern;

	cout<<"Enter Password : ";
	cin>>cuserp;



 if("admin"==cusern && "password"==cuserp){
    adm++;
    
  }



if(adm==1){
  
  mainMenu(cusern);

}else{
  cout<<"USERNAME AND Password not Match\n";
}

}
