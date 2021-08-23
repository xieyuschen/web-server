//
// Created by xieyuschen on 2021/8/23.
//

#ifndef WEB_SERVER_SERVER_H
#define WEB_SERVER_SERVER_H
#include<vector>

class Server {
public:
    Server();
    void Listen(int port);
    void Serve();
private:
    std::vector<int> sockets;
    int listenSocket;
};


#endif //WEB_SERVER_SERVER_H
