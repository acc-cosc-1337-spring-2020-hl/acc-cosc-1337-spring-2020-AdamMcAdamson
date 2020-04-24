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
	bool game_over();
	void start_game(string first_player);
	void mark_board(int position);
	string get_player() const;
	string get_winner();
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
	virtual bool check_column_win();
	virtual bool check_row_win();
	virtual bool check_diagonal_win();
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