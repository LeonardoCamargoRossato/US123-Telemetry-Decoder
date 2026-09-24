#ifndef UDP_RECEIVER_H
#define UDP_RECEIVER_H

#include <stddef.h>
#include <stdint.h>

int udp_receiver_init(uint16_t port);
int udp_receiver_read(char *buffer, size_t size);
void udp_receiver_close(void);

#endif
