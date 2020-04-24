#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

using std::cout;
using std::cin;

int main() 
{
	int x = 0;
	int o = 0;
	int tie = 0;
	TicTacToe game = TicTacToe();
	TicTacToeManager manager = TicTacToeManager();
	string player;
	string choice = "Y";

	do {

		cout << "Enter Starting Player: ";
		cin >> player;
		if (!(player == "X" || player == "O"))
		{
			cout << "Player must be 'X' or 'O'\n";
			continue;
		}

		game.start_game(player);

		while (!game.game_over())
		{
			cin >> game;
			cout << game;
			cout << "\n";
		}
		if (game.get_winner() == "X")
		{
			x++;
		}
		else if (game.get_winner() == "O")
		{
			o++;
		}
		else
		{
			tie++;
		}

		cout << "X:\t" << x << "\nO:\t" << o << "\nTies:\t" << tie << "\n";

		manager.save_game(game);
		
		cout << "\nPlay again? (Y: yes, N: no): ";
		cin >> choice;

	} while (choice == "Y");

	cout << manager;
	return 0;
}