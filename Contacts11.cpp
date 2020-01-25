#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Contacts
{
	public:
		char name[10],add[10],email[20],group[4];
		struct
		{
			char ph[12];
		}s[4];
		void NewContact()
		{	
		cout<<"ENTER THE DETAILS OF NEW CONTACT:"<<endl;
		cout<<"NAME:";
		cin>>name;
		cout<<"PHONE NUMBERS:";
		cout<<"\n(PRESS 0 FOR THE FIELDS NOT REQUIRED)";
		cout<<"\nPHONE NUMBER 1:";
		cin>>s[1].ph;
		cout<<"PHONE NUMBER 2:";
		cin>>s[2].ph;
		cout<<"PHONE NUMBER 3:";
		cin>>s[3].ph;
		cout<<"PHONE NUMBER 4:";
		cin>>s[4].ph;
		cout<<"ADDRESS:";
		cin>>add;
		cout<<"EMAIL:";
		cin>>email;
		cout<<"(ENTER ANY ONE OF THE FOLLOWING GROUPS:: 1:FAMILY 2:FRIENDS 3:WORK 4:NO SPECIFIC GROUP)\n";
		cout<<"GROUP:";
		cin>>group;
		}
		void showdata()
		{
		cout<<"\n";
		cout<<"NAME:"<<name;
		cout<<"\tPHONE NUMBER 1:"<<s[1].ph;
		cout<<"\tPHONE NUMBER 2:"<<s[2].ph;
		cout<<"\tPHONE NUMBER 3:"<<s[3].ph;
		cout<<"\tPHONE NUMBER 4:"<<s[4].ph;
		cout<<"\tADDRESS:"<<add;
		cout<<"\tEMAIL:"<<email;
		cout<<"\n(GROUPS :: 1:FAMILY 2:FRIENDS 3:WORK 4:NO SPECIFIC GROUP)\n";
		cout<<"\tGROUP:"<<group;
		}
};
int main()
{
	system("color 1f ");
	Contacts b,c;
	int a,d,e,g,k,count;
	char query[10],h[4];
	fstream f;
	fstream f1;
	do
	{
	system("cls");
	cout<<"\n\t 1.ADD NEW CONTACT"<<endl;
	cout<<"\t 2.DISPLAY CONTACTS"<<endl;
	cout<<"\t 3.SEARCH CONTACT"<<endl;
	cout<<"\t 4.EDIT CONTACT"<<endl;
	cout<<"\t 5.DELETE CONTACT"<<endl;
	cout<<"\t 6.EXIT"<<endl;
	cout<<"\t ENTER YOUR CHOICE: ";
	cin>>a;
	switch(a)
	{
		case 1:
			system("cls");
			while(1)
			{
				f.open("ContactList.txt",ios::in|ios::app);
				cout<<"ENTER THE NAME OF THE NEW CONTACT:";
				cin>>b.name;
				while(1)
				{
				f.read((char*)&c,sizeof(c));
				if(f.eof())
				break;
				else if(stricmp(b.name,c.name)==0)
				{
					cout<<"CONTACT WITH SIMILAR NAME EXISTS!\nCONTACT CANNOT BE ADDED!";
					goto choice1;
				}
				}
				f.close();
				f.open("ContactList.txt",ios::app);
				c.NewContact();
				f.write((char*)&c,sizeof(c));
				cout<<"CONTACT ADDED SUCCESSFULLY!";
				choice1:
				f.close();
				cout<<"\nPRESS 1 FOR PREVIOUS MENU\nPRESS 0 TO ADD ANOTHER CONTACT\nYOUR RESPONSE:";
				cin>>d;
				if(d)
				{
					break;
				}
				else
				{
					continue;
				}
			}
			break;
		case 2:
			system("cls");
			f.open("ContactList.txt",ios::in);
			count=0;
			if(!f)
			{
			cout<<"\nNO CONTACTS TO DISPLAY!\n";
			f.close();
			break;
			}
			else
			{
			cout<<"\nEXISTING CONTACTS:"<<endl;
			while(1)
			{
			f.read((char*)&c,sizeof(c));
			if(f.eof())
			break;
			c.showdata();
			count++;
			}
			f.close();
			if(count!=0)
			{
			cout<<"\nDO YOU WANT TO DISPLAY CONTACTS OF SPECIFIC GROUPS?\n1.YES\t2.NO";
			cin>>g;
			if(g==1)
			{
				do
				{
				system("cls");
				cout<<"(EXISTING GROUPS:1.FAMILY 2.FRIENDS 3.WORK 4.NO SPECIFIC GROUP)\n";
				cout<<"ENTER THE GROUP YOU WANT TO SEARCH FOR:";
				cin>>k;
				switch(k)
				{
					case 1:
						f.open("ContactList.txt",ios::in);
						strcpy(h,"1");
						while(1)
						{
						f.read((char*)&c,sizeof(c));
						if(f.eof())
						break;
						else if(stricmp(c.group,h)==0)
						c.showdata();
						}
						f.close();
						break;
					case 2:
						f.open("ContactList.txt",ios::in);
						strcpy(h,"2");
						while(1)
						{
						f.read((char*)&c,sizeof(c));
						if(f.eof())
						break;
						else if(stricmp(c.group,h)==0)
						c.showdata();
						}
						f.close();
						break;
					case 3:
						f.open("ContactList.txt",ios::in);
						strcpy(h,"3");
						while(1)
						{
						f.read((char*)&c,sizeof(c));
						if(f.eof())
						break;
						else if(stricmp(c.group,h)==0)
						c.showdata();
						}
						f.close();
						break;
					case 4:
						f.open("ContactList.txt",ios::in);
						strcpy(h,"4");
						while(1)
						{
						f.read((char*)&c,sizeof(c));
						if(f.eof())
						break;
						else if(stricmp(c.group,h)==0)
						c.showdata();
						}
						f.close();
						break;
					default:
						cout<<"GROUP DOES NOT EXISTS!";
						break;
				}
				cout<<"\nTRY AGAIN?\n1.YES\t2.NO";
				cin>>d;
				}while(d!=2);
			}
			}
			else
			break;
			cout<<endl;
			}
			break;
		case 3:
			system("cls");
			do
			{
			int count1=0;
			cout<<"\nNAME OF THE CONTACT YOU WANT TO SEARCH:";
			cin>>query;
			f.open("ContactList.txt",ios::in|ios::app);
			while(1)
			{
			f.read((char*)&c,sizeof(c));
			if(f.eof())
			break;
			if(stricmp(c.name,query)==0)
			{
			c.showdata();
			count1++;
			}
			}
			f.close();
			if(count1==0)
			{
			cout<<"\nMATCHING CONTACT NOT FOUND!";
			cout<<"\nDO YOU WANT TO ADD THIS CONTACT?\n\t1.YES \t2.NO\n";
			cin>>e;
			if(e==1)
			{
				f.open("ContactList.txt",ios::in);
				f1.open("Temp.txt",ios::app);
				while(1)
				{
				f.read((char*)&c,sizeof(c));
				if(f.eof())
				break;
				f1.write((char*)&c,sizeof(c));
				}
				system("cls");
				c.NewContact();
				f1.write((char*)&c,sizeof(c));
				cout<<"CONTACT ADDED SUCCESSFULLY!";
				f.close();
				f1.close();
				remove("ContactList.txt");
				rename("Temp.txt","ContactList.txt");
			}
			}
			else
			cout<<endl<<count1<<" MATCHING CONTACT(S) FOUND"<<endl;
			cout<<"\nPRESS 1 FOR PREVIOUS MENU\nPRESS 0 TO SEARCH ANOTHER CONTACT\nYOUR RESPONSE:";
			cin>>d;
			}while(d!=1);
			break;
		case 4:
			system("cls");
			do
			{
			int count2=0;
			f.open("ContactList.txt",ios::in);
			f1.open("Temp.txt",ios::out);
			cout<<"ENTER THE NAME OF THE CONTACT YOU WANT TO EDIT:";
			cin>>query;
			while(f.eof()!=1)
			{
			f.read((char*)&c,sizeof(c));
			if(f.eof())
			break;
			if(stricmp(c.name,query)==0)
			{
				count2++;
			}
			if(stricmp(c.name,query)!=0)
			{
			f1.write((char*)&c,sizeof(c));
			}
			}
			if(count2==0)
			{
				cout<<"CONTACT NOT FOUND!";
				f.close();
				f1.close();
				remove("Temp.txt");
				goto choice2;
			}
			cout<<"EDIT THE CHOSEN CONTACT:\n";
			c.NewContact();
			f1.write((char*)&c,sizeof(c));
			f.close();
			f1.close();
			cout<<"\nCHOSEN CONTACT EDITED SUCCESSFULLY!";
			remove("ContactList.txt");
			rename("Temp.txt","ContactList.txt");
			choice2:
			cout<<"\nPRESS 1 FOR PREVIOUS MENU\nPRESS 0 TO EDIT ANOTHER CONTACT\nYOUR RESPONSE:";
			cin>>d;
			}while(d!=1);
			break;
		case 5:
			system("cls");
			do
			{
			int count3=0;
			f.open("ContactList.txt",ios::in);
			f1.open("Temp.txt",ios::out);
			cout<<"\nENTER THE NAME OF THE CONTACT YOU WANT TO DELETE:";
			cin>>query;
			while(1)
			{
			f.read((char*)&c,sizeof(c));
			if(f.eof())
			break;
			if(stricmp(c.name,query)==0)
			{
				count3++;
			}
			if(stricmp(c.name,query)!=0)
			{
			f1.write((char*)&c,sizeof(c));
			}
			}
			if(count3==0)
			{
				cout<<"\nCONTACT NOT FOUND!";
				goto choice3;
			}
			f.close();
			f1.close();
			cout<<"CHOSEN CONTACT IS DELETED SUCCESSFULLY!";
			remove("ContactList.txt");
			rename("Temp.txt","ContactList.txt");
			choice3:
			cout<<"\nPRESS 1 FOR PREVIOUS MENU\nPRESS 0 TO DELETE ANOTHER CONTACT\nYOUR RESPONSE:";
			cin>>d;
			}while(d!=1);
			break;
		case 6:
			exit(0);
		default:
			cout<<"INVALID OPTION! PLEASE TRY AGAIN!";
			break;
	}
}while(a!=6);
}
