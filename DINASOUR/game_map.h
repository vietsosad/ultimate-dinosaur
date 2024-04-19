#pragma once
#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "CommonFunc.h"
#include "BaseObject.h"

#define MAX_TILES 25

class TileMat : public BaseObject
{
public:
    TileMat() { ; }
    ~TileMat() { ; }
};

class GameMap
{
private:
    Map game_map_;
    TileMat tile_mat[MAX_TILES];
public:

    GameMap() { ; }

    ~GameMap() { ; }

    void LoadMap(std::string name);

    void LoadTiles(SDL_Renderer* screen);

    void DrawMap(SDL_Renderer* screen);

};
#endif

