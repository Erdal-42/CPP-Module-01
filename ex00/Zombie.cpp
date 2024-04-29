#include "Zombie.hpp"

/*
 * Zombie Constructor
 */
Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
    setName(name);    
}

/*
 * Zombie Destructor
 */
Zombie::~Zombie()
{
    std::cout << name << " is smashed across the head with a bat." << std::endl;
}

/**
 * @brief Announces the presence of the zombie.
 *
 * This function prints a message to the standard output indicating the zombie's presence.
 *
 * @return void
 */
void            Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string     Zombie::getName(void) const
{
    return (name);
}

void    Zombie::setName(std::string str)
{
    name = str;
}