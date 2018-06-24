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
extern "C" {
	#include "cir_buffer.h"
}
#include "server/gui_magic.h"

class NetworkGui : public Receiver {
public:
    explicit NetworkGui(EventManager &evtMgr) noexcept : _evtMgr(evtMgr) { evtMgr.subscribe<MsgEvent>(*this); init_cbuf(&_buffer); }

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
    /*
     * Caca / 20
     */
    cir_buffer_t _buffer;

    int _serverSoket { -1 };
    uint16_t _serverPort { 4242 };
    int _ipAddr[4] { 127, 0, 0, 1 };

    EventManager &_evtMgr;
    std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> _networkProtocol{
	    { "WELCOME", [this](std::vector<std::string> &&params[[maybe_unused]]) { send(GUI_NAME); send("msz"); } },
	    { "msz", [this](std::vector<std::string> &&params[[maybe_unused]]) { _evtMgr.emit<MapDims>(std::move(params)); send("mct"); } }, //Map Size
	    { "bct", [this](std::vector<std::string> &&params[[maybe_unused]]) { _evtMgr.emit<FillCellInventory>(std::move(params)); } }, //Content of a Tile
	    { "pnw", [this](std::vector<std::string> &&params[[maybe_unused]]) { _evtMgr.emit<NewPlayer>(std::move(params)); send("mct"); } }, //Connection of a new Player && update Map Tiles
	    { "pdi", [this](std::vector<std::string> &&params[[maybe_unused]]) { _evtMgr.emit<PlayerDeath>(std::move(params)); } }, //Player Death
	    { "pdr", [this](std::vector<std::string> &&params[[maybe_unused]]) { _evtMgr.emit<ResourceDropping>(std::move(params)); } }, //Resource Dropping
	    { "pgt", [this](std::vector<std::string> &&params[[maybe_unused]]) { _evtMgr.emit<ResourceCollecting>(std::move(params)); } } //Resource Collecting
    };
};
