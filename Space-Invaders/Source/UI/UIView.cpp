#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\UI\UIView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Global;

		UIView::UIView() = default;

		UIView::~UIView() = default;

		void UIView::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			ui_state = UIState::VISIBLE;
		}

		void UIView::update() 
		{ 

		}

		void UIView::render()
		{ 

		}

		void UIView::show()
		{
			ui_state = UIState::VISIBLE;
		}

		void UIView::hide()
		{
			ui_state = UIState::HIDDEN;
		}
	}
}