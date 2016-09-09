#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include "./lib/include/thread.hpp"
#include "./lib/include/mutex.hpp"

class MutexTest : public Thread
{
    Mutex &m_mutex;
    public:
        MutexTest(Mutex& mutex) : m_mutex(mutex) {}
        void* run() {
            printf("thread waiting to get mutex\n");
            m_mutex.lock();
            printf("thread got mutex lock\n");
            // hold lock for awhile to make main thread wait
            sleep(10);
            m_mutex.unlock();
            return NULL;
        }
};

int main(int argc, char** argv)
{
    Mutex mutex;
    MutexTest test(mutex);
    test.start();
    // give the test thread a chance to acquire lock first
    sleep(1);
    // now it's main thread's turn 
    printf("main waiting to get mutex\n");
    mutex.lock();
    printf("main got mutex lock\n");
    mutex.unlock();
    test.join();
    exit(0);
}
