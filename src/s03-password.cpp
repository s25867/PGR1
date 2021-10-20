#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
if (argc<2)
{std::cout << "nie podales hasla\n";
return 0;}
	auto const a =argv[1];
	std::string b;
do {
std::cout << "podaj haslo\n";
std::getline(std::cin, b);
} while (a!=b);
std::cout << "ok!\n";
return 0;
}
