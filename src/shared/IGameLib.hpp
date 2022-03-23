/*
** EPITECH PROJECT, 2022
** IGameLib.hpp
** File description:
** .
*/

#pragma once

#include "IGraphicsLib.hpp"

#define QUIT_SIGNAL 9001
#define SUCCESS_SIGNAL 0
#define ERROR_SIGNAL 84

class IGameLib {
    public:
        ~IGameLib() = default;

        virtual int frame() = 0;

        virtual void setGfx(IGraphicsLib **_gfx) = 0;

    protected:
        IGraphicsLib **_gfx;
};