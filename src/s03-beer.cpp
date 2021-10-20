#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
if (argc<2)
	{std::cout << "nie podales liczby\n";
return 0;}
	int  a =std::stoi(argv[1]);
       std::cout << a << " bottles of beer on the wall" << a << " bottles of beer on the wall...\n";

do {
        std::cout << (a-1) << " bottles of beer on the wall" << a << " bottles of beer on the wall...\n";
	a--;
}
while (a!=0);
	std::cout << "No more bottles of beer on the wall, no more bottles of beer.Go to the store and buy some more, 99 bottles of beer on the wall..\n";
return 0;
}
