#ifndef HumanB_H
# define HumanB_H

#include "Weapon.hpp"

/**
 * @brief A class representing a human with a name and an optional weapon.
 */
class HumanB
{
    private:
        std::string name;
        Weapon      *weapon;
    public:
        HumanB(std::string);
        ~HumanB();
        void    attack(void) const;
        void    setWeapon(Weapon &);
        void    setName(std::string);
};

#endif