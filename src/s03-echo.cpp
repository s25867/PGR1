#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
if (argc<2)
	{std::cout << "nie podales argumentu\n";
return 0;}
	std::string a = (argv[1]);
        std::cout << a << " \n";;
return 0;
}
