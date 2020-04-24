#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test can’t call mark board before start game")
{

	TicTacToe3 game;

	REQUIRE_THROWS_AS(game.mark_board(1), Error);

}

TEST_CASE("Test start game accepts only X or O")
{

	TicTacToe3 game;

	REQUIRE_THROWS_AS(game.start_game("Y"), Error);

}

TEST_CASE("Test set first player to X")
{

	TicTacToe3 game;
	game.start_game("X");

	REQUIRE(game.get_player() == "X");

}

TEST_CASE("Test set first player to O")
{

	TicTacToe3 game;
	game.start_game("O");

	REQUIRE(game.get_player() == "O");

}

TEST_CASE("Test start game with X game flow")
{

	TicTacToe3 game;
	game.start_game("X");

	REQUIRE(game.get_player() == "X");

	game.mark_board(4);

	REQUIRE(game.get_player() == "O");

}

TEST_CASE("Test start game with O game flow")
{

	TicTacToe3 game;
	game.start_game("O");

	REQUIRE(game.get_player() == "O");

	game.mark_board(2);

	REQUIRE(game.get_player() == "X");

}

TEST_CASE("Test game over when board full")
{
	TicTacToe3 game;
	game.start_game("X");
	
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == false);
	game.mark_board(8);
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test Mark Position accepts values from  1 to 9 only")
{
	TicTacToe3 game;
	game.start_game("X");

	REQUIRE_THROWS_AS(game.mark_board(0), Error);
	REQUIRE_THROWS_AS(game.mark_board(10), Error);

	game.mark_board(5);
}

TEST_CASE("Test win by first column")
{
	TicTacToe3 game;
	game.start_game("X");

	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(4);
	game.mark_board(5);
	game.mark_board(7);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
TEST_CASE("Test win by second column")
{
	TicTacToe3 game;
	game.start_game("X");

	game.mark_board(2);
	game.mark_board(1);
	game.mark_board(5);
	game.mark_board(6);
	game.mark_board(8);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
TEST_CASE("Test win by third column")
{
	TicTacToe3 game;
	game.start_game("O");

	game.mark_board(3);
	game.mark_board(1);
	game.mark_board(6);
	game.mark_board(7);
	game.mark_board(9);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}
TEST_CASE("Test win by first row")
{
	TicTacToe3 game;
	game.start_game("X");

	game.mark_board(1);
	game.mark_board(7);
	game.mark_board(2);
	game.mark_board(8);
	game.mark_board(3);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
TEST_CASE("Test win by second row")
{
	TicTacToe3 game;
	game.start_game("X");

	game.mark_board(4);
	game.mark_board(7);
	game.mark_board(5);
	game.mark_board(8);
	game.mark_board(6);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
TEST_CASE("Test win by third row")
{
	TicTacToe3 game;
	game.start_game("O");

	game.mark_board(7);
	game.mark_board(1);
	game.mark_board(8);
	game.mark_board(2);
	game.mark_board(9);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}
TEST_CASE("Test win diagonally from top left")
{
	TicTacToe3 game;
	game.start_game("X");

	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(9);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
TEST_CASE("Test win diagonally from top right")
{
	TicTacToe3 game;
	game.start_game("O");

	game.mark_board(3);
	game.mark_board(1);
	game.mark_board(5);
	game.mark_board(2);
	game.mark_board(7);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}
TEST_CASE("Test for no winner")
{
	TicTacToe3 game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == false);
	game.mark_board(8);
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "C");
}


// --------- TicTacToe4 ---------
TEST_CASE("Test can’t call mark board before start game - 4")
{

	TicTacToe4 game;

	REQUIRE_THROWS_AS(game.mark_board(1), Error);

}

TEST_CASE("Test start game accepts only X or O - 4")
{

	TicTacToe4 game;

	REQUIRE_THROWS_AS(game.start_game("Y"), Error);

}

TEST_CASE("Test set first player to X - 4")
{

	TicTacToe4 game;
	game.start_game("X");

	REQUIRE(game.get_player() == "X");

}

TEST_CASE("Test set first player to O - 4")
{

	TicTacToe4 game;
	game.start_game("O");

	REQUIRE(game.get_player() == "O");

}

TEST_CASE("Test start game with X game flow - 4")
{

	TicTacToe4 game;
	game.start_game("X");

	REQUIRE(game.get_player() == "X");

	game.mark_board(4);

	REQUIRE(game.get_player() == "O");

}

TEST_CASE("Test start game with O game flow - 4")
{

	TicTacToe4 game;
	game.start_game("O");

	REQUIRE(game.get_player() == "O");

	game.mark_board(2);

	REQUIRE(game.get_player() == "X");

}

TEST_CASE("Test game over when board full - 4")
{
	TicTacToe4 game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(8);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == false);
	game.mark_board(10);
	REQUIRE(game.game_over() == false);
	game.mark_board(11);
	REQUIRE(game.game_over() == false);
	game.mark_board(12);
	REQUIRE(game.game_over() == false);
	game.mark_board(16);
	REQUIRE(game.game_over() == false);
	game.mark_board(13);
	REQUIRE(game.game_over() == false);
	game.mark_board(14);
	REQUIRE(game.game_over() == false);
	game.mark_board(15);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test Mark Position accepts values from  1 to 16 only - 4")
{
	TicTacToe4 game;
	game.start_game("X");

	REQUIRE_THROWS_AS(game.mark_board(0), Error);
	REQUIRE_THROWS_AS(game.mark_board(17), Error);

	game.mark_board(10);
}

TEST_CASE("Test win by first column - 4")
{
	TicTacToe4 game;
	game.start_game("X");

	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(9);
	game.mark_board(4);
	game.mark_board(13);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
TEST_CASE("Test win by second column - 4")
{
	TicTacToe4 game;
	game.start_game("X");

	game.mark_board(2);
	game.mark_board(1);
	game.mark_board(6);
	game.mark_board(3);
	game.mark_board(10);
	game.mark_board(4);
	game.mark_board(14);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
TEST_CASE("Test win by third column - 4")
{
	TicTacToe4 game;
	game.start_game("O");

	game.mark_board(3);
	game.mark_board(1);
	game.mark_board(7);
	game.mark_board(2);
	game.mark_board(11);
	game.mark_board(5);
	game.mark_board(15);


	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}
TEST_CASE("Test win by fourth column - 4")
{
	TicTacToe4 game;
	game.start_game("O");

	game.mark_board(4);
	game.mark_board(1);
	game.mark_board(8);
	game.mark_board(2);
	game.mark_board(12);
	game.mark_board(5);
	game.mark_board(16);


	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}
TEST_CASE("Test win by first row - 4")
{
	TicTacToe4 game;
	game.start_game("X");

	game.mark_board(1);
	game.mark_board(5);
	game.mark_board(2);
	game.mark_board(6);
	game.mark_board(3);
	game.mark_board(7);
	game.mark_board(4); 

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
TEST_CASE("Test win by second row - 4")
{
	TicTacToe4 game;
	game.start_game("X");

	game.mark_board(5);
	game.mark_board(2);
	game.mark_board(6);
	game.mark_board(3);
	game.mark_board(7);
	game.mark_board(4);
	game.mark_board(8);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
TEST_CASE("Test win by third row - 4")
{
	TicTacToe4 game;
	game.start_game("O");

	game.mark_board(9);
	game.mark_board(2);
	game.mark_board(10);
	game.mark_board(3);
	game.mark_board(11);
	game.mark_board(4);
	game.mark_board(12);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}
TEST_CASE("Test win by fourth row - 4")
{
	TicTacToe4 game;
	game.start_game("O");

	game.mark_board(13);
	game.mark_board(2);
	game.mark_board(14);
	game.mark_board(3);
	game.mark_board(15);
	game.mark_board(4);
	game.mark_board(16);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}
TEST_CASE("Test win diagonally from top left - 4")
{
	TicTacToe4 game;
	game.start_game("X");

	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(6);
	game.mark_board(3);
	game.mark_board(11);
	game.mark_board(4);
	game.mark_board(16);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
TEST_CASE("Test win diagonally from top right - 4")
{
	TicTacToe4 game;
	game.start_game("O");

	game.mark_board(4);
	game.mark_board(1);
	game.mark_board(7);
	game.mark_board(2);
	game.mark_board(10);
	game.mark_board(3);
	game.mark_board(13);


	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}
TEST_CASE("Test for no winner - 4")
{
	TicTacToe4 game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(8);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == false);
	game.mark_board(10);
	REQUIRE(game.game_over() == false);
	game.mark_board(11);
	REQUIRE(game.game_over() == false);
	game.mark_board(12);
	REQUIRE(game.game_over() == false);
	game.mark_board(16);
	REQUIRE(game.game_over() == false);
	game.mark_board(13);
	REQUIRE(game.game_over() == false);
	game.mark_board(14);
	REQUIRE(game.game_over() == false);
	game.mark_board(15);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "C");
}
TEST_CASE("Test for game over too early")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.game_over() == false);
}