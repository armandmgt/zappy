/*
** EPITECH PROJECT, 2018
** connexion
** File description:
** none
*/

#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int handle_client(int socket)
{
	pid_t pid;

	dprintf(socket, "WELCOME\n");
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0) {
		while (1) {
			dprintf(socket, "CLIENT-NUM\nX Y\n");
			return (0);
			/*gérer les messages*/
		}
	}
	return (0);
}

int server_connexion(int sock, struct sockaddr_in addr)
{
	struct sockaddr_in client;
	socklen_t s_in_size = sizeof(client);
	int socket;

	if (bind(sock, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
		return (-1);
	if (listen(sock, 1) == -1)
		return (-1);
	while (1) {
		socket = accept(sock, (struct sockaddr *)&client, &s_in_size);
		getsockname(socket, (struct sockaddr *)&client, &s_in_size);
		if (socket == -1 || handle_client(socket) == -1)
			return (-1);
		close(socket);
	}
	close(sock);
	return (0);
}

int init_server(char **av)
{
	struct protoent *proto = getprotobyname("TCP");
	struct sockaddr_in addr;
	int port = atoi(av[1]);
	int sock;

	if (!proto)
		return (-1);
	sock = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	if (sock == -1)
		return (-1);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	if (server_connexion(sock, addr) == -1)
		return (-1);
	return (0);
}