#pragma once
#include"Board.h"
class RenderService
{
public:

	RenderService(RenderService& other) = delete;

	void operator=(const RenderService&) = delete;

	static RenderService& GetInstance() {return *instance;}

	static void render(Board &board);
	
private:
	RenderService() {}

	static RenderService* instance;
};

