#include <sstream>
#include <string>

struct time1{

	int godzina;
	int minuta;
	int sekunda;
	time1(int, int, int);
	auto to_string() const -> std::string;
	auto next_hour() -> void;
	auto next_minute() -> void;
	auto next_second() -> void;
	auto tod() const -> std::string;
};



