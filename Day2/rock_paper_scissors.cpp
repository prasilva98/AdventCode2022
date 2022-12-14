
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>

int player_move_score(char pm) {

	if (pm == 'X') {

		return 1;

	}
	else if (pm == 'Y') {

		return 2;

	}
	else {

		return 3;
	}

}


int main()
{

	const int DRAW = 3;
	const int WIN = 6;
	const int LOSS = 0;

	std::ifstream my_stream;
	std::vector<char> opponent_move; 
	std::vector<char> your_move;

	int player_score = 0;

	my_stream.open("rps.txt", std::fstream::in);


	// Sanity check

	if (!my_stream) {

		std::cout << "File not Found" << std::endl;

	}

	else {

		while (1) {

			// Read all of the moves

			char om, ym;

			my_stream >> om;
			my_stream >> ym;

			opponent_move.push_back(om);
			your_move.push_back(ym);

			// Draw 

			if ( (om == 'A' && ym == 'X') || (om == 'B' && ym == 'Y') || (om == 'C' && ym == 'Z') ) {
				
				player_score += (DRAW + player_move_score(ym));

			}

			// WIN

			else if (ym == 'X' && om == 'C') {

				player_score += (WIN + player_move_score(ym));

			}
			else if (ym == 'Y' && om == 'A') {

				player_score += (WIN + player_move_score(ym));
			}
			
			else if (ym == 'Z' && om == 'B') {

				player_score += (WIN + player_move_score(ym));
			}

			// LOSS 

			else {

				player_score += (LOSS + player_move_score(ym));
			}

			std::cout << "Oppponent Move: " << om << " Your Move: " << ym << " New Player Score is: " << player_score << std::endl;

			if (my_stream.eof()) {

				std::cout << "Reached the end of the file " << std::endl;
				my_stream.close();

				break;
			}


		}
	}


	std::cout << "Your final score was " << player_score << std::endl;

	
	return 0;

}