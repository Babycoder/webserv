#pragma once

#include "utils.hpp"

class location_parser
{
	private :
		bool							auto_index;
		std::string						location_path;
		std::string						root_path;
		std::string						upload_path;
		std::string						cgi_path;
		std::vector<std::string>		accepted_requests;
		std::vector<std::string>		index;
		std::pair<int, std::string>		redirection;

		std::vector<std::string>		_locationBlock;


	public :
		

		location_parser();
		location_parser(std::vector<std::string> block);
		~location_parser();
		
		bool	set_locationdirectives(std::vector<std::string> tokens);

		location_parser &operator=(location_parser const &src);

};