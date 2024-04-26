
#include "CommonFunc.h"
#include "BaseObject.h"
#include "MainObject.h"
#include "ThreatsObject.h"
#include "TextObject.h"
#include "Menu.h"
#include "Button.h"

BaseObject g_background;
TTF_Font* font_scores=NULL;

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
        if (TTF_Init() == -1)
        {
            success = false;
        }
        font_scores = TTF_OpenFont("font/pixel_font_.ttf",20);
        if (font_scores == NULL)
        {
            success = false;
        }
    }
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        return false;
    }
    g_sound_jump = Mix_LoadWAV("Sounds/Jump.wav");
    g_sound_background = Mix_LoadWAV("Sounds/Sound_Game.wav");
    g_sound_touching = Mix_LoadWAV("Sounds/Lose.wav");
    g_sound_click = Mix_LoadWAV("Sounds/Click_Mouse.wav");
    if (g_sound_jump == NULL || g_sound_background == NULL || g_sound_touching == NULL||g_sound_click == NULL)
    {
        std::cout << "can not open music!!";
        return false;
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

std::vector<ThreatsObject*> MakeThreatList()
{
    std::vector<ThreatsObject*> list_threats;
    ThreatsObject* threats_objs = new ThreatsObject[5];
    for (int i = 0; i < 5; i++)
    {
        ThreatsObject* p_threat = (threats_objs + i);
        ThreatsObject* p_threat_1 = (threats_objs + i);
        if (p_threat != NULL)
        {
            p_threat->LoadImg("imgs/enemy/bat.png", g_screen);
            p_threat->set_clip();
            p_threat->set_x_pos(rand() % 890 + 275.5 * i);
            p_threat->set_y_pos(rand() % 410 - 45); 
            list_threats.push_back(p_threat);
        }
    }

    return list_threats;
}

std::vector<ThreatsObject*> MakeThreatList_1()
{
    std::vector<ThreatsObject*> list_threats_1;
    ThreatsObject* threats_objs = new ThreatsObject[5];
    for (int i = 0; i < 5; i++)
    {
        ThreatsObject* p_threat = (threats_objs + i);
     
        if (p_threat != NULL)
        {
            p_threat->LoadImg("imgs/enemy/cactus.png", g_screen);
            p_threat->set_clip();
            p_threat->set_x_pos(890-100*i + rand() %  350);
            p_threat->set_y_pos(410.5-rand()%5);
            list_threats_1.push_back(p_threat);
        }
    }

    return list_threats_1;
}

std::vector<ThreatsObject*> MakeThreatList_2()
{
    std::vector<ThreatsObject*> list_threats_2;
    ThreatsObject* threats_objs = new ThreatsObject[2];
    for (int i = 0; i < 2; i++)
    {
        ThreatsObject* p_threat = (threats_objs + i);

        if (p_threat != NULL)
        {
            p_threat->LoadImg("imgs/enemy/rocket_.png", g_screen);
            p_threat->set_clip();
            p_threat->set_x_pos(rand()%890);
            p_threat->set_y_pos(rand()%400+35);
            list_threats_2.push_back(p_threat);
        }
    }

    return list_threats_2;
}

int main(int argc, char* argv[])
{
    SDL_Rect des{ 0,0, 890,500 };

    if (InitData() == false)
        return -1;

    if (LoadBackground() == false)
        return -1;

    //Make MainObject
    MainObject p_player;
    p_player.LoadImg("imgs/character/dinasour_r.png", g_screen);
    p_player.set_clip();

    Menu* menu = new Menu;
    if (menu->loadMenuTexture("imgs/background/menu.png", g_screen) == false)
    {
        std::cerr << "unable to load menu's background" << std::endl;
    }

    bool gameState = 0;

    
    //Make ThreatsObject
 
    std::vector<ThreatsObject*> threat_list = MakeThreatList();
    std::vector<ThreatsObject*> threat_list_1 = MakeThreatList_1();
    std::vector<ThreatsObject*> threat_list_2 = MakeThreatList_2();

    //Time text
    TextObject time_scores;
    time_scores.SetColor(TextObject::WHITE_TEXT);

    Mix_PlayChannel(-1, g_sound_background, 0);

    bool is_quit = false;
    while (!is_quit)
    {
        if (gameState == 0)
        {
            while (SDL_PollEvent(&g_event))
            {
                if (g_event.type == SDL_QUIT)
                {
                    is_quit = true;
                }
                else
                {
                    menu->handleEvent(g_event);
                    if (menu->enter->getPressed() == 2)
                    {
                        Mix_PlayChannel(-1, g_sound_click, 0);
                        gameState = 1;
                    }
                    if (menu->quit->getPressed() == 2)
                    {
                        Mix_PlayChannel(-1, g_sound_click, 0);
                        is_quit = false;
                        SDL_Delay(1000);
                        return 0;
                    }
  
                }
                SDL_SetRenderDrawColor(g_screen, 0, 0, 0, RENDER_DRAW_COLOR);
                SDL_RenderClear(g_screen);
                menu->render(g_screen);
                SDL_RenderPresent(g_screen);
            }
        }
        else
        {
            while (SDL_PollEvent(&g_event) != 0)
            {
                if (g_event.type == SDL_QUIT)
                {
                    is_quit = true;
                }

                p_player.HandleInputAction(g_event, g_screen, g_sound_jump);

            }
            des.x -= 10;
            if (des.x <= 0) des.x = 890;
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            SDL_RenderClear(g_screen);
            g_background.SetRect(des.x - 890, des.y);
            g_background.Render(g_screen, NULL);
            g_background.SetRect(des.x, des.y);
            g_background.Render(g_screen, NULL);
            p_player.Show(g_screen);
            p_player.Handlemove();
            SDL_Rect rect_player = p_player.GetRectFrame();
            // khởi tạo con rơi
            for (int i = 0; i < threat_list.size(); i++) {
                ThreatsObject* p_threat = threat_list.at(i);
                if (p_threat != NULL)
                {
                    p_threat->moving();
                    p_threat->Show(g_screen);
                    SDL_Rect rect_threat = p_threat->GetRectFrame();
                    bool bCol1 = SDLCommonFunc::CheckCollision(rect_player, rect_threat);
                    if (bCol1)
                    {
                        Mix_HaltMusic();
                        Mix_PlayChannel(-1, g_sound_touching, 0);
                        if (MessageBox(NULL, L"GAME OVER!!", L"Info", MB_OK | MB_ICONSTOP) == IDOK)
                        {
                            p_threat->Free();
                            close();
                            SDL_Quit;
                            return 0;
                        }
                    }
                }
            }
            // khởi tạo xương rồng
            for (int i = 0; i < threat_list_1.size(); i++) {
                ThreatsObject* p_threat_1 = threat_list_1.at(i);
                if (p_threat_1 != NULL)
                {
                    p_threat_1->moving_1();
                    p_threat_1->Show(g_screen);
                    SDL_Rect rect_threat_1 = p_threat_1->GetRectFrame();
                    bool bCol1 = SDLCommonFunc::CheckCollision(rect_player, rect_threat_1);
                    if (bCol1)
                    {
                        Mix_HaltMusic();
                        Mix_PlayChannel(-1, g_sound_touching, 0);
                        if (MessageBox(NULL, L"GAME OVER!!", L"Info", MB_OK | MB_ICONSTOP) == IDOK)
                        {
                            p_threat_1->Free();
                            close();
                            SDL_Quit;
                            return 0;
                        }
                    }

                }
            }
            // khởi tạo tên lửa
            for (int i = 0; i < threat_list_2.size(); i++) {
                ThreatsObject* p_threat_2 = threat_list_2.at(i);
                if (p_threat_2 != NULL)
                {
                    p_threat_2->moving_2();
                    p_threat_2->Show(g_screen);
                    SDL_Rect rect_threat_2 = p_threat_2->GetRectFrame();
                    bool bCol1 = SDLCommonFunc::CheckCollision(rect_player, rect_threat_2);
                    if (bCol1)
                    {
                        Mix_HaltMusic();
                        Mix_PlayChannel(-1, g_sound_touching, 0);
                        if (MessageBox(NULL, L"GAME OVER!!", L"Info", MB_OK | MB_ICONSTOP) == IDOK)
                        {
                            p_threat_2->Free();
                            close();
                            SDL_Quit;
                            return 0;
                        }
                    }
                }
            }
            // show game scores
            std::string str_scores = "Scores: ";
            Uint32 scores = SDL_GetTicks() / 100;
            Uint32 val_scores = scores++;
            std::string str_val = std::to_string(val_scores);
            str_scores += str_val;
            time_scores.SetText(str_scores);
            time_scores.LoadFromRenderText(font_scores, g_screen);
            time_scores.RenderText(g_screen, SCREEN_WIDTH - 135, 20);
            SDL_RenderPresent(g_screen);
            SDL_Delay(60);
            //Run Threat

        }
    }
    close();
    for (auto p_threat : threat_list) {
        delete p_threat;
    }
    for (auto p_threat_1 : threat_list_1) {
        delete p_threat_1;
    }
    for (auto p_threat_2 : threat_list_2) {
        delete p_threat_2;
    }
    return 0;
}

// Le Hoang Viet

