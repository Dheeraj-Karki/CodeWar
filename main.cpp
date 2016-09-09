#include <iostream>
#include "./lib/include/thread.hpp"
#include "./lib/include/smartptr.hpp"
#include <unistd.h>

class Worker_1:public Thread 
{
    public:
        void* run()
        {
            for( int i = 0; i<10; i++)
            {
                std::cout<<"Worker 1 "<<self()<<" : "<<i<<std::endl;
                sleep(3);
            }
            std::cout<<"Worker 1 Finished "<<self()<<std::endl;
        }
};
typedef SmartPtr<Worker_1> WorkerPtr_1;
class Worker_2:public Thread 
{
    public:
        void* run()
       {
            for( int i = 0; i<10; i++)
            {
                std::cout<<"Worker 2 "<<self()<<" : "<<i<<std::endl;
                sleep(3);
            }
            std::cout<<"Worker 2 Finished "<<self()<<std::endl;
        }
};

int main()
{
    WorkerPtr_1 w1 ( new Worker_1() );
    Worker_2* w2 = new Worker_2();
    w1->start();
    w2->start();
    w1->join();
    w2->join();
    std::cout<<"main end"<<std::endl;
}
