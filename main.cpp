#include <iostream>  // created by kishan haldar
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;
#include "user.h"




int main(){

   system("clear");
   cout<<"*****************************************************Multiplxer*******************************************************\n\n\n\n";

   int n;
   char ch;
    int adm=0,usr=0;
    string usern,usert,userp,cusern,cusert,cuserp;

   RegisterUser user;

    ifstream ifs;
	ifs.open("userdetail.txt");

	cout<<"Enter username : ";
	cin>>cusern;

	cout<<"Enter Password : ";
	cin>>cuserp;


	while(ifs.read((char *)&user,sizeof(user))){

       usern=user.getUserName();
       usert=user.getuserType();
    
       userp=user.getPassword();
        
        if(cusern==usern && cuserp==userp && usert=="Admin")
         {
               adm++;
              break;
            }

if(cusern==usern && cuserp==userp && usert=="User"){
    usr++;
    break;
  }
}



 if("admin"==cusern && "password"==cuserp){
    adm++;
    
  }


if(adm==1){
   
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
   cout<<"4.SHOW CURRENT USER\n";
   cout<<"5.SHOW USER\n";
   cout<<"6.EXIT\n\n\n";

   cout<<"Press Any Integer Key\n";
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

    case 6:cout<<"                                                   HAVE NICE DAY! SEE YOU SOON        \n\n\n\n\n";
            exit(0); break;
    default: cout<<"invalid input\n";

   }

cout<<"\n\nTry Again with Y/N  : ";
cin>>ch;
}while(ch=='y'||ch=='Y');

cout<<"                                                   HAVE NICE DAY! SEE YOU SOON        \n\n\n\n\n";


}else if(usr==1){
 system("clear");
   cout<<"********************************************************Multiplxer***********************************************************\n\n\n\n";
 
  cout<<"WELCOME USER : "<<usern<<endl;
   cout<<endl;
  cout<<endl;
   cout<<endl;
  cout<<endl;

}else{
  cout<<"USERNAME AND Password not Match\n";
}


/*
   
*/	
ifs.close();


}