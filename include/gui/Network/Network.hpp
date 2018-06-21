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
#include "server/gui_magic.h"

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
    int _ipAddr[4] { 192, 168, 43, 35 };
    EventManager &_evtMgr;

    std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> _networkProtocol{
	    { "WELCOME", [this](std::vector<std::string> &&params[[maybe_unused]]) { send(GUI_NAME); send("msz"); } },
	    { "msz", [this](std::vector<std::string> &&params[[maybe_unused]]) { _evtMgr.emit<MapGeneration>(std::move(params)); send("mct"); } },
	    { "bct", [this](std::vector<std::string> &&params[[maybe_unused]]) { for (auto &it : params) { std::cout << it << " "; }; std::cout << std::endl; } }
    };
};
