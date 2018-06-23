/*
** EPITECH PROJECT, 2018
** Network
** File description:
** Network
*/

#include <poll.h>
#include <cstdio>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include "imgui.hpp"
#include "Network.hpp"

void NetworkGui::connect() noexcept
{
	uint32_t ip{0};
	struct sockaddr_in addr;
	socklen_t size = sizeof(struct sockaddr_in);

	if ((_serverSoket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		//Todo : Throw
		return;
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(_serverPort);
	for (auto it : _ipAddr) {
		ip <<= 8;
		ip += it;
	}
	addr.sin_addr.s_addr = htonl(ip);
	if ((::connect(_serverSoket, (struct sockaddr *) &addr, size)) == -1) {
		_serverSoket = -1;
		return;
	}
}

void NetworkGui::send(std::string &&msg) const noexcept
{
	dprintf(_serverSoket, "%s\n", msg.c_str());
}
 
void NetworkGui::receiveMsg() noexcept
{
	pollfd fds{_serverSoket, POLLIN, 100};
	poll(&fds, 1, 0);
	if (fds.revents & POLLIN && write_cbuf(&_buffer, _serverSoket) <= 0) {
		_evtMgr.emit<MsgEvent>("DISCONNECTED");
	}
	if (!_buffer.empty) {
		char *line = nullptr;
		while (read_cbuf(&_buffer, &line) /*&& line != nullptr */) {
				_evtMgr.emit<MsgEvent>(line);
			free(line);
		}
	}
}

void NetworkGui::updateGui() noexcept
{
	ImGuiWindowFlags window_flags = 0;
	static bool no_titlebar = false;
	static bool no_scrollbar = false;
	static bool no_menu = false;
	static bool no_move = false;
	static bool no_resize = false;
	static bool no_collapse = true;
	static bool no_nav = false;
	if (no_titlebar) window_flags |= ImGuiWindowFlags_NoTitleBar;
	if (no_scrollbar) window_flags |= ImGuiWindowFlags_NoScrollbar;
	if (!no_menu) window_flags |= ImGuiWindowFlags_MenuBar;
	if (no_move) window_flags |= ImGuiWindowFlags_NoMove;
	if (no_resize) window_flags |= ImGuiWindowFlags_NoResize;
	if (no_collapse) window_flags |= ImGuiWindowFlags_NoCollapse;
	if (no_nav) window_flags |= ImGuiWindowFlags_NoNav;
	if (!ImGui::Begin("Zappy NetWorkGui", nullptr, window_flags)) {
		ImGui::End();
		return;
	}
	if (ImGui::Button("Launch Server")) { /*launchServer();*/ };
	ImGui::Separator();
	ImGui::Text("Server ip :");
	ImGui::SameLine();
	ImGui::InputInt4("", _ipAddr);
	ImGui::SameLine();
	if (_serverSoket == -1 && ImGui::Button("Connect")) { connect(); };
	/*
	 * Todo: Console
	 */
	if (_serverSoket != -1)
		receiveMsg();
}

void NetworkGui::receive(const MsgEvent &msgEvent) noexcept
{
	std::cout << "COMMAND (" << msgEvent._command << ")" << std::endl;
	_networkProtocol.at(msgEvent._command)(msgEvent._params);
}
