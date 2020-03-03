//cpp
#include "tic_tac_toe.h"

// TicTacToe Class
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
}

void TicTacToe::mark_board(int position)
{
	if (!(position >= 1 || position <= 9))
	{
		throw Error("Position must be 1 to 9.");
	}
	else if (player == "")
	{
		throw Error("Game must start first.");
	}
	else
	{
		set_next_player();
	}
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

string TicTacToe::get_player() const
{
	return player;
}

// Error Class
string Error::get_message()
{
	return message;
}




