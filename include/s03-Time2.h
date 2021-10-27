#include <sstream>
#include <string>

struct time2{

	int godzina;
	int minuta;
	int sekunda;
	time2(int, int, int);
	auto to_string() const -> std::string;
};



