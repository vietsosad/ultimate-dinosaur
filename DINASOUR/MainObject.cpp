
#include "MainObject.h"

MainObject::MainObject()
{
    frame_ = 0;
    x_pos_ = 10;
    y_pos_ = 410.5;
    x_val_ = 0;
    y_val_ = 0;
    width_frame_ = 0;
    height_frame_ = 0;
    status_ = -1;
    input_type_.left_ = 0;
    input_type_.right_ = 0;
   
    input_type_.down_ = 0;
    status_ = WALK_RIGHT;

}

MainObject::~MainObject() {}

bool MainObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadImg(path, screen);

    if (ret == true)
    {
        width_frame_ = rect_.w/6;
        height_frame_ = rect_.h;
    }

    return ret;
}

void MainObject::set_clip()
{
    if (width_frame_ > 0 && height_frame_ > 0)
    {
        frame_clip_[0].x = 0;
        frame_clip_[0].y = 0;
        frame_clip_[0].w = width_frame_;
        frame_clip_[0].h = height_frame_;

        for (int i = 1; i < 6; i++) {
            frame_clip_[i].x = i*width_frame_;
            frame_clip_[i].y = 0;
            frame_clip_[i].w = width_frame_;
            frame_clip_[i].h = height_frame_;
        }
         
    }
}
void MainObject::Show(SDL_Renderer* des)
{
    if (status_ == WALK_LEFT) {
        LoadImg("imgs/character/dinasour_l.png", des);

    }
    else {
        LoadImg("imgs/character/dinasour_r.png", des);
    }
    if (1)
    {
        frame_++;
    }
    else
    {
        frame_ = 0;
    }
    if (frame_ >= 6) {
        frame_ = 0;
    }
    
    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect* current_clip = &frame_clip_[frame_];
    SDL_Rect renderQuad = { rect_.x, rect_.y, width_frame_, height_frame_ };

    SDL_RenderCopy(des, p_object_, current_clip, &renderQuad);
}

void MainObject::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
{
    /*input_type_.jump_--;
    if(input_type_.jump_ == 0) y_pos_ = 410.5;*/
    if (events.type == SDL_KEYDOWN)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_RIGHT:
        {
            status_ = WALK_RIGHT;
            input_type_.left_ = 1;
            input_type_.right_ = 0;
            x_pos_ += width_frame_ / 8;
            
         
        }
        break;
        case SDLK_LEFT:
        {
            status_ = WALK_LEFT;
            input_type_.left_ = 1;
            input_type_.right_ = 0;
            x_pos_ -= width_frame_ / 4;
            
        }
        break;
        case SDLK_SPACE:
        {
            input_type_.jump_ = 100;
            if (input_type_.jump_ > 0) 
            {
                y_pos_ += -18.5;
                --input_type_.jump_;
            }
        }
        break;
        default :
            break;
        }
    }
   
    std::cout << y_pos_ << "\n";
}
void MainObject::Handlemove() {
    if(y_pos_ < 410.5) y_pos_ += 8;
    rect_.y = 410.5;
    rect_.x += x_pos_;
    if (rect_.x < 0||rect_.x+ width_frame_>SCREEN_WIDTH) {
        rect_.x -= x_pos_;
    }
    rect_.y += y_pos_;
}
