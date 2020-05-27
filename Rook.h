#pragma once
#include"ChessPiece.h"
class Rook
	:public ChessPiece
{
public:

	Rook(ChessTypes::Color color)
		:ChessPiece(color, ChessTypes::ChessPieceType::ROOK) {
		displayedName = (color == ChessTypes::Color::BLACK) ? "BR" : "WR";
	}

	//virtual ChessTypes::TurnTestResult isValidMove(int xFrom, int yFrom, int xTo, int yTo);


private:

};

