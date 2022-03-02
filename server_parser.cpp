#include "server_parser.hpp"


server_parser::server_parser(){}
server_parser::~server_parser(){}

 server_parser &server_parser::operator=(server_parser const &src)
 {
	if (this == &src)
		return *this;
	host = src.host;
	port = src.host;
	names = src.names;
	clientMaxBodySizwe = src.clientMaxBodySizwe;
	_serverBlock = src._serverBlock;
	
	return *this;	
 }


 server_parser::server_parser(std::vector<std::string> block) : _serverBlock(block)
 {
	 std::vector<std::string>::iterator it = _serverBlock.begin() + 1;
	 _linetest = *it;
	 

 }

 std::string		server_parser::getlinetest()
 {
	 return _linetest;
 }