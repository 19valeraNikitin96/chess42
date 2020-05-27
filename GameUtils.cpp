#include "GameUtils.h"

GameUtils* GameUtils::instance = new GameUtils;

bool GameUtils::barrierVerticalBetween(int xFrom, int xTo, int y, Board& board)
{
	int from;
	int to;
	if (xFrom > xTo) {
		from = xTo;
		to = xFrom;
	}
	else {
		from = xFrom;
		to = xTo;
	}
	for (int x = from + 1; x < to; x++) 
		if (!board.getCell(x, y).isEmpty())
			return true;
	return false;
}

bool GameUtils::barrierHorizontalBetween(int yFrom, int yTo, int x, Board& board)
{
	int from;
	int to;
	if (yFrom > yTo) {
		from = yTo;
		to = yFrom;
	}
	else {
		from = yFrom;
		to = yTo;
	}
	for (int y = from + 1; y < to; y++)
		if (!board.getCell(x, y).isEmpty())
			return true;
	return false;
}

bool GameUtils::barrierDiagonalBetween(int xFrom, int yFrom, int xTo, int yTo, Board& board)
{
	int xStart;
	int xFinish;
	if (xFrom > xTo) {
		xStart = xTo;
		xFinish = xFrom;
	}
	else {
		xStart = xFrom;
		xFinish = xTo;
	}
	int yStart;
	int yFinish;
	if (yFrom > yTo) {
		yStart = yTo;
		yFinish = yFrom;
	}
	else {
		yStart = yFrom;
		yFinish = yTo;
	}
	for (int x = xStart + 1, y = yStart + 1; x < xFinish && y < yFinish; x++, y++) 
		if (!board.getCell(x, y).isEmpty())
			return true;
	return false;
}

bool GameUtils::isValidMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board)
{
	ChessPiece& chessPiece = board.get(xFrom, yFrom);
	if (!board.getCell(xTo, yTo).isEmpty() && board.get(xFrom, yFrom).colorsAreEquals(board.get(xTo, yTo)))
		return false;
	bool res = false;
	switch (chessPiece.getType()) {
	case ChessTypes::ChessPieceType::PAWN:
		res = isValidPawnMovement(xFrom, yFrom, xTo, yTo, board);break;
	case ChessTypes::ChessPieceType::ROOK:
		res = isValidRookMovement(xFrom, yFrom, xTo, yTo, board); break;
	case ChessTypes::ChessPieceType::KNIGHT:
		res = isValidKnightMovement(xFrom, yFrom, xTo, yTo, board); break;
	case ChessTypes::ChessPieceType::BISHOP:
		res = isValidBishopMovement(xFrom, yFrom, xTo, yTo, board); break;
	case ChessTypes::ChessPieceType::KING:
		res = isValidKingMovement(xFrom, yFrom, xTo, yTo, board); break;
	case ChessTypes::ChessPieceType::QUEEN:
		res = isValidQueenMovement(xFrom, yFrom, xTo, yTo, board); break;
	}
	if (res)
		chessPiece.firstTurnIsMade();
	return res;
}

bool GameUtils::isValidPawnMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board)
{
	if (!isCorrectPawnMovement(xFrom, yFrom, xTo, yTo, board))
		return false;
	if (abs(xFrom - xTo) >= 1 && yFrom == yTo) 
		return !barrierVerticalBetween(xFrom, xTo, yFrom, board);
	return true;
}

bool GameUtils::isCorrectPawnMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board) {
	
	if (board.get(xFrom, yFrom).getBase() == ChessTypes::Base::NORTH) {
		if (xFrom >= xTo)
			return false;
		if (xTo - xFrom == 1 && abs(yFrom - yTo) == 1 &&
			(!board.getCell(xTo, yTo).isEmpty() && !board.get(xFrom, yFrom).colorsAreEquals(board.get(xTo, yTo))))
			return true;
		if (xTo - xFrom == 1 && abs(yFrom - yTo) == 0 && board.getCell(xTo, yTo).isEmpty())
			return true;
		if (xTo - xFrom == 2 && abs(yFrom - yTo) == 0 && board.get(xFrom, yFrom).getIsFirstTurn() && board.getCell(xTo, yTo).isEmpty())
			return true;
	}
	else {
		if (xFrom <= xTo)
			return false;
		if (xFrom - xTo == 1 && abs(yFrom - yTo) == 1 &&
			(!board.getCell(xTo, yTo).isEmpty() && !board.get(xFrom, yFrom).colorsAreEquals(board.get(xTo, yTo))))
			return true;
		if (xFrom - xTo == 1 && abs(yFrom - yTo) == 0 && board.getCell(xTo, yTo).isEmpty())
			return true;
		if (xFrom - xTo == 2 && abs(yFrom - yTo) == 0 && board.get(xFrom, yFrom).getIsFirstTurn() && board.getCell(xTo, yTo).isEmpty())
			return true;
	}
	return false;
}

bool GameUtils::isValidRookMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board)
{
	if (!(xFrom == xTo || yFrom == yTo))
		return false;
	if (xFrom == xTo) 
		return !barrierHorizontalBetween(yFrom, yTo, xFrom, board);
	if (yFrom == yTo) 
		return !barrierVerticalBetween(xFrom, xTo, yFrom, board);
	return false;
}

bool GameUtils::isValidKnightMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board)
{
	if (abs(xFrom - xTo) == 2 && abs(yFrom - yTo) == 1)
		return true;
	if (abs(yFrom - yTo) == 2 && abs(xFrom - xTo) == 1)
		return true;
	return false;
}

bool GameUtils::isValidBishopMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board)
{
	if (abs(xFrom - xTo) == abs(yFrom - yTo))
		return !barrierDiagonalBetween(xFrom, yFrom, xTo, yTo, board);
	return false;
}

bool GameUtils::isValidKingMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board)
{
	bool vert = abs(xFrom - xTo) == 1;
	bool hor = abs(yFrom - yTo) == 1;
	if (vert || hor)
		return true;
	return false;
}

bool GameUtils::isValidQueenMovement(int xFrom, int yFrom, int xTo, int yTo, Board& board)
{
	if (abs(xFrom - xTo) == 0 || abs(yFrom - yTo) == 0 || abs(xFrom - xTo) == abs(yFrom - yTo))
	{
		if (abs(xFrom - xTo) == abs(yFrom - yTo))
			return !barrierDiagonalBetween(xFrom, yFrom, xTo, yTo, board);
		if (yFrom == yTo)
			return !barrierVerticalBetween(xFrom, xTo, yFrom, board);
		if (xFrom == xTo)
			return !barrierHorizontalBetween(yFrom, yTo, xFrom, board);
	}
	return false;
}
