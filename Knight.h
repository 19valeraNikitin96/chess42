#pragma once
#include "ChessPiece.h"
class Knight :
	public ChessPiece
{
public:

	Knight(ChessTypes::Color color) 
		:ChessPiece(color, ChessTypes::ChessPieceType::KNIGHT)
	{
		displayedName = (color == ChessTypes::Color::BLACK) ? "BN" : "WN";
	}

private:

};

