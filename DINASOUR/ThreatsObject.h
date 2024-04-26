#ifndef THREATS_OBJECT_H_
#define THREATS_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"

#define THREAT_FRAME_NUM 5
class ThreatsObject : public BaseObject
{
public:
	ThreatsObject();
	~ThreatsObject();
	enum TypeMove
	{
		STATIC_THREAT = 0,
		MOVE_IN_SPACE_THREAT = 1,
	};
	void set_x_val(const int& xVal) { x_val_ = xVal; }
	void set_y_val(const int& yVal) { y_val_ = yVal; }
	void set_x_pos(const float& xp) { x_pos_ = xp; }
	void set_y_pos(const float& yp) { y_pos_ = yp; }
	float get_x_pos() const { return x_pos_; }
	float get_y_pos() const { return y_pos_; }
	void set_clip();
	bool LoadImg(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	int get_width_frame() const { return width_frame_; }
	int get_height_frame() const { return height_frame_; }
	SDL_Rect GetRectFrame();
	void moving(); 
	void moving_1();
	void moving_2();
private:
	float y_val_;
	float x_val_;
	float x_pos_;
	float y_pos_;
	bool on_ground_;
	SDL_Rect frame_clip_[THREAT_FRAME_NUM];
	int width_frame_;
	int height_frame_;
	int frame_;
	
	int type_move_;
	int animation_a_;
	int animation_b_;
	Input input_type_;

};
#endif
// Le Hoang Viet