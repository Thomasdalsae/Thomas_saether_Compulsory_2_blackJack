#pragma once


#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <random> 
#include <algorithm>
//for loginchecker, want to uset the login profiles name as player.
std::vector<std::string>playerLogin;
//made a struct to hold all the information the cards need, there are 4 different types of cards with 13 cards each. 
struct cards
{
	int cardsType{};
	int cardNr{};
	//Here we have some contructors for our cards.
	cards(int type, int number) {
		cardsType = type;
		cardNr = number;
	}

};

//Global playerbank to keep track of currecny of both the player and the house.
std::vector<int> playerBank(2, 100);
bool loginChecker();
//made a function for just the AI, it takes inn the variables noted inn the syntax below.
int HouseAi(std::vector<cards>, std::vector<int>&, int drawTracker);
int txtInfo;




//This is all the variables used for the blackJack function
bool blackJack();
char input{};
//takes inn the players input to actives different parts of the code.
	int playerChoice{};

	int playerTurn{};
	int drawTracker{};
	int Pool{};
	std::vector<cards> Card_v;
	std::vector<int> playerSum(2, 0);
//---------------------------------------------------------------









void clearCin();