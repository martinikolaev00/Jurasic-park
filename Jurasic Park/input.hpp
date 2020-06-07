#pragma once
#include<iostream>
#include"HQ.hpp"
#include"Category.hpp"
using std::cout;
using std::cin;
using std::endl;
///This class will help us connect to the user
///
///We have our commands and a several functions to help us complete all commands in our menu
class input
{
	HQ uwu;
	const int MaxN = 200;
	char commands[11][20] = { "menu","add_dinosour" , "checkforcage","buildcage","remove_dinosour","stockfood","load","save","feed","stock_food", "exit" };
public: 
	///A greeting for users
	void Begin();
	///A switch to help us determine which function will be called, depending on what number the function received
	void switchmenu(int command);
	/// asks user to write the command he wants and compares it with out command list
	///if there is a matching command in the list the function is called
	void getcommand();
	///demands from user to type menu
	void Input();
	///prints out all the available commands
	void menu();
	///Asks user to insert all kinds of specifics in oder to make the dinosour that user wants
	void adddinosour();
	///calls buildcage in HQ
	void buildcage();
	///Checking if a suitable cage exists for the dinosour that user wants
	///if dinosour with such name exists then we check if suitable cages exist
	/// if there are we place the dino there if there aren't we promp the user to build one
	void checkforcage();
	/// calls function stockfood in HQ
	void stockfood();
	///calls function feed in HQ
	void feed();
	///calls function deserialize in HQ
	void load();
	///calls function serialize in HQ
	void save();
	void removedinosour();
	//void help();
	//void type();

};

