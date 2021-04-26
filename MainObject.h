#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include"Common_Function.h"
#include"BaseObject.h"
#include"AmoObject.h"
#include<vector>

#define WIDTH_MAIN_OBJECT 250
#define HEIGHT_MAIN_OBJECT 84

class MainObject :public BaseObject
{
public:
	MainObject();
	~MainObject();

	void HandleInputAction(SDL_Event events, Mix_Chunk* bullet_sound);
	void HandleMove();

	void SetAmoList(std::vector<AmoObject*> amo_list) { p_amo_list = amo_list; }
	std::vector<AmoObject*> GetAMoList() const { return p_amo_list; }

	void MakeAmo(SDL_Surface* des);
	void RemoveAmo(const int& idx);

private:
	int x_val_;
	int y_val_;

	std::vector<AmoObject*> p_amo_list;
};


#endif 
