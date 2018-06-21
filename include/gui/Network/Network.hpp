/*
** EPITECH PROJECT, 2018
** Network
** File description:
** Network
*/

#pragma once

#include <string>
#include <unordered_map>
#include "MyEvents.hpp"

class NetworkGui : public Receiver {
public:
    explicit NetworkGui(EventManager &evtMgr) noexcept : _evtMgr(evtMgr) { evtMgr.subscribe<MsgEvent>(*this); }
    ~NetworkGui() noexcept { _evtMgr.unsubscribe<MsgEvent>(*this); }

    void updateGui() noexcept;
public:
    /*
     * Events Callbacks
     */
    void receive(const MsgEvent &msgEvent) noexcept;
private:
    void connect() noexcept;
    void receiveMsg() noexcept;
    void send(std::string &&msg) const noexcept ;

    int _serverSoket { -1 };
    uint16_t _serverPort { 4242 };
    int _ipAddr[4] { 127, 0, 0, 1 };
    EventManager &_evtMgr;
};