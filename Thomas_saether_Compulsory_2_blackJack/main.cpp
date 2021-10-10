#include "Declear.h"







bool main() {
	std::vector<int> playerBank(2, 100);
	
	
	while (true)
	{
		
		blackJack();
	}
	
	return false;

}
bool blackJack(){
	char input{};
	int playerChoice{};
	int playerTurn{};
	int drawTracker{};
	int Pool{};
	std::vector<cards> Card_v;
	std::vector<int> playerSum(2, 0);

	while (true)
	{
		

	for (size_t i = 1; i <= 4; i++)
	{


		for (size_t j = 1; j <= 13; j++)
		{
			Card_v.push_back(cards(i, j));
		}
	}

	
	if (playerBank[0] < 10)
	{
		std::cout << "looks like you are out of money!" << std::endl;
		exit(0);
	}
	
	
	std::cout << "players bank :" << playerBank[0] << std::endl;
	std::cout << "houses bank :" << playerBank[1] << std::endl;

	


		std::cout << "Buy inn is 10$, Do you want to continue?" << std::endl;
		std::cin >> input;

		switch (toupper(input))
		{
		case 'y':
		{
			continue;
		}
		break;
		case 'n':
		{
			exit(0);
		}
		break;
		default:
			break;
		}


		playerBank[0] -= 10;
		playerBank[1] -= 10;
		playerSum[0] = 0;
		playerSum[1] = 0;
		Pool += 20;
		
		std::random_device rd;
		std::mt19937_64 g(rd());
		while (true)
		{

			

		std::shuffle(Card_v.begin(), Card_v.end(), g);


		
		std::cout << "Do you want to draw card? y/n  :" << std::endl;
		std::cin >> input;
		system("cls");
			if (toupper(input == 'y'))
			{
				drawTracker++;
				for (size_t i = 0; i < 1; i++)
				{
					if (Card_v[i].cardNr == 1)
					{
						std::cout << "Do you want the card to count as 1 or 11 ?: 1/11";
						std::cin >> playerChoice;

						switch (toupper(playerChoice))
						{
						case 11:
						{
							std::cout << "Player choose 11" << std::endl;
							std::cout << playerSum[0] << "+" << "11 = ";
							playerSum[0] += 11;
							std::cout << playerSum[0] << std::endl;
							continue;
						}
						break;
						case 1:
						{
							std::cout << "Player choose 1" << std::endl;
							std::cout << playerSum[0] << "+" << "1 = ";
							playerSum[0] += 1;
							std::cout << playerSum[0] << std::endl;
							continue;
						}
						break;
						default:
							break;
						}


					}
					if (Card_v[i].cardNr >= 10)
					{

						std::cout << "Face cards are 10" << std::endl;
						std::cout << playerSum[0] << "+" << "10 = ";
						playerSum[0] += 10;

					}
					else if (Card_v[i].cardNr < 10 && Card_v[i].cardNr > 1)
					{
						//Hvilken type å nr
						//std::cout << Card_v[i].cardsType << " " ;
						//std::cout << Card_v[i].cardNr << std::endl;

						std::cout << playerSum[0] << "+" << Card_v[i].cardNr << " = ";
						playerSum[0] += Card_v[i].cardNr;
					}

					std::cout << playerSum[0] << std::endl;
				}


				if (playerSum[0] > 21)
				{
					system("cls");
					std::cout << "you lose you'll get nothing, good day sir/madam" << std::endl;
					std::cout << "Do you want to play another round of blackjack?";
					return false;
				}

			}
		else if (toupper(input == 'n'))
		{

		std::cout << "Player one holds" << playerSum[0] << std::endl;

		HouseAi(Card_v, playerSum, drawTracker);
		break;
		}
		}




		if (playerSum[1] > 21)
		{
			std::cout << "house went to high... player wins";
			playerBank[0] += 20;
			return false;
		}
		if (playerSum[1] == playerSum[0])
		{
			system("cls");
			std::cout << "Looks like it's a draw" << std::endl;
			std::cout << "the buy inn is returned :";
			playerBank[0] += 10;
			playerBank[1] += 10;
			return false;
		}
		if (true)
		{

	clearCin();
	
	std::cout << "How much do you want to bet ? the house will match you.";
	std::cin >> playerChoice;
	while (playerChoice > playerBank[0] || playerChoice > playerBank[1])
	{
		std::cout << "You can't bet more than what you or the house have:";
		std::cin >> playerChoice;
	
	}
	


	playerBank[0] -= playerChoice;
	playerBank[1] -= playerChoice;

	Pool += playerChoice + playerChoice;

	std::cout << "The current pool is on:" << Pool << std::endl;


	if (playerSum[playerTurn] > playerSum[1])
	{
		playerBank[0] += Pool;
		std::cout << "congratulations player, you won against the house :" << Pool;
		
	}
	else
	{
		playerBank[1] += Pool;
		std::cout << "House wins :" << Pool << std::endl;
		
	}
	std::cout << playerBank[0] << std::endl;
	std::cout << playerBank[1] << std::endl;
	


		
		}
		

	}
	/*if (loginChecker() == true)

		std::cout << "Draw a card! :" << std::endl;
*/

	
	
	

	return false;

}

	
	
	


	/*std::copy(Card_v.begin(), Card_v.end(), / std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";*/



	
	

int HouseAi(std::vector<cards> Card_v, std::vector<int>& playerSum, int drawTracker) {
	while (true)
	{


	if (playerSum[1] < playerSum[0])
	{
	
		for (size_t i = drawTracker; playerSum[1] < playerSum[0] && i < Card_v.size() ; i++){

			drawTracker++;
			if (Card_v[i].cardNr == 1)
			{
				if (playerSum[1] < 11)
				{
					std::cout << playerSum[1] << "+" << "11 = ";
					playerSum[1] += 11;
					std::cout <<"House got" << playerSum[1] << std::endl;
					continue;
				}
				else 
				{
					std::cout << playerSum[1] << "+" << "1 = ";
					playerSum[1] += 1;
					std::cout << "House got" << playerSum[1] << std::endl;

				}
			}

			if (Card_v[i].cardNr >= 10)
			{

				std::cout << "Face cards are 10" << std::endl;
				std::cout << playerSum[1] << "+" << "10 = ";
				playerSum[1] += 10;

			}
			else if (Card_v[i].cardNr < 10 && Card_v[i].cardNr > 1)
			{
				std::cout << playerSum[1] << "+" << Card_v[i].cardNr << " = ";
				playerSum[1] += Card_v[i].cardNr;
			}

			std::cout << playerSum[1] << std::endl;
		}
		

	}
	std::cout << "House holds" << playerSum[1] << std::endl;
	
	break;
		}
	

		
		return playerSum[1];
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