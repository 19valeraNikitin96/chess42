
#include"Board.h"
#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"Queen.h"
#include<iostream>
#include"RenderService.h"
#include"Game.h"

int main(int argc, char* argv[]) {
	Game* game = new Game();
	game->init(ChessTypes::Base::NORTH);
	while (game->running()) {
		game->render();
		game->update();
	}
	system("pause");
}