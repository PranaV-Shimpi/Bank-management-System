#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<windows.h>
#include<string>


using namespace std;

void colour (int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}

class account
{
	int acno;
	char name[50];
	int deposit;
	char type;
public:
	void create_account();
	void show_account() ;
	void modify();
	void dep(int);
	void draw(int);
	void report();
	int retacno();
	int retdeposit();
	char rettype();
	void printFile();
};

void account::create_account()
{
	system("cls");
	cout<<"\n\n\t\t\t\tEnter Following Detaills";
	cout<<"\n\n\t\t\tAccount No. : ";
	cin>>acno;
	cout<<"\n\n\t\t\tName : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tEnter Type of the Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tInitial amount : ";
	cin>>deposit;
	cout<<"\n\n\n\n\t\t\tYour Account is successfully Created...";
}

void account::show_account()
{
    cout<<"\n\t\t\tAccount No. : "<<acno;

	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}


void account::modify()
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>deposit;
}

void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report()
{
	cout<<"\t\t"<<setw(3)<<acno<<setw(10)<<" "<<name<<setw(12)<<"  "<<type<<setw(13)<<"  "<<deposit<<endl;
}

int account::retacno()
{
	return acno;
}

int account::retdeposit()
{
	return deposit;
}

char account::rettype()
{
	return type;
}



void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void printFile();
int main()
{
	char ch;
	int num;
	do
	{
	system("cls");

	cout<<"\n\n\t\t\t=========================================\n";
	colour(110);
	cout<<"\t\t\t\t\t SWISS BANKS ";
	colour(15);
	colour(2300);
	cout<<"\n\t\t\t\t   Handcrafted in India   ";
    colour(15);

	cout<<"\n\t\t\t=========================================\n";
        colour(1152);
		cout<<"\n\t\t\t\t\t**MAIN MENU**\n";
		colour(15);
		cout<<"\n\t\t\t\t#1. CREATE NEW ACCOUNT";
		cout<<"\n\t\t\t\t#2. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t\t#3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t\t#4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t#5. LIST OF TOTAL ACCOUNTS";
		cout<<"\n\t\t\t\t#6. DELETE AN ACCOUNT";
		cout<<"\n\t\t\t\t#7. MODIFY AN ACCOUNT";
        cout<<"\n\t\t\t\t#8. TERMS AND CONDITIONS";
        cout<<"\n\t\t\t\t#9. EXIT";
		cout<<"\n\n\t\t\t\tSELECT OPTIONS : ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
		 	system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
		 	system("cls");
			cout<<"\n";
            printFile();
			break;

		 case '9':
		 	//system("cls");
			cout<<"\n\n\t\t\t ";
			cout<<"\n\n\t\t\t!!*********YOUR TRANSACTION IS SCUCCESFUL*********!!";
			cout<<"\n\n\t\t                            THANK YOU..... !!";

			break;
		 default :cout<<"\n\n\t\tWRONG INPUT ....";break;
		}
		cin.ignore();
		cin.get();
    }while(ch!='9');
	return 0;
}


void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.txt",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist";
}



void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
    File.open("account.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    cout<<"\n\n\t\t\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}



void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.txt",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.txt");
	rename("Temp.txt","account.txt");
	cout<<"\n\nRecord Deleted ...";
}


void display_all()
{
	system("cls");
	account ac;
	ifstream inFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\t\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"\t\t====================================================\n";
	cout<<"\t\tA/c no.      NAME           Type         Balance\n";
	cout<<"\t\t====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}


void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
    File.open("account.txt", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\t\t\tTO DEPOSIT AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if(bal<0)
					cout<<"Insufficient balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";

}


void printFile()
{

    ifstream infile("tc.txt");
    string line;
    while (getline(infile, line)) {
    cout << line << endl;
  }
}
