/*
** EPITECH PROJECT, 2018
** Network
** File description:
** Network
*/

#pragma once

#include <cstdint>

class NetworkGui {
public:
    NetworkGui() = default;

    void updateGui();
private:
    int connect();

    /*
     * Return size of an array as a compile-time constant
     * The array parameter has no name, because we care only about the number of elements it contains
     * Ref : (Effective Modern C++, Item 1)
     */
    template <typename T, size_t N>
    constexpr size_t arraySize(T (&)[N]) noexcept { return N; }

    int _serverSoket {-1};
    uint16_t _serverPort {4242};
    int _ipAddr[4] { 127, 0, 0, 1 };
};