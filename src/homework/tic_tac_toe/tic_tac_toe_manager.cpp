//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe> game)
{
	update_winner_count(game->get_winner());
	games.push_back(std::move(game));
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
	
	for (auto& game : manager.games)
	{
		if (game->get_winner() == "X")
		{
			x_wins++;
		}
		else if (game->get_winner() == "O")
		{
			o_wins++;
		}
		else
		{
			ties++;
		}
		out << *game << "\n";
	}
		out << "X_wins:\t" << x_wins << "\n";
		out << "O_wins:\t" << o_wins << "\n";
		out << "Ties:  \t" << ties   << "\n";
	
	return out;
}
