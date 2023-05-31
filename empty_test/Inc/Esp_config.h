/***************************/
/*Author : ahmed alaa	*/
/*date : 30/9/2020 		*/
/*version : v02			*/
/***************************/

#ifndef Esp_CONFIG_H
#define Esp_CONFIG_H

/*define recieving timout for each command that if it exceeded it means no more data*/
/*It varies depending on the router and server and also Clock freq, you'll need to try it*/
#define ECHO_TIMEOUT		100
#define MODE_TIMEOUT		150
#define ROUTER_TIMEOUT		4400000 //2.5*4=10 sec
#define SERVER_TIMEOUT		1100000
#define PREREQUEST_TIMEOUT	200
#define REQUEST_TIMEOUT		900000
#define TRANS_TIMEOUT		150


#endif
