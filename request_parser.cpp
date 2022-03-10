#include "request_parser.hpp"

request_parser::request_parser(){
	status = false;
	in_body = 0;
	bodyLength = 0;
}

request_parser::~request_parser(){

}

request_parser      &request_parser::operator=(request_parser const &src)
{
	if (this == &src)
		return *this;

	error =  src.error;
	methode = src.methode;
	path = src.path;
	queries = src.queries;
	headers = src.headers;
	bodyFile = src.bodyFile;
	status = src.status;
	in_body = src.in_body;
	bodyLength = src.bodyLength;

	return *this;
}



void				request_parser::sendLine(char *line)
{
	std::vector<std::string> lines;
	std::vector<std::string> tokens;
	std::vector<std::string>::iterator it;
	
	lines = ft_split(line, "\r\n");
	it = lines.begin();
	
	for(; it != lines.end(); it++)
	{
		if(in_body = 0)
		{
			tokens = ft_split(*it, " :");
		}
		else
		{

		}
	}



}


