#include "nameday.h"

//default constructor
Nameday::Nameday() : Event()
{
	year = 0;
	month = 0;
	day = 0;
}

//setter methods
void Nameday::set_year(int y)
{
	year = y;
}

void Nameday::set_month(int m)
{
	month = m;
}

void Nameday::set_day(int d)
{
	day = d;
}

//getter methods
int Nameday::get_year() const
{
	return year;
}

int Nameday::get_month() const
{
	return month;
}

int Nameday::get_day() const
{
	return day;
}

//print method
std::ostream& Nameday::print_event(std::ostream& os) const
{
	os << " | " << get_month() << "/" << get_day() << "/" << get_year() << std::endl;
	return os;
}

//input method
void Nameday::input_event(std::istream& is)
{
	int m, d, y;
	std::cout << "Date(MM DD YYYY): ";
	is >> m >> d >> y;
	set_month(m);
	set_day(d);
	set_year(y);
}

//save method
void Nameday::save_database(std::ostream& os)
{
	os << get_name() << std::endl;
	os << get_category() << std::endl;
	os << get_month() << std::endl;
	os << get_day() << std::endl;
	os << get_year() << std::endl;
}

//insert method
void Nameday::load_database(std::istream& is)
{
	std::string n;
	is >> n;

	std::string c;
	is >> c;

	int m;
	is >> m;

	int d;
	is >> d;

	int y;
	is >> y;

	if (is)
	{
		this->set_name(n);
		this->set_category(c);
		this->set_month(m);
		this->set_day(d);
		this->set_year(y);
	}
	else
	{
		std::cout << "Wrong format detected!!!" << std::endl;
	}
}

//operator overloading
bool Nameday::operator==(const Event* other)
{
	if (this->get_name() != other->get_name())
	{
		return false;
	}
	if (this->get_category() != other->get_category())
	{
		return false;
	}
	if (this->get_year() != other->get_year())
	{
		return false;
	}
	if (this->get_month() != other->get_year())
	{
		return false;
	}
	if (this->get_day() != other->get_year())
	{
		return false;
	}
}