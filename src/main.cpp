// main.cpp

#include <iostream>

#include "Socket/Socket.hpp"

int main () {
    srv::Socket socketServer = srv::Socket();
    socketServer.bind("127.0.0.1", 8000);
    socketServer.serve_and_listen();

    return 0;

}