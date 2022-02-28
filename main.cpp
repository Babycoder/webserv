#include "parser.hpp"
#include "request_parser.hpp"
#include "server_parser.hpp"
#include <fstream>
#include <string>
#include <iostream>


int     main(int ac , char *av[])
{

    if (ac == 2)
    {
        std::fstream file;
        std::string line;
        server_parser obj;
        bool in_block = 0;

        file.open(av[1], std::ios::in);
        if(file.is_open())
        {
            while (getline(file, line))
            {
                if(line == "server" || in_block == 1)
                {
                    in_block = 1;
                    obj._serverBlock.push_back(line);
                }
            }
            file.close();
        }
        else
        {
            std::cerr << "Please enter a valid config file" << std::endl;
            return 1;
        }
        std::vector<std::string>::iterator it = obj._serverBlock.begin();
        for(;it != obj._serverBlock.end(); it++)
            std::cout << *it << std::endl;

    }
    else
    {
        std::cerr << "Please enter a valid config file" << std::endl;
        return 1;
    }
    return 0;
}



