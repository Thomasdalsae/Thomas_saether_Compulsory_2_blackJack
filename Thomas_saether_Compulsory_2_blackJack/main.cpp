#include "Declear.h"

struct cards
{

	int cardsType;
	int cardNr;

};





int main() {
	std::vector<int> Card_v;
	
	Card_v.push_back(cards());
	

	cards[0].
	
	
	




	std::vector<int> card = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::random_device rd;
	std::mt19937_64 g(rd());

	std::shuffle(card.begin(), card.end(), g);

	std::copy(card.begin(), card.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";



	
	if (loginChecker() == true)

		std::cout << "Draw a card! :" << std::endl;
	
	
	return 0;
}


bool loginChecker() {

	
	for (size_t i = 0; i < 3; i++)
	{

	std::vector<std::string>playerLogin;
	
	std::string tempLogin;
	std::ifstream infile("loginInfo.txt");
	std::string line{};
	std::getline(infile, line);
	std::string line1 = line.substr(9);
	
	std::cout << "Username: ";
	std::cin >> tempLogin;
	playerLogin.push_back(tempLogin);
	
	
	if (playerLogin[0] == line1)
	{
		std::getline(infile, line);
		std::string line1 = line.substr(9);
		std::cout << "password: ";
		std::cin >> tempLogin;
		playerLogin.push_back(tempLogin);

		if (playerLogin[1] == line1)
		{
			std::cout << "Welcome " << playerLogin[0] << std::endl;
			return { true };
			
		}
		std::cout << "Password was not correct...Try again" << std::endl;
		continue;
		
	}
	
	std::cout << "User not found...Try again" << std::endl;


	

	
		}

	
	

	
	return {};
	}


void clearCin() {
	// Function that clears cin buffer.
	// Courtesy of Johannes Skjeltorp-Borgaas.

	std::cin.clear();
	std::cin.ignore(32767, '\n');
}