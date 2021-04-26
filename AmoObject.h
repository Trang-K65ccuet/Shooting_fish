#ifndef AMO_OBJECT_H_
#define AMO_OBJECT_H_

#include"BaseObject.h"

#define WIDTH_AMO_OBJECT 20
#define HEIGHT_AMO_OBJECT 19

class AmoObject:public BaseObject
{
public:
	AmoObject();
	~AmoObject();

	void HandleMove(const int& x_border, const int& y_border);

	bool get_is_move() const { return is_move_; }
	void set_is_move(bool is_move) { is_move_ = is_move; }

	void set_x_val(const int& val) { x_val_ = val; }
	void set_y_val(const int& val) { y_val_ = val; }

	int get_x_val() const { return x_val_; }
	int get_y_val() const { return y_val_; }

private:
	int x_val_;
	int y_val_;
	bool is_move_;
};

#endif
