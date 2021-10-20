#include <iostream>
#include <string>
#include <random>

auto main() -> int
{
	std::random_device rd;
	std::uniform_int_distribution<int> d100 (1, 100);

	auto const a = d100(rd);
	int  b;
	std::cout << a << "\n"; //wyświetla szukana liczbe
do {
	std::cout << "guess:\n";
	std::cin >> b;
	if (b>a)
		{std::cout << "too big\n";}
	else if (b<a)
		{std::cout << "too small\n";}
}
while (a!=b);
std::cout << "just right!\n";
return 0;
}
