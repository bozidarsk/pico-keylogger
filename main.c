// #include <stdio.h>
// #include "pico/stdlib.h"
// #include "wifi.h"
// #include "usb.h"

// int main() 
// {
// 	stdio_init_all();

// 	if (initialize_wifi("VIVACOM_FiberNet_9FAD", "cdtbmV8U8f", 20))
// 		return 1;

// 	if (initialize_tcp("192.168.1.100", 8000))
// 		return 1;

// 	initialize_usb();

// 	while (true) 
// 	{
// 		update_usb();
// 		printf("test\n");
// 		send_wifi("1234\n", 5);

// 		sleep_ms(100);
// 	}
// }
