#include "Zombie.hpp"


/**
 * @brief The main function for creating a zombie horde.
 *
 * This function creates a horde of zombies based on user input and announces each zombie.
 *
 * @return Returns 0 to indicate successful execution.
 */
int main()
{
    int         N;
    int         i;
    Zombie      *horde;
    std::string name;

    horde = NULL; 
    std::cout << "Enter the number zombie's you want to rise: ";
    std::cin >> N;
    std::cout << "Enter the name to use for your zombie horde: "; 
    std::cin >> name;
    horde = zombieHorde(N, name);
    i = -1;
    while (++i < N)
    {
        std::cout << i + 1 << ". Mah nem ihzz ";
        horde[i].announce();
    }
    i = -1;
    delete [] horde;

    return (0);
}