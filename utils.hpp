#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <map>


std::vector<std::string>        ft_split(std::string str, std::string delim);
bool                            is_empty(std::string str);
void                            print_vector(std::vector<std::string> vc);
bool                            is_serverline(std::string str);