#include "Category.hpp"
#include<cstring>

Categoryy::Categoryy():category(nullptr),types(nullptr),numoftypes(3)
{
	numoftypes = 3;
	category = new char[100];
	category[99] = '\0';
	types = new char* [numoftypes];
	for (int i = 0; i < 3; ++i)
	{
		types[i] = new char[30];
	}
}

Categoryy::Categoryy(const Categoryy& other)
{
	numoftypes = 3;
	category = new char[strlen(other.category)+1];
	strcpy(category, other.category);
	category[strlen(other.category)] = '\0';
	types = new char* [numoftypes];
	for (int i = 0; i < 3; ++i)
	{
		types[i] = new char[30];
	}
	copy(other);
}
	


Categoryy::Categoryy(char* category,int j,char type[][30])
{
	numoftypes = 3;
	this->category = new char[strlen(category)+1];
	strcpy(this->category, category);
	this->category[strlen(category)] = '\0';
	this->types = new char* [numoftypes];
	for (int i = 0; i < 3; ++i)
	{
		this->types[i] = new char[30];
	}
	for (int i = 0; i < 3; ++i)
	{
		strcpy(this->types[i], type[i+j*3]);
	}
	numinenum = j;
}

Categoryy& Categoryy::operator=(const Categoryy& other)
{
	if (this != &other)
		copy(other);
	return *this;
}

Categoryy::~Categoryy()
{
	del();
}

char* Categoryy::getcategory( char* buff)
{
	buff = new char[strlen(category)];
	strcpy(buff, category);
	return buff;
}

char* Categoryy::gettype(char* buff, int idx)
{
	if (idx <= numoftypes)
	{
		buff = new char[strlen(types[idx])];
		strcpy(buff, types[idx]);
		return buff;
	}
	else return nullptr;
}

int Categoryy::checktype(char* buff)
{
	for (int i = 0; i < numoftypes; ++i)
	{
		if (!strcmp(types[i], buff))
		{
			//idxoftype = i;
			return i;
		}
	}
	return -1;
}

bool Categoryy::operator==(const Categoryy& other)
{
	if (!strcmp(category, other.category))
	{
		for (int i = 0; i < numoftypes; ++i)
		{
			if (strcmp(types[i], other.types[i]))
				return false;
			else
				return true;
		}
	
			
	}
	return false;

}

void Categoryy::serialize(std::ofstream& ofs)
{
	if (!ofs.is_open())
	{
		std::cout << "File is not opened" << std::endl;
		return;
	}
	int cat = strlen(category);
	ofs.write((const char*)&cat, sizeof(int));
	ofs.write(category, cat);
	ofs.write((const char*)&numoftypes, sizeof(int));
	for (int i = 0; i < numoftypes; ++i)
	{
		int p = strlen(types[i]);
		ofs.write((const char*)&p, sizeof(int));
		ofs.write(types[i], p);
	}
	ofs.write((const char*)&idxoftype, sizeof(int));
	ofs.write((const char*)&numinenum, sizeof(int));
}



void Categoryy::deserialize(std::ifstream& ifs)
{
	if (!ifs.is_open())
	{
		std::cout << "File is not opened" << std::endl;
		return;
	}
	del();
	int cat;
	ifs.read((char*)&cat, sizeof(int));
	category = new char[cat + 1];
	ifs.read(category, cat);
	category[cat] = '\0';
	ifs.read((char*)&numoftypes, sizeof(int));
	types = new char* [3];
	for (int i = 0; i < numoftypes; ++i)
	{
		int p;
		ifs.read((char*)&p, sizeof(int));
		types[i] = new char[p + 1];
		ifs.read(types[i], p);
		types[i][p] = '\0';
	}
	ifs.read(( char*)&idxoftype, sizeof(int));
	ifs.read(( char*)&numinenum, sizeof(int));


}

void Categoryy::copy(const Categoryy& other)
{
	strcpy(category, other.category);
	category[strlen(other.category)] = '\0';
	for (int i = 0; i < 3; ++i)
	{
		strcpy(types[i], other.types[i]);
	}
	numinenum = other.numinenum;
}

void Categoryy::del()
{
	for (int i = 0; i < numoftypes; ++i)
		delete[] types[i];
	delete[] types;
	delete[] category;

}

