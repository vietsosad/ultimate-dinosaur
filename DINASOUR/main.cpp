
#include "CommonFunc.h"
#include "BaseObject.h"
#include "MainObject.h"

BaseObject g_background;
BaseObject g_character;
BaseObject g_font;
BaseObject g_grass;
bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)
        return false;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    g_window = SDL_CreateWindow("ULTIMATE_DINASOUR",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    if (g_window == NULL)
    {
        success = false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
            success = false;
        else
        {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags))
                success = false;
        }
    }
    return success;
}
bool LoadBackground() {
    bool ret = g_background.LoadImg("imgs/background/map.png", g_screen);
  
    if (ret == false) {
        std::cerr << "False to load map !!!";
        return false;
    }
    return true;
}
void close()
{
    g_background.Free();

    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_QUIT;
}

int main(int argc, char* argv[])
{
    SDL_Rect des{ 0,0, 890,500 };
    if (InitData() == false)
        return -1;

    if (LoadBackground() == false)
        return -1;
    MainObject p_player;
    p_player.LoadImg("imgs/character/dinasour_r.png", g_screen);
    p_player.set_clip();
    

    bool is_quit = false;
    while (!is_quit)
    {
        while (SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;
            }
           
            p_player.HandleInputAction(g_event, g_screen);
           
        }
        des.x -= 10;
        if (des.x <= 0) des.x = 890;
        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);
        g_background.SetRect(des.x - 890,des.y);
        g_background.Render(g_screen, NULL);
        g_background.SetRect(des.x, des.y);
        g_background.Render(g_screen, NULL);
        p_player.Show(g_screen);
        p_player.Handlemove();
        SDL_RenderPresent(g_screen);
        SDL_Delay(60);
    }
    close();
    return 0;
}


