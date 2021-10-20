#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
if (argc<2)
	{std::cout << "nie podales liczby\n";
return 0;}
	int  a =std::stoi(argv[1]);
	std::cout << a << "...\n";
do {
	std::cout << (a-1) << "...\n";
	a=a-1;
}
while (a!=0);
return 0;
}
