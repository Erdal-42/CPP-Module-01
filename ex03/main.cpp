#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


/**
 * @brief Entry point of the program.
 *
 * This function demonstrates the usage of the HumanA and HumanB classes with Weapon objects.
 * It creates instances of HumanA and HumanB, sets their weapons, and performs attacks.
 *
 * @return Returns 0 to indicate successful execution.
 */
int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    return 0;
}
