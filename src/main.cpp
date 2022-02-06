
#include <iostream>
#include <climits>
#include <exception>
#include "server/Server.h"

int main(int argc, char **argv) {
    int port;
    int exit_status;

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
    
    Server server;
    try {
        exit_status = server.run("127.0.0.1", port, 5);
    } catch (sock::socket_error &e) {
        std::cerr << "A connection error has occured, info: " << e.what() << std::endl;
        return -1;
    } catch (std::exception &e) {
        std::cerr << "An unexpected error has occured, info: " << e.what() << std::endl;
        return -1;
    }

    std::cout << "The server exited with status code: " << exit_status << std::endl;
    return 0;
}