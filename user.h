class RegisterUser{
 
  int userId;
  char userName[30];
  char contactNo[30];
  char email[30];
  char dob[30];
  char password[30];
  char userType[5];


public:

  //static  int count;
	int getUserId();
	char * getUserName();
	char * getContactNo();
	char * getDob();
	char * getEmail();
	char * getPassword();
	//char * getuserType();

	void setUserId(int Id);
	void setUserName(const char userName[]);
	void setContactNo(const char  contactNo[]);
	void setDob(const char dob[]);
	void setEmail(const char email[]);
	void setPassword(const char password[]);
	//void setuserType(const char userType[]);

	void adduser();
  void updateuser();
	void deluser();
  void showcuser();
	void showuser();



};


void RegisterUser::adduser(){
 int type;
 char userType[30];
 char userName[30];
  char contactNo[30];
  char email[30];
  char dob[30];
  char password[30];
   char cpassword[30];
  RegisterUser user;
int id=0;
ifstream ifs("userdetail.txt");
while(ifs.read((char*)&user,sizeof(user))){
	id=user.getUserId();
}

id++;
ifs.close();

  ofstream ofs("userdetail.txt",ios::app);

    //userID
    user.setUserId(id);

    
	
	cout<<"Enter Username:"<<endl;
	cin>>userName;
	user.setUserName(userName);
	
	cout<<"Enter contact No:"<<endl;
	cin>>contactNo;
	user.setContactNo(contactNo);

    cout<<"Enter Date of Birth:"<<endl;
	cin>>dob;
	user.setDob(dob);	

//Email Id
  string str;
  int pos;

do{
	cout<<"Enter Email Id:"<<endl;
	cin>>email;

	str=string(email);

    pos=str.find("@");
	if(pos>=0){
     	user.setEmail(email);
	}
	
 }while(pos<=0);
    
//password
    do{

     cout<<"Enter password:"<<endl;
	cin>>password;
	

	 cout<<"Enter Confirm password:"<<endl;
    
	cin>>cpassword;

	if(strcmp(password,cpassword)==0){
		user.setPassword(password);
		cout<<"Succesfully added \n";
	}
	else{
		cout<<"please enter again same password\n";
	}
}while(strcmp(password,cpassword)!=0);


	ofs.write((char *)&user,sizeof(user));
    ofs.close();

}


void RegisterUser::showuser(){

            cout<<"\n\n\n\n";
            cout<<"************************************************* User Details ******************************************************\n";
            cout<<setw(4)<<"user Id:";
     //     cout<<setw(12)<<"user Type:";
         cout<<setw(15)<<"username:";
           cout<<setw(15)<<"MobileNo:";
          cout<<setw(15)<<"DOB:";
          cout<<setw(30)<<"Email id:";
          cout<<setw(20)<<"Password:\n";
          cout<<"\n";

 RegisterUser user;
    ifstream ifs;
	ifs.open("userdetail.txt");


	while(ifs.read((char *)&user,sizeof(user))){
	cout<<setw(4)<<user.getUserId();
//	cout<<setw(12)<<user.getuserType();
	cout<<setw(18)<<user.getUserName();
	cout<<setw(15)<<user.getContactNo();
	cout<<setw(15)<<user.getDob();
	cout<<setw(30)<<user.getEmail();
	cout<<setw(20)<<user.getPassword();
	cout<<endl;

}
	ifs.close();

}


void RegisterUser::updateuser(){


 
  char check;
  int type;
 char userType[30];
 char userName[30];
  char contactNo[30];
  char email[30];
  char dob[30];
  char password[30];
   char cpassword[30];

   int userid,id;
   
   RegisterUser user;

   RegisterUser user1;

    ifstream ifs;
  
   int count=0;



   int cuser;

  ifstream myifs;
  myifs.open("userdetail.txt");
  while(myifs.read((char *)&user,sizeof(user))){

       cuser=user.getUserId();

   }

  myifs.close(); 

  ifs.open("userdetail.txt");
  ofstream wifs("myuserdetail.txt");


  cout<<"Enter the Id number you want to updated\n";
  cin>>id;

   if(id>=0 && id <= cuser){

  while(ifs.read((char *)&user,sizeof(user))){

       userid=user.getUserId();
      
        if(userid==id){
        
        user1.setUserId(id);
   
	

   cout<<"Do yo want update Username : \n";
   cin>>check;

   if(check=='y'||check=='Y'){
	cout<<"Enter Username:"<<endl;
	cin>>userName;
	user1.setUserName(userName);
}else
{
	user1.setUserName(user.getUserName());
}
	

   cout<<"Do yo want update contact No : \n";
   cin>>check;

   if(check=='y'||check=='Y'){
	cout<<"Enter contact No:"<<endl;
	cin>>contactNo;
	user1.setContactNo(contactNo);
}else
{
	user1.setContactNo(user.getContactNo());
}


    
   cout<<"Do yo want update Date of Birth : \n";
   cin>>check;

   if(check=='y'||check=='Y'){
    cout<<"Enter Date of Birth:"<<endl;
	cin>>dob;
	user1.setDob(dob);	
  }
  else{
  		user1.setDob(user.getDob());	
  }
//Email Id
  

   cout<<"Do yo want update email id : \n";
   cin>>check;

   if(check=='y'||check=='Y'){

  string str;
  int pos;

do{
	cout<<"Enter Email Id:"<<endl;
	cin>>email;

	str=string(email);

    pos=str.find("@");
	if(pos>=0){
     	user1.setEmail(email);
	}
	
 }while(pos<=0);
    }else{

    	user1.setEmail(user.getEmail());
    }
//password
     

   cout<<"Do yo want update password : \n";
   cin>>check;

   if(check=='y'||check=='Y'){

    
    do{

     cout<<"Enter password:"<<endl;
	cin>>password;
	

	 cout<<"Enter Confirm password:"<<endl;
    
	cin>>cpassword;

	if(strcmp(password,cpassword)==0){
		user1.setPassword(password);
		cout<<"Succesfully added \n";
	}
	else{
		cout<<"please enter again same password\n";
	}
}while(strcmp(password,cpassword)!=0);
}else{

	user1.setPassword(user.getPassword());
}


 wifs.write((char *)&user1,sizeof(user1));

         }
         else
         {
       
       user1.setUserId(user.getUserId());
       //user1.setuserType(user.getuserType());
       user1.setUserName(user.getUserName());
       user1.setContactNo(user.getContactNo());
       user1.setDob(user.getDob());
       user1.setEmail(user.getEmail());
       user1.setPassword(user.getPassword());
       wifs.write((char *)&user1,sizeof(user1));
         }
   
}
rename( "myuserdetail.txt" ,"userdetail.txt" );
 
 cout<<"This Id No. "<<id<<" is Succesfully Updated\n";

ifs.close();
wifs.close();
}
else{
  cout<<"\nNOT RECORD FOUND!!\n";
}

}






void RegisterUser::showcuser(){
 RegisterUser user;

ifstream ifs("userdetail.txt");
  cout<<"enter the record no. "<<endl;
  int recono;
  cin>>recono;
 //tellg
  long pos=(recono-1)*sizeof(RegisterUser);
  ifs.seekg(pos,ios::beg); //seek get and seek p
  ifs.read((char*)&user,sizeof(user));

 cout<<"************************************************* User Details ******************************************************\n";
            cout<<setw(4)<<"user Id:";
         // cout<<setw(12)<<"user Type:";
         cout<<setw(15)<<"username:";
           cout<<setw(15)<<"MobileNo:";
          cout<<setw(15)<<"DOB:";
          cout<<setw(30)<<"Email id:";
          cout<<setw(20)<<"Password:\n";
          cout<<"\n";

 cout<<setw(4)<<user.getUserId();
 // cout<<setw(12)<<user.getuserType();
  cout<<setw(18)<<user.getUserName();
  cout<<setw(15)<<user.getContactNo();
  cout<<setw(15)<<user.getDob();
  cout<<setw(30)<<user.getEmail();
  cout<<setw(20)<<user.getPassword();
  cout<<endl;

  ifs.close();

}


void RegisterUser::deluser(){

   int userid,id;
   
   RegisterUser user;

   RegisterUser user1;

    ifstream ifs;
  
   int count=0;


    int cuser;

  ifstream myifs;
  myifs.open("userdetail.txt");
  while(myifs.read((char *)&user,sizeof(user))){

       cuser=user.getUserId();

   }

  myifs.close(); 
	

	ifs.open("userdetail.txt");
	ofstream wifs("myuserdetail.txt");




	cout<<"Enter the Id number you want to deleted\n";
	cin>>id;


    if(id>=0 && id <= cuser){

	while(ifs.read((char *)&user,sizeof(user))){

       userid=user.getUserId();
      
        if(userid!=id){
       	 user1.setUserId(++count);
	     //user1.setuserType(user.getuserType());
	     user1.setUserName(user.getUserName());
	     user1.setContactNo(user.getContactNo());
	     user1.setDob(user.getDob());
         user1.setEmail(user.getEmail());
	     user1.setPassword(user.getPassword());
	     wifs.write((char *)&user1,sizeof(user1));
         }
   
}
rename( "myuserdetail.txt" ,"userdetail.txt" );
 
 cout<<"This Id No. "<<id<<" is Succesfully deleted\n";

ifs.close();
wifs.close();
}
else{
  cout<<"\nNO RECORD FOUND!!\n";
}

}

 

int RegisterUser::getUserId(){
	return userId;
}


char * RegisterUser::getUserName(){
 return userName;
}

char * RegisterUser::getContactNo(){
	return contactNo;
}

char * RegisterUser::getDob(){
	return dob;
}

char * RegisterUser::getEmail(){
	return email;

}
	
char * RegisterUser::getPassword(){
  return password;
}


void RegisterUser::setUserId(int Id){
	this->userId=Id;
}


void RegisterUser::setUserName(const char userName[]){
	strcpy(this->userName,userName);
}
	
void RegisterUser::setContactNo(const char  contactNo[]){
	strcpy(this->contactNo,contactNo);
}
	
void RegisterUser::setDob(const char dob[]){
	strcpy(this->dob,dob);
}
	

void RegisterUser::setEmail(const char email[]){
	strcpy(this->email,email);
}

void RegisterUser:: setPassword(const char password[]){
	strcpy(this->password,password);
}
