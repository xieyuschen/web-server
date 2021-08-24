# web-server
## servaddr and servaddr_in
`sockaddr` and `sockaddr_in` are same but look quite different for one has `sa_data[14]` but the other has three 
properties.
```c
struct sockaddr {
    unsigned short    sa_family;    // 2 bytes address family, AF_xxx
    char              sa_data[14];     // 14 bytes of protocol address
};

// IPv4 AF_INET sockets:

struct sockaddr_in {
    short            sin_family;       // 2 bytes e.g. AF_INET, AF_INET6
    unsigned short   sin_port;    // 2 bytes e.g. htons(3490)
    struct in_addr   sin_addr;     // 4 bytes see struct in_addr, below
    char             sin_zero[8];     // 8 bytes zero this if you want to
};
```

## htons and htonl
`htons` and `htonl` are quite different. They are be called for a short of `host to net short` and `host to net long`,since there existes `host to net`,there also owns `net to hosts`. Use `man htons` and you can see all of them.  
Here show a example for them:
```cpp
#include<arpa/inet.h>
#include<iostream>
#include<iomanip>  
using namespace std;
int main(){
    int num=0x10;
    cout<<"htons: "<<hex<<htons(num)<<", "<<"htonl: "<<htonl(num)<<endl;
    cout<<"ntons: "<<hex<<ntohs(num)<<", "<<"ntonl: "<<ntohl(num)<<endl;   
}
```
The output here:
```
htons: 1000, htonl: 10000000
ntons: 1000, ntonl: 10000000
```
This is quite normal if you understand its principle. Pay attention that they are nothing about max number is 65535 and ip address owns 32 bit. Main idea here is to make sure different machine can use the same endine(**Network byte order**,notes TCP/IP standard network byte order is big-endian) when transport and make sure recieved data is suitable for it's own cpu(**Host byte order**,depends on its cpu implement) .By the way, `l` is for 32bit and `s` is for 16bit, if you want to use it in 64bit, `ll` is a choice for you.


`netstat -tln`
