//
// Created by xieyuschen on 2021/8/23.
//

#include "Server.h"
#include <sys/socket.h>
#include "netinet/in.h"
#include "Log.h"
Server::Server() {
    listenSocket= socket(AF_INET,SOCK_STREAM,0);

}
void Server::Listen(int port) {
    sockaddr_in servaddr;
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(port);
    bind(listenSocket,(sockaddr*)&servaddr, sizeof(servaddr));
    listen(listenSocket,1024);
}
void Server::Serve() {
    sockaddr* addr;
    for(;;){
        socklen_t clilen=sizeof(addr);
        int t= accept(listenSocket,addr,&clilen);
        sockets.push_back(t);
        LOG("Connection No.%d is established",t);
    }
}