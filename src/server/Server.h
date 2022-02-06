
#include "../../../socket/src/Socket.h"

class Server {
public: // usings


private: // private methods

public: // public methods
    Server();
    ~Server() {}

    int run(const char *ip, int port, int queue);

private: // class members
    sock::Socket _socket;
};