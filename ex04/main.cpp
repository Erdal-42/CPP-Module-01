#include "replace.hpp"

int main(int ac, char *av[])
{
    if (ac < 4)
    {
        std::cout << "Please enter the necessary number of parameters: infile / to be replaced word / insert word " << std::endl;
        return (0);
    }
    replace_word(av);
    return 0;
}