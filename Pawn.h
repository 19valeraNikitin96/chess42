#pragma once
#include"ChessPiece.h"
class Pawn
	:public ChessPiece
{
public:

	Pawn(ChessTypes::Color color, ChessTypes::Base base) 
		:ChessPiece(color, ChessTypes::ChessPieceType::PAWN)
	{
		this->base = base;
		if (color == ChessTypes::Color::BLACK) 
			displayedName = "BP";
		else
			displayedName = "WP";
	}

private:

};


