/*
** EPITECH PROJECT, 2018
** Network
** File description:
** Network
*/

#pragma once

#include <string>

class NetworkGui {
public:
    NetworkGui() = default;

    void updateGui();
private:
    int connect();
    std::string receive();
    void send(std::string &&msg);

    int _serverSoket { -1 };
    uint16_t _serverPort { 4242 };
    int _ipAddr[4] { 127, 0, 0, 1 };
};