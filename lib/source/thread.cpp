#include"../include/thread.hpp"

Thread::Thread()
{
    m_tid = 0;
    m_bRunning = 0;
    m_bDetached = 0;
}

Thread::~Thread()
{
    if( m_bRunning == 1 && m_bDetached == 0 )
    {
        pthread_detach(m_tid);
    }
    else if( m_bRunning == 1 )
    {
        pthread_cancel(m_tid);
    }
}

void* runThread( void* args );
int Thread::start()
{
    int result = -1;
    result = pthread_create( &m_tid, NULL, runThread, this );
    if( result== 0 )
    {
        m_bRunning = 1;
    }
    return result;
}

void* runThread( void* args )
{
    ( (Thread *)args )->run();
}

int Thread::join()
{
    int result = -1;
    if( m_bRunning == 1 )
    {
        result = pthread_join( m_tid, NULL );
        if( result == 0 )
        {
            m_bRunning = 1;
        }
    }
    return result;
}

int Thread::detach()
{
    int result = -1;
    if( m_bRunning ==1 )
    {
        result = pthread_detach( m_tid );
        if( result ==0 )
        {
            m_bDetached = 1;
        }
    }
    return result;
}

pthread_t Thread::self()
{
    return this->m_tid;
}
