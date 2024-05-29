In this module I had to complete the following C++98 OOP exercises. I had to decide whether to allocate memory on stack or the heap. Also I had to utilize pointers and references in order to highlight their purpose and practicality.

TASKS

**Ex00: Zombie Class**

- Implement a Zombie class with a private string attribute name.
- Add a member function announce() that displays the zombie's name.
- Create two functions:
  - `Zombie* newZombie(std::string name)`: Creates and names a zombie, returning a pointer for external use.
  - `void randomChump(std::string name)`: Creates and names a zombie, then calls its announce() function.
- Determine when to allocate zombies on the stack or heap based on their usage and lifetime.
- Implement a destructor that prints the zombie's name for debugging purposes.

**Ex01: Zombie Horde**

- Implement `Zombie* zombieHorde(int N, std::string name)`:
  - Allocates memory for N Zombie objects in a single block.
  - Initializes each zombie with the provided name.
  - Returns a pointer to the first zombie.
- Create and run tests to verify the functionality of `zombieHorde()`.
- Call announce() for each zombie in the horde.
- Ensure proper memory management by deleting all zombies and checking for leaks.

**Ex02: Pointers and References**

- Create a program with:
  - A string variable initialized to "HI THIS IS BRAIN".
  - `stringPTR`: A pointer to the string.
  - `stringREF`: A reference to the string.
- Print:
  - Memory addresses of the string variable, `stringPTR`, and `stringREF`.
  - Values of the string variable, what `stringPTR` points to, and what `stringREF` refers to.

**Ex03: Weapon Class and Human Inheritance**

- Implement a Weapon class with:
  - A private string attribute type.
  - `getType()`: Returns a const reference to type.
  - `setType(const std::string& newType)`: Sets type using the new parameter.
- Create classes HumanA and HumanB:
  - Both have a Weapon object and a name string.
  - Both have an attack() function displaying: `<name> attacks with their <weapon type>`.
- Key differences:
  - HumanA takes the Weapon in its constructor.
  - HumanB does not take the Weapon in its constructor and may not always have one.
