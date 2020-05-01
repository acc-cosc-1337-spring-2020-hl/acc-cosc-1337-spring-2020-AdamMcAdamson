//h
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

using std::string; using std::vector;

class TicTacToe
{
public:	
	TicTacToe(int size) : pegs{size*size, " "} {};
	TicTacToe(vector<string>p, string win) : pegs{ p }, winner{ win } {};
	bool game_over();
	void start_game(string first_player);
	void mark_board(int position);
	string get_player() const;
	string get_winner();
	vector<string> get_pegs() const;
	friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
	friend std::istream& operator>>(std::istream& in, TicTacToe& game);
private:
	void set_next_player();
	void set_winner();
	void clear_board();
	bool check_board_full();
	string player;
	string winner;
protected:
	vector<string> pegs;
	virtual bool check_column_win() = 0;
	virtual bool check_row_win() = 0;
	virtual bool check_diagonal_win() = 0;
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