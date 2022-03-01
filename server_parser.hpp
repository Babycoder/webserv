#pragma once

#include "utils.hpp"

class server_parser
{
    private :
        std::string host;
        std::string port;
        std::vector<std::string> names;
        std::vector<std::string> error_pages;
       // int clientMaxBodySize;
       // std::vector<location> locations;

    public :
    std::vector<std::string> _serverBlock;
    //std::vector<>

   // server_parser();
    
    //~server_parser();

};