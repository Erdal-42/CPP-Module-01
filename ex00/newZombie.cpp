#include "Zombie.hpp"

/*
 *
 * @brief: It creates a zombie, names it and return it so you 
 * can use it outside of the function scope.
 * Heap is used when we need large memory variables to be used 
 * globally, and resizing is to be done frequently, whereas 
 * stack is used when the small variables need to be stored 
 * till the execution of function only and no/ very less 
 * resizing is to be done. Foe our case the stack is convenient.
 * 
 * @param: name of the new zombie.
 * 
 * @return: pointer to newly generated zombie.
 * 
 */
Zombie* newZombie(std::string str)
{
    Zombie  *z; 
    
    z = new Zombie();
    z->setName(str);
    return (z);   
}