#include "../Server/Server.hpp"

void Server::User(std::string username, int id)
{
    clients[id].setUserName(username);
    std::cout << "clients vectorune ait "<< id << ". indexteki, soket numarasi "<< clients[id].getSocket() << " olan clientin Username'i " << username << " olarak set." << std::endl;
}