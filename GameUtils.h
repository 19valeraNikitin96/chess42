#pragma once
#include<memory>
#include"Board.h"
//Singleton pattern
class GameUtils
{
protected:
	static GameUtils* instance;

	GameUtils() {}
public:

	GameUtils(GameUtils& other) = delete;

	void operator=(const GameUtils&) = delete;

	bool barrierVerticalBetween(int xFrom, int xTo, int y, Board& board);

	bool barrierHorizontalBetween(int yFrom, int yTo, int x, Board& board);

	bool barrierDiagonalBetween(int xFrom, int yFrom, int xTo, int yTo, Board& board);

	bool isValidMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board);

	static GameUtils& GetInstance() {return *instance;}

private:

	bool isValidPawnMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board);

	bool isValidRookMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board);

	bool isValidKnightMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board);

	bool isValidBishopMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board);

	bool isValidKingMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board);

	bool isValidQueenMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board);

	bool isCorrectPawnMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board);
};

