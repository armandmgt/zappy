/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** MyEvents
*/

#pragma once

#include "EventManager.hpp"

class MsgEvent : public BaseEvent {
public:
    explicit MsgEvent(std::string &&msg) noexcept : _msg(std::move(msg)) {}
public:
    std::string _msg;
};