// Socket.cpp

#include "Socket.hpp"

const int BACKLOG = 1024;

srv::Socket::Socket()
{
    // Create socket descriptor for server
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == 0) {
        std::cerr << "Fatal error: Can't create socket descriptor";
        exit(EXIT_FAILURE);
    }
};

void srv::Socket::bind(std::string ip_address, uint16_t port) {
    // Convervet address from presentation to network
    address.sin_family = AF_INET;
    address.sin_port = htons(8000);
    int result = inet_pton(AF_INET, ip_address.c_str(), &address.sin_addr);

    // int result = inet_pton(AF_INET, ip_address.c_str(), 
    //     &address.sin_addr.s_addr);

    if (result != 1) {
        std::cerr << "Invalid IP address\n";
        exit(EXIT_FAILURE);

    }
    addrlen = sizeof(address);
    int bind_ok = ::bind(
        serverfd, (struct sockaddr *)&address, addrlen);

    if (bind_ok < 0) {
        std::cerr<< "Error: Failed to bind address\n";
        exit(EXIT_FAILURE); // will modify to raise exception instead
    }

}

void srv::Socket::serve_and_listen() {
    if (::listen(serverfd, BACKLOG) < 0) {
        std::cerr << "Failed to listen\n";
        exit(EXIT_FAILURE); // will modify to raise exception instead
    }

    while (true) {
        std::cout << "Server started and listening...\n";
        sock = accept(
            serverfd,
            (struct sockaddr*)&address,
            (socklen_t*)&addrlen
        );

        if (sock < 0) {
            std::cerr<< "Error in accept\n";
            exit(EXIT_FAILURE);
        }
    }
    
    
}