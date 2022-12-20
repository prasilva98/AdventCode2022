#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <set>
#include <iterator>

int return_alphabet_score(char letter) {

	std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < alphabet.length(); i++) {

		if (alphabet[i] == letter) {

			return i + 1;
			 
		}
	}
}

int main()
{

	std::fstream my_stream;
	std::string rucksack[3];
	std::string f_compartment, s_compartment;
	int final_score = 0;
	int elf_group_counter = 0;
	int team_counter = 0;


	my_stream.open("rucksack.txt", std::fstream::in);


	if (!my_stream) {

		std::cout << "File not Found" << std::endl;

	}

	else {

		while (1) {

			// Insert rucksack contents into team members rucksack 
			my_stream >> rucksack[elf_group_counter];

		
			// Gotta find the existing letter 

			if (elf_group_counter == 2) {

				char common_component;

				std::cout << "Rucksack_0: " << rucksack[0] << std::endl;
				std::cout << "Rucksack_1: " << rucksack[1] << std::endl;
				std::cout << "Rucksack_2: " << rucksack[2] << std::endl;

				elf_group_counter = 0;
				team_counter++;

				for (int i = 0; i < rucksack[0].length(); i++) {

					char c = rucksack[0][i];

					if (rucksack[1].find(c) != std::string::npos && rucksack[2].find(c) != std::string::npos) {

						common_component = c;
						std::cout << "Common component between the teams is: " << common_component << std::endl;
						break;

					}
				}

				final_score += return_alphabet_score(common_component);
				std::cout << "Final score is: " << final_score << std::endl;
				std::cout << "Number of teams is: " << team_counter << std::endl;


			}
			else {
				
				elf_group_counter++;

			}


			if (my_stream.eof()) {

				std::cout << "Found the ending of the file " << std::endl;
				my_stream.close();

				break;

			}

		}
	}

	return 0;

}