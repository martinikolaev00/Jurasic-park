#include "Cage.hpp"
#include<cstring>

Cage::Cage():size(Size::Unknown),climate(Climate::Unknown),period(Period::Unknown),category(),dinosours()
{
	
}



Cage::Cage(Size size, Climate climate, Period peroid, int inhabitants,Categoryy& category)
{
	init(size, climate, peroid, inhabitants,category);


}

Cage::Cage(Size size, Climate climate, Period period):category()
{
	this->size = size;
	this->climate = climate;
	this->period = period;
}

Cage::Cage(const Cage& other):dinosours()
{
	
	copy(other);
}

Cage& Cage::operator=(const Cage& other)
{
	if (this != &other)
		copy(other);
	return *this;
}

Cage::~Cage()
{
	del();
}

void Cage::adddino(const Dinasour& other)
{
	
	dinosours.addelem(other);
}

bool Cage::checkfordino(Dinasour& dino)
{
	int inh = dinosours.size();
	for (int i = 0; i < inh; ++i)
	{
		
		if (dino==dinosours[i])
		{
			
			return true;
		}
	}
	
	return false;
}

bool Cage::removedino(Dinasour& dino)
{
	
	int p = -1;
	int inh = dinosours.size();
	for (int i = 0; i < inh; ++i)
	{
		if (dino == dinosours[i])
		{
			p = i;
			break;
		}
	}
	if (p != -1)
	{
		dinosours.remove(p);
		return true;
	}
	return false;

}

void Cage::getfood(int& meat, int& grass, int& fish)
{
	int size = dinosours.size();
	for (int i = 0; i < size; ++i)
	{
		int p = (int)dinosours[i].getfood();
		if (p == 0)
			grass++;
		else if (p == 1)
			meat++;
		else if (p == 2)
			fish++;
	}
}

void Cage::serialize(std::ofstream& ofs)
{
	if (!ofs.is_open())
	{
		std::cout << "File isnt opened" << std::endl;
		return;
	}
	int p = (int)size;
	ofs.write((const char*)&p, sizeof(int));
	p = (int)climate;
	ofs.write((const char*)&p, sizeof(int));
	int size = dinosours.size();
	ofs.write((const char*)&size, sizeof(int));
	for (int i = 0; i < size; ++i)
		dinosours[i].serialize(ofs);
	p = (int)period;
	ofs.write((const char*)&p, sizeof(int));
	category.serialize(ofs);
}

void Cage::deserialize(std::ifstream& ifs)
{
	if (!ifs.is_open())
	{
		std::cout << "File isnt opened" << std::endl;
		return;
	}
	int buff;
	ifs.read((char*)&buff, sizeof(int));
	if (buff == 1)
		size = Size::Small;
	if (buff == 3)
		size = Size::Medium;
	if (buff == 10)
		size = Size::Big;
	ifs.read((char*)&buff, sizeof(int));
	if (buff == 0)
		climate = Climate::Earth;
	if (buff == 1)
		climate = Climate::Water;
	if (buff == 2)
		climate = Climate::Air;
	int size;
	ifs.read((char*)&size, sizeof(int));
	for (int i = 0; i < size; ++i)
		dinosours[i].deserialize(ifs);
	ifs.read((char*)&buff, sizeof(int));
	if (buff == 0)
		period = Period::Triassic;
	if (buff == 1)
		period = Period::Chalk;
	if (buff == 2)
		period = Period::Jurassic;
	category.deserialize(ifs);

}

bool Cage::Checkforcage(Dinasour& dinasour)
{
	
	char* c = nullptr;
	char* b = nullptr;
	if (dinosours.size() == 0)
		if (checkemptycage(dinasour))
			return true;
		else return false;
	if (!strcmp(dinasour.getcategory().getcategory(c),category.getcategory(b)))
	{
		if (dinasour.getperiod() == this->period || this->period==Period::Unknown)
		{
			if (dinosours.size() + 1 > (int)size)
			{
				delete[] c;
				delete[] b;
				return false;
			}
			
		}
		else
		{
			delete[] c;
			delete[] b;
			return false;
		} 
	}
	else
	{
		delete[] c;
		delete[] b;
		return false;
	} 
	return true;

	//getcategory proveri dali ima ednakvi categorii// dali ima mqsto // dali ima ednakuv klimat-samo ako ima dinozavri
	//ako nqma proveri samo klimat i sloji categoryy i period spored dino
}

bool Cage::checkemptycage(Dinasour& dinasour)
{
	int p = dinasour.getcategory().getnuminenum();
	if ((p == 0 || p == 1) && (int)climate == 0)
	{
		category = dinasour.getcategory();
		period = dinasour.getperiod();
		return true;
	}
	else if (p == 2 && (int)climate == 3)
	{
		category = dinasour.getcategory();
		period = dinasour.getperiod();
		return true;
	}
	if (p == 3 && (int)climate == 2)
	{
		category = dinasour.getcategory();
		period = dinasour.getperiod();
		return true;
	}
	return false;
}



void Cage::init(Size size, Climate climate, Period peroid, int inhabitants, Categoryy& category)
{
	this->size = size;
	this->climate = climate;
	this->period = period;
	this->category = category;

}

void Cage::copy(const Cage& other)
{
	size = other.size;
	
	climate = other.climate;
	for (int i = 0; i<other.getdinosize(); ++i)
		dinosours[i] = other.dinosours[i];
	period = other.period;

}

void Cage::del()
{
	
}
