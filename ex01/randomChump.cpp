#include "Zombie.hpp"

/*
 *
 * @brief: This function creates a zombie, names it, and then 
 * the zombie announces itself.
 * 
 * When a new local variables is declared, it is stored in the
 * stack memory. After the function returns, the stack memory 
 * of this function is deallocated, which means all local 
 * variables become invalid. The allocation and deallocation 
 * for stack memory is automatically done. The variables 
 * allocated on the stack are called stack variables or 
 * automatic variables. Since the stack memory of a function 
 * gets deallocated after the function returns, there is no 
 * guarantee that the value stored in those area will survive.
 * ie i = 0, or int *i = 4;
 * 
 * In order to solve the volatile stack issue, you can either 
 * return by copy, or put the value at somewhere more permanent. 
 * Heap memory is such a place. Unlike stack memory, heap memory 
 * is allocated explicitly by programmers and it won’t be 
 * deallocated until it is explicitly freed. 
 *  
 * To allocate heap memory in C++, use the keyword "new" followed 
 * by the constructor of what you want to allocate. The return 
 * value of new operator will be the address of what you just 
 * defined (which points to somewhere in the heap).
 * 
 * @param: string zombie name
 * 
 * @return: none.
 */
void    randomChump(std::string name)
{
    std::string stack_title = "Stack_Zombie";
    std::string heap_title = "Heap_Zombie";
    Zombie stack_zombie(name + " " + stack_title);
    Zombie *heap_zombie = NULL;

    *heap_zombie = newZombie(name + " " + heap_title);
    stack_zombie.announce();
    heap_zombie->announce();
    delete (heap_zombie);
}