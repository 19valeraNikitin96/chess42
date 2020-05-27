#pragma once
#include"ChessPiece.h"
#include<memory>
class Cell
{
public:

	bool setChessPiece(ChessPiece* chessPiece) {
		if (this->chessPiece.get() != nullptr)
			return false;
		this->chessPiece.reset(chessPiece);
		return true;
	}

	ChessPiece* attacked(ChessPiece* chessPiece) {
		auto res = this->chessPiece.release();
		this->chessPiece.reset(chessPiece);
		return res;
	}

	bool isEmpty() {
		return this->chessPiece.get() == nullptr;
	}

	std::unique_ptr<ChessPiece>& getChessPiece() {
		return this->chessPiece;
	}

	ChessPiece* take() {return chessPiece.release();}

private:
	std::unique_ptr<ChessPiece> chessPiece;
};

