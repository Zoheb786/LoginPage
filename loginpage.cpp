#include<iostream>
#include<conio.h>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
using namespace std;
void regstr();
void login();
void forgot();
void exit();
int main()
{
	int choice;
    cout<<"****************Login Page******************\n";
    cout<<"1.Registration\n";
    cout<<"2.Login\n";
    cout<<"3.Forgot Credentials\n";
    cout<<"4.Exit\n";
    cout<<"Enter your choice.\n";
    cin>>choice;
    
//    switch case for getting choices
	 
	 switch(choice)
	 {
	 	case 1:
	 		regstr();
	 		break;
	 	case 2:
	 		login();
			break;
		case 3:
			forgot();
			break;
		case 4:
			exit();	
			break;
		default:
			cout<<"\nSorry Wrong Choice Selected\n";
			break;
			main();
    }
}
void regstr()
{
	string reguser,regpass;
	system("cls");
	cout<<"Enter the UserName\n";
	cin>>reguser;
	cout<<"Enter the Password\n";
	cin>>regpass;
	
	ofstream reg("database.txt",ios::app);
	reg<<reguser<<"    "<<regpass<<endl;
	system("cls");
	cout<<"Registration is Successfull\n";
	main();
}

void login()
{
	int exist;
	string user,pass,u,p;
	system("cls");
	cout<<"Enter the UserName:\n";
	cin>>user;
	cout<<"Enter the Password:\n";
	cin>>pass;
	
	ifstream input("database.txt");
	
	while(input>>u>>p)
	{
		if (u==user && p==pass)
		{
			exist=1;
			break;
		}
	}
	input.close();
	if(exist==1)
	{
		cout<<"Hello! "<<user<<" Welcome..!!\n";
		cin.get();
		cin.get();
		main();
	}
	else
	{
		cout<<"Sorry..Login ERROR\n";
		cin.get();
		cin.get();
		main();
	}
}
void forgot()
{
	int ch;
	cout<<"1.Find Account by UserName\n";
	cout<<"2.Main Menu\n";
	cin>>ch;
	
	switch(ch)
	{
		case 1:
			{
			int ex=0;
			string searchuser,sp,su;
			cout<<"Enter Your UserName\n";
			cin>>searchuser;
			
			ifstream searchu("database.txt");
			while(searchu>>su>>sp)
			{
				if(su == searchuser)
				{
					ex=1;
					break;
				}
			}
			searchu.close();
			if(ex==1)
			{
				cout<<"Hurray!!Your Account is Founded\n";
				cout<<"Your Password is\t"<<sp;
				cin.get();
				cin.get();
				main();
			}
			else
			{
				cout<<"Sorry you have no Account\n";
				cin.get();
				cin.get();
				main();
			}
			break;
		}
			case 2:
				{
				main();
			}
			default:
				{
				forgot();
			}
	}
}
void exit()
{
	cout<<"\nOkay...Its your Choice..!!";
	getch();
}
