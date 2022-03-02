#pragma once

#include "utils.hpp"

class server_parser
{
	private :
		int							port;
		std::string					host;
		std::vector<std::string>	names;
		std::vector<std::string>	error_pages;
		int							clientMaxBodySize;
		std::vector<std::string>	_serverBlock;
		
	   // std::vector<location> locations;

	public :

	// constructors and overloads :
	server_parser();
	server_parser(std::vector<std::string> block);
	~server_parser();
	
	server_parser &operator=(server_parser const &src);


	//	Setters :
	bool						set_directives(std::vector<std::string> tokens);
	bool						setPort(std::vector<std::string> tokens);
	bool						setHost(std::vector<std::string> tokens);
	bool						setNames(std::vector<std::string> tokens);
	bool						setErrorPages(std::vector<std::string> tokens);
	bool						setMaxSize(std::vector<std::string> tokens);
	void						setDefault();

	
	//	Getters :
	
	int							getMaxSzie();
	int							getPort();
	std::string					getHost();
	std::vector<std::string>    getNames();
	std::vector<std::string>    getErrorPages();
	std::vector<std::string>    getServerBlock();


};