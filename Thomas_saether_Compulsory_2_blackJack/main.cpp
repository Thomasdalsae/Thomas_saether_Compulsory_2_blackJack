#include "Declear.h"

struct cards
{
	int cardsType{};
	int cardNr{};
	cards(int type, int number) {
		cardsType = type;
		cardNr = number;
	}

};
struct players
{
	int playerName;
	int playerBank = 100;


};




int main() {
	
	char input{};
	int playerChoice{};

	std::vector<cards> Card_v;
	std::vector<int> playerSum(2,0);

	for (size_t i = 1; i <= 4; i++)
	{
		

	for (size_t j = 1; j <= 13; j++)
	{
		Card_v.push_back(cards(i, j));
	}
	}
	
	while (true)
	{
	std::random_device rd;
	std::mt19937_64 g(rd());

	std::shuffle(Card_v.begin(), Card_v.end(), g);


	std::cout << "Do you want to draw card? y/n" << std::endl;
			std::cin >> input;

			if (toupper(input == 'y'))
			{
				
				for (size_t i = 0; i < 1; i++)
				{
					if (Card_v[i].cardNr == 1)
					{
						std::cout << "Do you want the card to count as 1 or 11 ?: 1/11";
							std::cin >> playerChoice;

							switch (toupper(playerChoice))
							{
								case '11':
								{
									playerSum[0] += 11;
								}
								break;
								case '1':
								{
									playerSum[0] += 1;
								}
								break;
							default:
								break;
							}


					}
					if (Card_v[i].cardNr > 10)
					{
						playerSum[0] += 10;

					}
					else if (Card_v[i].cardNr < 10 && Card_v[i].cardNr > 1)
					{
						std::cout << Card_v[i].cardsType << " ";
						std::cout << Card_v[i].cardNr << std::endl;
						playerSum[0] += Card_v[i].cardNr;
					}

					std::cout << playerSum[0];
					
				}
			
			}
			else if (toupper(input == 'n'))
			{
				return false;
			}





	}




	
	
	


	/*std::copy(Card_v.begin(), Card_v.end(), / std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";*/



	
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