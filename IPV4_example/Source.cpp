#include "ipv4.h"

int main()
{
	ipv4 a{};
	unsigned long number;
	std::cin >> a;
	if (!std::cin.fail())
	{
		std::cout << "Entered ip: " << a << std::endl;
		std::cout << "Actual number: " << a.to_ulong() << std::endl;
		std::cout << a.to_string() << std::endl;
	}
	else
	{
		std::cout << "Bad input" << std::endl;
	}
	return 0;
}