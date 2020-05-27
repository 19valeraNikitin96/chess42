#include "RenderService.h"
#include<iostream>

void RenderService::render(Board& board)
{
	system("cls");
	std::cout << "   ";
	for (char i = 'a'; i <= 'h'; i++)
		std::cout << " " << i << " ";
	std::cout << std::endl << "  ________________________" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << i+1 << " ";
		std::cout << "|";
		for (int j = 0; j < 8; j++) {
			if (board.getCell(i, j).isEmpty()) 
				std::cout << "  " << "|";
			else 
				std::cout << board.get(i, j).getDisplayedName() << "|";
		}
		std::cout << std::endl << "  ________________________" << std::endl;
	}
}
