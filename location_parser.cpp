#include "location_parser.hpp"

location_parser::location_parser()
{

}

location_parser::~location_parser()
{

}

location_parser &location_parser::operator=(location_parser const &src){
	if(this == &src)
		return *this;
	auto_index = src.auto_index;
	location_path = src.location_path;
	root_path = src.root_path;
	upload_path = src.upload_path;
	cgi_path = src.cgi_path;
	accepted_requests = src.accepted_requests;
	index = src.index;
	redirection = src.redirection;
	_locationBlock = src._locationBlock;

	return *this;

}

bool	location_parser::set_locationdirectives(std::vector<std::string> tokens)
{

}

location_parser::location_parser(std::vector<std::string> block) : _locationBlock(block)
{
	std::vector<std::string>                tokens;
	
	
	std::vector<std::string>::iterator      it = _locationBlock.begin() + 1;
	for(; it != _locationBlock.end(); it++)
	{
		if(is_locationline(*it))
		{
			tokens = ft_split(*it, "	 ");
			if(!set_locationdirectives(tokens))
				throw "File Error : set a location directive failed !!";
		}
		else
			throw ("File Error: location line identation not valid !!");
	}
}