#include <sstream>
#include <string>

struct student{

	std::string imie;
	std::string nazwisko;
	std::string index;
	int rok;
	int ocena;
	student(std::string, std::string, std::string, int, int);
	auto to_string() const -> std::string;
};



