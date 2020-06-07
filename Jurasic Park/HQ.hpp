#pragma once
#include<iostream>
#include<fstream>
#include"Heaparr.hpp"
#include"Cage.hpp"
///A class that helps us store all the information in the program
///
///We have a vector to store all the existing dinosours in the zoo.
///We have a vector to store all the existing cages in the zoo.
///Then there is an array of different types of food that is required to feed the dinosours
///And last but not least we have our staff
class HQ
{
	Heaparr<Dinasour> dinosours;
	Heaparr<Cage> cages;
	//int dinacount=0;
	//int cagecount=0;
	int food[3] = { 0, };//food[0] = meat , food[1]=grass , food[3]=fish
	int staff=0;
public:
	///A simple function that increases dinosour count using heaparr's addelem function.
	///Also increasing staff count so we can properly take care of all members of our zoo
	void adddinosour(const Dinasour& dino);
	///A simple function that increases cage count using heaparr's addelem function
	void addcage(const Cage& cage);
	///A quick function to determine whether there is a spot in a cage for
	/// the dinosour that is on idx-th spot in our dinosours vector @see Checkforcage()
	/// and if a suitable cage is found we return it's index if not -1
	int checkforcage(int idx);
	///Function check if a dinosour with given from the user name exists in the zoo
	///it returns the fist dinosour with that name that it finds
	int checkfordino(char* name);
	///After receiving the required information this function easily adds the dinosour to that cage
	void adddinoincage(int idxcage,int idxdino);
	///User is promped to enter what kind of cage he wants to create.
	///After all the needed information is entered correctly the cage is created 
	void createcage();
	///This function determines whether dinosour with such name has been placed 
	/// in one of the many cages in the zoo, @warning there might be more than 1 dinosour with that name
	bool isdinoincage(char* name);
	///Simply removes dinosour on spot idx in the dinosours array from it's current cage 
	void removedino(int idx);
	///Counts what the total amount of food needed to feed all dinosours
	///if that amount is at stock it just feeds everybody
	///but it if isnt we need to restock out food supplies so
	///the function stockfood is called @see stockfood()
	void feed();
	///Asks the user how much food he wants to restock from each type 
	///This function usually comes after feed has told us how much food we need so its not hard to calculate it
	void stockfood();
	///@returns the max value of 3 given numbers
	int max(int a, int b, int c);
	///Saves all the current information about the program
	/// into separated files for dinosours/cages/etc
	void serialize();
	///Loads all the needed information for the program to work
	///@note there has to be a working save so this function can work properly
	void deserialize();

private: 
	
};

