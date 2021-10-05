class seat
{
	int seatid;
	char seattype[30];
	double seatfare;
	int noofseats;
	char farebasis[30];

	public:
   
	int getSeatid();
	char* getSeattype();
	double getSeatfare();
	int getNoofseats();
	char* getFarebasis();
	void setSeatId(int seatid);
	void setSeatType(char seattype[]);
	void setSeatfare(double seatfare);
	void setNoofseats(int noofseats);
	void setFarebasis(char farebasis[]);
};

int seat::getSeatid()
{
	return seatid;
}
char* seat::getSeattype()
{
	return seattype;
}
double seat::getSeatfare()
{
	return seatfare;
}
int seat::getNoofseats()
{
	return noofseats;
}
char* seat::getFarebasis()
{
	return farebasis;
}
void seat::setSeatId(int seatid)
{
	this->seatid=seatid;
}
void seat::setSeatType(char seattype[])
{
	strcpy(this->seattype,seattype);
}
void seat::setSeatfare(double seatfare)
{
	this->seatfare=seatfare;
}
void seat::setNoofseats(int noofseats)
{
	this->noofseats=noofseats;
}
void seat::setFarebasis(char farebasis[])
{
	strcpy(this->farebasis,farebasis);
}



void addseat()
{
	ofstream ofs("seats.data",ios::app);
	seat s;
	int seatid;
	char seattype[30];
	double seatfare;
	int noofseats;
	char farebasis[30];

		cout << "enter the seat id" << endl;
		cin >> seatid;
		s.setSeatId(seatid);
		
		cout << "enter the seat type" << endl;
		cin >> seattype;
		s.setSeatType(seattype);

		cout << "enter seat fare" << endl;
		cin >> seatfare;
		s.setSeatfare(seatfare);
	
		cout << "enter no of seats" << endl;
		cin >> noofseats;
		s.setNoofseats(noofseats);

		cout << "enter farebasis" << endl;
		cin >> farebasis;
		s.setFarebasis(farebasis);

		ofs.write((char *)&s,sizeof(s));

		ofs.close();
}


void updateseat()
{
	fstream fs("seats.data",ios::in|ios::out);
	seat s;
	int seatid;
	int f=0;
	cout << "ENTER THE SEAT ID" << endl;
	cin >> seatid ;
	char choice1=' ';
	int pos=0;
	while (fs.read((char *)&s,sizeof(s)))
	{
		if (seatid==s.getSeatid())
		{
			f=1;
			int seat_id;
			double seatfare;
			cout << "DO YOU WANT TO ENTER SEAT FARE" << endl;
			cout << "press Y/N" << endl;
			cin>>choice1;
			if(choice1=='y')
			{
				cout << "enter the seat fare";
				cin >> seatfare;
				s.setSeatfare(seatfare);
				cin.ignore();
			}
			fs.seekp(pos);
			fs.write((char*)&s,sizeof(s));
			break;	
		}
		pos=fs.tellg();
	}
	if(f==0)
	{
		cout << "sorry!!!!!!!!!!!!" ;
		cout << "specified record doesnt exist" << endl;
	}
	fs.close();
}
			

void deleteseat()
{
	int seatid;
	cout << "enter seat id" << endl;
	cin >> seatid;
	ofstream ofs;
	ofs.open("newseat.data");
	ifstream ifs;
	ifs.open("seats.data");
	seat s;
	while(ifs.read((char *)&s,sizeof(s)))
	{
		if (seatid!=s.getSeatid())
		{
			ofs.write((char*)&s,sizeof(s));
		}
	}
if(seatid!=s.getSeatid()){
		cout<<"\n\nno record found\n\n"<<endl;
      }      
      else{
      	cout<<"\n\nSeat Deleted successfully\n\n"<<endl;
      }

rename("newseat.data","seats.data");
ifs.close();
ofs.close();
}
	
void listseat()
{
	seat s;
	int seatid;
	char seattype[30];
	double seatfare;
	int noofseats;
	char farebasis[30];

	cout << "enter seat id" << endl;
	cin >> seatid;
	cout << "seat id" << endl;
	cout << "seat type" << endl;
	cout << "seat fare " << endl;
	cout << "no of seats" << endl;
	cout << "fare basis " << endl;

	ifstream ifs("seats.data");
	while(ifs.read((char *)&s,sizeof(s)))
	{
	cout<<"SeatId"<<"\t"<<"SeatType"<<"\t"<<"SeatFare"<<"\t"<<"NoOfSeats"<<"\t"
	<<"FareBasis"<<endl;
		if (seatid==s.getSeatid())
		{
		cout << ""<<s.getSeatid() << "\t";
		cout << ""<<s.getSeattype() << "\t"<<"\t";
		cout << ""<<s.getSeatfare() << "\t"<<"\t";
		cout << ""<<s.getNoofseats() <<"\t"<<"\t";
		cout << ""<<s.getFarebasis() << "\n";
		break;
		}
	}
	ifs.close();
}



void listallseats()
{
	seat s;
	int seatid;
	char seattype[30];
	double seatfare;
	int noofseats;
	char farebasis[30];

	ifstream ifs;
	ifs.open("seats.data");
	cout<<"SeatId"<<"\t"<<"SeatType"<<"\t"<<"SeatFare"<<"\t"<<"NoOfSeats"<<"\t"
	<<"FareBasis"<<endl;
	while(ifs.read((char *)&s,sizeof(s)))
	{
		cout << ""<<s.getSeatid() << "\t";
		cout << ""<<s.getSeattype() << "\t"<<"\t";
		cout << ""<<s.getSeatfare() << "\t"<<"\t";
		cout << ""<<s.getNoofseats() <<"\t"<<"\t";
		cout << ""<<s.getFarebasis() << "\n";
	}
	ifs.close();		

	
}