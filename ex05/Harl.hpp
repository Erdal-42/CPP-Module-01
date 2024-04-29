
//header protection
//Suppressing warnings: Pragmas can be used to 
//suppress specific compiler warnings that you may consider irrelevant or false positives.
#pragma once
#include <string>
#include <iostream>
#include <cstdlib>

class Harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};