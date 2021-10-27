#include <s03-Student.h>
#include <string>
#include <iostream>

auto student::to_string() const -> std::string
{
	auto out = std::ostringstream{};

	out << this->imie << " " << this->nazwisko << " " << this->index << " " << this->rok << " " << this->ocena << "\n";

	return out.str();
}

student::student(std::string imie, std::string nazwisko, std::string index, int rok, int ocena)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->index = index;
	this->rok = rok;
	this->ocena = ocena; 
}
auto main() -> int
{
	auto s = student{"Aleksander", "Bogdan", "25867", 1, 4};

	std::cout << s.to_string();

}


