#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
if (argc<2)
	{std::cout << "nie podales liczby\n";
return 0;}
	int  a =std::stoi(argv[1]);
do {
        std::cout << a << ":";
	if (a%3==0) std::cout << "Fizz";
	if (a%5==0) std::cout << "Buzz";
	a=a-1;
	std::cout << "\n";
}
while (a!=0);
return 0;
}
