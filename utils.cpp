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

bool                            is_empty(std::string str)
{
	if (str.empty())
		return true;
	for(size_t i = 0; i < str.length() ; i++)
	{
		if (str[i] != 32 && str[i] != 9)
			return false;
	}
	return true;
}


void		print_vector(std::vector<std::string> vc)
{
	std::vector<std::string>::iterator it = vc.begin();
	for(;it != vc.end(); it++)
		std::cout << *it << std::endl;
}