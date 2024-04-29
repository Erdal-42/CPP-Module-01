#include "HumanB.hpp"

/**
 * @brief Constructs a HumanB object with the specified name.
 *
 * @param theName The name of the HumanB object.
 */
HumanB::HumanB(std::string theName) : name(theName)
{
    weapon = NULL;
}

/**
 * @brief Destructor for the HumanB object.
 */
HumanB::~HumanB()
{

}

/**
 * @brief Attacks using the current weapon, if any.
 *
 * If no weapon is set, the HumanB object defends by taking guard.
 */
void    HumanB::attack(void) const
{
    if (!weapon)
        std::cout << name << " defends by taking guard." << std::endl;
    else
        std::cout << name << " attacks with " << weapon->getType() << std::endl;
}

/**
 * @brief Sets the weapon for the HumanB object.
 *
 * @param theWeapon Reference to the Weapon object to set as the weapon.
 */
void HumanB::setWeapon(Weapon &theWeapon)
{
    weapon = &theWeapon;
}

/**
 * @brief Sets the name of the HumanB object.
 *
 * @param theName The new name for the HumanB object.
 */
void    HumanB::setName(std::string theName)
{
    name = theName;
}
