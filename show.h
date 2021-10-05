class shows
{
	int showId;
	char showDate[30];
	char showTime[30];
	//Hall showHall;
	//Movie showMovie;
	public:
	int getShowId();
	char* getShowDate();
	char* getShowTime();
	//Hall getShowHall();
	//Movie getShowMovie();
	void setShowId(int showId);
	void setShowDate(const char showDate[]);
	void setShowTime(const char showTime[]);
	//void setShowHall(Hall showHall);
	//void setShowMovie(Movie showMovie);
};

int shows::getShowId()
{
	return showId;
}
char* shows::getShowDate()
{
	return showDate;
}
char* shows::getShowTime()
{
	return showTime;
}
/*Hall shows::getShowHall()
{
	return showHall;
}
Movie shows::getShowMovie()
{
	return showMovie;
}*/

void shows::setShowId(int showId)
{
	// include condition to check only valid int.s are entered & no char is inserted.

	this->showId=showId;
}
void shows::setShowDate(const char showDate[])
{
	strcpy(this->showDate,showDate);
}
void shows::setShowTime(const char showTime[])
{
	strcpy(this->showTime,showTime);
}
/*void setShowHall(Hall showHall)
{
	this->showHall=showHall;
}
void setShowMovie(Movie showMovie)
{
	this->showMovie=showMovie;
}*/


void addshows()
{
	
	shows s;
	int showId;
	char showDate[30];
	char showTime[30];

    ofstream ofs("show.data",ios::app);  	// ofstream file object, to be needed for outputting the data input by the user.

		cout << "enter the show id"<< endl;
		cin>>showId;
		cin.ignore();
		s.setShowId(showId);

		cout<< " enter the show date (dd-mm-yyyy) : " << endl; 
		cin.getline(showDate,30);
		s.setShowDate(showDate);
		//cin.ignore();

		cout<< " enter the show time (Morn, Noon or Eve) : " << endl;
		cin.getline(showTime,30);
		s.setShowTime(showTime);
	
				// Closing the ofstream file, ofstream file is for outputting data.

cout<<"\nSuccessfully Added\n";
ofs.write((char*)&s,sizeof(s));	
ofs.close();

}

void deleteshows()
{
	shows s;
	ofstream ofs;
	int showId;
	cout << " enter Show id " <<endl;
	cin>> showId;
	ofs.open("show1.data",ios::out);
	ifstream ifs;
	ifs.open("show.data",ios::in);
	while(ifs.read((char*)&s,sizeof(s)))
	{
		if(showId!=s.getShowId())
			ofs.write((char*)&s,sizeof(s));
	}
	ifs.close();
	ofs.close();
	rename("show1.data","show.data");
}

void updateshows()
{
  fstream fs("show.data",ios::in|ios::out);
  shows s;
  int showId;
  int f=0;
  cout<<"enter show id"<<endl;
  cin>>showId;
  char choice=' ';
  int pos=0; 
  while(fs.read((char *)&s,sizeof(s)))
  {
    if(showId==s.getShowId())
    {
 	f=1;
     	char showDate[30];
	char showTime[30];
	cout<<"do you want to edit date"<<endl;
        cout<<"y/n"<<endl;
   	cin>>choice;
	if(choice=='y')
	{
	  cout<<"enter the show date"<<endl;
	  cin.ignore();
	  cin.getline(showDate,30);
	  s.setShowDate(showDate);
	}
	
	cout<<"do you want to edit seat count"<<endl;
	cout<<"y/n"<<endl;
	cin>>choice;
	if(choice=='y')
	{
	  cout<<"enter the show time"<<endl;
	  cin.ignore();
	  cin.getline(showTime,30);
	  s.setShowTime(showTime);
	}
	
	fs.seekp(pos);
	fs.write((char *)&s,sizeof(s));
	break;
      }
	pos=fs.tellg();
     }
   if(f==0)
  {
    cout<<"sorry!!!!";
    cout<<"SPECIFIED RECORD DOESNOT EXIST"<<endl;
  }
    fs.close();
}

void listshows()
{
	int showId;
	cout << " enter show id" <<endl;
	cin>>showId;
	ifstream ifs("show.data");
	shows s;
	while(ifs.read((char*)&s,sizeof(s)))
	{
		if(showId==s.getShowId())
		{
			cout<< s.getShowId()<<"\t";
			cout<< s.getShowTime()<<"\t";
			cout<< s.getShowDate()<<"\n";
                        break;
              } 
         }
}

void listallshows()
{
	shows s;
	int showId;
	ifstream ifs;
	ifs.open("show.data");
	while(ifs.read((char*)&s,sizeof(s)))
	{
		cout << s.getShowId()<< "\t";
		cout << s.getShowDate()<< "\t";
		cout << s.getShowTime()<< "\n";
	}
	ifs.close();
}