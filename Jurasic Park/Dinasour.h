#pragma once
#include<iostream>
#include<fstream>
#include"Category.hpp"
enum class Period
{
	Unknown =-1,
	Triassic ,
	Chalk,
	Jurassic
	
};
enum class Category
{
	Unknown = -1,
	Vegitarian ,
	Carnivorous ,
	Aqueous,
	Flying
};
enum class Food
{
	Unknown = -1,
	Grass=0,
	Meat,
	Fish

};
enum class Gender
{
	Unknown = -1,
	Male =0,
	Female
};
/// we have a class dinasour which stays strong to it's name and creates different kinds of dinosours with all kind of specifics
/// @param name a char* variable to hold the name of the dinosour
/// @param period, an enum variable of Period type
///@param category is a variable from Categoryy class
///@param a variable to set the gender of the dinsour, sadly there are only 2 genders

class Dinasour
{
	 char* name;
	Period period;
	Categoryy category;
	Food food;
	Gender gender;
	 char* type;
public:
	///Default constructor
	Dinasour();
	/// Full destructor, calls function init with all the given variables from the user 
	Dinasour(const char* name, Period period, Categoryy& category, Food food, Gender gender, const char* type);
	///Standart copy costructor
	///Just sets the needed amount of space and calls copy fuction
	///@see copy()
	Dinasour(const Dinasour& other);
	///completely copying this dinosour using other's information
	///Though it's really important to check whether *this and other are not the same
	///After the check in complete we just proceed to call copy() @see copy()
	Dinasour& operator=(const Dinasour& other);
	///calls del() to release all the memory on the heap @see del()
	~Dinasour();
	///@returns the period of the dinosour
	Period getperiod();
	///A simple function to get the category of a dinosour,
	///we must not forget that category is a class object so we return  & to avoid copying the object
	///@returns category
	Categoryy& getcategory();
	///A function that returns the name of the dinosour.
	///We expect a char* argument from the user when he calls this function.
	///Truly this there is a possibility for a mem leak and is abit slower tha. just retuning the name,
	/// but we use it in order to achieve full encapsulation @returns a copy of name
	char* getname(char* buff);
	///Overload of operator==, which will help us determine if 2 dinosours are identical
	bool operator==(const Dinasour& other);
	///@returns what kind of food this dinosour consumes
	Food getfood();
	///A function that returns the type of the dinosour.
	///We expect a char* argument from the user when he calls this function.
	///Truly this there is a possibility for a mem leak and is abit slower tham just retuning the type,lll,
	/// but we use it in order to achieve full encapsulation @returns a copy of type
	char* gettype(char* buff);
	///a simple function to store all the dinosour data in the given file
	void serialize(std::ofstream& ofs);
	///taking all needed information from file and setting up the dinosour
	void deserialize(std::ifstream& ifs);
private:
	///completetly initializing the dinosour with information from user
	void init(const char* name, Period period, Categoryy& category, Food food, Gender gender, const char* type);
	///copying all variables
	void copy(const Dinasour& other);
	///deleting dynamic mem
	void del();
};

