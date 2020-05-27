#pragma once
#include"ChessTypes.h"
#include<string>
class ChessPiece
{
public:

	ChessPiece(ChessTypes::Color color, ChessTypes::ChessPieceType type) {
		this->type = type;
		this->color = color;
	}

	//virtual ChessTypes::TurnTestResult isValidMove(int xFrom, int yFrom, int xTo, int yTo) = 0;

	std::string getDisplayedName() { return displayedName; }

	ChessTypes::ChessPieceType getType() { return type; }

	void firstTurnIsMade() {
		isFirstTurn = false;
	}

	bool colorsAreEquals(ChessPiece& other) {
		return this->color == other.color;
	}

	ChessTypes::Color getColor() { return color; }

	ChessTypes::Base getBase() { return base; }

	bool getIsFirstTurn() { return isFirstTurn; }

protected:
	ChessTypes::Color color;
	std::string displayedName;
	bool isFirstTurn = true;
	ChessTypes::Base base;
private:
	ChessTypes::ChessPieceType type;
};

