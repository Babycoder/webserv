#include "utils.hpp"
#include "location_parser.hpp"


int     main()
{
	std::vector<std::string> block;

	block.push_back("	location");
	block.push_back("		auto_index on");
	location_parser _location(block);

	std::cout << _location.getAutoIndex() << std::endl;
	return 0;
}	