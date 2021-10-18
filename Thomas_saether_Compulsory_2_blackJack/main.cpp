#include "Declear.h"


//login is Thomas
//password is 123321
int main() {
	std::vector<int> playerBank(2, 100);
	if (loginChecker() == true)

	
	while (true)
	{
		
		blackJack();
	}
	


}
bool blackJack(){

	//making the vector for the cards.
	while (true)
	{
		

	for (size_t i = 1; i <= 4; i++)
	{


		for (size_t j = 1; j <= 13; j++)
		{
			Card_v.push_back(cards(i, j));
		}
	}

	//this is a checker for the banks of both the player and the house. they need to have more than 10.
	if (playerBank[0] < 10)
	{
		std::cout << "looks like you are out of money!" << std::endl;
		exit(0);
	}
	if (playerBank[1] < 10)
	{
		std::cout << "House is out of money, you win this time!" << std::endl;
		exit(0);
	}
	
	//showing the banks of each player
	std::cout << playerLogin[0] << " bank :" << playerBank[0] << std::endl;
	std::cout << "houses bank :" << playerBank[1] << std::endl;

	
	//making the players pay 10$.
	std::cout << "Buy inn is 10$, Do you want to continue? y/n  :" << std::endl;
	std::cin >> input;

	//forcing the input from the player to become uppercase, makes it easier to use the switch case.
	char blackJackAnswer = toupper(input);

	switch (blackJackAnswer)

	{
	case 'Y':
	{
		system("cls");
		break;
		
	}
	break;
	case 'N':
	{
		exit(0);
	}
	break;
	default:
		break;
	}
	//setting up the correct values for banks and players current card sum. also adding the buyinn to the pool.
		playerBank[0] -= 10;
		playerBank[1] -= 10;
		playerSum[0] = 0;
		playerSum[1] = 0;
		Pool += 20;
		//randomizer that i use inn the shuffle.
		std::random_device rd;
		std::mt19937_64 g(rd());


		while (true)
		{
			//shuffle takes all the cards within the vector and (suprise) shuffles it. 
			//(Card_v.begin(), Card_v.end() tells the shuffle where to start and where it ends. this is easiest with vector
	
		std::shuffle(Card_v.begin(), Card_v.end(), g);
		Pool = 0;
		std::cout << "Do you want to draw card? y/n  :" << std::endl;
		std::cin >> input;
		system("cls");
			if (toupper(input == 'y'))
			{
				//the drawTracker is very important, it keeps track on where inn the vector the player currently are
				//i use this information and send it to my ai function, this makes it continue where the player left off in the vector.
				drawTracker++;
				for (size_t i = 0; i < 1; i++)
				{
					//if the player draws a ace he/she can choose between 1 and 11.
					if (Card_v[i].cardNr == 1)
					{
						std::cout << "Do you want the card to count as 1 or 11 ?: 1/11";
						std::cin >> playerChoice;

						switch (toupper(playerChoice))
						{
						case 11:
						{
							std::cout << playerLogin[0] << " choose 11" << std::endl;
							std::cout << playerSum[0] << "+" << "11 = ";
							playerSum[0] += 11;
							std::cout << playerSum[0] << std::endl;
							continue;
						}
						break;
						case 1:
						{
							std::cout << playerLogin[0] << " choose 1" << std::endl;
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
					//if the card that is drawn is over 10 it will automatically become card value 10.
					if (Card_v[i].cardNr >= 10)
					{

						std::cout << "Face cards are 10" << std::endl;
						std::cout << playerSum[0] << "+" << "10 = ";
						playerSum[0] += 10;

					}
					//every other card uses their given number ans value.
					else if (Card_v[i].cardNr < 10 && Card_v[i].cardNr > 1)
					{

						std::cout << playerSum[0] << "+" << Card_v[i].cardNr << " = ";
						playerSum[0] += Card_v[i].cardNr;
					}

					std::cout << playerSum[0] << std::endl;
				}

				//this is a checker for player, if you go over 21 the house wins.
				if (playerSum[0] > 21)
				{
					system("cls");
					std::cout << playerLogin[0] << " went to high...House wins:" << std::endl;
					playerBank[1] += 20;
					return false;
				}

			}
			//when the player is happy with the current cardsum he can decide to hold.
		else if (toupper(input == 'n'))
		{

		std::cout << playerLogin[0] <<" holds" << playerSum[0] << std::endl;

		clearCin();

		std::cout << "How much do you want to bet ? the house will match you.";
		std::cin >> playerChoice;
		//this is a saftey check for betting to high or low. both for the players and house banks.
		while (playerChoice > playerBank[0] || playerChoice < playerBank[0] || playerChoice > playerBank[1] || playerChoice < playerBank[1])
		{

			if (playerChoice > playerBank[0] && playerChoice > playerBank[1])
			{
				std::cout << "You can't bet more than what you or the house have:";
				std::cin >> playerChoice;

			}
			else
			{
				break;
			}

		}
		system("cls");
		std::cout << playerLogin[0] <<" betted :" << playerChoice;
		//after the player have betted the Ai function starts. it takes inn the information from the players game.
		//the card vector which hold all the card, the current players value and where he is in the vector.
		HouseAi(Card_v, playerSum, drawTracker);
		break;
		}
		}
		//if the house gets the same cardvalue as the player it becomes a draw and the player are given the option to play again.
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
			//takes the betted amout out of the players and houses bank and adds it to the pool.
	playerBank[0] -= playerChoice;
	playerBank[1] -= playerChoice;

	Pool += playerChoice + playerChoice;

	std::cout << "The current pool is on:" << Pool << std::endl;

	if (playerSum[1] > 21)
	{
		std::cout << "house went to high..." << playerLogin[0] << " wins" << std::endl;
		playerBank[0] += Pool;
		return false;
		
	}

	if (playerSum[0] > playerSum[1] && playerSum[0] <= 21)
	{
		playerBank[0] += Pool;
		std::cout << "congratulations " << playerLogin[0] <<" you won against the house : " << Pool << std::endl;
		
	}
	else
	{
		playerBank[1] += Pool;
		std::cout << "House wins :" << Pool << std::endl;
		
	}

	


		
		}
		

	}




	return false;

}


//this is basically the same as the blackJack funtion wihtout the cout.
//the AI will always try to get draw or better than the player.
int HouseAi(std::vector<cards> Card_v, std::vector<int>& playerSum, int drawTracker) {
	while (true)
	{


	if (playerSum[1] < playerSum[0])
	{
	
		for (size_t i = drawTracker; playerSum[1] < playerSum[0] && i < Card_v.size() ; i++){

			drawTracker++;
			if (Card_v[i].cardNr == 1)
			{
				//if ai can us 11 from the ace without going above 21 it will.
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


	



//this is the login checker, it checks the input from the player. if it matches the username and password from the "server"
//it will give them acces to play.
bool loginChecker() {
	
	//gives the user 3 chances to login
	for (size_t i = 0; i < 3; i++)
	{


	//saves the attempts to the templogin
		//checks the text file
		//take one and one line from the txt
		//after the 9th char it will start the check.
	std::string tempLogin;
	std::ifstream infile("loginInfo.txt");
	std::string line{};
	std::getline(infile, line);
	std::string line1 = line.substr(9);
	
	std::cout << "Username: ";
	std::cin >> tempLogin;
	playerLogin.push_back(tempLogin);
	
	//if the username matches the line from the txt file it will give them the chance to write inn the password
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