#include "buffered_channel.h"
#include <thread>

using std::thread;

int32_t main() {
    BufferedChannel<int> channel(10);
    thread _1s = thread(&BufferedChannel<int>::Send, &channel, 1);
    thread _1r = thread(&BufferedChannel<int>::Recieve, &channel);
    thread close = thread(&BufferedChannel<int>::Close, &channel);
    thread _2s = thread(&BufferedChannel<int>::Send, &channel, 1);
    thread _2r = thread(&BufferedChannel<int>::Recieve, &channel);

    _1s.join();
    _1r.join();
    close.join();
    _2s.join();
    _2r.join();
}