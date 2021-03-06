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
	this-> sekunda = sekunda;;
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


    auto time1::count_seconds() const -> std::uint64_t {
        std::uint64_t count = 0;
        count += godzina * 60 * 60;
        count += minuta * 60;
        count += sekunda;
        return count;
    }

    auto time1::count_minutes() const -> std::uint64_t {
        std::uint64_t count = 0;
        count += godzina * 60;
        count += minuta;
        return count;
    }	

    auto ttm(time1 czas) -> time1
{
	auto time=time1{0, 0, 0};
	time.sekunda = 60 - czas.sekunda;

	if(time.sekunda > 0)
	time.minuta = 59 - czas.minuta;
	else
	time.minuta = 60 - czas.minuta;

	if(time.minuta > 0)
	time.godzina = 23 - czas.godzina;
	else
	time.minuta = 24 - czas.godzina;

	return time;

}

    auto time1::operator+ (time1 const& o) const -> time1 {
        unsigned short g = godzina;
        unsigned short m = minuta;
        unsigned short s = sekunda;
        s += o.sekunda;
        if(s > 59) {
            s -= 60;
            m++;
        }
        m += o.minuta;
        if(m > 59) {
            m -= 60;
            g++;
        }
        g += o.godzina;
        if(g > 23)
            g -= 24;

        return time1(g, m, s);
    }

    auto time1::operator- (time1 const& o) const -> time1 {
        short g = godzina;
        short m = minuta;
        short s = sekunda;
        s -= o.sekunda;
        if(s < 0) {
            s += 60;
            m--;
        }
        m -= o.minuta;
        if(m < 0) {
            m += 60;
            g--;
        }
        g -= o.godzina;
        if(g < 0)
            g += 24;

        return time1(g, m, s);
    }

    auto time1::operator< (time1 const& o) const -> bool {
        if(godzina < o.godzina)
            return true;
        if(godzina != o.godzina)
            return false;
        if(minuta < o.minuta)
            return true;
        if(minuta != o.minuta)
            return false;
        if(sekunda < o.sekunda)
            return true;
        if(sekunda != o.minuta)
            return false;
        return false;
    }

    auto time1::operator> (time1 const& o) const -> bool {
        if(godzina > o.godzina)
            return true;
        if(godzina != o.godzina)
            return false;
        if(minuta > o.minuta)
            return true;
        if(minuta != o.minuta)
            return false;
        if(sekunda > o.sekunda)
            return true;
        if(sekunda != o.minuta)
            return false;
        return false;
    }

    auto time1::operator== (time1 const& o) const -> bool {
        return (godzina==o.godzina && minuta==o.minuta&&sekunda==o.sekunda);
    }

    auto time1::operator!= (time1 const& o) const -> bool {
        return !(godzina==o.godzina && minuta==o.minuta&&sekunda==o.sekunda);
    }

auto main() -> int
{
	auto s = time1{1, 1, 0};


	std::cout << s.to_string();
        s.count_minutes();
        s.count_seconds();
        std::cout << s.tod();
    std::cout << "seconds: " << s.count_seconds() << "\n";
    std::cout << "minutes: " << s.count_minutes() << "\n";

	s.next_hour();
	s.next_minute();
	s.next_second();
	std::cout << s.to_string();
	std::cout << s.tod();

	s.count_minutes();
	s.count_seconds();
    std::cout << "seconds: " << s.count_seconds() << "\n";
    std::cout << "minutes: " << s.count_minutes() << "\n";
	std::cout << "time to midnight" <<  ttm(s).to_string() << "\n";
}


