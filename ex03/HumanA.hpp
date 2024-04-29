
#ifndef HumanA_H
# define HumanA_H

#include "Weapon.hpp"


/**
 * @brief The HumanA class represents a human with a specific weapon.
 *
 * This class contains a name and a reference to a Weapon object.
 */
class HumanA
{
    private:
        std::string name;
        Weapon      &weapon;
    public:
        HumanA(std::string, Weapon &);
        ~HumanA();
        void    attack(void) const;
        void    setWeapon(Weapon &);
        void    setName(std::string);
};

#endif