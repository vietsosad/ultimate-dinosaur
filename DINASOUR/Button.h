#ifndef BUTTON_H
#define BUTTON_H

#include"CommonFunc.h"
#include"LTexture.h"

class Button
{
public:
    Button(int x, int y, int w, int h);
    ~Button();

    void hanldEvent(SDL_Event e);
    bool loadButtonTexture(std::string path, SDL_Renderer* screen);
    void render(SDL_Renderer* screen);
    void free();
    bool checkCollision(int mx, int my);
    int getPressed();
    void set_clip(int x, int y, int w, int h);


private:
    LTexture buttonTexture;
    SDL_Rect box;
    enum mouse_state
    {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        MOUSE_DOWN = 2
    };
    int mouseSate;
    bool release;
    int pressed;
    SDL_Rect clip;

};


#endif // BUTTON_H
// Le Hoang Viet