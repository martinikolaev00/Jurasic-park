#include "Dinasour.h"
#include<cstring>
Dinasour::Dinasour():name(nullptr),period(Period::Unknown),category(),food(Food::Unknown),gender(Gender::Unknown),type(nullptr)
{
	name = new char[100];
	name[99] = '\0';
	type = new char[100];
	type[99] = '\0';
}
Dinasour::Dinasour(const char* name, Period period, Categoryy& category, Food food, Gender gender, const char* type)
{
	init(name, period, category, food, gender, type);


}

Dinasour::Dinasour(const Dinasour& other)
{
	name = new char[strlen(other.name)];
	name[strlen(other.name)] = '\0';
	type = new char[strlen(other.type)];
	type[strlen(other.type)] = '\0';
	copy(other);

}

Dinasour& Dinasour::operator=(const Dinasour& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;

}

Dinasour::~Dinasour()
{
	del();
}

void Dinasour::init(const char* name, Period period, Categoryy& category, Food food, Gender gender, const char* type)
{

	this->name = new char[strlen(name)+1];
	this->type= new char[strlen(type)+1];
	strcpy(this->name, name);
	this->name[strlen(name)] = '\0';
	this->period = period;
	this->category = category;
	this->food = food;
	this->gender = gender;
	strcpy(this->type, type);
	this->type[strlen(type)] = '\0';
}
 


void Dinasour::copy(const Dinasour& other)
{
	strcpy(name, other.name);
	period = other.period;
	category = other.category;
	food = other.food;
	gender = other.gender;
	strcpy(type, other.type);
}

Period Dinasour::getperiod()
{
	return period;
}

Categoryy& Dinasour::getcategory()
{
	return category;
}

char* Dinasour::getname(char* buff)
{
	buff = new char[strlen(name) + 1];
	strcpy(buff, name);
	buff[strlen(name)] = '\0';
	return buff;
}

bool Dinasour::operator==(const Dinasour& other)
{
	if (!strcmp(name, other.name))
		if (!strcmp(type, other.type))
			if (period == other.period)
				if (category == other.category)
					if (food == other.food)
						if (gender == other.gender)
							return true;
	return false;


}

Food Dinasour::getfood()
{
	return food;
}

char* Dinasour::gettype(char* buff)
{
	return buff = category.getcategory(buff);
}

void Dinasour::serialize(std::ofstream& ofs)
{
	if (!ofs.is_open())
	{
		std::cout << "File isnt opened" << std::endl;
		return;
	}
	int nam =strlen(name);
	ofs.write((const char*)&nam, sizeof(int));
	ofs.write(name, nam);
	int p = (int)period;
	ofs.write((const char*)&p, sizeof(int));
	category.serialize(ofs);
	p = (int)food;
	ofs.write((const char*)&p, sizeof(int));
	p = (int)gender;
	ofs.write((const char*)&p, sizeof(int));
	int typ = strlen(type);
	ofs.write((const char*)&typ, sizeof(int));
	ofs.write(type, typ);
}

void Dinasour::deserialize(std::ifstream& ifs)
{
	if (!ifs.is_open())
	{
		std::cout << "File isnt opened" << std::endl;
		return;
	}
	del();
	int nam;
	ifs.read((char*)&nam, sizeof(int));
	name = new char[nam+1];
	ifs.read(name, nam);
	name[nam] = '\0';
	int p;
	ifs.read((char*)&p, sizeof(int));
	if (p == 0)
		period = Period::Triassic;
	if (p == 1)
		period = Period::Chalk;
	if (p == 2)
		period = Period::Jurassic;
	category.deserialize(ifs);
	ifs.read((char*)&p, sizeof(int));
	if (p == 0)
		food = Food::Grass;
	if (p == 1)
		food = Food::Meat;
	if (p == 2)
		food = Food::Fish;
	ifs.read((char*)&p, sizeof(int));
	if (p == 0)
		gender = Gender::Male;
	if (p == 1)
		gender = Gender::Female;
	int typ;
	ifs.read((char*)&typ, sizeof(int));
	type = new char[typ+1];
	type[typ] = '\0';
	ifs.read(type, typ);




}





void Dinasour::del()
{
	delete[] name;
	delete[] type;
}
