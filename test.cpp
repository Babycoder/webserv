#include "utils.hpp"
#include "request_parser.hpp"

int     main()
{


	std::string str = "DELETE /path?query1=val&query2=val&query3=val&query4=val HTTP/1.1\r\n";
	std::string str2 = "headkey1: value\r\nheadkey2: value\r\nheadkey3: value\r\nheadkey4: value";
	std::string str3 = "\r\nTransfer-Encoding: chunked\r\n\r\n26\r\nVoici les données du premier morceau\r\n";

	request_parser obj;

	obj.sendLine(str);
	obj.sendLine(str2);
	obj.sendLine(str3);
	obj.sendLine("26\r\nVoici les données du premier morceau\r\n");
	obj.sendLine("1C\r\net voici un second morceau\r\n");
	obj.sendLine("12\r\nsans saut de ligne\r\n0\r\n\r\n");
	
	
	// obj.sendLine("\n1body body body body body body body body body body body body body body body body body1\n");
	// obj.sendLine("\n2body body body body body body body body body body body body body body body body body2\n");
	// obj.sendLine("\n3body body body body body body body body body body body body body body body body body3\n");
	// obj.sendLine("\n4body body body body body body body body body body body body body body body body body4\n");

	//std::vector<std::string> tokens = ft_split(obj.requestHeader, "\r\n");
	//print_vector(tokens);

	//std::cout << "================\n" << obj.reserve << "\n===============\n";

	// std::cout << obj.getVersion() << std::endl;

	return 0;
}	