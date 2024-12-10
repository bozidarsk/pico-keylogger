#ifndef WIFI_H
#define WIFI_H

int initialize_wifi(const char* ssid, const char* password, int timeout);
int initialize_tcp(const char* ip, int port);
void send_wifi(const void* data, uint16_t size);

#endif
