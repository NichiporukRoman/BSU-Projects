#ifndef BUFFERED_CHANNEL_H_
#define BUFFERED_CHANNEL_H_
#include <utility>
#include <queue>
#include <mutex>
#include <condition_variable>

template<class T> class BufferedChannel {
public:
    explicit BufferedChannel(int size)
    {
        this->size = size;
        this->isOpen = true;
        this->isEmpty = true;
    }

    void Send(T value) {
        std::unique_lock<std::mutex> lock(mutex);
        waitForInput.wait(lock, [this] { return queue.size() < size;});
        if (!isOpen) {
            throw std::runtime_error("Channel is closed!");
        }
        queue.push(value);
        isEmpty = false;
        waitForInput.notify_one();
        lock.unlock();
    }

    std::pair<T, bool> Recieve() {
        std::unique_lock<std::mutex> lock(mutex);
        waitForOutput.wait(lock, [this] {return !isEmpty;});
        if (!isOpen) {
            throw std::runtime_error("Channel is closed!");
        }
        T value = queue.front();
        queue.pop();
        waitForOutput.notify_one();
        lock.unlock();
        return std::pair<T, bool>(value, isOpen);
    }

    void Close() {
        std::unique_lock<std::mutex> lock(mutex);
        isOpen = false;
        lock.unlock();
    }

private:
    int size;
    bool isOpen;
    bool isEmpty;
    std::mutex mutex;
    std::queue<T> queue;
    std::condition_variable waitForInput;
    std::condition_variable waitForOutput;
};

#endif // BUFFERED_CHANNEL_H_
