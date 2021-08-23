//
// Created by xieyuschen on 2021/8/23.
//

#ifndef WEB_SERVER_LOG_H
#define WEB_SERVER_LOG_H
#include "stdio.h"

class Log {
public:

};
#define LOG(...){\
    fprintf(stderr,"File %s at line %d [info]",__FILE__,__LINE__); \
    fprintf(stderr,__VA_ARGS__);                                  \
    fprintf(stderr,"\n");                                         \
}
#endif //WEB_SERVER_LOG_H
