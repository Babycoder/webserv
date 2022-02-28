#include "utils.hpp"



std::vector<std::string>        ft_split(std::string str, std::string delim)
{
    std::vector<std::string> tokens;

    char *ptr = strtok((char *)str.c_str(), delim.c_str());
    
    while(ptr != NULL)
    {
        tokens.push_back(ptr);
		ptr = strtok(NULL, delim.c_str());
    }

    return tokens;
}