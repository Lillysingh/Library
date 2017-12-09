#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


void border(char ch1, char ch2, int x, int y, int l, int b )
//x,y are the top left coordinates and l and b are length and breadth of box
{
	for ( int i=x ; i<=x+l ; i++ )
	{
		gotoxy(i,y);
		if(i%2==0)
		cout<<ch1;
		else cout<<ch2;
	}
	for ( int j=y+1 ; j<y+b ; j++ )
	{
		gotoxy(x,j);
		if(j%2==0)
		cout<<ch1;
		else cout<<ch2;
	}
		for ( int k=x ; k<=x+l ; k++)
	{
		gotoxy(k,y+b);
		if(k%2==0)
		cout<<ch1;
		else cout<<ch2;
	}
	for ( int m=y+1 ; m<y+b ; m++)
	{
		gotoxy(x+l,m);
		if(m%2==0)
		cout<<ch1;
		else cout<<ch2;
	}
}
void align(char* word,int x=30,int y=12.5)
{
	gotoxy(x,y);
	cout<<word;
}
void center( char opt[20], char str[80], int y )
// opt is to decide whether a box is required or not
{
	if (strcmp(opt,"box")==0)
	{
		int l,x;
		l=strlen(str);
		x=40-l/2;
		gotoxy(x,y);
		cout<<str;
		border('.','*',x-5,y-5,l+10,10);
	}
	else
	{
		int l,x;
		l=strlen(str);
		x=40-l/2;
		gotoxy(x,y);
		cout<<str;
	}
}

long binary( long m )
	{
	int i=0, j, p;
	long binary_array[100], bin=0;
	while( m>0 )
		{
		binary_array[i]=m%2;
		m=m/2;
		i++;
		}
	for ( j=i-1;j>=0;j--,p++ )
		{
		bin+= pow(10,j)*binary_array[j];
		}
	return bin;
	}

void encrypt( long array[100] )
	{
	int l;
	long m,n;
	for( l=0;l<100;l++)
		{
		m=array[l];
		n=binary(m);
		array[l]=m+n;
		}
	}

void getpass( long pass[100] )
{
	char ch;
	int i,j,flag=0;
	long k;
	for( i=0;i<100;i++ )
		{
		ch=getch();
		if( ch!=13 )
			{
			k=ch;          //k stores the ascii value
			pass[i]=k;
			cout<<"*";
			}
		else
		  for(j=i;j<100;j++)
				 {pass[j]=0;
				 flag=1;}

		  if (flag)
			i=j;

		}
		encrypt(pass);
}

//*******************
//function prototypes
//*******************
void login();
void due_date();
void menu();
void add();
void add_new_book();
void add_new_librarian();
void add_new_member();
void search();
void book_search();
void book_search_id();
void book_search_name();
void book_search_author();
void member_search();
void member_search_id();
void member_search_telephone();
void issue_book();
void return_book();
void remove();
void remove_book();
void remove_member();
void report();
void book_report();
void member_report();

//******************************
//class definition for LIBRARIAN
//******************************

class librarian
{
	char name[100];
	char username[100];
	long password[100];
 public:
	void input();
	long ret_password(int );
	char* ret_username()
	{
		return username;
	}
	char* ret_name()
	{
		return name;
	}

};

void librarian::input()
	{
		border('*','.',0,0,80,24);
		center("nobox","*Enter a username and password of minimum 6 characters.",21);
		center("nobox","*Include special characters to increase the strength. ",22);
		border('+','+',25,5,35,13);
		gotoxy(34,10);
		cout<<"Name: ";
		gotoxy(30,12);
		cout<<"Username: ";
		gotoxy(30,14);
		cout<<"Password: ";
		gotoxy(40,10);
		gets(name);
		gotoxy(40,12);
		gets(username);
		gotoxy(40,14);
		getpass(password);
		clrscr();
		center("nobox","WELCOME TO THE CULT",11);
		center("nobox",username,12);
		center("box","Press any key to continue",13);
		getch();
	}

long librarian::ret_password(int x)
{
	return password[x];
}

//*************************
//class definition for BOOK
//*************************

class book
{
	int book_id;
	char book_name[20];
	char book_author[20];
	float book_price;
	int quantity;
 public:
	void input();
	void book_details();
	int retbook_id()
	{
		return book_id;
	}
	char* retbook_name()
	{
		return book_name;
	}
	char* retbook_author()
	{
		return book_author;
	}
	float retbook_price()
	{
		return book_price;
	}
	void qty(int q)
	{
		quantity+=q;
	}
	int ret_qty()
	{
		return quantity;
	}
};

void book::input()
{
	int addition_quantity;
	border('*','.',0,0,80,24);
	gotoxy(20,8);
	cout<<"Enter the book name: ";
	gets(book_name);
	gotoxy(20,10);
	cout<<"Enter the book author: ";
	gets(book_author);
	gotoxy(20,12);
	cout<<"Enter the book id: ";
	cin>>book_id;
	gotoxy(20,14);
	cout<<"Enter the book price: ";
	cin>>book_price;
	gotoxy(20,16);
	cout<<"Enter the number of copies added: ";
	cin>>addition_quantity;
	qty(addition_quantity);
}

 void book::book_details()
{
	clrscr();
	border('*','.',0,0,80,24);
	center("nobox","BOOK DETAILS",10);
	gotoxy(20,12);
	cout<<"Book name: "<<book_name<<endl;
	gotoxy(20,13);
	cout<<"Book author: "<<book_author<<endl;
	gotoxy(20,14);
	cout<<"Quantity: "<<quantity<<endl;
	gotoxy(20,15);
	cout<<"Book price: "<<book_price<<endl;
	center("nobox","Press any key to continue",20);
	getch();
}

//***************************
//class definition for MEMBER
//***************************

class member
{
	int mem_id;
	char mem_name[100];
	long tel_no;
	int membook_id;
 public:
	void input();
	void member_details();
	int retmem_id()
	{
		return mem_id;
	}
	char* retmem_name()
	{
		return mem_name;
	}
	long rettel_no()
	{
		return tel_no;
	}
	int retmem_book_id()
	{
		return membook_id;
	}
	void mem_book_id( int id)
	{
		membook_id=id;
	}
};

void member::input()
{
	clrscr();
	border('*','.',0,0,80,24);
	gotoxy(20,10);
	cout<<"Enter the member name: ";
	gets(mem_name);
	gotoxy(20,13);
	cout<<"Enter 4 digit member id: ";
	cin>>mem_id;
	gotoxy(20,16);
	cout<<"Enter the member's telephone number: ";
	cin>>tel_no;
	gotoxy(20,18);
	cout<<"Enter the id of the book issued: ";
	cin>>membook_id;
}

void member::member_details()
{
	clrscr();
	border('*','.',0,0,80,24);
	center("nobox","MEMBER DETAILS",12);
	gotoxy(20,14);
	cout<<"Member name: "<<mem_name<<endl;
	gotoxy(20,15);
	cout<<"Member telephone number: "<<tel_no<<endl;
	gotoxy(20,16);
	cout<<"Member ID: "<<mem_id<<endl;
	gotoxy(20,17);
	center("nobox","Press any key to continue",20);
	getch();
}

//*****************
//USELESS FUNCTIONS
//*****************

void login()
{
				librarian l;
				int c=0, access_value=0;
				char uname[100];
				long upass[100];
  login_screen: clrscr();
				border('+','+',25,7,30,8);
				gotoxy(30,10);
				cout<<"Username: ";
				gotoxy(30,12);
				cout<<"Password: ";
				gotoxy(40,10);
				gets(uname);
				gotoxy(40,12);
				getpass(upass);
				c++;
				ifstream filein;
				filein.open("librarian.dat",ios::in||ios::binary);
				while(!filein.eof())
				{
					filein.read((char*)&l,sizeof(l));
						if (strcmp(uname,l.ret_username())==0)
					  for (int q=0;q<100;q++)
					if (upass[q]==l.ret_password(q))
					 access_value=1;
				}
				filein.close();

				if( access_value )
				{
					gotoxy(3,14);
					center("nobox","Access granted.....",14);
					center("nobox","press any key to continue",15);
					getch();
				}
				else
				{
					gotoxy(3,14);
					if( c==1 )
					{
						clrscr();
						center("box","Access denied.....you have 2 tries left. press any key to retry.",12);
						getch();
						goto login_screen;
					}
					else if ( c==2 )
					{
						clrscr();
						center("box","Access denied.....you have 1 try left. press any key to retry.",12);
						getch();
						goto login_screen;
					}
					else exit(0);

				}
 }

void due_date()
{
	int x, flag=0,year;
	time_t t;
	tm d;
	t= time(NULL);
	d= *localtime(&t);
	year=d.tm_year+1900;
	if(year%4==0 && year%100==0 || year%400==0)  // LEAP YEAR
	{
		  x=d.tm_yday+8;     // days since jan 1 + 1 week
			if (x>366)
				{
					x=x-366;
					flag=1;
				}
			else if( x>335)
				x=x-335;
			else if( x>305)
				x=x-305;
			else if( x>274)
				x=x-274;
			else if( x>244)
				x=x-244;
			else if( x>213)
				x=x-213;
			else if( x>182)
				x=x-182;
			else if( x>152)
				x=x-152;
			else if( x>121)
				x=x-121;
			else if( x>91 )
				x=x-91;
			else if(x>60)
				x=x-60;
			else if(x>31)
				x=x-31;
	}
	else
	{
		x=d.tm_yday+8;     // days since jan 1 + 1 week
		if (x>365)
		{
			x=x-365;
			flag=1;
		}
		else if( x>334)
				x=x-334;
		else if( x>304)
				x=x-304;
		else if( x>273)
				x=x-273;
		else if( x>243)
				x=x-243;
		else if( x>212)
				x=x-212;
		else if( x>181)
				x=x-181;
		else if( x>151)
				x=x-151;
		else if( x>120)
				x=x-120;
		else if( x>90 )
				x=x-90;
		else if(x>59)
				x=x-59;
		else if(x>31)
				x=x-31;
		}
		if(flag)
	cout<<"Due date: "<<x<<"."<<(d.tm_mon+1)<<"."<<(d.tm_year+1901); // next year if borrowed between 25 dec and 31 dec
	cout<<"Due date: "<<x<<"."<<(d.tm_mon+1)<<"."<<(d.tm_year+1900);
}

//************
//display menu
//************

void menu()
{
	int option;
	do
	{
		menu:
		clrscr();
		border('*','.',25,2,30,20);
		center("nobox","MAIN MENU",4);
		center("nobox","-----------------------",5);
		center("nobox","1.ADD ",6);
		center("nobox","2.SEARCH",8);
		center("nobox","3.ISSUE BOOK",10);
		center("nobox","4.RETURN BOOK",12);
		center("nobox","5.REMOVE",14);
		center("nobox","6.REPORT",16);
		center("nobox","7.EXIT",18);
		center("nobox","ENTER YOUR OPTION: ",20);
		cin>>option;

		switch(option)
		{
			case 1:  add();
					 break;
			case 2:  search();
					 break;
			case 3:  issue_book();
					 break;
			case 4:  return_book();
					 break;
			case 5:  remove();
					 break;
			case 6:  report();
					 break;
			case 7:  clrscr();
					 center("box","Have a nice day ahead.",11);
					 center("nobox","Press any key to exit system",13);
					 getch();
					 exit(0);
			case 8:
					remove("members.dat");
					remove("books.dat");
					break;
			default: clrscr();
					 center("nobox","Invalid option.....",12);
					 center("box","Press any key to go back to main menu",13);
					 getch();
					 goto menu;
		}
		}while(option!=7);

}

//*****************************************
// add function and derivatives definitions
//*****************************************

void add()
{
	char ch;
	do
	{	add:
		clrscr();
		border('!','^',29,5,23,15);
		center("nobox","ADD",7);
		center("nobox","============",8);
		center("nobox","a. BOOK",10);
		center("nobox","b. LIBRARIAN",12);
		center("nobox","c. MEMBER",14);
		center("nobox","d. EXIT",16);
		center("nobox","ENTER YOUR OPTION: ",18);
		ch=getche();
		switch(ch)
		{
			case 'a': add_new_book();
					  break;
			case 'b': add_new_librarian();
					  break;
			case 'c': add_new_member();
					  break;
			case 'd': 
				return;
			default:  clrscr();
					  center("nobox","Invalid option......",12);
					  center("box","Press any key to go back to previous page",13);
					  getch();
					  goto add;
		}
	}while(ch!='d');
}

void add_new_librarian()
{
	clrscr();
	librarian l;
	char new_username[100];
	cout<<"Enter the username of the new librarian: ";
	gets(new_username);
	fstream file;
	file.open("librarian.dat",ios::in|ios::binary);
	while(file.read((char*)&l,sizeof(l)))
	{
		if (strcmp(new_username,l.ret_username())==0 )
		{
			clrscr();
			center("nobox","Username or password already exists",11);
			center("nobox","Please try another combination",12);
			center("box","Press any key to retry : ",13);
			getch();
			return;
		}
	}
	l.input();
	file.close();
	file.open("librarian.dat",ios::app|ios::binary);
	file.write((char*)&l,sizeof(l));
	cout<<"Press any key to continue";
	getch();
	file.close();
}

void add_new_book()
{
	clrscr();
	book b;
	char book_added_name[20];
	cout<<"Enter the book name: ";
	gets(book_added_name);
	fstream file;
	file.open("books.dat",ios::in|ios::binary);

	while(file.read((char*)&b,sizeof(b)))
	{
		if( strcmp(b.retbook_name(),book_added_name)==0)
		{
			cout<<"Book already exists";
			cout<<"Press any key to retry";
			getch();
			return;
		}
	}
	b.input();
	file.close();
	file.open("books.dat",ios::app|ios::binary);
	file.write((char*)&b,sizeof(b));
	cout<<"Press any key to continue";
	getch();
	file.close();
}


void add_new_member()
{
	clrscr();
	member m;
	int member_added_id;
	cout<<"Enter the member id for the new member: ";
	cin>>member_added_id;
	fstream file;
	file.open("members.dat",ios::in|ios::binary);

	while(file.read((char*)&m,sizeof(m)))
	{
		if(m.retmem_id()==member_added_id)
		{
			cout<<"Memeber already exists";
			cout<<"Press any key to retry";
			getch();
			return;
		}
	}
	m.input();
	file.close();
	file.open("members.dat",ios::app|ios::binary);
	file.write((char*)&m,sizeof(m));
	cout<<"Press any key to continue";
	getch();
	file.close();
}

//********************************************
// search function and derivatives definitions
//********************************************

void search()
{
	int x;
	do
	{
		search:
		clrscr();
		border('@','@',29,5,23,13);
		center("nobox","SEARCH",7);
		center("nobox","*************",8);
		center("nobox","1. BOOK",10);
		center("nobox","2.MEMBER",12);
		center("nobox","3. EXIT",14);
		center("nobox","ENTER YOUR OPTION: ",16);
		cin>>x;
		switch(x)
		{
			case 1: book_search();
					break;
			case 2: member_search();
					break;
			case 3: break;
			 default: clrscr();
					 center("nobox","Invalid option......",12);
					  center("box","Press any key to go back to previous page",13);
					  getch();
					goto search;
		}
	}while(x!=3);
}

void book_search()
{
	char ch;
	do
	{
		book_search:
		clrscr();
		border('#','$',29,5,23,15);
		center("nobox","BOOK SEARCH",7);
		center("nobox","~~~~~~~~~~~~~~~",8);
		center("nobox","a. BY ID",10);
		center("nobox","b. BY BOOK NAME",12);
		center("nobox","c. BY BOOK AUTHOR",14);
		center("nobox","d. EXIT",16);
		center("nobox","ENTER YOUR OPTION: ",18);
		ch=getche();
		switch(ch)
		{
			case 'a':	book_search_id();
						break;
			case 'b':	book_search_name();
						break;
			case 'c':	book_search_author();
						break;
			case 'd':	break;
			default: 	clrscr();
						center("nobox","Invalid option......",12);
						 center("box","Press any key to go back to previous page",13);
						 getch();
						 goto book_search;
		}
	}while(ch!='d');
}

void book_search_id()
{
	int id_enter,q=0;
	book b;
	clrscr();
	border('"','+',0,0,80,24);
	center("nobox","BOOK SEARCH BY ID",8);
	center("nobox","Enter the book ID: ",10);
	cin>>id_enter;
	ifstream file;
	file.open("books.dat",ios::in|ios::binary);
	while(file.read((char*)&b,sizeof(b)))
	{
		if(id_enter==b.retbook_id())
		{
			q=1;
			b.book_details();
		}
	}
	file.close();

	if(q!=1)
	{
		center("nobox","BOOK NOT FOUND",12);
		center("nobox","Press any key to retry : ",13);
		getch();
	}
}


void book_search_name()
{
	book b;
	int k=0;
	char str[20];
	clrscr();
	border('%','*',0,0,80,24);
	center("nobox","BOOK SEARCH BY NAME",8);
	center("nobox","Enter the book name: ",10);
	gets(str);
	ifstream file;
	file.open("books.dat",ios::in|ios::binary);
	while(file.read((char*)&b,sizeof(b)))
	{
		if(strcmp(str,b.retbook_name())==0)
		{
			k=1;
			b.book_details();
		}
	}
	file.close();

	if(k!=1)
	{
		center("nobox","BOOK NOT FOUND",12);
		center("nobox","Press any key to retry: ",13);
		getch();
	}
}

void book_search_author()
{
	book b;
	int k=0;
	char str[20];
	clrscr();
	border('%','*',0,0,80,24);
	center("nobox","BOOK SEARCH BY AUTHOR NAME",8);
	center("nobox","Enter the book author: ",10);
	gets(str);
	 ifstream file;
	file.open("books.dat",ios::in|ios::binary);
	while(file.read((char*)&b,sizeof(b)))
	{
		if(strcmp(str,b.retbook_author())==0)
		{
			k=1;
			b.book_details();
			cout<<"-----------------------------------------------"<<'\n';
		}
	}
	file.close();

	if(k==0)
	{
		center("nobox","BOOK NOT FOUND",12);
		center("nobox","Press any key to retry: ",13);
		getch();
	}
}

void member_search()
{
	char ch;
	do
	{
		member_search:
		clrscr();
		border('+','-',27,5,26,13);
		center("nobox","MEMBER SEARCH",7);
		center("nobox","^^^^^^^^^^^^^^^^^",8);
		center("nobox","a. BY ID",10);
		center("nobox","b. BY TELEPHONE NUMBER",12);
		center("nobox","c. EXIT",14);
		center("nobox","ENTER YOUR OPTION: ",16);
		ch=getche();
		switch(ch)
		{
			case 'a': member_search_id();
					  break;
			case 'b': member_search_telephone();
					  break;
			case 'c': break;
			default : clrscr();
					  center("nobox","Invalid option......",12);
					  center("box","Press any key to go back to previous page",13);
					  getch();
					  goto member_search;
		}
	}while(ch!='c');
}

void member_search_id()
{
	int x=0,mem_id_enter;
	member m;
	clrscr();
	border('"','+',0,0,80,24);
	center("nobox","MEMBER SEARCH BY ID",8);
	center("nobox","Enter the member ID: ",10);
	cin>>mem_id_enter;
	ifstream file;
	file.open("members.dat",ios::in||ios::binary);
	while(file.read((char*)&m,sizeof(m)))
	{
		if(mem_id_enter==m.retmem_id())
		{
			x=1;
			m.member_details();
		}
	}
	file.close();

	if(x!=1)
	{
		center("nobox","MEMBER DOES NOT EXIST",12);
		center("nobox","Press any key to retry: ",13);
		getch();
	}
}

void member_search_telephone()
{
	int x=0,mem_telno_enter;
	member m;
	clrscr();
	border('"','+',0,0,80,24);
	center("nobox","MEMBER SEARCH BY TELEPHONE NUMBER",8);
	center("nobox","Enter the member telephone number: ",10);
	cin>>mem_telno_enter;
	ifstream file;
	file.open("members.dat",ios::in||ios::binary);
	while(file.read((char*)&m,sizeof(m)))
	{
		if(mem_telno_enter==m.rettel_no())
		{
			x=1;
			m.member_details();
		}
	}
	file.close();

	if(x!=1)
	{
		center("nobox","MEMBER DOES NOT EXIST",12);
		center("nobox","Press any key to retry: ",13);
		getch();
	}
}

//********************
// book issue function
//********************
void issue_book()
{
	member m;
	book b;
	int book_found=0, member_found=0, member_book_issue_id;
	char book_issued[20];

	clrscr();
	border('~','-',0,0,80,24);
	center("nobox","ISSUE BOOK",4);
	center("nobox","Enter the book name: ",6);
	gets(book_issued);
	center("nobox","Enter member id: ",8);
	cin>>member_book_issue_id;

	fstream bfile, mfile;
	bfile.open("books.dat",ios::in|ios::out|ios::binary);
	mfile.open("members.dat",ios::in|ios::out|ios::binary);

	while(bfile.read((char*)&b,sizeof(b)))
	{
		if( strcmp(book_issued,b.retbook_name())==0 && b.ret_qty()>0 )
		{
			book_found=1;
			break;
		}
	}
	while(mfile.read((char*)&m,sizeof(m)))
	{
		if(m.retmem_id()== member_book_issue_id)
		{
			member_found=1;
			break;
		}
	}


	if( book_found && member_found )
	{
		m.mem_book_id(b.retbook_id());
		b.qty(-1);
		center("nobox","Book has been successfully borrowed",12);
		center("nobox","Press any key to view details",13);
		getch();
		clrscr();
		border('.','#',0,0,80,24);
		center("nobox","STATUS",4);
		center("nobox","~~~~~~~~~~~~~~~~~~~~",6);
		align("Book name: ",30,8);
		cout<<b.retbook_name();
		align("Book author: ",30,10);
		cout<<b.retbook_author();
		align("Book price: ",30,12);
		cout<<b.retbook_price();
		align("Member name: ",30,14);
		cout<<m.retmem_name();
		align(" ID of book borrowed: ",30,16);
		cout<<m.retmem_book_id();
		gotoxy(30,18);
		due_date();
		center("nobox","Press any key to continue",20);
		getch();
	}

	else if(!book_found)
	{
		clrscr();
		center("box","Book not found",12);
		center("nobox","Press any key to retry",14);
		getch();
	}
	else if(!member_found)
	{
		clrscr();
		center("box","Member does not exist",12);
		center("nobox","Press any key to retry",14);
		getch();
	}

	mfile.close();
	bfile.close();
}

//*********************
// book return function
//*********************
void return_book()
{
	member m;
	book b;
	int member_book_issue_id,book_match=0,id_match=0;
	char book_issued[20];

	clrscr();
	border('~','-',0,0,80,24);
	center("nobox","RETURN BOOK",4);
	center("nobox","Enter the book name: ",6);
	gets(book_issued);
	center("nobox","Enter member id: ",8);
	cin>>member_book_issue_id;

	fstream bfile, mfile;
	bfile.open("books.dat",ios::in|ios::out|ios::binary);
	mfile.open("members.dat",ios::in|ios::out|ios::binary);

	while(bfile.read((char*)&b,sizeof(b)))
	{
		if( strcmp(book_issued,b.retbook_name())==0 )
		{
			book_match=1;
			break;
		}
	}
	while(mfile.read((char*)&m,sizeof(m)))
	{
		if(m.retmem_id()== member_book_issue_id)
		{
			id_match=1;
			break;
		}
	}

	if( book_match && id_match )
	{
		b.qty(1);
		m.mem_book_id(0);
	}
	else if(!book_match)
	{
		clrscr();
		center("box","This book doesn't belong to this library",12);
		center("nobox","Press any key to retry",14);
		getch();
	}
	else if(!id_match)
	{
		clrscr();
		center("box","Member does not exist",12);
		center("nobox","Press any key to retry",14);
		getch();
	}
}

//********************************
// remove function and derivatives
//********************************

void remove()
{
	int x;
	do
	{
		report:
		clrscr();
		border('@','@',29,5,23,13);
		center("nobox","REMOVE",7);
		center("nobox","*************",8);
		center("nobox","1. BOOK",10);
		center("nobox","2.MEMBER",12);
		center("nobox","3. EXIT",14);
		center("nobox","ENTER YOUR OPTION: ",16);
		cin>>x;
		switch(x)
		{
			case 1: remove_book();
					break;
			case 2: remove_member();
					break;
			case 3: break;
			 default: clrscr();
					 center("nobox","Invalid option......",12);
					  center("box","Press any key to go back to previous page",13);
					  getch();
					goto report;
		}
	}while(x!=3);
}

void remove_book()
{
	member m;
	book b;
	int member_book_issue_id,book_match=0,id_match=0;
	float amt_due;
	char book_issued[20];
	clrscr();
	border('~','-',0,0,80,24);
	center("nobox","REMOVE BOOK",4);
	center("nobox","Enter the book name: ",6);
	gets(book_issued);
	center("nobox","Enter member id: ",8);
	cin>>member_book_issue_id;
	fstream bfile, mfile, file;
	bfile.open("books.dat",ios::in|ios::out|ios::binary);
	mfile.open("members.dat",ios::in|ios::out|ios::binary);
	while(bfile.read((char*)&b,sizeof(b)))
	{
		if( strcmp(book_issued,b.retbook_name())==0 )
		{
			book_match=1;
			break;
		}
	}
	while(mfile.read((char*)&m,sizeof(m)))
	{
		if(m.retmem_id()== member_book_issue_id)
		{
			id_match=1;
			break;
		}
	}
	if( book_match && id_match )
	{
		if (b.ret_qty()>1)
		{
			b.qty(-1);
		}
		else
		{
			file.open("temp.dat",ios::app|ios::binary);
			while(bfile.read((char*)&b,sizeof(b)))
			{
				if( strcmp(book_issued,b.retbook_name())!=0 )
				file.write((char*)&b,sizeof(b));
			}
			remove("books.dat");
			rename("temp.dat","books.dat");
		}

		amt_due=0.15*b.retbook_price()+b.retbook_price();

		clrscr();
		border(':','-',0,0,80,24);
		center("nobox","BOOK HAS BEEN REMOVED",8);
		center("box","The member owes the library: ",12);
		cout<<amt_due;

	}
	else if(!book_match)
	{
		clrscr();
		center("box","This book doesn't belong to this library",12);
		center("nobox","Press any key to retry",14);
		getch();
	}
	else if(!id_match)
	{
		clrscr();
		center("box","Member does not exist",12);
		center("nobox","Press any key to retry",14);
		getch();
	}
}

void remove_member()
{
	member m;
	int member_book_issue_id;
	clrscr();
	border('~','-',0,0,80,24);
	center("nobox","REMOVE MEMBER",4);
	center("nobox","Enter member id: ",8);
	cin>>member_book_issue_id;
	fstream mfile, file;
	mfile.open("members.dat",ios::in|ios::out|ios::binary);
	while(mfile.read((char*)&m,sizeof(m)))
	{
		if(m.retmem_id()== member_book_issue_id && m.retmem_book_id()==0)
		{
			file.open("temp.dat",ios::app|ios::binary);
			while(mfile.read((char*)&m,sizeof(m)))
			{
				if( member_book_issue_id != m.retmem_id() )
				file.write((char*)&m,sizeof(m));
			}
			remove("members.dat");
			rename("temp.dat","members.dat");
			center("nobox","MEMBER HAS BEEN REMOVED",8);
			center("nobox","Press any key to return",13);
			getch();
			break;
		}

		else if(m.retmem_id()== member_book_issue_id && m.retmem_book_id()!=0)
		{
			center("nobox","Member possesses a library book.",10);
			center("nobox","Member can't be removed ",11);
			center("nobox","till book is returned",12);
			center("nobox","Press any key to return",13);
			getch();
			break;
		}
	}
}

//********************************
// report function and derivatives
//********************************

void report()
{
	int x;
	do
	{
		report:
		clrscr();
		border('@','@',29,5,23,13);
		center("nobox","REPORT",7);
		center("nobox","*************",8);
		center("nobox","1. BOOK",10);
		center("nobox","2.MEMBER",12);
		center("nobox","3. EXIT",14);
		center("nobox","ENTER YOUR OPTION: ",16);
		cin>>x;
		switch(x)
		{
			case 1: book_report();
					break;
			case 2: member_report();
					break;
			case 3: break;
			 default: clrscr();
					 center("nobox","Invalid option......",12);
					  center("box","Press any key to go back to previous page",13);
					  getch();
					goto report;
		}
	}while(x!=3);
}

void book_report()
{
	book b;
	clrscr();
	border('*','.',0,0,80,24);
	ifstream file;
	file.open("books.dat",ios::in|ios::binary);
	while(file.read((char*)&b,sizeof(b)))
	{
		b.book_details();
		getch();
	}
}
void member_report()
{
	member m;
	clrscr();
	border('*','.',0,0,80,24);

	ifstream file;
	file.open("members.dat",ios::in|ios::binary);
	while(file.read((char*)&m,sizeof(m)))
	{
		m.member_details();
		getch();
	}
}

//*************
//MAIN FUNCTION
//*************

void main()
{
	fstream file;
	librarian l;
	clrscr();
	file.open("librarian.dat",ios::in|ios::binary);
	border('*','.',0,0,80,24);
	gotoxy(20,12);
	if(!file)
	{
		file.close();
		file.open("librarian.dat",ios::out|ios::binary);
		cout<<"In order to start using software please enter";
		gotoxy(20,13);
		cout<<"One librarian details\n";
		getch();
		clrscr();
		file.open("librarian.dat",ios::out|ios::binary);
		l.input();
		file.write((char*)&l,sizeof(l));
		file.close();
	}
  	//login();
	menu();
}
