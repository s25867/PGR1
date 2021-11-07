#include <sstream>
#include <string>

struct time1 {
	int g2;
	int m2;
	int s2;
	int godzina;
	int minuta;
	int sekunda;
    time1(int, int, int);
	auto to_string() const -> std::string;
	auto next_hour() -> void;
	auto next_minute() -> void;
	auto next_second() -> void;
	auto tod() const -> std::string;

    auto count_seconds() const -> std::uint64_t;
    auto count_minutes() const -> std::uint64_t;
    auto ttm() const -> time1;

	auto operator + ( time1 const &) const -> time1 ;
	auto operator - ( time1 const &) const -> time1 ;
	auto operator < ( time1 const &) const -> bool ;
	auto operator > ( time1 const &) const -> bool ;
	auto operator == ( time1 const &) const -> bool ;
	auto operator != ( time1 const &) const -> bool ;
};



