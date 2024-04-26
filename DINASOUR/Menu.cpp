#include"Menu.h"

Menu::Menu()
{
	enter = new Button(380,150, 300, 98);

	instruction = new Button(380, 270, 300, 98);
	quit = new Button(380,400, 300, 98);
	gameNameClip.x = 0;
	gameNameClip.y = 0;
	gameNameClip.w = 100;
	gameNameClip.h = 55;
	x = 0;
}

Menu::~Menu()
{
	free();
}

bool Menu::loadMenuTexture(std::string path, SDL_Renderer* screen)
{
	return menuTexture.loadFromFile(path, screen) && enter->loadButtonTexture("imgs/button/play_button.png", screen) /*&& gameName.loadFromFile("imgs/button/exit_button.png", screen)*/ && instruction->loadButtonTexture("imgs/button/help_button.png", screen) && quit->loadButtonTexture("imgs/button/exit_button.png", screen);
}

void Menu::render(SDL_Renderer* screen)
{
	menuTexture.render(0, 0, screen);
	enter->render(screen);
	instruction->render(screen);
	quit->render(screen);
	/*gameName.render(550, 150, screen, &gameNameClip, 1, 4);*/
}

void Menu::free()
{
	menuTexture.free();
	enter->free();
	instruction->free();
	quit->free();
}

void Menu::handleEvent(SDL_Event e)
{
	enter->hanldEvent(e);
	instruction->hanldEvent(e);
	quit->hanldEvent(e);
}
// Le Hoang Viet