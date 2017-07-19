/* udp_perf Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/


#ifndef __UDP_PERF_H__
#define __UDP_PERF_H__



#ifdef __cplusplus
extern "C" {
#endif


/*test options*/
#define EXAMPLE_ESP_WIFI_MODE_AP CONFIG_UDP_PERF_WIFI_MODE_AP //TRUE:AP FALSE:STA
#define EXAMPLE_ESP_UDP_MODE_SERVER CONFIG_UDP_PERF_SERVER //TRUE:server FALSE:client
#define EXAMPLE_ESP_UDP_PERF_TX CONFIG_UDP_PERF_TX //TRUE:send FALSE:receive
#define EXAMPLE_PACK_BYTE_IS 97 //'a'
/*AP info and tcp_server info*/
#define EXAMPLE_DEFAULT_SSID CONFIG_UDP_PERF_WIFI_SSID
#define EXAMPLE_DEFAULT_PWD CONFIG_UDP_PERF_WIFI_PASSWORD
#define EXAMPLE_DEFAULT_PORT 8800
#define EXAMPLE_DEFAULT_PKTSIZE CONFIG_UDP_PERF_PKT_SIZE
#define EXAMPLE_MAX_STA_CONN 1 //how many sta can be connected(AP mode)

#ifdef CONFIG_UDP_PERF_SERVER_IP
#define EXAMPLE_DEFAULT_SERVER_IP CONFIG_UDP_PERF_SERVER_IP
#else
#define EXAMPLE_DEFAULT_SERVER_IP "0.0.0.0"
#endif /*CONFIG_UDP_PERF_SERVER_IP*/


#define TAG "udp_perf:"

/* FreeRTOS event group to signal when we are connected to WiFi and ready to start UDP test*/
extern EventGroupHandle_t udp_event_group;
#define WIFI_CONNECTED_BIT BIT0
#define UDP_CONNCETED_SUCCESS BIT1

extern int total_data;
extern int success_pack;


//using esp as station
void wifi_init_sta();
//using esp as softap
void wifi_init_softap();

//create a udp server socket. return ESP_OK:success ESP_FAIL:error
esp_err_t create_udp_server();
esp_err_t del_udp_server();
void udp_conn(void *pvParameters);
//create a udp client socket. return ESP_OK:success ESP_FAIL:error

//send or recv data task
void recv_data(void *pvParameters);

//get socket error code. return: error code
int get_socket_error_code(int socket);

//show socket error code. return: error code
int show_socket_error_reason(int socket);

//check connected socket. return: error code
int check_connected_socket();

//close all socket
void close_socket();


extern void uart_task(void *pvParameters);

#ifdef __cplusplus
}
#endif


#endif /*#ifndef __UDP_PERF_H__*/

