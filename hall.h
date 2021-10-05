class hall
{
	int hall_id;
	char hall_name[30];
	//seat *hall_seats;

	int noOfSeatTypes;
	
	public:
	int getHallId();
	char* getHallName();
	int getNoOfSeatTypes();
	//seat* getHallSeats();
	void setHallId(int hall_id);
	void setHallName(char* hall_name);
	void setNoOfSeatTypes(int noOfSeatTypes);
	//void setHallSeats(seat hall_seats[]);
};

int hall::getHallId()
{
	return hall_id;
}

char* hall::getHallName()
{
	return hall_name;
}

int hall::getNoOfSeatTypes()
{
	return noOfSeatTypes;
}

void hall:: setHallId(int hall_id)
{
	this->hall_id=hall_id;
}


void hall::setHallName(char* hall_name)
{
	strcpy(this->hall_name,hall_name);
}

void hall::setNoOfSeatTypes(int noOfSeatTypes)
{
	this->noOfSeatTypes=noOfSeatTypes;
}

	

void addHall()
{

	ofstream ofs("halls.data",ios::app);
	hall h;
	int hall_id;
	char hall_name[30];
	int noOfSeatTypes;
	
		cout<<"enter the hallId:"<<endl;
		cin>>hall_id;
		h.setHallId(hall_id);
	cin.ignore();

		cout<<"enter the hall name:"<<endl;
		cin.getline(hall_name,30);
                h.setHallName(hall_name);

		cout<<"enter the no of seattypes:"<<endl;
		cin>>noOfSeatTypes;
		h.setNoOfSeatTypes(noOfSeatTypes);
		ofs.write((char *)&h,sizeof(h));

	ofs.close();
}

void updateHall()
{

fstream fs("halls.data",ios::in|ios::out);
hall h;
int f=0;
int hall_id;
cout<<"enter the hall id"<<endl;
cin>>hall_id;
char choice1=' ';
int pos=0;

while(fs.read((char *)&h,sizeof(h)))
{
if(hall_id==h.getHallId())
{
f=1;

int hall_id;
char hall_name[30];
int noOfSeatTypes;

cout<<" do u want to edit name"<<endl;
cout<<"press y/n";
cin>>choice1;
if(choice1=='y')
{
cout<<"enter the hall name:  "<<endl;
cin.ignore();
cin.getline(hall_name,30);
h.setHallName(hall_name);
}


cout<<"do u want  to edit no of seats  "<<endl;
cout<<"press y/n";
cin>>choice1;
if(choice1=='y')
{
cout<<"enter the no of seats:  "<<endl;
cin.ignore();
cin >> noOfSeatTypes;
h.setNoOfSeatTypes(noOfSeatTypes);
}


fs.seekp(pos);
fs.write((char *)&h,sizeof(h));
break;
}
pos=fs.tellg();
}
if(f=0)
{
cout<<"sorry!!!"<<endl;
cout<<"specified record doesnt exit.."<<endl;
}
fs.close();

}																					
void deleteHall()
{
	hall h;
	int hall_id;
	ofstream ofs;
	cout<<"enter hall_id"<<endl;
	cin>>hall_id;
	ofs.open("newhall.data",ios::out);
	ifstream ifs;
	
	ifs.open("halls.data",ios::in);
	while(ifs.read((char *)&h,sizeof(h)))
	{
		if(hall_id!=h.getHallId())
		ofs.write((char *)&h,sizeof(h));
	}

  if(hall_id!=h.getHallId()){
		cout<<"\n\nno record found\n\n"<<endl;
      }      
      else{
      	cout<<"\n\nHall Deleted successfully\n\n"<<endl;
      }


	ifs.close();
	ofs.close();
	rename("newhall.data","halls.data");

}

void listAllHall()
{
	hall h;
	int hall_id;
	char hall_name[30];
	int noOfSeatTypes;
	ifstream ifs;
	ifs.open("halls.data");
	
	while(ifs.read((char *)&h,sizeof(h)))
	{
		cout<<h.getHallId()<<"\t";
		cout<<h.getHallName()<<"\t";
		cout<<h.getNoOfSeatTypes()<<"\n";
	}
	ifs.close();
}

void listHall()
{
	int hall_id;
	cout<<"enter hall id"<<endl;
	cin>>hall_id;
	ifstream ifs("halls.data");
	hall h;
	while(ifs.read((char *)&h,sizeof(h)))
	{
		if(hall_id==h.getHallId())
		{
		cout<<h.getHallId()<<"\t";
		cout<<h.getHallName()<<"\t";
		cout<<h.getNoOfSeatTypes()<<"\t";
		break;
		}
	}
}