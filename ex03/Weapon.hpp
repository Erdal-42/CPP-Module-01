#ifndef Weapon_H
# define Weapon_H

#include <iostream>
#include <string>

/**
 * @brief A class representing a weapon with a type.
 */
class Weapon
{
    private:
        std::string type;
    public:
        Weapon();
        Weapon(std::string);
        ~Weapon();
        void        setType(std::string);
        std::string const getType(void) const;  
};                                              

#endif