#include "tic_tac_toe.h"

using std::cout;
using std::cin;

int main() 
{
	TicTacToe game;
	string player;
	string choice = "Y";
	int position;

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
			std::cout << "\nEnter position (1-9) player " << game.get_player() << ": ";
			cin >> position;
			cout << "\n";

			game.mark_board(position);
			game.display_board();
			cout << "\n";
		}
		if (game.get_winner() == "C")
		{
			cout << "It's a tie!\n";
		}
		else
		{
			cout << "Player " << game.get_winner() << " wins!\n";
		}

		cout << "\nPlay again? (Y: yes, N: no): ";
		cin >> choice;

	} while (choice == "Y");
	return 0;
}