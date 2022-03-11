#include "utils.hpp"
#include "request_parser.hpp"

int     main()
{


	std::string str = "DELETE /path?query1=val&query2=val&query3=val&query4=val HTTP/1.1\r\n";
	std::string str2 = "headkey1: value\r\nheadkey2: value\r\nheadkey3: value\r\nheadkey4: value";
	std::string str3 = "\r\nContent-Length: 686\r\n\r\nbody body body body body";

	request_parser obj;

	obj.sendLine(str);
	obj.sendLine(str2);
	obj.sendLine(str3);

	std::vector<std::string> tokens = ft_split(obj.requestHeader, "\r\n");
	print_vector(tokens);

	std::cout << "================\n" << obj.reserve << "\n===============\n";

	std::cout << obj.getMethode() << std::endl;

	return 0;
}	