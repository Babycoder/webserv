#pragma once

#include "utils.hpp"

class request_parser
{
	private:

		// Directives :
		std::string                         error;
		std::string                         methode;
		std::string                         path;
		std::string                         queries;
		std::string                         version;
		std::map<std::string, std::string>  headers;
		std::string                         bodyFile;
		//server_parser						serv;

		
		// Variables;

		std::string							requestHeader;
		std::string							reserve;
		int									in_body;
		int									bodyLength;
		bool								status;

	
	
	public:

		request_parser();
		~request_parser();
		request_parser &operator=(request_parser const &src);
		
		void								sendLine(char *line);

		
		
		
		// Getters :
		
		std::string                         getError() { return error; }
		std::string                         getMethode() { return methode; }
		std::string                         getPath() { return path; }
		std::string                         getQueries() { return queries; }
		std::string                         getVersion() { return version; }
		std::map<std::string, std::string>  getHeaders() { return headers; }
		std::string                         getBodyFile() { return bodyFile;}
		bool								getStatus(){return status; }
		//server_parser                       getServer() { return serv; }
};