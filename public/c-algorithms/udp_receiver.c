#include "udp_receiver.h"

#ifdef _WIN32
#include <winsock2.h>

static SOCKET socket_handle = INVALID_SOCKET;

int udp_receiver_init(uint16_t port) {
    WSADATA winsock_data;
    struct sockaddr_in address;

    if (WSAStartup(MAKEWORD(2, 2), &winsock_data))
        return -1;

    socket_handle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socket_handle == INVALID_SOCKET)
        return -2;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    address.sin_port = htons(port);

    return bind(
        socket_handle,
        (struct sockaddr *)&address,
        sizeof(address)
    ) == SOCKET_ERROR ? -3 : 0;
}

int udp_receiver_read(char *buffer, size_t size) {
    int received = recv(socket_handle, buffer, (int)size - 1, 0);
    if (received > 0)
        buffer[received] = '\0';
    return received;
}

void udp_receiver_close(void) {
    if (socket_handle != INVALID_SOCKET)
        closesocket(socket_handle);
    WSACleanup();
}

#else

int udp_receiver_init(uint16_t port) {
    (void)port;
    return -1;
}

int udp_receiver_read(char *buffer, size_t size) {
    (void)buffer;
    (void)size;
    return -1;
}

void udp_receiver_close(void) {}

#endif
