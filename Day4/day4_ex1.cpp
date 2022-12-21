#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <set>
#include <iterator>
#include <sstream>

bool check_if_within_bounds(int num, int low, int high) {

	if (num >= low && num <= high) {
		return true;
	}

	else {

		return false;

	}

}


int main()
{

	std::fstream my_stream;
	int contained_pairs = 0;
	char non_used_character;
	int pairs[4];

	my_stream.open("pairs.txt", std::fstream::in);

	if (!my_stream) {

		std::cout << "File not Found" << std::endl;

	}

	else {

		while (1) {

			my_stream >> pairs[0];
			my_stream >> non_used_character;
			my_stream >> pairs[1];
			my_stream >> non_used_character;
			my_stream >> pairs[2];
			my_stream >> non_used_character;
			my_stream >> pairs[3];

			std::cout << "First Pair: " << pairs[0] << "-" << pairs[1] << " Second Pair: " << pairs[2] << "-" << pairs[3] << std::endl;

			// With the gathered paris check if one contains the other I guess. 



			if (   check_if_within_bounds(pairs[0], pairs[2], pairs[3]) && check_if_within_bounds(pairs[1], pairs[2], pairs[3]) ) {

				std::cout << "First pair is within bounds of second pair " <<  std::endl;
				contained_pairs++;

			}

			else if ( check_if_within_bounds(pairs[2], pairs[0], pairs[1]) && check_if_within_bounds(pairs[3], pairs[0], pairs[1]) ) {
				
				std::cout << "Seconds pair is within bounds of first pair " << std::endl;
				contained_pairs++;


			}

			if (my_stream.eof()) {

				std::cout << "Found the ending of the file " << std::endl;
				my_stream.close();

				std::cout << "The number of contained pairs is: " << contained_pairs << std::endl;

				break;

			}

		}
	}

	return 0;

}

