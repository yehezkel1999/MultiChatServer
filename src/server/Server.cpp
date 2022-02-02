
#include "Server.h"

Server::Server()
    : _socket() {}

int Server::run(const char *ip, int port, int queue) {
    // todo, listen on a different thread, accept commands on this thread.

    _socket.sbind(ip, port);
    _socket.slisten(queue);

    while (true) {
        sock::Socket client = _socket.saccept();
    }

    return 0;
}