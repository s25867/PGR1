#include <sstream>
#include <string>

struct time1{

	int godzina;
	int minuta;
	int sekunda;
	time1(int, int, int);
	auto to_string() const -> std::string;
};



