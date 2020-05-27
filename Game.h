#pragma once
#include"Board.h"
class Game
{
public:

	Game();

	~Game();

	void init(ChessTypes::Base baseOfWhite);

	void handleEvents();

	void update();

	void render();

	void clean();

	bool running();

private:
	bool isRunning;
	Board board;
	ChessTypes::Color turn = ChessTypes::Color::WHITE;
};

