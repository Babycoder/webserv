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

        file.open(av[1], std::ios::in);
        if(file.is_open())
        {
            while (getline(file, line))
            {
                std::cout << line << std::endl;
            }
            file.close();
        }   
        else
        {
            std::cerr << "Please enter a valid config file" << std::endl;
            return 1;
        }

    }
    else
    {
        std::cerr << "Please enter a valid config file" << std::endl;
        return 1;
    }
    return 0;
}



