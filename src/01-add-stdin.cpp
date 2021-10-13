#include <iostream>
#include <string>

auto ask(std::string prompt) -> int
{
	std::cout << prompt << " =";
	auto a = std::string{};
	std::getline(std::cin, a);
	return std::stoi(a);
}
auto main () -> int
{
auto const a = ask(" a ");
auto const b = ask(" b ");
std :: cout << ( a + b ) << " \n ";
return 0;
}
	




