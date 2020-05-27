#pragma once
#include "ChessPiece.h"
class King :
	public ChessPiece
{
public:
	King(ChessTypes::Color color)
		:ChessPiece(color, ChessTypes::ChessPieceType::KING) 
	{
		displayedName = (color == ChessTypes::Color::BLACK) ? "BK" : "WK";
	}

private:

};

