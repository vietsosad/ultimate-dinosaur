#pragma once
#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H

#include "CommonFunc.h"
#include "BaseObject.h"
#define PLAYER_JUMP 20
class MainObject : public BaseObject
{
private:
    float x_val_;
    float y_val_;

    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[6];
    Input input_type_;
    int frame_;
    int status_;

public:
    MainObject();
    ~MainObject();
    enum WalkType
    {
        WALK_RIGHT = 0,
        WALK_LEFT = 1,
        JUMP 
    };
    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);

    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void Handlemove();
    void set_clip();

};



#endif