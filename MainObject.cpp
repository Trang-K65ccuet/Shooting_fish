#include "MainObject.h"

MainObject::MainObject()
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	x_val_ = 0;
	y_val_ = 0;
}

MainObject::~MainObject()
{
	;
}

void MainObject::HandleInputAction(SDL_Event events, Mix_Chunk* bullet_sound)
{
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val_ -= HEIGHT_MAIN_OBJECT / 25;
			break;
		case SDLK_DOWN:
			y_val_ += HEIGHT_MAIN_OBJECT / 25;
			break;
		case SDLK_RIGHT:
			x_val_ += WIDTH_MAIN_OBJECT / 25;
			break;
		case SDLK_LEFT:
			x_val_ -= WIDTH_MAIN_OBJECT / 25;
			break;
		case SDLK_SPACE:
			AmoObject* p_amo = new AmoObject();
			p_amo->LoadImg("image//amo.png");
			Mix_PlayChannel(-1, bullet_sound, 0);
			
			p_amo->SetRect(this->rect_.x + this->rect_.w - 22, this->rect_.y + this->rect_.h * 0.72);
			p_amo->set_is_move(true);
			p_amo->set_x_val(20);

			p_amo_list.push_back(p_amo);
		}
	}
	else if (events.type == SDL_KEYUP)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val_ += HEIGHT_MAIN_OBJECT / 25;
			break;
		case SDLK_DOWN:
			y_val_ -= HEIGHT_MAIN_OBJECT / 25;
			break;
		case SDLK_RIGHT:
			x_val_ -= WIDTH_MAIN_OBJECT / 25;
			break;
		case SDLK_LEFT:
			x_val_ += WIDTH_MAIN_OBJECT / 25;
			break;
		}
	}
	else if (events.type == SDL_MOUSEBUTTONDOWN)
	{
		AmoObject* p_amo = new AmoObject();
		if (events.button.button == SDL_BUTTON_LEFT)
		{
			p_amo->LoadImg("image//amo.png");
			Mix_PlayChannel(-1, bullet_sound, 0);
		}

		p_amo->SetRect(this->rect_.x + this->rect_.w - 22, this->rect_.y + this->rect_.h * 0.72);
		p_amo->set_is_move(true);
		p_amo->set_x_val(20);

		p_amo_list.push_back(p_amo);
	}
}

void MainObject::MakeAmo(SDL_Surface* des)
{
	for (int i = 0; i < p_amo_list.size(); i++)
	{
		AmoObject* p_amo = p_amo_list.at(i);
		if (p_amo != NULL)
		{
			if (p_amo->get_is_move())
			{
				p_amo->Show(des);
				p_amo->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			}
			else
			{
				if (p_amo != NULL)
				{
					p_amo_list.erase(p_amo_list.begin() + i);

					delete p_amo;
					p_amo = NULL;
				}
			}
		}
	}
}

void MainObject::HandleMove()
{
	rect_.x += x_val_;

	if (rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT>SCREEN_WIDTH)
	{
		rect_.x -= x_val_;
	}

	rect_.y += y_val_;

	if (rect_.y < 0 || rect_.y + HEIGHT_MAIN_OBJECT>SCREEN_HEIGHT - 100)
	{
		rect_.y -= y_val_;
	}
}

void MainObject::RemoveAmo(const int& idx)
{
	for (int i = 0; i < p_amo_list.size(); i++)
	{
		if (idx < p_amo_list.size())
		{
			AmoObject* p_amo = p_amo_list.at(idx);
			p_amo_list.erase(p_amo_list.begin() + idx);

			if (p_amo != NULL)
			{
				delete p_amo;
				p_amo = NULL;
			}
		}
	}
}


