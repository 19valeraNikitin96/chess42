#pragma once
#include"Cell.h"
//#include"GameUtils.h"

class Board
{
public:

	const static int WIDTH = 8;
	const static int HEIGHT = 8;

	bool put(ChessPiece* chessPiece, int x, int y) {
		return cells[x][y].setChessPiece(chessPiece);
	}

	void move(int xFrom, int yFrom, int xTo, int yTo) {
		if (cells[xTo][yTo].isEmpty()) 
			cells[xTo][yTo].setChessPiece(cells[xFrom][yFrom].take());
		else 
			cells[xTo][yTo].attacked(cells[xFrom][yFrom].take());
	}

	ChessPiece& get(int x, int y) {
		return *cells[x][y].getChessPiece().get();
	}

	Cell& getCell(int x, int y) {
		return cells[x][y];
	}

private:
	Cell cells[8][8];
};

