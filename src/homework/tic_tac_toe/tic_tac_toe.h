//h
#include <string>
#include <vector>
#include <iostream>
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

using std::string; using std::vector;

class TicTacToe
{
public:
	bool game_over();
	void start_game(string first_player);
	void mark_board(int position);
	string get_player() const;
	string get_winner();
	friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
	friend std::istream& operator>>(std::istream& in, TicTacToe& game);
private:
	void set_next_player();
	bool check_column_win();
	bool check_row_win();
	bool check_diagonal_win();
	void set_winner();
	void clear_board();
	bool check_board_full();
	vector<string> pegs{ 9, " " };
	string player;
	string winner;
};


class Error
{
public:
	Error(string msg) : message{ msg } {};
	string get_message();
private:
	string message;
};
#endif //!TIC_TAC_TOE_H