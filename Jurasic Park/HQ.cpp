#include "HQ.hpp"




void HQ::adddinosour(const Dinasour& dino)
{
	dinosours.addelem(dino);
	staff++;
}

void HQ::addcage(const Cage& cage)
{
	cages.addelem(cage);
	
}

int HQ::checkforcage(int idx)
{
	int cagecount = cages.size();
	for (int i = 0; i < cagecount; ++i)
	{
		if (cages[i].Checkforcage(dinosours[idx]))
			return i;
	}
	return -1;
}

int HQ::checkfordino(char* name)
{
	char* c=nullptr;
	int dinacount = dinosours.size();
	for (int i = 0; i < dinacount; ++i)
	{
		if(!strcmp(dinosours[i].getname(c),name))
		{ 
			delete[] c;
			return i;
		}
	}
	delete[] c;
	return -1;
}

void HQ::adddinoincage(int idxcage , int idxdino)
{
	cages[idxcage].adddino(dinosours[idxdino]);
}

void HQ::createcage()
{
	std::cout << "Please enter what size cage you want: " << std::endl << "1)Small" << std::endl << "2)Medium" << std::endl << "3)Large: ";
	char buff[20]; std::cin >> buff;
	Size size;
	if (!strcmp(buff,"large"))
		size = Size::Big;
	else if(!strcmp(buff, "medium"))
		size = Size::Medium;
	else if(!strcmp(buff, "small"))
		size = Size::Small;
	else
	{
		std::cout << "enter a valid option" << std::endl;
		return;
	}
	Climate climat;
	std::cout << "Please enter what kind of climate you want for your cage: " << std::endl << "1)Earth" << std::endl << "2)Water" << std::endl << "3)Air: ";
	std::cin >> buff;
	if (!strcmp(buff, "earth"))
		climat = Climate::Earth;
	else if (!strcmp(buff, "water"))
		climat = Climate::Water;
	else if (!strcmp(buff, "air"))
		climat = Climate::Air;
	else
	{
		std::cout << "enter a valid option" << std::endl;
		return;
	}
	Period period = Period::Unknown;
	Cage buffer(size, climat, period);
	cages.addelem(buffer);
	std::cout << "Cage successfully created" << std::endl;

}

bool HQ::isdinoincage(char* name)
{
	int p = checkfordino(name);
	if (p != -1)
	{
		for (int i = 0; i < cages.size(); ++i)
		{
			if (cages[i].checkfordino(dinosours[p]))
				return true;
		}
	}
	return false;
}

void HQ::removedino(int idx)
{
	int size = cages.size();
	for (int i = 0; i < size; ++i)
	{
		if (cages[i].removedino(dinosours[idx]))
			return;
	}
}

void HQ::feed()
{
	int meat = 0,grass = 0,fish = 0;
	int size = cages.size();
	for (int i= 0; i < size; ++i)
	{
		cages[i].getfood(meat, grass, fish);
	}
	if ((food[0] - meat < 0) || (food[1] - grass < 0) || (food[2] - fish < 0))
	{
		std::cout << "There isnt enough food to feed all dinosours, we need to restock" << std::endl;
		std::cout << "There is" << food[0] << "meat and we need: " << meat << "there is" << food[1] << "grass and we need: " << grass << "there is" << food[2] << "fish and we need: " << fish << std::endl;
		return;
	}
	else
	{
		food[0] -= meat;
		food[1] -= grass;
		food[2] -= fish;
		std::cout << "You've successfully fed all the dinosours" << std::endl;
	}
}

void HQ::stockfood()
{
	int q = max(food[0], food[1], food[2]);
	std::cout << "What amount do u want to acquire for each type: ";
	int p; std::cin >> p;
	if (p+q> 2000000000)
	{
		std::cout << "The requested amount is too much" << std::endl;
		return;
	}
	for (int i = 0; i < 3; ++i)
		food[i] += p;
}

int HQ::max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return a;
	else if (b >= a && b >= c)
		return b;
	else return c;
}

void HQ::serialize()
{
	std::ofstream ofs("Dinosours.bin", std::ios::binary);
	int p = dinosours.size();
	ofs.write((const char*)&p, sizeof(int));
	for (int i = 0; i < p; ++i)
		dinosours[i].serialize(ofs);
	std::ofstream cfs("Cages.bin", std::ios::binary);
	 p = cages.size();
	 cfs.write((const char*)&p, sizeof(int));
	for (int i = 0; i < p; ++i)
		cages[i].serialize(cfs);
	std::ofstream other("other.bin", std::ios::binary);
	
	for (int i = 0; i < 3; ++i)
		other.write((const char*)&food[i], sizeof(int));
	other.write((const char*)&staff, sizeof(int));
	ofs.close();
	cfs.close();
	other.close();
	std::cout << "Saving complete" << std::endl;
}

void HQ::deserialize()
{
	std::ifstream ifs("Dinosours.bin", std::ios::binary);
	int p;
	ifs.read((char*)&p, sizeof(int));
	Dinasour buff;
	for (int i = 0; i < p; ++i)
	{
		buff.deserialize(ifs);
		dinosours.addelem(buff);
	}
	std::ifstream cfs("Cages.bin", std::ios::binary);
	cfs.read((char*)&p, sizeof(int));
	Cage test;
	for (int i = 0; i < p; ++i)
	{
		test.deserialize(cfs);
		cages.addelem(test);
	}
	std::ifstream other("other.bin", std::ios::binary);
	for (int i = 0; i < 3; ++i)
		other.read((char*)&food[i], sizeof(int));
	other.read((char*)&staff, sizeof(int));
	ifs.close();
	cfs.close();
	other.close();
	std::cout << "Loading complete" << std::endl;

}
