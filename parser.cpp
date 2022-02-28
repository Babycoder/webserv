#include "parser.hpp"

parser::parser(std::string av)
{
    bool in_block = 0;

    _file.open(av, std::ios::in);
    if(_file.is_open())
    {
        while (getline(_file, _line))
        {
            // if (_line != "server" && in_block == 0)
            // {
            //     error;
            // }
            if(_line == "server" || in_block == 1)
            {
                if (_line.empty() && in_block == 1)
                {
                    /*
                        int this scope i will create an object of server_parse and send the server block
                        set in_block to 0 => clear the _block 
                    */
                    in_block = 0;
                    break;
                }
                if (!_line.empty())
                {
                    in_block = 1;
                    _block.push_back(_line);
                }
            }
        }
        _file.close();
    }
    else
    {
        throw "Open config file Error";
    }

}

parser::~parser(){}


void    parser::display()
{
    std::vector<std::string>::iterator it = _block.begin();
    for(;it != _block.end(); it++)
        std::cout << *it << std::endl;
}
