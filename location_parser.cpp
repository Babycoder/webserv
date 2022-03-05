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
	//redirection = src.redirection;
	_locationBlock = src._locationBlock;

	return *this;

}


bool		location_parser::setAutoIndex(std::vector<std::string> tokens)
{
	if(tokens.size() != 2)
		return false;
	if (tokens[1] == "on")
		auto_index = true;
	else if (tokens[1] == "off")
		auto_index = false;
	else
		return false;
	return true;
}

bool		location_parser::setLocationPath(std::vector<std::string> tokens)
{
	if(tokens.size() != 2)
		return false;
	location_path = tokens[1];
	
	return true;
}

bool		location_parser::setRootPath(std::vector<std::string> tokens)
{
	if(tokens.size() != 2)
		return false;
	root_path = tokens[1];

	return true;
}

bool		location_parser::setUploadPath(std::vector<std::string> tokens)
{
	if(tokens.size() != 2)
		return false;
	upload_path = tokens[1];

	return true;
}

bool		location_parser::setCgiPath(std::vector<std::string> tokens)
{
	if(tokens.size() != 2)
		return false;
	cgi_path = tokens[1];

	return true;
}

bool		location_parser::setAcceptedRequeasts(std::vector<std::string> tokens)
{
	if(tokens.size() < 2 || tokens.size() > 4)
		return false;
	
	std::vector<std::string>::iterator it = tokens.begin() + 1;

	for(; it != tokens.end() ; it++)
	{
		if (*it != "GET" || *it != "DELETE" || *it != "POST")
			return false;
		accepted_requests.push_back(*it);
	}

	return true;
}

bool		location_parser::setIndex(std::vector<std::string> tokens)
{
	if (tokens.size() < 2)
		return false;
	
	std::vector<std::string>::iterator it = tokens.begin() + 1;

	for(; it != tokens.end() ; it++)
		index.push_back(*it);
	
	return true;
}





bool	location_parser::set_locationdirectives(std::vector<std::string> tokens)
{
	bool res;

	if (tokens[0] == "auto_index")
		res = setAutoIndex(tokens);
	else if (tokens[0] == "location_path")
		res = setLocationPath(tokens);
	else if (tokens[0] == "root")
		res = setRootPath(tokens);
	else if (tokens[0] == "upload")
		res = setUploadPath(tokens);
	else if (tokens[0] == "cgi")
		res = setCgiPath(tokens);
	else if (tokens[0] == "requests")
		res = setAcceptedRequeasts(tokens);
	else if (tokens[0] == "index")
		res = setIndex(tokens);
	// else if (tokens[0] == "redirection")
	// 	res = setRedirection(tokens);
	else
		res = false;	
	return res;
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


bool							location_parser::getAutoIndex()
{
	return (auto_index);
}
std::string						location_parser::getLocationPath()
{
	return	(location_path);
}
std::string						location_parser::getRootPath()
{
	return (root_path);
}

std::string						location_parser::getUploadPath()
{
	return	(upload_path);
}

std::string						location_parser::getCgiPath()
{
	return (cgi_path);
}

std::vector<std::string>		location_parser::getAcceptedRequeasts()
{
	return (accepted_requests);
}

std::vector<std::string>		location_parser::getIndex()
{
	return (index);
}

// std::vector<std::string>		location_parser::getRedirection()
// {
// 	return ();
// }