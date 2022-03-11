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

		int									in_body;
		bool								status;

	
	
	public:

		request_parser();
		~request_parser();
		request_parser &operator=(request_parser const &src);
		
		void								sendLine(std::string _line);

		
		std::string							requestHeader;
		std::string							chunkedBody;
		std::string							reserve;
		int									bodyLength;
		int									stored;
		
		
		// Getters :
		
		std::string                         getError() { return error; }
		std::string                         getMethode() { return methode; }
		std::string                         getPath() { return path; }
		std::string                         getQueries() { return queries; }
		std::string                         getVersion() { return version; }
		std::map<std::string, std::string>  getHeaders() { return headers; }
		std::string                         getBodyFile() { return bodyFile;}
		bool								getStatus(){return status; }
		//server_parser						getServer() { return serv; }


		// Setters :

		bool		fillRequestHeader(std::string line);
		bool		set_requestDirectives(std::string token);
		bool		setRequestLine(std::string token);
		bool		setPath(std::string token);
		bool		setVersion(std::string token);
		bool		fillChunkedBody(std::string line);


};