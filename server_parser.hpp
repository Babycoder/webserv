#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

class server_parser
{
    private :
        std::string host;
        std::string port;
        std::vector<std::string> names;
        std::vector<std::string> error_pages;
       // std::vector<location> locations;
        int clientMaxBodySize;

    public :
    std::vector<std::string> _serverBlock;
    //std::vector<>

   // server_parser();
    
    //~server_parser();

};