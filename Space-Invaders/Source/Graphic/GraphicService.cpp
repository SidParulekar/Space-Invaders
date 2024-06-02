#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Graphic\GraphicService.h"

GraphicService::GraphicService()
{
	game_window = nullptr;
	video_mode = nullptr;
}

GraphicService::~GraphicService()
{
	onDestroy();
}

void GraphicService::setVideoMode()
{
	video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
}

sf::RenderWindow* GraphicService::createGameWindow()
{
	setVideoMode();
	return new sf::RenderWindow(*video_mode, game_window_title); 
}

void GraphicService::initialize()
{
	game_window = createGameWindow();
	game_window->setFramerateLimit(frame_rate); 
}

sf::RenderWindow* GraphicService::getGameWindow()
{
	return game_window;
}

void GraphicService::update()
{
}

void GraphicService::render()
{
	
}

bool GraphicService::isGameWindowOpen()
{
	return game_window->isOpen();
}

void GraphicService::onDestroy()
{
	delete video_mode;
}

sf::Color GraphicService::getWindowColor()
{
	return window_color;
}
