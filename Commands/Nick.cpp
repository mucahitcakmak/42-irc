#include "../Server/Server.hpp"

void Server::Nick(std::string nickname, int id)
{
    clients[id].setNickName(nickname);
    std::cout << "clients vectorune ait "<< id << ". indexteki, soket numarasi "<< clients[id].getSocket() << " olan clientin nickname'i " << nickname << " olarak set." << std::endl;
}