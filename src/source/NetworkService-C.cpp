/*
 * NetworkService-C.cpp
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#include <iostream>
using namespace std;

#include <SuperMaximo_GameLibrary/classes/NetworkService.h>

#include "../headers/NetworkService-C.h"

extern "C" {

int initNetworking() {
	return SuperMaximo::initNetworking();
}

void quitNetworking() {
	SuperMaximo::quitNetworking();
}


NetworkService * networkServiceNew(const char * newName) {
	return (NetworkService*)(new SuperMaximo::NetworkService(newName));
}

void networkServiceDelete(NetworkService * networkService) {
	delete (SuperMaximo::NetworkService*)networkService;
	networkService = 0;
}

const char * networkServiceName(NetworkService * networkService) {
	return ((SuperMaximo::NetworkService*)networkService)->name().c_str();
}

int networkServiceServerStarted(NetworkService * networkService) {
	return ((SuperMaximo::NetworkService*)networkService)->serverStarted();
}

int networkServiceClientStarted(NetworkService * networkService) {
	return ((SuperMaximo::NetworkService*)networkService)->clientStarted();
}


int networkServiceStartServer(NetworkService * networkService, int newMaxSockets, int newPort) {
	return ((SuperMaximo::NetworkService*)networkService)->startServer(newMaxSockets, newPort);
}

void networkServiceCloseServer(NetworkService * networkService) {
	return ((SuperMaximo::NetworkService*)networkService)->closeServer();
}

int networkServiceRestartServer(NetworkService * networkService) {
	return ((SuperMaximo::NetworkService*)networkService)->restartServer();
}

uint32_t networkServiceNewLocalAddress(NetworkService * networkService) {
	return ((SuperMaximo::NetworkService*)networkService)->newLocalAddress();
}

uint32_t networkServiceLocalAddress(NetworkService * networkService) {
	return ((SuperMaximo::NetworkService*)networkService)->localAddress();
}

int networkServiceCheckForNewClient(NetworkService * networkService, int useUdp) {
	return ((SuperMaximo::NetworkService*)networkService)->checkForNewClient(useUdp);
}

int networkServiceClientExists(NetworkService * networkService, int id) {
	return ((SuperMaximo::NetworkService*)networkService)->clientExists(id);
}

int networkServiceTotalClients(NetworkService * networkService) {
	return ((SuperMaximo::NetworkService*)networkService)->totalClients();
}

void networkServiceKickClient(NetworkService * networkService, int id) {
	((SuperMaximo::NetworkService*)networkService)->kickClient(id);
}


int networkServiceStartClient(NetworkService * networkService, const char * newAddress, int newPort) {
	return ((SuperMaximo::NetworkService*)networkService)->startClient(newAddress, newPort);
}

void networkServiceCloseClient(NetworkService * networkService) {
	((SuperMaximo::NetworkService*)networkService)->closeClient();
}

int networkServiceRestartClient(NetworkService * networkService) {
	return ((SuperMaximo::NetworkService*)networkService)->restartClient();
}

int networkServiceConnectToServer(NetworkService * networkService, int useUdp) {
	return ((SuperMaximo::NetworkService*)networkService)->connectToServer(useUdp);
}

int networkServiceClientNumber(NetworkService * networkService) {
	return ((SuperMaximo::NetworkService*)networkService)->clientNumber();
}


int networkServiceSendStrTcp(NetworkService * networkService, const char * data, int id, int isServer, int size) {
	return ((SuperMaximo::NetworkService*)networkService)->sendStrTcp(data, id, isServer, size);
}

const char * networkServiceRecvStrTcp(NetworkService * networkService, int id, int isServer, int size) {
	return ((SuperMaximo::NetworkService*)networkService)->recvStrTcp(id, isServer, size).c_str();
}

int networkServiceSendIntTcp(NetworkService * networkService, int data, int id, int isServer) {
	return ((SuperMaximo::NetworkService*)networkService)->sendIntTcp(data, id, isServer);
}

int networkServiceRecvIntTcp(NetworkService * networkService, int id, int isServer) {
	return ((SuperMaximo::NetworkService*)networkService)->recvIntTcp(id, isServer);
}


int networkServiceSendStrUdp(NetworkService * networkService, const char * data, int id, int isServer) {
	return ((SuperMaximo::NetworkService*)networkService)->sendStrUdp(data, id, isServer);
}

const char * networkServiceRecvStrUdp(NetworkService * networkService, int isServer) {
	return ((SuperMaximo::NetworkService*)networkService)->recvStrUdp(isServer).c_str();
}

const char * networkServiceRecvStrUdpStr(NetworkService * networkService, int * idBuffer, int isServer) {
	return ((SuperMaximo::NetworkService*)networkService)->recvStrUdp(idBuffer, isServer).c_str();
}

int networkServiceRecvStrUdpId(NetworkService * networkService, const char ** stringBuffer, int isServer) {
	return ((SuperMaximo::NetworkService*)networkService)->recvStrUdp((string*)stringBuffer, isServer);
}

int networkServiceSendIntUdp(NetworkService * networkService, int data, int id, int isServer) {
	return ((SuperMaximo::NetworkService*)networkService)->sendIntUdp(data, id, isServer);
}

int networkServiceRecvIntUdp(NetworkService * networkService, int isServer) {
	return ((SuperMaximo::NetworkService*)networkService)->recvIntUdp(isServer);
}

int networkServiceRecvIntUdpInt(NetworkService * networkService, int * idBuffer, int isServer) {
	return ((SuperMaximo::NetworkService*)networkService)->recvIntUdp(idBuffer, isServer);
}

int networkServiceRecvIntUdpId(NetworkService * networkService, int * intBuffer, int isServer) {
	return ((SuperMaximo::NetworkService*)networkService)->recvIntUdpId(intBuffer, isServer);
}

}
