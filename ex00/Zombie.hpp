#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstring>

/**
 * @brief The Zombie class represents a zombie entity.
 * 
 * This class provides functionality to create, destroy, and interact with zombies.
 */
class Zombie
{
    private:
        std::string name;

    public:
        Zombie(void);
        Zombie(std::string);
        ~Zombie();
        void            announce(void) const;
        std::string     getName(void) const;
        void            setName(std::string);
};

Zombie* newZombie(std::string);
void    randomChump(std::string);

#endif