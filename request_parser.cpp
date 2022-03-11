#include "request_parser.hpp"

request_parser::request_parser(){
	bodyFile = "requestBody.txt";
	status = false;
	stored = 0;
	in_body = 0;
	bodyLength = -42;
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


bool		request_parser::fillRequestHeader(std::string line)
{
	bool res = false;

	size_t pos = line.find("\r\n\r\n");

	if (pos != std::string::npos)
	{
		requestHeader += line.substr(0, pos);
		reserve += line.substr(pos + 4);
		in_body = 1;
		res = true;
	}
	else
	{
		requestHeader += line;
	}


	return res;
}

bool		request_parser::setPath(std::string token)
{
	std::vector<std::string> tokens = ft_split(token, "?");

	if (tokens.size() < 2)
	{
		path = token;
		return true;
	}
	else
	{
		path = tokens[0];
		queries = tokens[1];
		return true;
	}
	
	return false;
}

bool		request_parser::setVersion(std::string token)
{
	std::vector<std::string> tokens = ft_split(token, "/");

	if(tokens.size() == 2)
		version = tokens[1];
	else
		return false;
	
	return true;
}


bool		request_parser::setRequestLine(std::string token)
{

	bool res = true;

	std::vector<std::string> tokens = ft_split(token, " ");
	
	if (tokens.size() != 3)
		return false;
	
	if (tokens[0] == "GET" || tokens[0] == "POST" || tokens[0] == "DELETE")
		methode = tokens[0];
	else
		return false;

	if (!setPath(tokens[1]))
		return false;
	
	if(!setVersion(tokens[2]))
		return false;

	return true;	
}



bool		request_parser::set_requestDirectives(std::string	token)
{


	std::vector<std::string> tokens = ft_split(token, ": ");

	if(tokens.size() < 2)
		return false;

	headers[tokens[0]] = tokens[1];
	if(tokens[0] == "Content-Length")
		bodyLength = atoi(tokens[1].c_str());

	return true;
}



void				request_parser::sendLine(std::string _line)
{

	if (in_body == 0)
	{
		if (fillRequestHeader(_line))
		{
			std::vector<std::string> tokens = ft_split(requestHeader, "\r\n");
			std::vector<std::string>::iterator it = tokens.begin();

			if (!setRequestLine(*it))
				throw "Request Error: Request Line failed !!";
			it++;
			for(; it < tokens.end(); it++)
			{
				if(!set_requestDirectives(*it))
					throw "Request Error: Set Request Header failed !!";
			}
		}
	}
	else
	{
		if (bodyLength != -42)
		{
			std::fstream file;
			
			file.open(bodyFile, std::ios::app);
			if(file.is_open())
			{
				if(!reserve.empty())
				{
					_line = reserve + _line;
					reserve.clear();
				}
				if((_line.length() + stored) > bodyLength)
				{
					_line = _line.substr(0, (bodyLength - stored));
					status = true;
				}
				file << _line;
				stored += _line.length();
				std::cout << "Length of _line = " << _line.length() << std::endl;
				file.close();
			}

		}
		else
		{

		}
	}

}


