#pragma once
#include<iostream>
#include<istream>
#include<cctype>
#include<cstring>
#include"HQ.hpp"
#include"Commands.hpp"
#include"Category.hpp"
using std::cout;
using std::cin;
using std::endl;

static HQ hq;
const int MaxN = 200;
char commands[8][20] = { "menu","add_dinasour" , "checkforcage","buildcage","remove_dinasour","stockfood", "help","exit" };



void Begin()
{
	cout << "\t\t\t\t~~~~~~ Welcome to JUSARIC PARK ~~~~~~" << endl;
	Input();
}


void switchmenu(int command)
{
	switch (command)
	{
	case 0:
	{
		menu();
		break;
	}
	case 1:
	{
		adddinasour();
		break;
	}
	case 2:
	{
		checkforcage();
		break;
	}case 3:
	{
		buildcage();
		break;
	}
	case 4:
	{
		removedinasour();
		break;
	}
	case 5:
	{
		stockfood();
		break;
	}

	case 6:
	{
		help();
		break;
	}
	case 7:
	{
		return;
		break;
	}
	default:
	{
		cout << "UKNOWN COMMAND, try again" << endl;
		cin.ignore();
		menu();
	}
	}
}


void getcommand()
{
	char buff[20] = { '\0', };
	while (true)
	{
		
		cin >> buff;
		int command = -1;
		for (int i = 0; i < 9; i++)
		{
			if (!strcmp(buff, commands[i]))
			{
				command = i;
				break;
			}

		}
		if (command == 8)
			break;
		switchmenu(command);
		memset(buff, '\0', 20);
	}

}
void Input()
{
	char buff[20] = { '\0', };
	do
	{
		cout << "Type menu if you want to see commands" << endl;

		cin >> buff;
		if (!strcmp(buff, commands[0]))
			break;
		memset(buff, 20, '\0');
	} while (true);
	menu();

}


void menu()
{
	cout << "Welcome to menu, the available commands are: " << endl
		<< "1)add_dinasour" << endl
		<< "2)checkforcage" << endl
		<< "3)buildcage" << endl
		<< "4)remove_dinasour" << endl
		<< "5)stockfood" << endl
		<< "6)help" << endl
		<< "7)exit" << endl;

	getcommand();

}

void adddinasour()
{
	char name[MaxN] = { '\0', };
	char type[90] = { '\0', };
	char buff[30] = { '\0', };
	Period p;
	Categoryy g;
	Food f;
	Gender ge;
	char types[12][30]= { "type1","type2","type3","type4","type5","type6","type7","type8","type9","type10","type11","type12" };
	cout << "Please enter name: ";
	cin >> name;
	cout << endl;
	char c = cin.peek();
	cout << "Please choose a period:" << endl<<" 1)triassic" << endl << " 2)chalk" << endl << " 3)jurassic: ";
	cin >> buff;
	cout << endl;
	if (!strcmp(buff, "triassic"))
		p = Period::Triassic;
	else if (!strcmp(buff, "chalk"))
		p = Period::Chalk;
	else if (!strcmp(buff, "jurassic"))
		p = Period::Jurassic;
	else
	{
		cout << "Invalid period, try again" << endl;
		return;
	}	
	cout << "Please choose a category" << endl << " 1)vegitarian" << endl << " 2)carnivorous"<< endl<<" 3)aqueous" << endl << " 4)flying: ";
	cin >> buff;
	cout << endl;
	if (!strcmp(buff, "vegitarian"))
	{
		Categoryy cat(buff, 0,types);
		cout << "Please choose type 1)type1" << endl << "2)type2" << endl << "3)type3: ";
		cin >> type;
		
		if (cat.checktype(type) == -1)
		{
			cout << "Invalid type, please try again"; return;
		}
		g = cat;
	}
	else if (!strcmp(buff, "carnivorous"))
	{
		Categoryy cat(buff, 1, types);
		cout << "Please choose type 1)type4" << endl << "2)type5" << endl << "3)type6: ";
		cin >> type;
		
		if (cat.checktype(type) == -1)
		{
			cout << "Invalid type, please try again"; return;
		}
		g = cat;
	}
	else if (!strcmp(buff, "aqueous"))
	{
		Categoryy cat(buff, 2,types);
		cout << "Please choose type 1)type7" << endl << "2)type8" << endl << "3)type9: ";
		cin >> type;
		
		if (cat.checktype(type) == -1)
		{
			cout << "Invalid type, please try again"; return;
		}
		g = cat;
	}
	else if (!strcmp(buff, "flying"))
	{
		Categoryy cat(buff, 3, types);
		cout << "Please choose type 1)type10" << endl << "2)type11" << endl << "3)type12: ";
		cin >> type;
		
		if (cat.checktype(type) == -1)
		{
			cout << "Invalid type, please try again"; return;
		}
		g = cat;
	}
	else
	{
		cout << "Invalid category, try again" << endl;
		return;
	}
	cout << "Please choose food:" << endl << " 1)grass" << endl << " 2)meat" << endl << " 3)fish: ";
	cin >> buff;
	cout << endl;
	if (!strcmp(buff, "grass"))
		f = Food::Grass;
	else if (!strcmp(buff, "meat"))
		f = Food::Meat;
	else if (!strcmp(buff, "fish"))
		f = Food::Fish;
	else
	{
		cout << "Invalid food, try again" << endl;
		return;
	}
	cout << "Please choose gender:" << endl << " 1)male" << endl << " 2)female: ";
	cin >> buff;
	cout << endl;
	if (!strcmp(buff, "male"))
		ge = Gender::Male;
	else if (!strcmp(buff, "female"))
		ge = Gender::Female;
	else
	{
		cout << "Invalid gender, try again" << endl;
		return;
	}
	Dinasour test(name, p, g, f, ge, type);
	hq.adddinasour(test);
	cout << "Congratulations you created a dinasour" << endl;
	getcommand();
}
void buildcage()
{
	hq.createcage();
}
void checkforcage() 
{
	char buff[100];
	cout << "Write the name of the Dinasour that you need cage for: ";
	cin >> buff;
	int p = hq.checkfordino(buff);
	if (p==-1)
		cout << "this dinasour doesnt exist yet" << endl;
	else if (hq.checkforcage(p) == -1)
	{
		cout << "Currently there is no suitable cage for this dinasour, would you like to build one? I thought so, lets head to the menu" << endl;
		menu();
	}
	else {
		cout << "We found a suitable cage for the dinasour.Welcome to the JURASIC zoo" << buff << endl;
		hq.adddinoincage(hq.checkforcage(p), p); // check
	}
}

void removedinasour()
{
	cout << "this part of the zoo is currently inavailable" << endl;
	menu();
}
void stockfood()
{
	cout << "this part of the zoo is currently inavailable" << endl;
	menu();
}



void help()
{
	cout << "You have chosen help: " << endl;
		/*"registration - <username*> <age> <email> - spots marked with * must be filled for a successful registration" << endl <<
		"challenge <challenger*> <#challenge*> <challenged users*> - all participants must be registred" << endl <<
		"profile_info <username*> - prints out information for the user" << endl <<
		"list_by  <newest/oldest/most_popular*> - prints out all registered challenges" << endl <<
		"exit - closes the application" << endl;*/
	
}
