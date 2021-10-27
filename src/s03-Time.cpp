#include <s03-Time2.h>
#include <s03-Time.h>
#include <string>
#include <iostream>

auto time1::to_string() const -> std::string
{
	auto out = std::ostringstream{};

	out << this->godzina << " :" << this->minuta << " :" << this->sekunda <<"\n";

	return out.str();
}

time1::time1(int godzina, int minuta, int sekunda)
{
        this->godzina = godzina;
        this->minuta = minuta;
        this->sekunda = sekunda;
}

// +1 godzina
//time1::time1(int godzina, int minuta, int sekunda)
//{
//	this->godzina = 1 + godzina;
//	this->minuta = 1 + minuta;
//	this->sekunda = 1 + sekunda;
//}
auto main() -> int
{
	auto s = time1{9, 50, 12};

	std::cout << s.to_string();

}


