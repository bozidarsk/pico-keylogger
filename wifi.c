#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "lwip/tcp.h"
#include "wifi.h"

static struct tcp_pcb* pcb;

int initialize_wifi(const char* ssid, const char* password, int timeout) 
{
	if (cyw43_arch_init()) 
	{
		printf("Failed to initialize wifi.\n");
		return 1;
	}

	cyw43_arch_enable_sta_mode();

	printf("Connecting to '%s'.\n", ssid);

	if (cyw43_arch_wifi_connect_timeout_ms(ssid, password, CYW43_AUTH_WPA2_AES_PSK, timeout * 1000)) 
	{
		printf("Failed to connect to '%s'.\n", ssid);
		return 1;
	}

	printf("Connected to '%s'.\n", ssid);
	return 0;
}

int initialize_tcp(const char* ip, int port) 
{
	pcb = tcp_new_ip_type(IPADDR_TYPE_V4);
	ip_addr_t address;

	if (!ipaddr_aton(ip, &address)) 
	{
		printf("Failed to parse ip address.\n");
		return 1;
	}

	cyw43_arch_lwip_begin();

	err_t error = tcp_connect(pcb, &address, port, NULL);
    if (error) 
    {
    	printf("Failed to connect to a tcp server. (%i)\n", error);
    	return 1;
    }

    cyw43_arch_lwip_end();

    return 0;
}

void send_wifi(const void* data, uint16_t size) 
{
	tcp_write(pcb, data, size, TCP_WRITE_FLAG_COPY);
}
