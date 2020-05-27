#pragma once
#include "ChessPiece.h"
class Bishop :
	public ChessPiece
{
public:

	Bishop(ChessTypes::Color color)
		:ChessPiece(color, ChessTypes::ChessPieceType::BISHOP) {
		displayedName = (color == ChessTypes::Color::BLACK) ? "BB" : "WB";
	}

private:


};

