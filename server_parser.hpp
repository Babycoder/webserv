#pragma once

#include "utils.hpp"

class server_parser
{
    private :
        std::string _linetest;
        std::string host;
        std::string port;
        std::vector<std::string> names;
        std::vector<std::string> error_pages;
        int clientMaxBodySizwe;
        std::vector<std::string> _serverBlock;
        
       // std::vector<location> locations;

    public :

    server_parser();
    server_parser(std::vector<std::string> block);
    ~server_parser();

    std::string     getlinetest();
    server_parser &operator=(server_parser const &src);

};