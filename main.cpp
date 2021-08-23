#include "Server.h"
#include "Log.h"
int main() {
    LOG("123");
    Server s{};
    s.Listen(33333);
    s.Serve();
}
