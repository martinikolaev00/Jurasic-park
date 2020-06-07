#pragma once
#include<iostream>
#include<fstream>
///This class will give us a wider variety of options to create dinosours and cages
///@param category is the name of the category
///@param types is an array of what kind of types this category has
///@param numoftypes amount of types

class Categoryy
{
	char* category;
	char** types;
	int numoftypes;
	int idxoftype;
	int numinenum;
public:
	///default constructor
	///just sets all the needed memory to create an empty categoryy object
	Categoryy();
	///simple copy constructor
	///sets up all the needed memory and calls copy function @see copy()
	Categoryy(const Categoryy& other);
	///A simple constructor which makes a fully working object with data from the user
	Categoryy(char* category,int j, char types[][30]);
	///Standart overload of operator=
	/// Helps us to make our object identical to the given by the user one.
	///We just need to not forget to check if the 2 objests arent already identical
	Categoryy& operator=(const Categoryy& other);
	/// calls del() to release all the dynamic memory
	~Categoryy();
	///A function that returns the name of the object.
	///We expect a char* argument from the user when he calls this function.
	///Truly this there is a possibility for a mem leak and is abit slower tham just retuning the category,
	/// but we use it in order to achieve full encapsulation @returns a copy of category
	char* getcategory(char* buff);
	///Function that returns a certain type of the array of types
	///user must promp the idx of the type that he wants
	///if the given index exists in the array 
	///@returns a copy of the type placed on variable buff
	char* gettype(char* buff,int idx);
	///This function helps us to find out whether a certain type exists in the object's types array
	///We compare each element in types with the variable buff and if some of them match. 
	///We return the idx of that type, otherwise we return -1
	int checktype(char* buff);
	///A simple overaload of operator== to determine whether 2 objects are identical
	bool operator==(const Categoryy& other);
	int getnuminenum() { return numinenum; }
	/// A function that helps us to preserve all the information
	///for this object into to given file
	void serialize(std::ofstream& ofs);
	///Function that loads all the stored information
	///from the file that the user provided 
	void deserialize(std::ifstream& ifs);
private:
	void copy(const Categoryy& other);
	void del();
};

