#pragma once

#include "utils.hpp"

class parser {

	private :
		
		std::vector<std::string>	_block;
		std::fstream				_file;
		std::string					_line;

	public :

		parser(std::string av);
		~parser();

		void	display();
		
};