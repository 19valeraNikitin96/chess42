#include<iostream>

#include "Game.h"
#include"Rook.h"
#include"Bishop.h"
#include"King.h"
#include"Knight.h"
#include"Pawn.h"
#include"Queen.h"

#include"RenderService.h"
#include"GameUtils.h"

Game::Game()
{
	isRunning = false;
}

Game::~Game()
{
}

void Game::init(ChessTypes::Base baseOfWhite)
{
	if (ChessTypes::Base::NORTH == baseOfWhite) {
		board.getCell(0, 0).setChessPiece(new Rook(ChessTypes::Color::WHITE));
		board.getCell(0, 1).setChessPiece(new Knight(ChessTypes::Color::WHITE));
		board.getCell(0, 2).setChessPiece(new Bishop(ChessTypes::Color::WHITE));
		board.getCell(0, 3).setChessPiece(new Queen(ChessTypes::Color::WHITE));
		board.getCell(0, 4).setChessPiece(new King(ChessTypes::Color::WHITE));
		board.getCell(0, 5).setChessPiece(new Bishop(ChessTypes::Color::WHITE));
		board.getCell(0, 6).setChessPiece(new Knight(ChessTypes::Color::WHITE));
		board.getCell(0, 7).setChessPiece(new Rook(ChessTypes::Color::WHITE));
		for (int i = 0; i < 8; i++)
			board.getCell(1, i).setChessPiece(new Pawn(ChessTypes::Color::WHITE, ChessTypes::Base::NORTH));

		board.getCell(7, 0).setChessPiece(new Rook(ChessTypes::Color::BLACK));
		board.getCell(7, 1).setChessPiece(new Knight(ChessTypes::Color::BLACK));
		board.getCell(7, 2).setChessPiece(new Bishop(ChessTypes::Color::BLACK));
		board.getCell(7, 3).setChessPiece(new Queen(ChessTypes::Color::BLACK));
		board.getCell(7, 4).setChessPiece(new King(ChessTypes::Color::BLACK));
		board.getCell(7, 5).setChessPiece(new Bishop(ChessTypes::Color::BLACK));
		board.getCell(7, 6).setChessPiece(new Knight(ChessTypes::Color::BLACK));
		board.getCell(7, 7).setChessPiece(new Rook(ChessTypes::Color::BLACK));
		for (int i = 0; i < 8; i++)
			board.getCell(6, i).setChessPiece(new Pawn(ChessTypes::Color::BLACK, ChessTypes::Base::SOUTH));
	}
	else {
		board.getCell(0, 0).setChessPiece(new Rook(ChessTypes::Color::BLACK));
		board.getCell(0, 1).setChessPiece(new Knight(ChessTypes::Color::BLACK));
		board.getCell(0, 2).setChessPiece(new Bishop(ChessTypes::Color::BLACK));
		board.getCell(0, 3).setChessPiece(new Queen(ChessTypes::Color::BLACK));
		board.getCell(0, 4).setChessPiece(new King(ChessTypes::Color::BLACK));
		board.getCell(0, 5).setChessPiece(new Bishop(ChessTypes::Color::BLACK));
		board.getCell(0, 6).setChessPiece(new Knight(ChessTypes::Color::BLACK));
		board.getCell(0, 7).setChessPiece(new Rook(ChessTypes::Color::BLACK));
		for (int i = 0; i < 8; i++)
			board.getCell(1, i).setChessPiece(new Pawn(ChessTypes::Color::BLACK, ChessTypes::Base::NORTH));

		board.getCell(7, 0).setChessPiece(new Rook(ChessTypes::Color::WHITE));
		board.getCell(7, 1).setChessPiece(new Knight(ChessTypes::Color::WHITE));
		board.getCell(7, 2).setChessPiece(new Bishop(ChessTypes::Color::WHITE));
		board.getCell(7, 3).setChessPiece(new Queen(ChessTypes::Color::WHITE));
		board.getCell(7, 4).setChessPiece(new King(ChessTypes::Color::WHITE));
		board.getCell(7, 5).setChessPiece(new Bishop(ChessTypes::Color::WHITE));
		board.getCell(7, 6).setChessPiece(new Knight(ChessTypes::Color::WHITE));
		board.getCell(7, 7).setChessPiece(new Rook(ChessTypes::Color::WHITE));
		for (int i = 0; i < 8; i++)
			board.getCell(6, i).setChessPiece(new Pawn(ChessTypes::Color::WHITE, ChessTypes::Base::SOUTH));
	}
	Game::isRunning = true;
}

void Game::handleEvents()
{

}

void Game::update()
{
	auto player = (ChessTypes::Color::WHITE == turn) ? "white" : "black";
	std::cout << "Turn of " << player << std::endl;
	while (true) {
		int xFrom;
		char yChar;
		std::cout << "****Select chess piece****" << std::endl;
		std::cout << "Input row (1 - 8):" << std::endl;
		std::cin >> xFrom;
		if (xFrom - 1 < 0 || xFrom - 1 > 7) {
			std::cout << "Invalid row :(" << std::endl;
			continue;
		}
		std::cout << "Input column (a - h):" << std::endl;
		std::cin >> yChar;
		int yFrom = yChar - 'a';
		//std::cout << "DEBUG:" << "yFrom = " << yFrom << std::endl;
		if (yFrom < 0 || yFrom > 7) {
			std::cout << "Invalid column :(" << std::endl;
			continue;
		}
		if (board.getCell(xFrom - 1, yFrom).isEmpty()) {
			std::cout << "Selected cell must be not empty :))" << std::endl;
			continue;
		}
		if (board.get(xFrom - 1, yFrom).getColor() != turn) {
			std::cout << "Select not opponent chess piece :)" << std::endl;
			continue;
		}
		std::cout << "****Select cell****" << std::endl;
		std::cout << "Input row (1 - 8):" << std::endl;
		int xTo;
		std::cin >> xTo;
		if (xTo - 1 < 0 || xTo - 1 > 7) {
			std::cout << "Invalid row :(" << std::endl;
			continue;
		}
		std::cout << "Input column (a - h):" << std::endl;
		std::cin >> yChar;
		int yTo = yChar - 'a';
		if (yTo < 0 || yTo > 7) {
			std::cout << "Invalid column :(" << std::endl;
			continue;
		}
		if (!GameUtils::GetInstance().isValidMovement(xFrom - 1, yFrom, xTo - 1, yTo, board)) {
			std::cout << "Incorrect turn!" << std::endl;
			continue;
		}
		else
			board.move(xFrom - 1 , yFrom, xTo - 1, yTo);
		turn = (ChessTypes::Color::WHITE == turn) ? ChessTypes::Color::BLACK : ChessTypes::Color::WHITE;
		break;
	}
}

void Game::render()
{
	RenderService::render(board);
}

void Game::clean()
{
}

bool Game::running()
{
	return Game::isRunning;
}
