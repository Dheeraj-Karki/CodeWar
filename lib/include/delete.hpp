#pragma once

#define NON_COPAYABLE(className)\
    private:\
        className( const className& );\
        className& operator=( const className& );
