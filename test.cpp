#include "utils.hpp"
#include "request_parser.hpp"

int     main()
{

	// std::string str = "aymen ghazali student\r\nat 1337";
	// size_t pos = str.find("\r\n");

	// //std::string str2 = str.substr(pos);

	// if(pos != std::string::npos)
	// 	std::cout <<  pos << std::endl;

	std::string str = "GET /path?query1=val&query2=val&query3=val&query4=val HTTP/1.1\r\n";
	std::vector<std::string> tokens;

	tokens = ft_split(str, ": \r\n");

	std::cout << tokens.size() << std::endl;

	for (int i = 0; i < tokens.size(); i++)
		std::cout << tokens[i] << std::endl;


	return 0;
}	