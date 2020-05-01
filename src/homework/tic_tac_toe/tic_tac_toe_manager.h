//h
#include "tic_tac_toe_data.h"
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

using std::vector;
using std::unique_ptr;

class TicTacToeManager
{
public:
	TicTacToeManager() = default;
	TicTacToeManager(TicTacToeData& d);
	~TicTacToeManager();
	void save_game(unique_ptr<TicTacToe>& game);
	friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
private:
	TicTacToeData data;
	void update_winner_count(std::string winner);
	vector<unique_ptr<TicTacToe>> games;
	int o_win{ 0 };
	int x_win{ 0 };
	int tie{ 0 };
};


#endif //!TIC_TAC_TOE_MANAGER_H
