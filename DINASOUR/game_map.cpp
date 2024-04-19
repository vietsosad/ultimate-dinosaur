#include "game_map.h"


void GameMap::LoadMap(std::string name) {
    std::ifstream file(name.c_str(), std::ios::binary);
    if (!file.is_open()) {
        std::cout << 0;
        return;
    }

    game_map_.max_x = 0;
    game_map_.max_y = 0;

        for (int j = 0; j < MAX_MAP_X; j++) {
    for (int i = 0; i < MAX_MAP_Y; i++) {
            int tile_value{1};
            file >> tile_value;
            game_map_.tile[i][j] = tile_value;
            if (tile_value > 0) {
                if (j > game_map_.max_x) {
                    game_map_.max_x = j;
                }
                if (i > game_map_.max_y) {
                    game_map_.max_y = i;
                }
            }
        }
    }

    game_map_.max_x = (game_map_.max_x + 1) * TILE_SIZE_;
    game_map_.max_y = (game_map_.max_y + 1) * TILE_SIZE_;
    game_map_.start_x = 0;
    game_map_.start_y = 0;
    game_map_.file_name = name;
    file.close();
}


void GameMap::LoadTiles(SDL_Renderer* screen)
{
    std::string file_img;

    for (int i = 0; i < MAX_TILES; i++)
    {
        file_img = "map/" + std::to_string(1) + ".png";

        //FILE* fp = fopen_s(file_img.c_str(), "rb");
        FILE* fp = NULL;
        errno_t no1 = fopen_s(&fp, file_img.c_str(), "rb");

        if (no1 != 0)
        {
            std::cout << "ERR(" << no1 << "): mo lan 1" << std::endl;
        }

        if (fp == NULL)
        {
            continue;
        }
        fclose(fp);

        tile_mat[i].LoadImg("map/one.png", screen);
    }
}
void GameMap::DrawMap(SDL_Renderer* screen)
{
    int x1 = 0;
    int x2 = 0;

    int y1 = 0;
    int y2 = 0;

    int map_x = 0;
    int map_y = 0;

    map_x = game_map_.start_x / TILE_SIZE_;

    x1 = (game_map_.start_x % TILE_SIZE_) * -1;
    x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE_);

    map_y = game_map_.start_y / TILE_SIZE_;

    y1 = (game_map_.start_y % TILE_SIZE_) * -1;
    y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE_);

    for (int i = y1; i < y2; i += TILE_SIZE_)
    {
        map_x = game_map_.start_x / TILE_SIZE_;
        for (int j = x1; j < x2; j += TILE_SIZE_)
        {
            int val = game_map_.tile[map_y][map_x];
            if (val > 0)
            {
                tile_mat[val].SetRect(j, i);
                tile_mat[val].Render(screen);
            }
            map_x++;
        }
        map_y++;
    }
}



