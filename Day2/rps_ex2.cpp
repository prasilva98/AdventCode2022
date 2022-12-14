
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>

char win_move(char m) {

	char pm;

	if (m == 'A') {

		pm = 'Y';
	}

	else if (m == 'B') {

		pm = 'Z';

	}

	else if (m == 'C') {

		pm = 'X';

	}

	return pm;

}

char loose_move(char m) {

	char pm;

	if (m == 'A') {

		pm = 'Z';

	}
	else if (m == 'B') {

		pm = 'X';

	}
	else if (m == 'C') {

		pm = 'Y';
	}

	return pm;


}

int player_move_score(char pm) {

	if (pm == 'X' || pm == 'A') {

		return 1;

	}
	else if (pm == 'Y' || pm == 'B') {

		return 2;

	}
	else {

		return 3;
	}

}


int main()
{

	const int LOSS = 0;
	const int DRAW = 3;
	const int WIN = 6;

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

			// LOSS

			if (ym == 'X') {

				player_score += LOSS + player_move_score(loose_move(om));


			}

			// DRAW

			else if (ym == 'Y') {
				
				player_score += DRAW + player_move_score(om);

			}

			// WIN

			else if (ym == 'Z') {

				std::cout << "you have to win here " << std::endl;

				player_score += WIN + player_move_score(win_move(om));

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