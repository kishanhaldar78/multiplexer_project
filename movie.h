class Movies
{
 int movieId;
 char movieName[30];
 char desc[30];
 public:
 void setMovieId(int movieId);
 void setMovieName(char *movieName);
 void setDesc(char *desc);
 int getMovieId();
 char *getMovieName();
 char *getDesc();
};
void Movies::setMovieId(int movieId)
{
this->movieId=movieId;
}
void Movies::setMovieName( char *movieName)
{
strcpy(this->movieName,movieName);
}
void  Movies::setDesc( char *desc)
{
strcpy(this->desc,desc);
}
int  Movies::getMovieId()
{
return movieId;
}
char* Movies::getMovieName()
{
return movieName;
}
char* Movies::getDesc()
{
return desc;
}
void addMovies()
{

	ofstream ofs("movies.data",ios::app);
	Movies m;
	int movieId;
        char movieName[30];
        char desc[30];

	cout<<"enter movieId"<<endl;
	cin>>movieId;
	cin.ignore();
	m.setMovieId(movieId);
	cout<<"enter the  movieName"<<endl;
	cin.getline(movieName,30);
	m.setMovieName(movieName);
	cout<<"enter Desc"<<endl;
	cin.getline(desc,30);
	m.setDesc(desc);
	ofs.write((char *)&m,sizeof(m));

	ofs.close();
}


void updateMovie()
{
	fstream fs("movies.data",ios::in|ios::out);
	Movies m;
	int movieId;
	int f=0;
	cout<<"enter the movieId";
	cin>>movieId;
	char choice1=' ';
	int pos=0;
	while(fs.read((char *)&m,sizeof(m)))
	{
	if(movieId==m.getMovieId())
	{
	f=1;
	char movieName[30];
	char moviedesc[30];
	cout<<"Do You Want To Edit Name?"<<endl;
	cout<<"Press y/n";
	cin>>choice1;
	if(choice1=='y')
	{
	cout<<"Enter The Movie Name"<<endl;
	cin.ignore();
	cin.getline(movieName,30);
	m.setMovieName(movieName);
	}
	cout<<"Do You Want To Edit Description?";
	cout<<"Press y/n";
	cin>>choice1;
	if(choice1=='y')
	{
	cout<<"Enter The Description"<<endl;
	cin.ignore();
	cin.getline(moviedesc,30);
	m.setDesc(moviedesc);
	}
	fs.seekp(pos);
	fs.write((char *)&m,sizeof(m));
	break;
	}
	pos=fs.tellg();
	}
	if(f==0)
	{
	cout<<"sorry!!!";
	cout<<"Specified Record Does Not Exist\n";
	}
	fs.close();

	
}

void deleteMovie()
{
	Movies m;
	int movieId;
	//char movieName[30];
	//char desc[30];
	cout<<"Enter MovieId"<<endl;
	cin>>movieId;
	ofstream ofs;
	ofs.open("newmovie.data",ios::out);
	ifstream ifs;
	ifs.open("movies.data",ios::in);
	
	
	//ofs.open("newmovie.data");
	//ifs.open("movies.data");
	while(ifs.read((char *)&m,sizeof(m)))
	{
		if(movieId!=m.getMovieId())
		ofs.write((char *)&m,sizeof(m));
	}
	if(movieId!=m.getMovieId()){
		cout<<"\n\nno record found\n\n"<<endl;
      }      
      else{
      	cout<<"\n\nMovie Deleted successfully\n\n"<<endl;
      }
	
	ifs.close();
	ofs.close();
/*
	ifstream ifs1;
	ifs1.open("newmovie.data",ios::out);
	while(ifs.read((char *)&m,sizeof(m)))
	{
	cout<<m.getMovieId()<<"\t\t";
	cout<<m.getMovieName()<<"\t\t";
	cout<<m.getDesc()<<"\t\t";
	}

ifs1.close();*/

rename("newmovie.data","movies.data");
}


void listMovies()
{
	Movies m;
	int movieId;
	char movieName[30];
	char desc[30];

	cout<<"Enter MovieId"<<endl;
	cin>>movieId;
	cout<<"MovieId"<<endl;
	cout<<"MovieName"<<endl;
	cout<<"Movie Desc"<<endl;
	ifstream ifs("movies.data");
	while(ifs.read((char *)&m,sizeof(m)))
	{
	if(movieId==m.getMovieId())
	{
	cout<<m.getMovieId()<<"\t\t";
	cout<<m.getMovieName()<<"\t\t";
	cout<<m.getDesc()<<"\t\t";
	}
}
ifs.close();
}

void listallMovies()
{
         Movies m;
	int movieId;
        char movieName[30];
        char desc[30];

	cout<<"MovieId"<<"\t\t";
	cout<<"MovieName"<<"\t\t";
	cout<<"Desc"<<"\n";
	ifstream ifs;
	ifs.open("movies.data");
	while(ifs.read((char *)&m,sizeof(m)))
	{
	cout<<m.getMovieId()<<"\t\t";
	cout<<m.getMovieName()<<"\t\t";
	cout<<m.getDesc()<<"\n";
}
ifs.close();
}
	

