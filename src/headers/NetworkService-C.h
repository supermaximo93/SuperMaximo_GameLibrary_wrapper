/*
 * NetworkService-C.h
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#ifndef NETWORKSERVICEC_H_
#define NETWORKSERVICEC_H_

#define STR_BUFFER_SIZE 128
#define STR_SIZE 32
#define INT_SIZE 8
#define WAIT_TIME 10

#ifdef __cplusplus

class NetworkService;
extern "C" {

#else

#include <stdint.h>
typedef struct NetworkService NetworkService;

#endif

int initNetworking();
void quitNetworking();

NetworkService * networkServiceNew(const char * newName);
void networkServiceDelete(NetworkService * networkService);

const char * networkServiceName(NetworkService * networkService);

int networkServiceServerStarted(NetworkService * networkService);
int networkServiceClientStarted(NetworkService * networkService);

int networkServiceStartServer(NetworkService * networkService, int newMaxSockets, int newPort);
void networkServiceCloseServer(NetworkService * networkService);
int networkServiceRestartServer(NetworkService * networkService);
uint32_t networkServiceNewLocalAddress(NetworkService * networkService);
uint32_t networkServiceLocalAddress(NetworkService * networkService);
int networkServiceCheckForNewClient(NetworkService * networkService, int useUdp);
int networkServiceClientExists(NetworkService * networkService, int id);
int networkServiceTotalClients(NetworkService * networkService);
void networkServiceKickClient(NetworkService * networkService, int id);

int networkServiceStartClient(NetworkService * networkService, const char * newAddress, int newPort);
void networkServiceCloseClient(NetworkService * networkService);
int networkServiceRestartClient(NetworkService * networkService);
int networkServiceConnectToServer(NetworkService * networkService, int useUdp);
int networkServiceClientNumber(NetworkService * networkService);

int networkServiceSendStrTcp(NetworkService * networkService, const char * data, int id, int isServer, int size);
const char * networkServiceRecvStrTcp(NetworkService * networkService, int id, int isServer, int size);
int networkServiceSendIntTcp(NetworkService * networkService, int data, int id, int isServer);
int networkServiceRecvIntTcp(NetworkService * networkService, int id, int isServer);

int networkServiceSendStrUdp(NetworkService * networkService, const char * data, int id, int isServer);
const char * networkServiceRecvStrUdp(NetworkService * networkService, int isServer);
const char * networkServiceRecvStrUdpStr(NetworkService * networkService, int * idBuffer, int isServer);
int networkServiceRecvStrUdpId(NetworkService * networkService, const char ** stringBuffer, int isServer);
int networkServiceSendIntUdp(NetworkService * networkService, int data, int id, int isServer);
int networkServiceRecvIntUdp(NetworkService * networkService, int isServer);
int networkServiceRecvIntUdpInt(NetworkService * networkService, int * idBuffer, int isServer);
int networkServiceRecvIntUdpId(NetworkService * networkService, int * intBuffer, int isServer);

#ifdef __cplusplus
}
#endif

#endif /* NETWORKSERVICEC_H_ */
