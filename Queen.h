#pragma once
#include "ChessPiece.h"
class Queen :
	public ChessPiece
{
public:

	Queen(ChessTypes::Color color)
		:ChessPiece(color, ChessTypes::ChessPieceType::QUEEN) {
		displayedName = (color == ChessTypes::Color::BLACK) ? "BQ" : "WQ";
	}

private:

};

