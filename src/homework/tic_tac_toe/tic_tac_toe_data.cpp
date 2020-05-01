#include "tic_tac_toe_data.h"

//cpp

void TicTacToeData::save_games(const std::vector<std::unique_ptr<TicTacToe>>& games)
{
	std::ofstream game_file;
	game_file.open("game_results.txt");

	for (auto& game : games)
	{
		for (auto& peg : game->get_pegs())
		{
			game_file << peg;
		}
		game_file << game->get_winner() << "\n";
	}
}

std::vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
	std::string line;
	std::ifstream game_file("game_results.txt");
	std::vector<string> pegs;

	std::vector<std::unique_ptr<TicTacToe>> games;

	if (game_file.is_open())
	{
		while (getline(game_file, line))
		{
			pegs.clear();
			for (int i = 0; i < line.length()-1; i ++)
			{
				pegs.push_back(string(1, line.at(i)));
			}
			std::unique_ptr<TicTacToe> game;
			
			if (pegs.size() == 9)
			{
				game = std::make_unique<TicTacToe3>(pegs, string(1, line.at(line.length() - 1)));
			}
			else if (pegs.size() == 16)
			{
				game = std::make_unique<TicTacToe4>(pegs, string(1, line.at(line.length() - 1)));
			}
			else
			{
				continue;
			}
			games.push_back(std::move(game));
		}
	}
	game_file.close();

	return games;
}
