#include "ipv4.h"

int main()
{
	ipv4 a{};
	ipv4 b{};
	std::cin >> a >> b;
	if (!std::cin.fail())
	{
		for (ipv4 current = a; current <= b; current++)
		{
			std::cout << current << std::endl;
		}
	}
	else
	{
		std::cout << "Bad input" << std::endl;
	}
	return 0;
}