#include "../Server/Server.hpp"

void Server::Pass(std::string pass, int id)
{
    clients[id].setPass(pass);
    std::cout << "clients vectorune ait "<< id << ". indexteki, soket numarasi "<< clients[id].getSocket() << " olan clientin şifresi " << pass << " olarak set." << std::endl;
}