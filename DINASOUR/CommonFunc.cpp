﻿#include "CommonFunc.h"
#include "TextObject.h"


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

    // Kiểm tra va chạm
    if (right_a <= left_b || left_a >= right_b || bottom_a <= top_b || top_a >= bottom_b)
    {
        
        return false;
    }

    return true;
}


// Le Hoang Viet

