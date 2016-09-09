#pragma once

template<class T>
class SmartPtr
{
    public:
        // Constructor
        explicit SmartPtr( T* ptr = NULL )
        { 
            m_ptr = ptr; 
        }
        // Destructor
        virtual ~SmartPtr()
        {
            if(m_ptr)
            {
                delete m_ptr;
            }
        }
        // Overloading dereferncing operator
        T& operator* ()
        {
            return *m_ptr;
        }
        // Overloding arrow operator so that members of T can be accessed
        // like a pointer (useful if T represents a class or struct or 
        // union type)
        T& operator ->()
        {
            return m_ptr;
        }
    private:
        //Actual Pointer
        T* m_ptr;

};
