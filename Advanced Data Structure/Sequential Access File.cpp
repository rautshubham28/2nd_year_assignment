#include"iostream"
#include"fstream"
#include<string.h>
using namespace std;

class Record
{
	int rollno;
	char name[20];
	char subject[20]; 
	int subcode;
 	float internal_asses;
 	float university_exam;
 	public:
		Record()
		{
			rollno=0;
	 		strcpy(name,"\0");
	 		strcpy(subject,"\0");
	 		subcode=0;
	 		internal_asses=0.0;
	 		university_exam=0.0;
		}
		int getRollno()
		{
		 	return(rollno);
		}
		void getData()
		{
		 	cout<<"\nEnter Details : ";
	 		cout<<"\nRoll no : ";
	 		cin>>rollno;
	 		cout<<"Name    : ";
	 		cin>>name;
	 		cout<<"Subject Code : ";
	 		cin>>subcode;
	 		cout<<"Subject Name : ";
	 		cin>>subject;
	 		cout<<"Internal AssessMent Marks : ";
	 		cin>>internal_asses;
	 		cout<<"University Exam Marks     : ";
	 		cin>>university_exam;
		}
		void putData()
		{
	 		cout<<"\nRoll No.     : ";
	 		cout<<rollno;
	 		cout<<"\t\tName : ";
	 		cout<<name;
	 		cout<<"\nSubject Code : ";
	 		cout<<subcode;
	 		cout<<"\tSubject Name : ";
	 		cout<<subject;
		 	cout<<"\nInternal AssessMent Marks : ";
	 		cout<<internal_asses;
	 		cout<<"\nUniversity Exam Marks     : ";
	 		cout<<university_exam<<"\n\n";
		}
};
class File
{
 	ifstream fin;
 	ofstream fout;
 	fstream fs;
 	public:
		void insert( );
		void display();
		void search(int );
		int Delete(int );
		int edit(int );	
};
void File::insert()
{
 	Record r;
 	r.getData();
 	fout.open("Madhu",ios::ate|ios::app);
 	fout.write((char *)&r,sizeof(r));
 	fout.close();
}
void File::display()
{
 	Record r;
 	fin.open("Madhu");
 	fin.seekg(0, ios::beg);
 	while(fin.read((char *)&r,sizeof(r)))
	{
		r.putData();
	}
 	fin.close();
}
void File::search(int rollno)
{
 	Record r;
 	int flag=0;
 	fin.open("Madhu");
 	fin.seekg(0, ios::beg);
 	while(fin.read((char *)&r,sizeof(r)))
	{
	 	if(r.getRollno()==rollno)
		{
		 	flag=1;
		 	break;
		}
	}
 	fin.close(); 
 	if(flag==1)
	{
	 	cout<<"\nRecord Found :";
	 	r.putData();
	}
 	else
	{
	 	cout<<"\nRecord not Found ";
	}
}
int File::Delete(int rollno)
{
 	Record r;
 	int flag=0;
 	fin.open("Madhu");
 	fout.open("Temp",ios::ate|ios::app);
 	fin.seekg(0, ios::beg);
 	while(fin.read((char *)&r,sizeof(r)))
	{
	 	if(r.getRollno()==rollno)
		{
		 	flag=1;
		}
	 	else
		{
		 	fout.write((char *)&r,sizeof(r));
		}
	}
	fin.close();
 	fout.close();
 	remove("Madhu");

 	rename("Temp","Madhu");
 
 	return(flag);
}
int File::edit(int rollno)
{
 	Record r;
 	int flag=0;
 	fs.open("Madhu");
 	fs.seekg(0, ios::beg);
 	while(fs.read((char *)&r,sizeof(r)))
	{
	 	if(r.getRollno()==rollno)
		{
		 	flag=1;
		 	cout<<"\nEnter New Details : ";
		 	r.getData();
		 	fs.seekp((int)fs.tellg()-sizeof(r),ios::beg);
	 	 	fs.write((char *)&r,sizeof(r));
		}	 
	}
 	fs.close();
 	return(flag);
}

int main()
{
 	File f;
 	int ch,n,i,flag=0;
 	do
  	{
    	cout<<"\n\n\t-----M E N U-----";
    	cout<<"\n\n1. Build A Master Table";
    	cout<<"\n2. List A Table";
    	cout<<"\n3. Insert a New Entry";
    	cout<<"\n4. Delete Old Entry";
    	cout<<"\n5. Edit an Entry";
    	cout<<"\n6. Search for a Record";
    	cout<<"\n7. Quit";
    	cout<<"\n     Enter your Choice : ";
    	cin>>ch;
    	switch(ch)
	{
	 	case 1:if(flag==0)
		{
		 	cout<<"\n Enter No of Records to insert : ";
			cin>>n;
			for(i=0; i<n; i++)
			{
			  	f.insert();
			}
			flag=1;
		}
		else
		{
			 cout<<"\n Sorry.. Table is Already build... \n If want to add record please select Insert a New Entry in option.....";
		}
		break;

		case 2:f.display();
		break;

		case 3:f.insert();
		break;

		case 4:cout<<"\nEnter Roll No of Student Whoes Record is to be Deleted :";
		cin>>n;
		i=f.Delete(n);
		if(i==1)
		{
			cout<<"\nRecord Deleted Successfully";
		}
		else
		{
			cout<<"\nRecord not Found ";
		}
		break;

		case 5:cout<<"\nEnter Roll No of Student Whoes Record is to be Edit : ";
		cin>>n;
		i=f.edit(n);
		if(i==1)
		{
			cout<<"\nRecord Modified Successfully";
		}
		else
		{
			cout<<"\nRecord not Found ";
		}
		break;
	 	case 6:cout<<"\nEnter Roll No of Student Whoes Record is to be Searched : ";
		cin>>n;
		f.search(n);
		break;
	 	case 7:
		break;
	 	default:cout<<"\n Enter Valid Choice.....";
		}
   	}while(ch!=7);
 	return(0);
}



/************OutPut***************

[student@localhost ~]$ g++ SAF.cpp
[student@localhost ~]$ ./a.out


	-----M E N U-----

1. Build A Master Table
2. List A Table
3. Insert a New Entry
4. Delete Old Entry
5. Edit an Entry
6. Search for a Record
7. Quit
     Enter your Choice : 1

 Enter No of Records to insert : 2

Enter Details : 
Roll no : 79
Name    : Akshay
Subject Code : 10
Subject Name : DS
Internal AssessMent Marks : 40
University Exam Marks     : 70

Enter Details : 
Roll no : 75
Name    : Sandy
Subject Code : 20
Subject Name : CG
Internal AssessMent Marks : 43
University Exam Marks     : 60


	-----M E N U-----

1. Build A Master Table
2. List A Table
3. Insert a New Entry
4. Delete Old Entry
5. Edit an Entry
6. Search for a Record
7. Quit
     Enter your Choice : 2

Roll No.     : 79		Name : Akshay
Subject Code : 10	Subject Name : DS
Internal AssessMent Marks : 40
University Exam Marks     : 70


Roll No.     : 75		Name : Sandy
Subject Code : 20	Subject Name : CG
Internal AssessMent Marks : 43
University Exam Marks     : 60



	-----M E N U-----

1. Build A Master Table
2. List A Table
3. Insert a New Entry
4. Delete Old Entry
5. Edit an Entry
6. Search for a Record
7. Quit
     Enter your Choice : 5

Enter Roll No of Student Whoes Record is to be Edit : 75

Enter New Details : 
Enter Details : 
Roll no : 72

Name    : Sam
Subject Code : 25
Subject Name : CO
Internal AssessMent Marks : 38
University Exam Marks     : 70
Record Modified Successfully

	-----M E N U-----

1. Build A Master Table
2. List A Table
3. Insert a New Entry
4. Delete Old Entry
5. Edit an Entry
6. Search for a Record
7. Quit
     Enter your Choice : 6

Enter Roll No of Student Whoes Record is to be Searched : 79

Record Found :
Roll No.     : 79		Name : Akshay
Subject Code : 10	Subject Name : DS
Internal AssessMent Marks : 40
University Exam Marks     : 70



	-----M E N U-----

1. Build A Master Table
2. List A Table
3. Insert a New Entry
4. Delete Old Entry
5. Edit an Entry
6. Search for a Record
7. Quit
     Enter your Choice : 4

Enter Roll No of Student Whoes Record is to be Deleted : 72

Record Deleted Successfully

	-----M E N U-----

1. Build A Master Table
2. List A Table
3. Insert a New Entry
4. Delete Old Entry
5. Edit an Entry
6. Search for a Record
7. Quit
     Enter your Choice : 7
[student@localhost ~]$ 


*********************************/
