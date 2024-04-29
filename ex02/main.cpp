#include <iostream>
# include <string>


/*
 * In C++, a reference to a string is a way to create 
 * an alias or alternative name for an existing string 
 * object. It allows you to access and manipulate the 
 * string using a different identifier without making 
 * a copy of the original string data.
 * 
 * To create a reference to a string in C++, you can 
 * use the & symbol when declaring the reference 
 * variable.
 * 
 * Note that when using references, you need to ensure 
 * that the referenced object remains valid throughout 
 * the lifetime of the reference. If the referenced 
 * object is destroyed or goes out of scope, using the 
 * reference will result in undefined behavior.
 * 
 */ 

int main()
{
    std::string str;
    std::string *stringPTR;
    std::string &stringREF = str;

    str = "HI THIS IS BRAIN";
    stringPTR = &str;

    std::cout << "The memory address of the string: " << &str << std::endl;
    std::cout << "The memory address held by the string pointer: " << stringPTR << std::endl;
    std::cout << "The memory address held by the string reference: " << &stringREF << std::endl;

    std::cout << "The value of the string variable: " << str << std::endl;
    std::cout << "The value pointed to by string pointer: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by string reference: " << stringREF << std::endl;

    return (0);
}