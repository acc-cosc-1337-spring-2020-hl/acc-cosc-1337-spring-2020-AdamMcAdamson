//h
#include "tic_tac_toe.h"
#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H

class TicTacToe4 : public TicTacToe
{
public:
	TicTacToe4() : TicTacToe(4) {};
	TicTacToe4(std::vector<string> p, string win) : TicTacToe(p, win) {};
private:
	bool check_column_win();
	bool check_row_win();
	bool check_diagonal_win();
};

#endif // !TIC_TAC_TOE_4_H