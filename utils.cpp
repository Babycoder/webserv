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

bool                            is_serverline(std::string str)
{
	if(str[0] == 9 && str[1] != 9 && str[1] != 32)
		return true;
	return false;
}

bool                            is_digit(std::string str)
{
	for(size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return false;
	}
	return true;
}


bool							is_directive(std::string str)
{
	if (str == "port" || str == "host" ||  str == "server_name" ||  str == "root" ||  str == "error_page" ||  str == "location")
		return true;
	return false;
}

















