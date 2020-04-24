//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(TicTacToe game)
{
	games.push_back(game);
	update_winner_count(game.get_winner());
}

void TicTacToeManager::update_winner_count(std::string winner)
{
	if (winner == "X")
	{
		x_win++;
	}
	else if(winner == "O")
	{
		o_win++;
	}
	else
	{
		tie++;
	}
}

std::ostream & operator<<(std::ostream & out, const TicTacToeManager & manager)
{
	int x_wins = 0;
	int o_wins = 0;
	int ties = 0;
	for (auto &game : manager.games)
	{
		if (game.get().get_winner() == "X")
		{
			x_wins++;
		}
		else if (game.get().get_winner() == "O")
		{
			o_wins++;
		}
		else
		{
			ties++;
		}
		out << game.get() << "\n";
		out << "X_wins:\t" << x_wins << "\n";
		out << "O_wins:\t" << o_wins << "\n";
		out << "Ties:  \t" << ties   << "\n";
	}
	return out;
}
