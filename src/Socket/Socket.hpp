// Socket.hpp

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace srv {
class Socket {

private:
    struct sockaddr_in address; // Address Structure
    int sock;
    int serverfd;
    size_t addrlen;

public:
    Socket ();

    void bind(std::string ip_address, uint16_t port);
    void serve_and_listen();
    void close();

};

}