#include "Zombie.hpp"

/*
 *
 * @brief: This function allocates N Zombie objects in
 * a single allocation. Then, it has to initialize the
 * zombies, giving each one of them the name passed as 
 * parameter. The function returns a pointer to the 
 * first zombie.
 * 
 * @param: numner of zombies to be generated N and
 * the same name to be set for each zombie.
 * 
 * @return: pointer to the first zombie in the array. 
 * 
 */

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie  *horde = new Zombie[N];
    int     i;

    i = -1;
    while (++i < N)
        horde[i].setName(name);
    return (horde);
}