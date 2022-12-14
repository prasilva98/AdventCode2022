// AdventCode2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>

/*
int main()
{
	std::ifstream input_file;

	const int TOP_3 = 3;

	input_file.open("elf_calories.txt", std::ifstream::in);

	if (!input_file) {

		// If the file is read then start extracting the values
		std::cout << "File not Found" << std::endl;

	}

	else {

		// File was not found

		std::cout << "File Found sucessfully! ";

		int sum_calories = 0;

		std::vector<int> elf_calories;

		int max1_calories = 0;
		int max2_calories = 0;
		int max3_calories = 0;

		while (1) {


			// Get the calories 
			int calories;
			input_file >> calories;

			sum_calories += calories;


			std::cout << calories << std::endl;

			// Remove \n at the end of the number 
			char s1 = input_file.get();
			
			// Check if the next line is empty
			char s = input_file.peek();

			if (s == '\n') {
				
				std::cout << "Sum Calories: " << sum_calories << std::endl;

				elf_calories.push_back(sum_calories);

				// Reset calories counter, because we've moved on to another elf 
				sum_calories = 0;

			}


			if (input_file.eof()) {

				std::cout << "Reached the end of the file " << std::endl;
				input_file.close();


				// Sort the calories from max to min 

				std::sort(elf_calories.begin(), elf_calories.end(), std::greater<int>() );

				int top3_sum = 0;

				auto it = elf_calories.begin();

				for (int i = 0; i < TOP_3; i++) {

					if (i == 0) {

						std::cout << "Max Number of calories is: " << *it << std::endl; 

					}

					top3_sum += *it;
					it++;

				}

				std::cout << "Sum of the top 3 valories reaches: " << top3_sum << std::endl;


				break;

			}

		}


	}


	return 0;
}

*/