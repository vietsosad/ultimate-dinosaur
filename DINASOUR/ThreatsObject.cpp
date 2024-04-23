#include "ThreatsObject.h"
ThreatsObject::ThreatsObject()
{
    width_frame_ = 0;
    height_frame_ = 0;
    x_val_ = 0.0;
    y_val_ = 0.0;
    x_pos_ = 0.0;
    y_pos_ = 0.0;
    on_ground_ = 0;
    frame_ = 0;
}

ThreatsObject::~ThreatsObject()
{

}
bool ThreatsObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadImg(path, screen);
    if (ret)
    {
        width_frame_ = rect_.w / THREAT_FRAME_NUM;
        height_frame_ = rect_.h;
    }
    return ret;
}

void ThreatsObject::set_clip()
{
    if (width_frame_ > 0 && height_frame_ > 0)
    {
        frame_clip_[0].x = 0;
        frame_clip_[0].y = 0;
        frame_clip_[0].w = width_frame_;
        frame_clip_[0].h = height_frame_;

        for (int i = 1; i < 5; i++) {
            frame_clip_[i].x = i * width_frame_;
            frame_clip_[i].y = 0;
            frame_clip_[i].w = width_frame_;
            frame_clip_[i].h = height_frame_;
        }
    }
}
void ThreatsObject::Show(SDL_Renderer* des)
{
    if (1)
    {
        frame_++;
        if (frame_ >= 5) {
            frame_ = 0;
        }
    }
    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect* current_clip = &frame_clip_[frame_];
    SDL_Rect renderQuad = { rect_.x, rect_.y, width_frame_, height_frame_ };

    SDL_RenderCopy(des, p_object_, current_clip, &renderQuad);
}
void ThreatsObject::moving()
{
    x_pos_ -= 15;
    if (x_pos_ < 0)
    {
        x_pos_ = 890;
        y_pos_ = rand() % 400;
    }
}
void ThreatsObject::moving_1()
{
    x_pos_ -= 10;
    if (x_pos_ < 0) { x_pos_ = 890 + rand() % 500; }
}
void ThreatsObject::moving_2()
{
    x_pos_ -= 25;
    if (x_pos_ < 0) { x_pos_ = 890 + rand() % 400 - 56, y_pos_ = rand() % 500 - 45; }
}
