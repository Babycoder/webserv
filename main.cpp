#include "parser.hpp"
#include "server_parser.hpp"
#include "utils.hpp"


int     main(int ac , char *av[])
{

    if (ac == 2)
    {
        try
        {
            parser parser(av[1]);
            parser.display();
        }
        catch(const char *str)
        {
            std::cerr << str << std::endl;
            exit(1);
        }
    }
    else
    {
        std::cerr << "Please provide a config file" << std::endl;
        return 1;
    }
    return 0;
}

