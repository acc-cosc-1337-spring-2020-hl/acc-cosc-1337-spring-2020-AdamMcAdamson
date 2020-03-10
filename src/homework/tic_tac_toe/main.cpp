#include "tic_tac_toe.h"

using std::cout;
using std::cin;

int main() 
{
	TicTacToe game;
	string player;
	int position;

	cout << "Enter Starting Player: ";
	cin >> player;

	game.start_game(player);

	while (!game.game_over())
	{
		std::cout << "\nEnter position player " << game.get_player() << ": ";
		cin >> position;
		cout << "\n";

		game.mark_board(position);
		game.display_board();
		cout << "\n";
	}

	return 0;
}