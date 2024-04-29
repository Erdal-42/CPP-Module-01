#include "Weapon.hpp"

/**
 * @brief Default constructor for the Weapon class.
 */
Weapon::Weapon(void)
{

}

/**
 * @brief Constructor for the Weapon class.
 * @param theType The type of the weapon.
 */
Weapon::Weapon(std::string theType)
{
    setType(theType);
}

/**
 * @brief Destructor for the Weapon class.
 */
Weapon::~Weapon()
{

}

/**
 * @brief Sets the type of the weapon.
 * @param theType The type of the weapon.
 */
void Weapon::setType(std::string theType)
{
    type = theType;
}

/**
 * @brief Gets the type of the weapon.
 * @return The type of the weapon.
 */
std::string const Weapon::getType(void) const
{
    return (type);
}
