/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "chrono"
#include "../Terrain.hpp"
#include "../Astar.hpp"
#include "../../include/PacmanMacros.hpp"
#include "../Player.hpp"
#include <utility>

namespace Pacman
{
    enum GhostState
    {
        HUNTING = 0,
        HUNTED = 1,
        DEFEATED = 2,
        RECOVERING = 3,
        SLEEPING = 4
    };

    typedef struct
    {
        int right;
        int left;
        int backfacing;
        int frontfacing;
    } directions_t;

    class BaseGhost
    {
        public:
            BaseGhost(Terrain *_scene, IGraphicsLib **_gfx, Player *pacman);

            void setState(GhostState state);

            void masterMove(size_t x, size_t y);

            virtual void move(size_t x, size_t y);

            void draw();

            int getID() const;

            std::pair<size_t, size_t> getLocation();

        protected:
            GhostState _state;

            int _id;

            int _movementTile = BLINKY_GHOST_FRONTFACING;

            int _initialSleepSeconds = 10;

            directions_t _movementTiles = {
                PINKY_GHOST_RIGHT,
                PINKY_GHOST_LEFT,
                PINKY_GHOST_BACKFACING,
                PINKY_GHOST_BACKFACING
            };

            std::chrono::time_point<std::chrono::system_clock> stateChangeTimer{};

            std::deque<coordinates_t> _path;

            size_t _x;

            size_t _y;

            Terrain *_scene;

            IGraphicsLib **_gfx;

            Player *_pacman;
    };
}
