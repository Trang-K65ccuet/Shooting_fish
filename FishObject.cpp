#include "FishObject.h"

FishObject::FishObject()
{
	rect_.x = SCREEN_WIDTH;
	rect_.y = SCREEN_HEIGHT * 0.5;
	x_val_ = 0;
	y_val_ = 0;
	fish_type_ = NONE;
}

FishObject::~FishObject()
{

}


void FishObject::HandleMove(const int& x_border, const int& y_border)
{
	rect_.x -= x_val_;
	if (rect_.x < -rect_.w)
	{
		rect_.x = SCREEN_WIDTH;
		int rand_y = rand() % 400;
		if (rand_y <= 30) rand_y = 250;
		rect_.y = rand_y;
	}
}

void FishObject::Reset(const int& xboder)
{
	rect_.x = xboder;
	int rand_y = rand() % 400;
	if (rand_y <= 30) rand_y = 250;
	rect_.y = rand_y;
}

