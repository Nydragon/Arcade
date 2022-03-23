/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "Arcade.hpp"

Error::Arcade::Arcade(const std::string &message)
{
    this->_message = message;
}

const char *Error::Arcade::what() const noexcept
{
    return this->_message.c_str();
}

Error::FileNotFound::FileNotFound(const std::string &filePath)
    : Arcade("File not found: " + filePath)
{
}
