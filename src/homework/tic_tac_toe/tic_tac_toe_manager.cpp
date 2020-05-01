//cpp
#include "tic_tac_toe_manager.h"

TicTacToeManager::TicTacToeManager(TicTacToeData & d)
{
	data = d;
	games = d.get_games();
	for (auto & game : games)
	{
		update_winner_count(game->get_winner());
	}
}

TicTacToeManager::~TicTacToeManager()
{
	data.save_games(games);
}

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe> &game)
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

	for (auto & game : manager.games)
	{
		out << *game << "\n\n";
	}

	out << "X_wins:\t" << manager.x_win << "\n";
	out << "O_wins:\t" << manager.o_win << "\n";
	out << "Ties:  \t" << manager.tie   << "\n";
	
	return out;
}
