//cpp
#include "tic_tac_toe.h"

// TicTacToe Class
bool TicTacToe::game_over()
{


	return check_board_full();
}

void TicTacToe::start_game(string first_player)
{
	if (!(first_player == "X" || first_player == "O"))
	{
		throw Error("Player must be X or O.");
	}
	else
	{
		player = first_player;
	}

	clear_board();
}

void TicTacToe::mark_board(int position)
{
	if (!(position >= 1 || position <= 9))
	{
		throw Error("Position must be 1 to 9.");
	}
	else if (pegs[position - 1] != " ")
	{
		throw Error("Position already filled.");
	}
	else if (player == "")
	{
		throw Error("Game must start first.");
	}
	else
	{
		pegs[position - 1] = player;
		set_next_player();
	}
}

void TicTacToe::display_board() const
{
	string out = " ";
	for (int i = 0; i < 9; i++) {
		if (i % 3 != 0) {
			out += " | ";
		} 
		else if (i / 3 > 0) {
			out += "\n-----------\n ";
		}
		out += pegs[i];
	}
	std::cout << out;
}

bool TicTacToe::check_board_full()
{
	for (auto p : pegs)
	{
		if (p == " ")
		{
			return false;
		}
	}
	return true;
}

void TicTacToe::set_next_player()
{
	if (player == "X")
	{
		player = "O";
	}
	else if (player == "O")
	{
		player = "X";
	}
	else
	{
		throw Error("Player Unknown.");
	}
}

void TicTacToe::set_winner()
{
	winner = player;
}

void TicTacToe::clear_board()
{
	for (auto p : pegs)
	{
		p = " ";
	}
}

string TicTacToe::get_player() const
{
	return player;
}

string TicTacToe::get_winner()
{
	return winner;
}

bool TicTacToe::check_column_win()
{
	for (int i = 0; i < 3; i++) {
		if (pegs[i] == pegs[i + 3] && pegs[i + 3] == pegs[i + 6]) {
			return true;
		}
	}
	return false;
}

bool TicTacToe::check_row_win()
{
	for (int i = 0; i < 3; i++) {
		if (pegs[i*3] == pegs[i*3 + 1] && pegs[i*3 + 1] == pegs[i*3 + 2]) {
			return true;
		}
	}
	return false;
}

bool TicTacToe::check_diagonal_win()
{
	if (pegs[0] == pegs[4] && pegs[4] == pegs[8])
	{
		return true;
	}
	else if (pegs[2] == pegs[4] && pegs[4] == pegs[6]) {
		return true;
	}
	else
	{
		return false;
	}
}

// Error Class
string Error::get_message()
{
	return message;
}
