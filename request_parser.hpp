#pragma once

#include "utils.hpp"

class request_parser
{
    private:
        std::string                         error;
        //server_parser                       serv;
        std::string                         methode;
        std::string                         path;
        std::string                         queries;
        std::string                         version;
        std::map<std::string, std::string>  headers;
        std::string                         bodyFile;

    public:

    
        std::string                         getError() { return error; }
        //server_parser                       getServer() { return serv; }
        std::string                         getMethode() { return methode; }
        std::string                         getPath() { return path; }
        std::string                         getQueries() { return queries; }
        std::string                         getVersion() { return version; }
        std::map<std::string, std::string>  getHeaders() { return headers; }
        std::string                         getBodyFile() { return bodyFile; }
};