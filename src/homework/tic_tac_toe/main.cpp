#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

using std::cout;
using std::cin;
using std::vector;
using std::unique_ptr;
using std::make_unique;

int main() 
{

	int x = 0;
	int o = 0;
	int tie = 0;
	vector<unique_ptr<TicTacToe>> games;
	TicTacToeManager manager = TicTacToeManager();
	unique_ptr<TicTacToe> game;
	int gameType = 0;
	string player;
	string choice = "Y";

	do {
		cout << "Would you like to play 3 or 4? ";
		cin >> gameType;
		
		if (gameType == 3)
		{
			game = make_unique<TicTacToe3>();
			games.push_back(std::move(game));
		}
		else if (gameType == 4)
		{
			game = make_unique<TicTacToe4>();
			games.push_back(std::move(game));
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
		
		games[games.size()-1]->start_game(player);

		while (!games[games.size()-1]->game_over())
		{

			cin >> *games[games.size() - 1];
			cout << *games[games.size() - 1];
			cout << "\n";
		}

		if (games[games.size() - 1]->get_winner() == "X")
		{
			x++;
		}
		else if (games[games.size() - 1]->get_winner() == "O")
		{
			o++;
		}
		else
		{
			tie++;
		}

		cout << "X:\t" << x << "\nO:\t" << o << "\nTies:\t" << tie << "\n";

		manager.save_game(std::move(games[games.size() - 1]));
		
		cout << "\nPlay again? (Y: yes, N: no): ";
		cin >> choice;

	} while (choice == "Y");

	cout << manager;
	
	return 0;
}