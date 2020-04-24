//cpp
#include "tic_tac_toe.h"

// TicTacToe Class
bool TicTacToe::game_over()
{
	if (check_column_win() || check_row_win() || check_diagonal_win())
	{
		set_winner();
		return true;
	}
	else if(check_board_full())
	{
		winner = "C";
		return true;
	}
	else
	{
		return false;
	}
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
	if (!(position >= 1 && position <= 9))
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
		if (!game_over()) {
			set_next_player();
		}
	}
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
	for (auto&  p : pegs)
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
		if (pegs[i] == player  && pegs[i + 3] == player && pegs[i + 6] == player) {
			return true;
		}
	}
	return false;
}

bool TicTacToe::check_row_win()
{
	for (int i = 0; i < 3; i++) {
		if (pegs[i*3] == player && pegs[i*3 + 1] == player && pegs[i*3 + 2] == player) {
			return true;
		}
	}
	return false;
}

bool TicTacToe::check_diagonal_win()
{
	if (pegs[0] == player && pegs[4] == player && pegs[8] == player)
	{
		return true;
	}
	else if (pegs[2] == player && pegs[4] == player && pegs[6] == player) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream & operator<<(std::ostream & out, const TicTacToe & game)
{
	out << " ";
	for (int i = 0; i < 9; i++) {
		if (i % 3 != 0) {
			out << " | ";
		}
		else if (i / 3 > 0) {
			out << "\n-----------\n ";
		}
		out << game.pegs[i];
	}
	return out;
}

std::istream & operator>>(std::istream & in, TicTacToe & game)
{
	int position;

	std::cout << "\nEnter position (1-9) player " << game.get_player() << ": ";
	
	in >> position;

	std::cout << "\n";
	game.mark_board(position);
	
	return in;
}

// Error Class
string Error::get_message()
{
	return message;
}
