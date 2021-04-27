#ifndef FISH_OBJECT_H_
#define FISH_OBJECT_H_
#include"Common_Function.h"
#include"BaseObject.h"

#define WIDTH_FISH1 68
#define HEIGHT_FISH1 81

#define WIDTH_FISH2 144
#define HEIGHT_FISH2 78

#define WIDTH_BOMB 50
#define HEIGHT_BOMB 51

class FishObject : public BaseObject
{
public:
	enum Fishtype
	{
		NONE = 0,
		FISH1 = 1,
		FISH2 = 2, 
		BOMB = 3,  
	};

	FishObject();
	~FishObject();

	void HandleMove(const int& x_border, const int& y_border);

	int get_type() const { return fish_type_; }
	void set_type(const int& type) { fish_type_ = type; }

	void set_x_val(const int val) { x_val_ = val; }
	void set_y_val(const int val) { y_val_ = val; }

	void SetWidthHeigh(const int& width, const int& height) { rect_.w = width; rect_.h = height; }

	void Reset(const int& xboder);


private:
	int x_val_;
	int y_val_;
	int fish_type_;

};

#endif
