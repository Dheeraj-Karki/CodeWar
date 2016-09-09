/*
Create a mutex 
int pthread_mutex_init(pthread_mutex_t *mtx, const pthread_mutexattr_t *attr);
 
Locks the mutex blocking on it until the lock is acquired
int pthread_mutex_lock(pthread_mutex_t *mutex);
 
Attempt to lock a mutex without blocking
int pthread_mutex_trylock(pthread_mutex_t *mutex); 
 
Unlocks a mutex
int pthread_mutex_unlock(pthread_mutex_t *mutex); 
 
Deletes a mutex
int pthread_mutex_destroy(pthread_mutex_t *mutex);*

*/
#pragma once
#include<pthread.h>
#include"../include/delete.hpp"
class Mutex
{
    NON_COPAYABLE(Mutex)
    public:
        Mutex() { pthread_mutex_init(&m_mutex,NULL);};
        ~Mutex(){ pthread_mutex_destroy(&m_mutex);};
        int lock(){ return pthread_mutex_lock(&m_mutex);};
        int tryLock(){ return pthread_mutex_trylock(&m_mutex);};
        int unlock(){ return pthread_mutex_unlock(&m_mutex);};
    private:
        pthread_mutex_t m_mutex;
};


