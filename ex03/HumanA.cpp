#include "HumanA.hpp"

/**
 * @brief Constructor for the HumanA class.
 *
 * Initializes a HumanA object with the given name and weapon.
 *
 * @param theName The name of the HumanA object.
 * @param theWeapon A reference to the Weapon object that the HumanA object will use.
 */
HumanA::HumanA(std::string theName, Weapon &theWeapon) : name(theName), weapon(theWeapon)
{

}

/**
 * @brief Destructor for the HumanA class.
 */
HumanA::~HumanA()
{

}

/**
 * @brief Performs an attack action.
 *
 * Prints a message indicating that the HumanA object is attacking with its weapon.
 */
void HumanA::attack(void) const
{
    std::cout << name << " attacks with " << weapon.getType() << std::endl;
}

/**
 * @brief Sets the weapon of the HumanA object.
 *
 * @param theWeapon A reference to the new Weapon object that the HumanA object will use.
 */
void HumanA::setWeapon(Weapon &theWeapon)
{
    weapon.setType(theWeapon.getType());
}

/**
 * @brief Sets the name of the HumanA object.
 *
 * @param theName The new name for the HumanA object.
 */
void HumanA::setName(std::string theName)
{
    name = theName;
}
