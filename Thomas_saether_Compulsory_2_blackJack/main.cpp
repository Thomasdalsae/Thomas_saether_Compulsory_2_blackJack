#include "Declear.h"

int main() {
	
	
	if(loginChecker() == true)


	
	
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
			std::cout << "Welcome" << playerLogin[0] << std::endl;
			return { true };
			
		}
		std::cout << "Password was not correct...Try again" << std::endl;
		continue;
		
	}
	
	std::cout << "User not found...Try again" << std::endl;


	/*while (std::getline(infile, line)) {

			std::string line1 = line.substr(9);

			if (playerLogin[0] == line1)
			{
				std::cout << "Welcome" << playerLogin[0];
				return { true };
			}
			 if (playerLogin[0] != line1) {

				std::cout << "Incorrect login...Try again" << std::endl;
			
			}

*/		
		}

	//infile.close();
	

	
	return {};
	}





	



void clearCin() {
	// Function that clears cin buffer.
	// Courtesy of Johannes Skjeltorp-Borgaas.

	std::cin.clear();
	std::cin.ignore(32767, '\n');
}