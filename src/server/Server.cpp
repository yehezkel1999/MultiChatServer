
#include "Server.h"
#include <iostream>

Server::Server()
    : _socket() {}

int Server::run(const char *ip, int port, int queue) {
    // todo, listen on a different thread, accept commands on this thread.

    std::cout << "Binding server to host: " << ip << ", listenning on port " << port << std::endl;
    _socket.sbind(ip, port);
    _socket.slisten(queue);
    std::cout << "Done." << std::endl;

    while (true) {
        sock::Socket client = _socket.saccept();
        std::cout << "A new client has entered the chat, info: " << client << std::endl;
    }

    return 0;
}