#include<iostream>
#include<conio.h>
#include<string>
#include<time.h>
#include<fstream>
#include<cstdlib>
using namespace std;

void welcome();
int destination();
int international();
int Domestic();
int Departure();

struct Billing
{
	string name;
	int ticto[25], con[25], adl[25], chld[25], inf[25];
};

int bill(int i);
int clas();
int discode();
int discount(int, int);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int ch, selDs, selDp;
	int cusnum = 0, total = 0, totalbill = 0;
	int code = 0;

	fstream fl;
	string name;
	fl.open("D:\\customer choice info.txt", ios::out);

	if (!fl)
	{
		cout << "File not open" << endl;
	}
	else
	{
		welcome();
		ch = destination();
		if (ch == 1)
		{
			selDs = international();
			selDp = Departure();
			total = total + 500;		//since user choosed international travel total is incremented by 500 $
			switch (selDs)							//storing  destination location in a file
			{
			case 1:
				fl << "Destination : Dubai\n" << endl;
				break;
			case 2:
				fl << "Destination : Bejing\n" << endl;
				break;
			case 3:
				fl << "Destination : London\n" << endl;
				break;
			case 4:
				fl << "Destination : Paris\n" << endl;
				break;
			case 5:
				fl << "Destination : Barcelona\n" << endl;
				break;
			case 6:
				fl << "Destination : Munich\n" << endl;
				break;
			case 7:
				fl << "Destination : New York\n" << endl;
				break;
			case 8:
				fl << "Destination : Los Angelas\n" << endl;
				break;
			default:
				cout << "Destination not updated" << endl;
				break;
			}
			switch (selDp)			//storing departure location in a file
			{
			case 1:
				fl << "Deprature : Islamabad International Airport\n" << endl;
				break;
			case 2:
				fl << "Departure location : Lahore International Airport\n" << endl;
				break;
			case 3:
				fl << "Departure location : Peshwar International Airport\n" << endl;
				break;
			case 4:
				fl << "Departure location : Karachi International Airport\n" << endl;
				break;
			case 5:
				fl << "Departure location : Quetta International Airport\n" << endl;
				break;
			default:
				cout << "Departure location not updated" << endl;
				break;
			}
		}
		else
		{
			selDs = Domestic();
			selDp = Departure();
			total = total + 150;				//since user choosed domestic flight total is incremented by 150 $
			switch (selDs)						//storing destination location in a file
			{
			case 1:
				fl << "Destination : Mirpur AJK\n" << endl;
				break;
			case 2:
				fl << "Destination : Naran\n" << endl;
				break;
			case 3:
				fl << "Destination : Skardu\n" << endl;
				break;
			case 4:
				fl << "Destination : Thar Desert\n" << endl;
				break;
			case 5:
				fl << "Destination : Multan\n" << endl;
				break;
			case 6:
				fl << "Destination : D.G Khan\n" << endl;
				break;
			case 7:
				fl << "Destination : Abbotabad\n" << endl;
				break;
			case 8:
				fl << "Destination : Gwadar\n" << endl;
				break;
			default:
				cout << "Destination not updated" << endl;
				break;
			}
			switch (selDp)							//storing departure location in a file
			{
			case 1:
				fl << "Deprature : Islamabad International Airport\n" << endl;
				break;
			case 2:
				fl << "Departure location : Lahore International Airport\n" << endl;
				break;
			case 3:
				fl << "Departure location : Peshwar International Airport\n" << endl;
				break;
			case 4:
				fl << "Departure location : Karachi International Airport\n" << endl;
				break;
			case 5:
				fl << "Departure location : Quetta International Airport\n" << endl;
				break;
			default:
				cout << "Departure location not updated" << endl;
				break;
			}
		}
	}

	cout << "Enter customer number =" << endl;		//No of customer is handled whom will use
	cin >> cusnum;
	ch = clas();
	total = total + bill(cusnum);
	if (ch == 1)
	{
		total = total + 200;
	}

	if (total >= 1000)				//to check if customer is applicable for discount
	{
		cout << "Your total before discount is = " << total << endl;

		for (int i = 0; i < 55; i++)
		{
			cout << "*";
		}
		cout << endl;

		code = discode();
	}
	if (code != 0)
	{
		totalbill = discount(total, code);		//total bill calucalted after discount is cut off 
	}
	else
	{
		totalbill = total;
	}
	for (int i = 0; i < 55; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "Thank you for shopping with Us\n We wish you a fantastic adventure" << endl;
	cout << "Your total bill is = " << totalbill << " $" << endl;
	fl << "total = " << totalbill << " $" << endl;
	fl.close();
	for (int i = 0; i < 55; i++)
	{
		cout << "*";
	}
	cout << endl;




	_getch();
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void welcome()
{
	for (int i = 0; i < 55; i++)
	{
		cout << "*";
	}
	cout << endl;																									// Welcome function for users
	cout << "\t\tWelcome to Ticket Hub" << endl;
	for (int i = 0; i < 55; i++)
	{
		cout << "*";
	}
	cout << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int destination()								//customer is offered 2 choices to travel international or domestic
{												//And according to choice total will increase
	int ch;
	char cho = 'n';
	while (cho == 'n')
	{
		cout << "Please select where you wish to travel\n\t 1 for International(+500 $)\n\t 2 for Domestic(+150 $)" << endl;		//Selection of International or domestic travel
		cin >> ch;
		if (ch == 1)
		{
			cout << "International selected !" << endl;
		}
		else if (ch == 2)
		{
			cout << "Domestic selected !" << endl;
		}
		cout << "If you had an oopsie you can go back by entering 'n'\nIf not then press 'y'to countinue." << endl;	// Asking user to recheck their selection
		cin >> cho;
	}
	for (int i = 0; i < 55; i++)
	{
		cout << "*";
	}
	cout << endl;
	return ch;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int international()										// customer is offered different location where he/she wishes to travel
{
	int ch;
	char cho = 'n';

	while (cho == 'n')
	{
		cout << "Currently Ticket Hub are offering these lavish Destionations" << endl;								   	// Destinations list offered by company 	
		cout << " 1) Dubai \t2) Bejing\n 3) London \t4) Paris\n 5) Barcelona \t6) Munich\n 7) New York \t8) Los Angelas" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\tDubai Selected !" << endl;
			break;
		case 2:
			cout << "\tBejing Selected !" << endl;
			break;
		case 3:
			cout << "\tLondon Selected !" << endl;																		// Checking which destinantion is selected	
			break;																										// and informing user about selection
		case 4:
			cout << "\tParis Selected !" << endl;
			break;
		case 5:
			cout << "\tBarcelona Selected !" << endl;
			break;
		case 6:
			cout << "\tMunich Selected !" << endl;
			break;
		case 7:
			cout << "\tNew York Selected !" << endl;
			break;
		case 8:
			cout << "\tLos Angelas Selected !" << endl;
			break;
		default:
			cout << "Invalid selection try again" << endl;
			break;
		}
		cout << "If you had an oopsie you can go back by entering 'n'\nIf not then press 'y'to countinue." << endl;	// Asking user to recheck their selection
		cin >> cho;
	}
	for (int i = 0; i < 55; i++)
	{
		cout << "*";
	}
	cout << endl;
	return ch;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Domestic()					// customer is offered different location where he/she wishes to travel
{
	int ch;
	char cho = 'n';
	while (cho == 'n')
	{
		cout << "Currently Ticket Hub are offering these thrilling Destionations" << endl;								   	// Destinations list offered by company 	
		cout << " 1) Mirpur AJK \t2) Naran\n 3) Skardu \t4) Thar Desert\n 5) Multan \t6) D.G Khan\n 7) Abbotabad \t8) Gwadar" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\tMirpur AJK Selected !" << endl;
			break;
		case 2:
			cout << "\tNaran Selected !" << endl;
			break;
		case 3:
			cout << "\tSkardu Selected !" << endl;																		// Checking which destinantion is selected	
			break;																										// and informing user about selection
		case 4:
			cout << "\tThar Desert Selected !" << endl;
			break;
		case 5:
			cout << "\tMultan Selected !" << endl;
			break;
		case 6:
			cout << "\tD.G Khan Selected !" << endl;
			break;
		case 7:
			cout << "\tAbbotabad Selected !" << endl;
			break;
		case 8:
			cout << "\tGwadar Selected !" << endl;
			break;
		default:
			cout << "Invalid selection try again" << endl;
			break;
		}
		cout << "If you had an oopsie you can go back by entering 'n'\nIf not then press 'y'to countinue." << endl;	// Asking user to recheck their selection
		cin >> cho;
	}
	for (int i = 0; i < 55; i++)
	{
		cout << "*";
	}
	cout << endl;
	return ch;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Departure()						//customer is asked for Depatur location according to his/her convenience 
{
	int ch;
	char cho = 'n';
	while (cho == 'n')
	{
		cout << "Currently Ticket Hub are offering these location to Depart from:" << endl;								   	// Destinations list offered by company 	
		cout << " 1) Islamabad Internation Airport \t2) Lahore Internation Airport\n 3) Peshawar International Airport \t4) Karachi International Airport\n 5) Quetta International Airport" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\tYou selected Islamabad International Airport as your Departing location !" << endl;
			break;
		case 2:
			cout << "\tYou selected Lahore International Airport as your Departing location !" << endl;
			break;
		case 3:
			cout << "\tYou selected Peshawar International Airport as your Departing location !" << endl;				// Checking which destinantion is selected	
			break;																										// and informing user about selection
		case 4:
			cout << "\tYou selected Karachi International Airport as your Departing location !" << endl;
			break;
		case 5:
			cout << "\tYou selected Quetta International Airport as your Departing location !" << endl;
			break;
		default:
			cout << "Invalid selection try again" << endl;
			break;
		}
		cout << "If you had an oopsie you can go back by entering 'n'\nIf not then press 'y'to countinue." << endl;	// Asking user to recheck their selection
		cin >> cho;
	}
	for (int i = 0; i < 55; i++)
	{
		cout << "*";
	}
	cout << endl;
	return ch;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int clas()								//customer is issued 2 choices to select a travelling group a Luxuary one which will add 200 to total and an Econmy one which won't add any to total value
{
	int ch;
	cout << "We are currently offering:\n\t1)A luxuary class:(+200) \t 2)An Econmy class:(+0)" << endl;
	cout << "\tFrench fine cusine\t\t Desi Tarka \n\twith Complementary Beverage\t Cold Drink of choice" << endl;
	cin >> ch;
	for (int i = 0; i < 55; i++)
	{
		cout << "*";
	}
	cout << endl;
	if (ch == 1)
	{
		cout << "You selected Luxuary class" << endl;
	}
	else
		cout << "You selected Econmy" << endl;
	return ch;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int bill(int i)								// A file is created in which customer information is collected includeing name,contact details and etc.
{
	struct Billing bill;
	srand(time(0));
	int total = 0;
	char cho = 'n';

	fstream fl;
	string name;
	fl.open("D:\\customer info.txt", ios::out);

	if (!fl)
	{
		cout << "File not open" << endl;
	}
	else
	{
		while (cho == 'n')
		{
			cout << "Enter Name =" << endl;
			getline(cin, bill.name);
			cin >> bill.name;
			fl << "Name : " << bill.name << "\n";

			cout << "Enter Contact =" << endl;
			cin >> bill.con[i];
			fl << "Contact : " << bill.con[i] << "\n";

			cout << "\nAdult = 250 $\n\n\tChildren = 200 $\n\n\t\tInfants = 150 $" << endl << endl;
			cout << "Enter number of adults" << endl;
			cin >> bill.adl[i];
			fl << "Number of Adult tickets: " << bill.adl[i] << "\n";

			total = total + bill.adl[i] * 250;

			for (int i = 0; i < 55; i++)
			{
				cout << "*";
			}
			cout << endl;

			cout << "Enter number of children" << endl;
			cin >> bill.chld[i];
			fl << "Number of Child tickets: " << bill.chld[i] << "\n";
			total = total + bill.chld[i] * 200;

			for (int i = 0; i < 55; i++)
			{
				cout << "*";
			}
			cout << endl;

			cout << "Enter number of infants" << endl;
			cin >> bill.inf[i];
			fl << "Number of Infant tickets: " << bill.inf[i] << "\n";
			total = total + bill.inf[i] * 150;

			for (int i = 0; i < 55; i++)
			{
				cout << "*";
			}
			cout << endl;

			bill.ticto[i] = total;


			for (int i = 0; i < 55; i++)
			{
				cout << "*";
			}
			cout << endl;

			cout << "If you had an oopsie you can go back by entering 'n'\nIf not then press 'y'to countinue." << endl;	// Asking user to recheck their selection
			cin >> cho;
		}
		fl.close();
	}
	for (int i = 0; i < 55; i++)
	{
		cout << "*";
	}
	cout << endl;
	return total;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int discode()									// A discount code will be generated
{
	int disc = 0;
	cout << "Congradulation !!! since your total exceeded 1000" << endl;
	cout << "Ticket Hub will give you a discount code which you can enter" << endl;
	cout << "At checkout to get discount" << endl;
	for (int k = 0; k < 5; k++)
	{
		disc = rand() % 10000;
	}
	cout << "Your discount code is = " << disc << endl;
	for (int i = 0; i < 55; i++)
	{
		cout << "*";
	}
	cout << endl;
	return disc;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int discount(int x, int code)					//Discount code compared with generated one and the typed in one which if matched will cut out 10% of total cost
{
	int val, codin;

xyz:
	cout << "Enter your discount code =" << endl;
	cin >> codin;
	if (codin == code)
	{
		val = x * 0.9;
		goto abc;
	}
	goto xyz;
abc:
	for (int i = 0; i < 55; i++)
	{
		cout << "*";
	}
	cout << endl;
	return val;
}