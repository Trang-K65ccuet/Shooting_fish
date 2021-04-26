#include"Common_Function.h"
#include"MainObject.h"
#include"FishObject.h"
#include"ExplosionObject.h"
#include"PlayerPower.h"
#include"TextObject.h"
#undef main

TTF_Font* g_font_text = NULL;
TTF_Font* g_font_menu = NULL;
TTF_Font* g_font_end = NULL;


bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	//Init screen
	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (g_screen == NULL)
	{
		return false;
	}

	//Init audio
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		return false;

	//Read file wav audio
	g_sound_bullet = Mix_LoadWAV("sound//Explosion+1.wav");
	g_sound_exp[0] = Mix_LoadWAV("sound//Arrow+Swoosh+2.wav");
	g_sound_exp[1] = Mix_LoadWAV("sound//Explosion+5.wav");
	g_sound_track = Mix_LoadWAV("sound//ChocoboRacingWhiteMagesTheme-HoaTau-3316647.wav");

	if (g_sound_exp[0] == NULL || g_sound_exp[1] == NULL 
		|| g_sound_bullet == NULL||g_sound_track==NULL) return 0;

	//Init text
	if (TTF_Init() == -1)
	{
		return false;
	}

	//Read file ttf(text font)
	g_font_text = TTF_OpenFont("text//gamecuben.ttf", 20);
	g_font_menu= TTF_OpenFont("text//gamecuben.ttf", 50);
	g_font_end=TTF_OpenFont("text//gamecuben.ttf", 30);
	if (g_font_text == NULL && g_font_menu==NULL&&g_font_end==NULL)
	{
		return false;
	}

	return true;
}

int main(int arc, char* argv[])
{
	//Check quit
	bool is_quit = false;
	if (Init() == false) return 0;

	//Make sound track
	Mix_PlayChannel(-1, g_sound_track, -1);

    again:
    //Show menu
    int ret_menu = SDLCommonFunc::ShowMenu(g_screen, g_font_menu);

    //Check exit
	if (ret_menu == 1) is_quit = true;


	//LoadBackground
	g_bkground = SDLCommonFunc::LoadImage("image//background.png");
	if (g_bkground == NULL)
	{
		return 0;
	}

	//Make PlayerPower
	PlayerPower player_power;
	player_power.Init();

	//Make text
	TextObject score_game;
	score_game.SetColor(TextObject::BLACK_TEXT);

	//Make MainObject
	MainObject main_object;
	main_object.SetRect(150, 250);
	bool ret = main_object.LoadImg("image//mainobject.png");
	if (!ret) return 0;

	//Make Fish1
	FishObject* p_fish1s = new FishObject[NUM_FISH1];
	for (int f1 = 0; f1 < NUM_FISH1; f1++)
	{
		FishObject* p_fish1 = (p_fish1s + f1);
		if (p_fish1)
		{
			p_fish1->SetWidthHeigh(WIDTH_FISH1, HEIGHT_FISH1);
			bool f1_ret = p_fish1->LoadImg("image//fish1.png");
			p_fish1->set_type(FishObject::FISH1);
			if (f1_ret == false) return 0;
			else
			{
				int rand_y = rand() % 400;
				if (rand_y <= 30) rand_y = 150;
				p_fish1->SetRect(SCREEN_WIDTH + f1 * 400, rand_y);
				p_fish1->set_x_val(5);
			}
		}
	}

	//Make Fish2
	FishObject* p_fish2s = new FishObject[NUM_FISH2];
	for (int f2 = 0; f2 < NUM_FISH2; f2++)
	{
		FishObject* p_fish2 = (p_fish2s + f2);
		if (p_fish2)
		{
			p_fish2->SetWidthHeigh(WIDTH_FISH2, HEIGHT_FISH2);
			bool f2_ret = p_fish2->LoadImg("image//fish2.png");
			p_fish2->set_type(FishObject::FISH2);
			if (f2_ret == false) return 0;
			else
			{
				int rand_y = rand() % 400;
				if (rand_y <= 30) rand_y = 250;
				p_fish2->SetRect(SCREEN_WIDTH + f2 * 400, rand_y);
				p_fish2->set_x_val(3);
			}
		}
	}

	//Make Bomb
	FishObject* p_bombs = new FishObject[NUM_BOMB];
	for (int b = 0; b < NUM_BOMB; b++)
	{
		FishObject* p_bomb = (p_bombs + b);
		if (p_bomb)
		{
			p_bomb->SetWidthHeigh(WIDTH_BOMB, HEIGHT_BOMB);
			bool b_ret = p_bomb->LoadImg("image//bomb.png");
			if (b_ret == false) return 0;
			else
			{
				int rand_y = rand() % 400;
				if (rand_y <= 30) rand_y = 350;
				p_bomb->SetRect(SCREEN_WIDTH + b * 300, rand_y);
				p_bomb->set_x_val(4);
			}
		}
	}

	//Init ExplosionObject-bomb
	ExplosionObject exp_bomb;
	ret = exp_bomb.LoadImg("image//exp_main.png");
	exp_bomb.set_clip();
	if (!ret) return 0;

	//Init die_num and score
	unsigned int die_number = 0;
	unsigned int score_value = 0;

	//Play
	while (!is_quit)
	{
		while (SDL_PollEvent(&g_even))
		{
			if (g_even.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			main_object.HandleInputAction(g_even, g_sound_bullet);//Action
		}

		//Apply background
		SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);

		//Show PlayerPower
		player_power.Render(g_screen);

		//Show score value
		std::string val_str_score = std::to_string(score_value);
		std::string strScore("SCORE: ");
		strScore += val_str_score;

		//Show text
		score_game.SetText(strScore);
		score_game.CreateGameText(g_font_text, g_screen);

		//Imp MainObject
		main_object.HandleMove();
		main_object.Show(g_screen);
		main_object.MakeAmo(g_screen);

		//Imp Fish1
		for (int fi1 = 0; fi1 < NUM_FISH1; fi1++)
		{
			FishObject* p_fish1 = (p_fish1s + fi1);
			if (p_fish1)
			{
				p_fish1->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_fish1->Show(g_screen);

				//Check collision main_amo&fish1
				std::vector<AmoObject*>amo_list = main_object.GetAMoList();
				for (int im1 = 0; im1 < amo_list.size(); im1++)
				{
					AmoObject* p_amo = amo_list.at(im1);
					if (p_amo != NULL)
					{
						bool ret_col_f1 = SDLCommonFunc::CheckCollision(p_amo->GetRect(), p_fish1->GetRect());
						if (ret_col_f1)
						{
							//Score
							score_value += 2;
							//Sound
							Mix_PlayChannel(-1, g_sound_exp[0], 0);
							//Remove amo
							main_object.RemoveAmo(im1);

							//Reset fish1
							p_fish1->Reset(SCREEN_WIDTH);
						}
					}
				}
			}
		}

		//Imp Fish2
		for (int fi2 = 0; fi2 < NUM_FISH2; fi2++)
		{
			FishObject* p_fish2 = (p_fish2s + fi2);
			if (p_fish2)
			{
				p_fish2->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_fish2->Show(g_screen);

				//Check collision main_amo&fish2
				std::vector<AmoObject*>amo_list = main_object.GetAMoList();
				for (int im2 = 0; im2 < amo_list.size(); im2++)
				{
					AmoObject* p_amo = amo_list.at(im2);
					if (p_amo != NULL)
						{
						bool ret_col_f2 = SDLCommonFunc::CheckCollision(p_amo->GetRect(), p_fish2->GetRect());
						if (ret_col_f2)
						{
							//Score
							score_value += 3;
							//Sound
							Mix_PlayChannel(-1, g_sound_exp[0], 0);
							//Remove amo
							main_object.RemoveAmo(im2);

							//Reset fish2
							p_fish2->Reset(SCREEN_WIDTH);
                        }
					}
				}
			}
		}

		//Imp Bomb
		for (int bi = 0; bi < NUM_BOMB; bi++)
		{
			FishObject* p_bomb = (p_bombs + bi);
			if (p_bomb)
			{
				p_bomb->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_bomb->Show(g_screen);

				//Check collision main_amo&bomb
				std::vector<AmoObject*>amo_list = main_object.GetAMoList();
				for (int bm = 0; bm < amo_list.size(); bm++)
				{
					AmoObject* p_amo = amo_list.at(bm);
					if (p_amo != NULL)
					{
						bool ret_col_b = SDLCommonFunc::CheckCollision(p_amo->GetRect(), p_bomb->GetRect());
						if (ret_col_b)
						{
							//Sound
							Mix_PlayChannel(-1, g_sound_exp[1], 0);

							//Remove amo
							main_object.RemoveAmo(bm);

							//Bomb Explosion
							for (int ep = 0; ep < 4; ep++)
							{
								//Exp-pos
								int xb_pos = (p_bomb->GetRect().x + p_bomb->GetRect().w * 0.5) - EX_WIDTH * 0.5;
								int yb_pos = (p_bomb->GetRect().y + p_bomb->GetRect().h * 0.5) - EX_HEIGHT * 0.5;

								//Exp
								exp_bomb.set_frame(ep);
								exp_bomb.SetRect(xb_pos, yb_pos);
								exp_bomb.ShowEx(g_screen);

								if (SDL_Flip(g_screen) == -1)
								{
									delete[] p_bombs;
									SDLCommonFunc::CleanUp();
									SDL_Quit();
									return 0;
								}
							}

							//Reset bomb
							p_bomb->Reset(SCREEN_WIDTH + rand() % 600);

							die_number++;
							if (die_number <= 2)
							{
								//Score
								if (score_value < 5) score_value = 0;
								else score_value -= 5;

								//Decrease Player Power
								player_power.Decrease();
								player_power.Render(g_screen);

								if (SDL_Flip(g_screen) == -1)
								{
									delete[] p_bombs;
									SDLCommonFunc::CleanUp();
									SDL_Quit;
									return 0;
								}
							}
							else
							{
								//Show end
								int ret_end = SDLCommonFunc::ShowEnd(g_screen, g_font_end);

								//Quit
								if (ret_end == 0)
								{
									is_quit = true;
									delete[] p_fish1s;
									delete[] p_fish2s;
									delete[] p_bombs;
									SDLCommonFunc::CleanUp();
									SDL_Quit();
									return 0;
								}
								else
								{
									is_quit = false;
									SDL_FreeSurface(g_bkground);
									for (int if1 = 0; if1 < NUM_FISH1; if1++)
									{
										FishObject* p_fish1 = (p_fish1s + if1);
										p_fish1 = NULL;
									}

									for (int if2 = 0; if2 < NUM_FISH2; if2++)
									{
										FishObject* p_fish2 = (p_fish2s + if2);
										p_fish2 = NULL;
									}

									for (int ib = 0; ib < NUM_BOMB; ib++)
									{
										FishObject* p_bomb = (p_bombs + ib);
										p_bomb = NULL;
									} 
									goto again;
                                }
							}
						}
					}
				}
			}
		}

		//Update screen
		if (SDL_Flip(g_screen) == -1)
		{
			delete[] p_fish1s;
			delete[] p_fish2s;
			delete[] p_bombs;
			SDLCommonFunc::CleanUp();
			SDL_Quit();
			return 1;
		}
	}
	//Delete object
	delete[] p_fish1s;
	delete[] p_fish2s;
	delete[] p_bombs;

	//Quit
	SDLCommonFunc::CleanUp();
	SDL_Quit();
	return 1;
}