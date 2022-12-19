#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

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
	std::string rucksack;
	std::string f_compartment, s_compartment;
	int final_score = 0;


	my_stream.open("rucksack.txt", std::fstream::in);


	if (!my_stream) {

		std::cout << "File not Found" << std::endl;

	}

	else {

		while (1) {

			// Duplicate component
			bool found_the_duplicate = false;
			char dupl_component;

			my_stream >> rucksack;

			// Get all the rucksack components 

			std::cout << rucksack << std::endl;

			size_t midpoint = rucksack.length() / 2;

			// Divide them in half

			f_compartment = rucksack.substr(0, midpoint);
			s_compartment = rucksack.substr(midpoint);

			std::cout << "First Compartment: " << f_compartment << " Second Compartment: " << s_compartment << std::endl;

			for (int i = 0; i < f_compartment.length(); i++) {

				for (int j = 0; j <= s_compartment.length(); j++) {

					if (f_compartment[i] == s_compartment[j]) {

						found_the_duplicate = true;

						std::cout << "Found a component duplicate: " << f_compartment[i] << std::endl; 

					}
				}

				if (found_the_duplicate == true) {


					final_score += return_alphabet_score(f_compartment[i]);
					std::cout << "New Score is: " << final_score << std::endl;
					found_the_duplicate = false;
					break;

				}
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