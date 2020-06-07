#pragma once
#include"Dinasour.h"
#include"Heaparr.hpp"

enum class Climate
{
	Unknown = -1,
	Earth ,
	Water ,
	Air
};
enum class Size
{
	Unknown = -1,
	Small=1,
	Medium=3,
	Big=10
};
///This the living habitat of our dinosours.Ofcourse come in many varieties so we have many different cages
///	
///@param size -The first part of this class is enum type Size, we have 3 different types of size.Small for 1 dinosaour, medium for 3 and big for 10.
///@param climate Then we have enum type what kind of climate the cage has, there are three types earth/water/air
///@param dinosours Ater than we have a vector array from dinosours that inhabit the cage
///@category And at the end there is a composition with class Categoryy
class Cage
{

	Size size;
	//int inhabitants;
	Climate climate;
	Heaparr<Dinasour> dinosours;
	//Dinasour* dinosours; // heaparr
	Period period;
	Categoryy category;
	
	
public:
	///default constructor
	Cage();
	//Cage(Categoryy& category,Climate climate);
	///full constructor
	Cage(Size size, Climate climate, Period peroid, int inhabitants, Categoryy& category);
	Cage(Size size, Climate climate, Period period);
	///A checking function to see if there is an available cage for the given dinosour
	///@returns bool for yes or no
	///First it checks if the cage is empty, if it is it goes to @see checkemptycage()
	///if cage is not empty we have @param c and @param b , 2 char* nullptrs which will help us get the categories of the dinosour and the cage
	///dinosour calls @see getcategory() which @returns category from the dinosour but we must not forget that this is a class object
	///there for category calls  getcategory() with c which returns a copy of the name of the category, same goes for cage
	///if cagegories match all thats left to check is the period and whether there is space or no
	///after all the checks we delete whatever the pointers returned and leave the function
	/// @see getcategory() in dinosour class
	bool Checkforcage(Dinasour& dinasour);
	///Category was planned originaly as enum but while developing the project it turned into a class
	///@see getnuminenum() func returns (int)enum number which is compared to the climate to see if dinosour is suiteble for this cage
	///this function also @returns bool to indicate whether this exact dinosour can be placed there
	bool checkemptycage(Dinasour& dinasour);
	///copy constructor for cage, since all data in class cage is either enum type or vector there is no need to be initialized so we can copy it straight away
	Cage(const Cage& other);
	///standart operator=
	Cage& operator=(const Cage& other);
	/// destructor calls @see del() function
	~Cage();
	///simpy adds the dinosour to the inhabitant list of the cage 
	void adddino(const Dinasour& other);
	///Simply checks if the given dino exists in the cage @returns bool for whether a certain dinosour exists in it's inhabitants
	///We just get the size of the vector and run a for cycle to compare the inhabitants and the given dinosour
	bool checkfordino(Dinasour& dino);
	/// This function checks if the given dino is inbetween the inhabitants
	/// @param p is the number of the dino in the inhabitants array
	/// if dino is actually an inhabitant p will be !=-1 then we remove it and @returns true for successful removal
	/// if p==-1 then the dino isnt inhabitant and @returns false for fail
	bool removedino(Dinasour& dino);
	/// @returns the amount of inhabitants of the cage
	int getdinosize() const { return dinosours.size(); }
	///Uses @param meat
	///@param grass
	///@param fish 
	///to count what amount food is needed to feed all the dinosours in this cage
	/// going over each inhabitant to see what kind of food he consumes and adding it to the total number
	void getfood(int& meat, int& grass, int& fish);
	///Serializes all the information about this cage into the given file
	///In enum size each type of size coresponds to the amount of possible dinosours, so we can safely serialize it
	///Then we serialize each inhabitant on it's own with serialize function in class dinosour
	///Then we serialize the category with it's own serialize function
	void serialize(std::ofstream& ofs);
	///deserializes all the needed info for the cage
	/// We start with size, then  climate
	///Then we deserialize all the dinosours in the cage one by one using the deserialize() func in class Dinosour
	///And finally we deserialize category with it's own function
	void deserialize(std::ifstream& ifs);
	
	
private:
	///This function initializes all the variables by given values from the user
	void init(Size size, Climate climate, Period peroid, int inhabitants,Categoryy& category);
	/// completetly copies the current cage from the given one
	void copy(const Cage& other);
	/// deletes all the heap variables
	void del();
};

	