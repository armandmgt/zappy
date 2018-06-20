/*
** EPITECH PROJECT, 2018
** Network
** File description:
** Network
*/

#include "imgui.hpp"
#include "Network.hpp"
#include <sys/socket.h>
#include <netinet/in.h>

void NetworkGui::updateGui()
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
		return ;
	}
	if (ImGui::Button("Launch Server")) { /*launchServer();*/ }; ImGui::Separator();
	ImGui::Text("Server ip :"); ImGui::SameLine(); ImGui::InputInt4("", _ipAddr); ImGui::SameLine();
	if (_serverSoket == -1 && ImGui::Button("Connect")) { connect(); };
}

#include <cstdio>
#include <iostream>

int NetworkGui::connect()
{
	uint32_t ip {0};
	struct sockaddr_in addr;
	socklen_t size = sizeof(struct sockaddr_in);

	if ((_serverSoket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		return -1;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(_serverPort);
	for (auto it : _ipAddr) {
		ip <<= 8;
		ip += it;
	}
	addr.sin_addr.s_addr = htonl(ip);
	if ((::connect(_serverSoket, (struct sockaddr *)&addr, size)) == -1)
		return -1;
//	FILE *stream;
//	char *line = NULL;
//	size_t len = 0;
//	ssize_t nread;
//	stream = fdopen(_serverSoket, "r");
//	while ((nread = getline(&line, &len, stream)) != -1) {
//		printf("Retrieved line of length %zu:\n", nread);
//		fwrite(line, nread, 1, stdout);
//	}
//	//free(line);
//	fclose(stream);
	return 0;
}
