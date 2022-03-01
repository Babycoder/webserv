#pragma once

#include "utils.hpp"

class parser {

	private :
		
		std::vector<std::string>	_block;
		std::string					_line;

	public :

		parser(std::string av);
		parser();
		~parser();

		parser &operator=(parser const &src);

		void	display();
		
};