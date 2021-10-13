#include <iostream>
#include <string>

auto ask(std::string prompt) -> float
{
	std::cout << prompt << " =";
	auto a = std::string{};
	std::getline(std::cin, a);
	return std::stof(a);
}
auto main () -> int
{
auto const a = ask(" a ");
auto const b = ask(" b ");
if (b == 0)
{
std::cout << "You cannot divide by 0\n";
}
else
{
 std :: cout << ( a/b ) << " \n ";
return 0;
}}





