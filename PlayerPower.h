#ifndef PLAYER_POWER_H_
#define PLAYER_POWER_H_
#include"BaseObject.h"
#include<vector>

class PlayerPower : public BaseObject
{
public:
	PlayerPower();
	~PlayerPower();

	void AddPos(const int& xpos);
	void Render(SDL_Surface* des);
	void Init();
	void Decrease();

private:
	int number_;
	std::vector<int>pos_list_;
};

#endif
