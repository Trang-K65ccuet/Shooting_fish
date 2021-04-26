#include "Common_Function.h"
#include"TextObject.h"


int SDLCommonFunc::ShowMenu(SDL_Surface* des, TTF_Font* font)
{
    g_menu = LoadImage("image//menu.png");
    if (g_menu == NULL)
    {
        return 1;
    }

    //Num item
    const int num_item = 2;

    //Pos text menu
    SDL_Rect pos_arr[num_item];
    pos_arr[0].x = 75;
    pos_arr[0].y = 250;

    pos_arr[1].x = 85;
    pos_arr[1].y = 350;

    //Add width,height text
    SDL_Rect pos_add[num_item];
    pos_add[0].x = 230;
    pos_add[0].y = 55;

    pos_add[1].x = 190;
    pos_add[1].y = 55;

   //Add text
    TextObject text_menu[num_item];

    //Add text properties
    text_menu[0].SetText("PLAY");
    text_menu[0].SetColor(TextObject::BLACK_TEXT);
    text_menu[0].SetRect(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].SetText("EXIT");
    text_menu[1].SetColor(TextObject::BLACK_TEXT);
    text_menu[1].SetRect(pos_arr[1].x, pos_arr[1].y);

    //Init check selected
    bool selected[num_item] = { 0,0 };

    int xm ;//mouse-x
    int ym ;//mouse-y

    SDL_Event m_event;

    while (true)
    {
        SDLCommonFunc::ApplySurface(g_menu, des, 0, 0);
        for (int i = 0; i < num_item; ++i)
        {
            //Creat text on des
            text_menu[i].CreateGameText(font, des);
        }

        while (SDL_PollEvent(&m_event))
        {
            switch (m_event.type)
            {
            case SDL_QUIT:
                return 1;
            case SDL_MOUSEMOTION:
            {
                //Find mouse pos
                xm = m_event.motion.x;
                ym = m_event.motion.y;

                for (int i = 0; i < num_item; i++)
                {
                    //Check mouse pos~text pos
                    if (xm >= pos_arr[i].x && xm <= pos_arr[i].x + pos_add[i].x &&
                        ym >= pos_arr[i].y && ym <= pos_arr[i].y + pos_add[i].y)
                    {
                        if (selected[i] == false)
                        {
                            selected[i] = 1;
                            text_menu[i].SetColor(TextObject::RED_TEXT);
                        }
                    }
                    else
                    {
                        if (selected[i] == true)
                        {
                            selected[i] = 0;
                            text_menu[i].SetColor(TextObject::BLACK_TEXT);
                        }
                    }
                }
            }
            break;

            case SDL_MOUSEBUTTONDOWN:
            {
                xm = m_event.motion.x;
                ym = m_event.motion.y;
                for (int i = 0; i < num_item; i++)
                {
                    //Check mouse pos~text pos
                    if (xm >= pos_arr[i].x && xm <= pos_arr[i].x + pos_add[i].x &&
                        ym >= pos_arr[i].y && ym <= pos_arr[i].y + pos_add[i].y)
                    {
                        return i;
                    }
                }
            }
            break;
            case SDL_KEYDOWN:
            {
                if (m_event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return 1;
                }
            }
            break;
            default:
                break;
            }
            SDL_Flip(des);
        }
    }

    return 1;
}

int SDLCommonFunc::ShowEnd(SDL_Surface* des, TTF_Font* font)
{
    g_end = LoadImage("image//end.png");
    if (g_end == NULL)
    {
        return 1;
    }

    const int num_item = 2;

    //Pos text end
    SDL_Rect pos_arr_end[num_item];
    pos_arr_end[0].x = 320;
    pos_arr_end[0].y = 400;

    pos_arr_end[1].x = 540;
    pos_arr_end[1].y = 400;

    //Add width,height text
    SDL_Rect pos_add_end[num_item];
    pos_add_end[0].x = 110;
    pos_add_end[0].y = 33;

    pos_add_end[1].x = 315;
    pos_add_end[1].y = 33;

    bool selected[num_item] = { 0,0 };

    //Add text
    TextObject text_end[num_item];

    //Add text properties
    text_end[0].SetText("QUIT");
    text_end[0].SetColor(TextObject::BLACK_TEXT);
    text_end[0].SetRect(pos_arr_end[0].x, pos_arr_end[0].y);

    text_end[1].SetText("PLAY AGAIN");
    text_end[1].SetColor(TextObject::BLACK_TEXT);
    text_end[1].SetRect(pos_arr_end[1].x, pos_arr_end[1].y);

    int xe;//mouse-x
    int ye;//mouse-y

    SDL_Event e_event;

    while (true)
    {
        SDLCommonFunc::ApplySurface(g_end, des, 250, 125);

        for (int i = 0; i < num_item; ++i)
        {
            //Creat text on des
            text_end[i].CreateGameText(font, des);
        }

        while (SDL_PollEvent(&e_event))
        {
            switch (e_event.type)
            {
            case SDL_QUIT:
                return 0;
            case SDL_MOUSEMOTION:
            {
                //Find mouse pos
                xe = e_event.motion.x;
                ye = e_event.motion.y;

                //Check mouse pos~text pos
                for (int i = 0; i < num_item; i++)
                {
                    //Check mouse pos~text pos
                    if (xe >= pos_arr_end[i].x && xe <= pos_arr_end[i].x + pos_add_end[i].x &&
                        ye >= pos_arr_end[i].y && ye <= pos_arr_end[i].y + pos_add_end[i].y)
                    {
                        if (selected[i] == false)
                        {
                            selected[i] = 1;
                            text_end[i].SetColor(TextObject::WHITE_TEXT);
                        }
                    }
                    else
                    {
                        if (selected[i] == true)
                        {
                            selected[i] = 0;
                            text_end[i].SetColor(TextObject::BLACK_TEXT);
                        }
                    }
                }
            }
            break;

            case SDL_MOUSEBUTTONDOWN:
            {
                xe = e_event.motion.x;
                ye = e_event.motion.y;
                for (int i = 0; i < num_item; i++)
                {
                    //Check mouse pos~text pos
                    if (xe >= pos_arr_end[i].x && xe <= pos_arr_end[i].x + pos_add_end[i].x &&
                        ye >= pos_arr_end[i].y && ye <= pos_arr_end[i].y + pos_add_end[i].y)
                    {
                        return i;
                    }
                }
            }
            break;
            case SDL_KEYDOWN:
            {
                if (e_event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return 0;
                }
            }
            break;
            default:
                break;
            }
            SDL_Flip(des);
        }
    }
    return 0;
}

SDL_Surface* SDLCommonFunc::LoadImage(std::string file_path)
{
	SDL_Surface* load_image = NULL;
	SDL_Surface* optimize_image = NULL;

	load_image = IMG_Load(file_path.c_str());
	if (load_image != NULL)
	{
		optimize_image = SDL_DisplayFormat(load_image);
		SDL_FreeSurface(load_image);
		if (optimize_image != NULL)
		{
			UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0, 0);
			SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
		}
	}

	return optimize_image;
}

void SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, NULL, des, &offset);
}

void SDLCommonFunc::ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, clip, des, &offset);
}

bool SDLCommonFunc::CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
    int left_a = object1.x;
    int right_a = object1.x + object1.w;
    int top_a = object1.y;
    int bottom_a = object1.y + object1.h;

    int left_b = object2.x;
    int right_b = object2.x + object2.w;
    int top_b = object2.y;
    int bottom_b = object2.y + object2.h;

    // Case 1: size object 1 < size object 2
    if (left_a > left_b && left_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            return true;
        }
    }

    if (left_a > left_b && left_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            return true;
        }
    }

    if (right_a > left_b && right_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            return true;
        }
    }

    if (right_a > left_b && right_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            return true;
        }
    }

    // Case 2: size object 1 < size object 2
    if (left_b > left_a && left_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            return true;
        }
    }

    if (left_b > left_a && left_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            return true;
        }
    }

    if (right_b > left_a && right_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            return true;
        }
    }

    if (right_b > left_a && right_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            return true;
        }
    }

    // Case 3: size object 1 = size object 2
    if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
    {
        return true;
    }

    return false;
}

void SDLCommonFunc::CleanUp()
{
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_bkground);
}