#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

using std::cout;
using std::cin;

int main() 
{
	int x = 0;
	int o = 0;
	int tie = 0;
	std::vector<std::reference_wrapper<TicTacToe>> games;
	TicTacToeManager manager = TicTacToeManager();
	int gameType = 0;
	string player;
	string choice = "Y";

	/* 
	
	Cannot Figure out main, but my test cases work.

	pushed_back games have pegs.size() == 0 which should not be the case. 

	I suspect I am doing something wrong with handling a vector<reference_wrapper<Type>> vs. a vector<Type>
	--------------------------------


	do {
		cout << "Would you like to play 3 or 4? ";
		cin >> gameType;
		
		if (gameType == 3)
		{
			TicTacToe game = TicTacToe3();
			games.push_back(game);
		}
		else if (gameType == 4)
		{
			TicTacToe game = TicTacToe4();
			games.push_back(game);
		}
		else
		{
			cout << "Game Type must be 3 or 4.\n";
			continue;
		}
		
		cout << "Enter Starting Player: ";
		cin >> player;
		if (!(player == "X" || player == "O"))
		{
			cout << "Player must be 'X' or 'O'\n";
			continue;
		}

		while (!games[games.size()-1].get().game_over())
		{

			cin >> games[games.size() - 1].get();
			cout << games[games.size() - 1].get();
			cout << "\n";
		}
		if (games[games.size() - 1].get().get_winner() == "X")
		{
			x++;
		}
		else if (games[games.size() - 1].get().get_winner() == "O")
		{
			o++;
		}
		else
		{
			tie++;
		}

		cout << "X:\t" << x << "\nO:\t" << o << "\nTies:\t" << tie << "\n";

		manager.save_game(games[games.size() - 1].get());
		
		cout << "\nPlay again? (Y: yes, N: no): ";
		cin >> choice;

	} while (choice == "Y");

	cout << manager;
	*/
	return 0;
}