#pragma once


#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <random> 
#include <algorithm>


struct cards
{
	int cardsType{};
	int cardNr{};
	cards(int type, int number) {
		cardsType = type;
		cardNr = number;
	}

};


int HouseAi(std::vector<cards> , std::vector<int>&, int drawTracker);


bool loginChecker();
int txtInfo;





void clearCin();