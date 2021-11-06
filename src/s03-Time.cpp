#include <s03-Time.h>
#include <string>
#include <iostream>

auto time1::to_string() const -> std::string
{
	auto out = std::ostringstream{};
		std::string x;
		std::string y;
		std::string z;
	if (godzina<10)
		{x = "0";}
	else {x = "";}

        if (minuta<10)
                {y = "0";}
        else {y = "";}

        if (sekunda<10)
                {z = "0";}
        else {z = "";}

	out << x << this->godzina << ":" << y << this->minuta << ":" << z << this->sekunda << "\n";

	return out.str();
}

time1::time1(int godzina, int minuta, int sekunda)
{
        this->godzina = godzina;
        this->minuta = minuta;
        this->sekunda = sekunda;
}

auto time1::next_hour() -> void
{
	if (godzina==23)
		{godzina = 0;}
	else
		godzina++;
}

auto time1::next_minute() -> void
{
	if (minuta==59)
		{minuta = 0;
		godzina++;}
	else
		minuta++;
}

auto time1::next_second() -> void
{
	if (sekunda==59)
		{sekunda = 0;
		minuta++;}
	else
		sekunda++;
}

auto time1::tod() const -> std::string
{
        auto out = std::ostringstream{};
		if (godzina < 6)
	{out << "night\n";}
		else if (godzina < 12)
	{out << "morning\n";}
		else if (godzina < 16)
	{out << "afternoon\n";}
		else if (godzina < 20)
	{out << "evening\n";}
		else
	{out << "evening\n";}
return out.str();
}


auto main() -> int
{
	auto s = time1{7, 13, 0};

	std::cout << s.to_string();
	s.next_hour();
	s.next_minute();
	s.next_second();
	std::cout << s.to_string();
	std::cout << s.tod();
}


