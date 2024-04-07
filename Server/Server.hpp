#pragma once

#include "../Channel/Channel.hpp"
#include "../Client/Client.hpp"
#include <vector>
#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <fstream>
#include <ctime>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sstream>

# define SOCKET_ERROR -1
# define PASS "PASS"
# define JOIN "JOIN"
# define USER "USER"
# define NICK "NICK"

class Server
{
    private:
	    struct sockaddr_in			server_address;
		typedef void(Server::*fpoint)(std::string, int);
        std::vector<Channel>		channels;
        std::vector<Client>			clients;
        std::vector<std::string>	commands;
		std::vector<int>			connected_clients;

		int							sockfd;
		int							acceptFd;
		int 						port;
		std::string					serverIp;
		std::string					pass;
		fd_set 						readfds;

    public:
		Server(int port, std::string arg_pass);
		std::vector<Channel> 		getChannels();
		std::vector<std::string>	getCommands();
		std::vector<Client> 		getClients();

		void						executeCommand(int clientsockt);
		void						User(std::string username, int id);
		void						Pass(std::string pass, int id);
		void						Nick(std::string nickname, int id);

		int							getServerFd();
		int							getAcceptFd();
		int							getPort();
		void						initilizeServer();
		int 						perr(std::string err, int sockfd);
		void						checkCommands(Server &server, std::string buffer, int socket);
		~Server();
};