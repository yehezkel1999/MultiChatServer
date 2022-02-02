
#include <iostream>
#include <climits>
#include "server/Server.h"

int main(int argc, char **argv) {
    int port;

    std::cout << '\n';

    // TODO add optianal arg, listening queue size, default 5

    if (argc == 1) {
        std::cerr << "too few arguments given, please call with the port you want to listen on." << std::endl;
        return -1;
    } else if (argc > 2) {
        std::cerr << "too many arguments given, please call with the port you want to listen on." << std::endl;
        return -1;
    }
    port = std::atoi(argv[1]);
    if (port < 0 || port > USHRT_MAX) {
        std::cerr << "port exceeds maximum possible values" << std::endl;
        return -1;
    }
    std::cout << "Server starting, listenning on port " << port;

    Server server;
    int exit_status = server.run("127.0.0.1", port, 5);

    std::cout << "The server exited with status code: " << exit_status << std::endl;
    return 0;
}