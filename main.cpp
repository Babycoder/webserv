#include "parser.hpp"
#include "request_parser.hpp"
#include "server_parser.hpp"


int     main(int ac , char *av[])
{

    if (ac == 2)
    {
        std::cout << "All Good (y)" << std::endl;
    }
    else
    {
        std::cerr << "Please enter a valid config file" << std::endl;
        return 1;
    }
    return 0;
}