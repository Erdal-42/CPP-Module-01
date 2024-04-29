#include "replace.hpp"


/**
 * @brief Counts the number of elements in a string array.
 * @param arr The string array to count elements from.
 * @return The number of elements in the array (excluding the null terminator).
 *
 * This function iterates through the string array until it encounters the null
 * terminator and returns the count of elements.
 */
int countMembers(char** arr)
{
    int count = 0;
    char** current = arr;
    
    while (*current != nullptr )
    {
        count++;
        current++;
    }
    
    return count;
}
/**
 * @brief Checks if the number of command-line arguments is valid.
 * @param av Array of command-line arguments.
 * @return 1 if the number of arguments is valid, 0 otherwise.
 *
 * This function checks if the number of command-line arguments is at least 4.
 * Additionally, it verifies that none of the first three arguments are null.
 * It prints an error message to the standard error stream if any of the conditions
 * are not met.
 */
int testNumParameters(char *av[])
{
    if (countMembers(av) < 4)
    {
        std::cout << "\tInvalid number of parameters." << std::endl;
        return (0);
    }
    else if (!av[1] || !av[2] || !av[3])
    {
        std::cout << "\tInvalid parameter." << std::endl;
        return (0);
    }
    return (1);
}

/**
 * @brief Generates a new output file name based on the input file name.
 * @param filename The input file name.
 * @return The generated output file name (string).
 *
 * This function extracts the filename part (excluding the extension) from the
 * provided input file name and appends ".replace" to it. If the input filename
 * is empty, it returns NULL.
 */
std::string prepareFileName(std::string filename)
{
    int         i;
    std::string str;

    if (filename.length() == 0)
        return (NULL);
    i = 0;
    while (filename[i] && filename[i] != '.')
        ++ i;
    if (!i)
        exit(EXIT_FAILURE);
    str = filename.substr(0, i);
    str = str + ".replace";

    return (str);
}

/**
 * @brief Checks if a file is empty.
 * @param filename The name of the file to check.
 * @return true if the file is empty, false otherwise.
 *
 * This function opens the file in read mode and checks if the peek() function
 * returns the end-of-file indicator. If the file is empty, it prints a message to
 * the standard output stream.
 */
bool isFileEmpty(const std::string& filename) {
    bool status;
    std::ifstream file(filename);
    status = file.peek() == std::ifstream::traits_type::eof();
    if (status == true)
        std::cout << "\tSource file is empty!" << std::endl;
    return (status);
}

/**
 * @brief Replaces a specific word in a file with another word.
 * @param av Array of command-line arguments.
 *
 * This function performs the following steps:
 * 1. Calls `testNumParameters` to ensure valid arguments.
 * 2. Prepares the output file name using `prepareFileName`.
 * 3. Deletes the existing output file if it exists.
 * 4. Opens the input and output files.
 * 5. Checks if the input file is empty and returns if so.
 * 6. Extracts the words to be replaced and the replacement word from arguments.
 * 7. Reads lines from the input file and replaces occurrences of the specified
 *    word with the replacement word.
 * 8. Writes the modified lines to the output file.
 * 9. Closes both input and output files.
 */
void    replace_word(char *av[])
{
    if (!testNumParameters(av))
        return ;    
    std::string     outfile_name;
    std::string     infile_name(av[1]);
    std::string     lineA;
    std::string     lineB;
    std::fstream    infile(infile_name);
    outfile_name = prepareFileName(infile_name);
    if (std::remove(outfile_name.c_str()) != 0) {
        std::cerr << "Error deleting existing file: " << outfile_name << std::endl;
    }
    std::fstream    outfile(outfile_name);
    outfile.open(outfile_name, std::ios::out);
    if (!outfile.is_open()) 
    {
        std::cout << "\tFailed to open destination file!" << std::endl;
        return ;
    }
    if (!infile.is_open()) 
    {
        std::cout << "\tFailed to open source file!" << std::endl;
        return ;
    }
    if (isFileEmpty(av[1]))
        return ;
    std::string s1 = av[2];
    std::string s2 = av[3];
    while (std::getline(infile, lineA))
    {
        size_t position = lineA.find(s1);
        while (position != std::string::npos)
        {
            lineB += lineA.substr(0, position) + s2;
            lineA = lineA.substr(position + s1.length(), lineA.length() - (position + s1.length()));
            position = lineA.find(s1);      
        } 
        lineB += lineA;
        outfile << lineB;
        outfile << std::endl;
        lineB = "";
    } 
    infile.close();
    outfile.close();
}

/**
 * @brief Reads and outputs the contents of a file line by line.
 * 
 * @param filename The name of the file to read.
 * @return 0 if the file is successfully read, otherwise an error code.
 */
int cat(std::string filename) 
{
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }
    return 0;
}

/**
 * @brief A function to test various scenarios of the replace_word function.
 */
void tester(void)
{
    char *av[4];
    
    std::cout << "\nRequired Number of Parameter Test" << std::endl;
    
    av[0] = (char *)"tester.exe";
    av[1] = (char *)"test1.txt";
    av[2] = (char *)"a";
    av[3] = NULL;
    replace_word(av);
    
    std::cout << "\nEmpty File Test" << std::endl;
    av[0] = (char *)"tester.exe";
    av[1] = (char *)"test1.txt";
    av[2] = (char *)"a";
    av[3] = (char *)"A";
    replace_word(av);


    std::cout << "\nNon-Existing File Test" << std::endl;
    av[0] = (char *)"tester.exe";
    av[1] = (char *)"testX.txt";
    av[2] = (char *)"a";
    av[3] = (char *)"A";
    replace_word(av);

    std::cout << "\nCommon File Test" << std::endl;
    std::cout << "\tReplacing 1's with One's" << std::endl;
    av[0] = (char *)"tester.exe";
    av[1] = (char *)"test2.txt";
    av[2] = (char *)"1";
    av[3] = (char *)"One";
    cat("test2.txt");
    std::cout << "\tReplacing 1's with One's" << std::endl;
    replace_word(av);
    cat("test2.replace");
    std::cout << "\tReplacing One's with 2's" << std::endl;
    av[1] = (char *)"test3.txt";
    av[2] = (char *)"One";
    av[3] = (char *)"2";
    replace_word(av);
    cat("test3.replace");
}


