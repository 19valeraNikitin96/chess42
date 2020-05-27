#pragma once

namespace ChessTypes {

	enum class Base {
		NORTH, SOUTH
	};

	enum class Color {
		BLACK, WHITE
	};

	enum class ChessPieceType {
		PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN
	};

	/*
		if check method returns RED then chess piece cannot move to this position
		if check method returns YELLOW then chess piece attack opponent chess piece
		if check method returns RED then chess piece can move to this position
	*/
	enum class TurnTestResult {
		RED, YELLOW, GREEN
	};
}