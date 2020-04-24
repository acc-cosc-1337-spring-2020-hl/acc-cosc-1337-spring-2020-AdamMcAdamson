//h
#include "tic_tac_toe.h"
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

class TicTacToeManager
{
public:
	void save_game(std::unique_ptr<TicTacToe> game);
	friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
private:
	void update_winner_count(std::string winner);
	std::vector<std::unique_ptr<TicTacToe>> games;
	int o_win{ 0 };
	int x_win{ 0 };
	int tie{ 0 };
};


#endif //!TIC_TAC_TOE_MANAGER_H
