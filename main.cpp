#include "parser.hpp"
#include "server_parser.hpp"
#include "utils.hpp"


int     main(int ac , char *av[])
{

    parser conf;

    if (ac == 2)
    {
        try
        {
            conf = parser(av[1]);

        }
        catch(const char *str)
        {
            std::cerr << str << std::endl;
            exit(1);
        }
        conf.display();
    }
    else
    {
        std::cerr << "Please provide a config file" << std::endl;
        return 1;
    }
    return 0;
}

