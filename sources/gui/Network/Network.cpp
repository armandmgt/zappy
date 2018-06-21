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

void NetworkGui::receiveMsg() noexcept
{
	if (_serverSoket != -1) {
		pollfd fds[] = {_serverSoket, POLLIN, 0};
		if (poll(fds, 1, 0) == 0)
			return;
		else if (fds[0].revents & POLLIN) {
			ssize_t nread;
			size_t len = 0;
			char *line = nullptr;
			static FILE *stream = fdopen(_serverSoket, "r");;

			nread = getline(&line, &len, stream);
			_evtMgr.emit<MsgEvent>((nread == -1) ? "DISCONNECTED" : line);
			free(line);
		}
	}
}

void NetworkGui::send(std::string &&msg) const noexcept
{
	dprintf(_serverSoket, msg.c_str());
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
	receiveMsg();
}

void NetworkGui::receive(const MsgEvent &msgEvent) noexcept
{
	std::cout << msgEvent._msg << std::endl;
}