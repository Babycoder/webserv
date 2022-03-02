#include "server_parser.hpp"


server_parser::server_parser(){
	port = 80;
	host = "0.0.0.0";
}
server_parser::~server_parser(){}

 server_parser &server_parser::operator=(server_parser const &src)
 {
	if (this == &src)
		return *this;
	host = src.host;
	port = src.port;
	names = src.names;
	error_pages = src.error_pages;
	clientMaxBodySize = src.clientMaxBodySize;
	_serverBlock = src._serverBlock;
	
	return *this;	
 }


 server_parser::server_parser(std::vector<std::string> block) : _serverBlock(block)
 {
	port = 80;
	host = "0.0.0.0";
	
	std::vector<std::string>::iterator it = _serverBlock.begin() + 1;
	for(; it != _serverBlock.end(); it++)
	{
		if(is_serverline(*it))
		{

		}
		else
			throw ("File Error: line identation not valid !!");
	}
	 
 }


int							server_parser::getMaxSzie()
{
	return clientMaxBodySize;
}

int							server_parser::getPort()
{
	return port;
}

std::string					server_parser::getHost()
{
	return host;
}

std::vector<std::string>	server_parser::getNames()
{
	return names;
}

std::vector<std::string>	server_parser::getErrorPages()
{
	return error_pages;
}

std::vector<std::string>	server_parser::getServerBlock()
{
	return	_serverBlock;
}