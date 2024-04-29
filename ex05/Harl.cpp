#include "Harl.hpp"

/**
 * @brief Default constructor for the Harl class.
 *
 * This constructor does not perform any specific initialization.
 */
Harl::Harl()
{

}

/**
 * @brief Destructor for the Harl class.
 */
Harl::~Harl()
{

}

/**
 * @brief Prints a debug message.
 *
 * This function outputs a specific debug message related to the Harl character.
 */
void    Harl::debug(void)
{
    std::cout << "DEBUG: I love having extra beef patty for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

/**
 * @brief Prints an info message.
 *
 * This function outputs a specific message from Harl.
 */
void    Harl::info(void)
{
    std::cout << "INFO: I cannot believe adding extra beef patty costs more money. You didn’t put enough meat in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

/**
 * @brief Prints a warning message.
 *
 * This function outputs a specific warning message from Harl.
 */
void    Harl::warning(void)
{
    std::cout << "WARNING: I think I deserve to have some extra beef patty for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{

    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

/**
 * @brief Complains based on the provided message level.
 * @param level The level of the complaint (e.g., "DEBUG", "INFO", "WARNING", "ERROR").
 *
 * This function maps the provided complaint level to the corresponding member
 * function using a function pointer array. If the level matches one of the
 * available options (DEBUG, INFO, WARNING, ERROR), it calls the corresponding
 * member function. Otherwise, it prints an error message indicating that the
 * complaint level is not understood.
 */
void    Harl::complain(std::string level)
{
    void (Harl::*complain_ptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    //complain_ptr = &Harl::error;    //what do I do for other complain functions?
    std::string complain[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;
    int flag = 0;

    i = 0;
    while (i < 4)
    {
        if (complain[i] == level)
        {
            (this->*complain_ptr[i])();
            flag = 1;
        }
        ++ i;
    }
    if (!flag)
        std::cout << level << ": Sorry! Harl did not understand the complaint."  << std::endl; 
}

/**
 * @brief Entry point of the program.
 *
 * This function creates a Harl object and calls the `complain` function with
 * different message levels to demonstrate its functionality.
 */
int main()
{
    Harl    *harl = NULL;

    harl->complain("DEBUG");
    harl->complain("ERROR");
    harl->complain("INFO");
    harl->complain("WARNING");
    harl->complain("FIRE");
}
