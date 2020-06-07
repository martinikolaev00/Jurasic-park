#include "input.hpp"

void input::Begin()
{
	cout << "\t\t\t\t~~~~~~ Welcome to JUSARIC PARK ~~~~~~" << endl;
	Input();
}

void input::switchmenu(int command)
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
		adddinosour();
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
		removedinosour();
		break;
	}
	case 5:
	{
		stockfood();
		break;
	}

	
	case 6:
	{
		load();
		break;
	}
	case 7:
	{
		save();
		break;
	}
	case 8:
	{
		feed();
		break;
	}case 9:
	{
		stockfood();
		break;
	}
	default:
	{
		cout << "UKNOWN COMMAND, try again" << endl;
		cin.ignore();
		
	}
	}
}

void input::getcommand()
{
	char buff[20] = { '\0', };
	while (true)
	{

		cin >> buff;
		int command = -1;
		for (int i = 0; i < 11; i++)
		{
			if (!strcmp(buff, commands[i]))
			{
				command = i;
				break;
			}

		}
		if (command == 10)
			break;
		switchmenu(command);
		memset(buff, '\0', 20);
	}
}

void input::Input()
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

void input::menu()
{
	cout << "Welcome to menu, the available commands are: " << endl
		<< "1)add_dinosour" << endl
		<< "2)checkforcage" << endl
		<< "3)buildcage" << endl
		<< "4)remove_dinosour" << endl
		<< "5)stockfood" << endl
		<< "6)load" << endl
		<< "7)save" << endl
		<< "7)feed" << endl
		<< "8)stock_food" << endl
		<< "9)exit" << endl;

	getcommand();
}

void input::adddinosour()
{
	
	char* name = new char[MaxN];
	*name = { '\0', };
	char type[90] = { '\0', };
	char buff[30] = { '\0', };
	Period p;
	Categoryy g;
	Food f;
	Gender ge;
	char types[12][30] = { "triceratop","dracorex","diplodocus","abelisaurus","aerosteon","t-rex","liopleurodon","mauisaurus","helicoprion","pteranodon","pterosaur","pterodactyl" };
	cout << "Please enter name: ";
	cin >> name;
	//cout << endl;
	//char c = cin.peek();
	cout << "Please choose a period:" << endl << " 1)triassic" << endl << " 2)chalk" << endl << " 3)jurassic: ";
	cin >> buff;
	//cout << endl;
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
	cout << "Please choose a category" << endl << " 1)vegitarian" << endl << " 2)carnivorous" << endl << " 3)aqueous" << endl << " 4)flying: ";
	cin >> buff;
	if (!strcmp(buff, "vegitarian"))
	{
		Categoryy cat(buff, 0, types);
		cout << "Please choose type" << endl << " 1)triceratop" << endl << "2)dracorex " << endl << "3)diplodocus : ";
		cin >> type;
		if (cat.checktype(type) == -1)
		{
			cout << "Invalid type, please try again"; return;
		}
		g = cat;
		f = Food::Grass;
	}
	else if (!strcmp(buff, "carnivorous"))
	{
		Categoryy cat(buff, 1, types);
		cout << "Please choose type" << endl << " 1)abelisaurus " << endl << "2)aerosteon " << endl << "3)t-rex: ";
		cin >> type;
		if (cat.checktype(type) == -1)
		{
			cout << "Invalid type, please try again"; return;
		}
		g = cat;
		f = Food::Meat;
	}
	else if (!strcmp(buff, "aqueous"))
	{
		Categoryy cat(buff, 2, types);
		cout << "Please choose type" << endl << " 1)liopleurodon" << endl << "2)mauisaurus" << endl << "3)helicoprion: ";
		cin >> type;
		if (cat.checktype(type) == -1)
		{
			cout << "Invalid type, please try again"; return;
		}
		g = cat;
		f = Food::Fish;
	}
	else if (!strcmp(buff, "flying"))
	{
		Categoryy cat(buff, 3, types);
		cout << "Please choose type"<<endl<<" 1)pteranodon" << endl << "2)pterosaur" << endl << "3)pterodactyl: ";
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
	if (strstr(buff, "flying"))
	{
		cout << "Please choose food:" << endl << " 1)grass" << endl << " 2)meat" << endl << " 3)fish: ";
		cin >> buff;
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
	}
	cout << "Please choose gender:" << endl << " 1)male" << endl << " 2)female: ";
	cin >> buff;
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
	uwu.adddinosour(test);
	cout << "Congratulations you created a dinosour" << endl;
	delete[] name;
}

void input::buildcage()
{
	uwu.createcage();
}

void input::checkforcage()
{
	char buff[100];
	cout << "Write the name of the Dinasour that you need cage for: ";
	cin >> buff;
	int p = uwu.checkfordino(buff);
	if (p == -1)
		cout << "this dinosour doesnt exist yet" << endl;
	else if (uwu.checkforcage(p) == -1)
	{
		cout << "Currently there is no suitable cage for this dinosour, would you like to build one? I thought so, lets head to the menu" << endl;
		menu();
	}
	else {
		cout << "We found a suitable cage for the dinosour.Welcome to the JURASIC zoo " << buff << endl;
		uwu.adddinoincage(uwu.checkforcage(p), p); // check
	}
}

void input::stockfood()
{
	uwu.stockfood();
}

void input::feed()
{
	uwu.feed();
}

void input::load()
{
	cout << "Loading process starting" << endl;
	uwu.deserialize();
}

void input::save()
{
	cout << "Saving process started" << endl;
	uwu.serialize();
}

void input::removedinosour()
{
	char name[200];
	cout << "Whats the name of the dinosour u want to remove: " << endl;
	cin >> name;
	int p=uwu.checkfordino(name);
	if (p != -1)
	{
		uwu.removedino(p);
	}
	else {
		cout << "This dinosour doesnt exist in our zoo, would you like to create it?(y/n): ";
		char c; cin >> c;
		if (c == 'y')
			adddinosour();
	}


}

//void input::help()
//{
//	cout << "You have chosen help: " << endl;
//	
//}
