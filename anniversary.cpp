#include "anniversary.h"

//default constructor
Anniversary::Anniversary() : Event()
{
	partner = "";
	year = 0;
	month = 0;
	day = 0;
}

//setter methods
void Anniversary::set_partner(std::string p)
{
	partner = p;
}

void Anniversary::set_year(int y)
{
	year = y;
}

void Anniversary::set_month(int m)
{
	month = m;
}

void Anniversary::set_day(int d)
{
	day = d;
}

//getter methods
std::string Anniversary::get_partner() const
{
	return partner;
}

int Anniversary::get_year() const
{
	return year;
}

int Anniversary::get_month() const
{
	return month;
}

int Anniversary::get_day() const
{
	return day;
}

//print method
std::ostream& Anniversary::print_event(std::ostream& os) const
{
	os << " | " << get_partner() << " | " << get_month() << "/" << get_day() << "/" << get_year() << std::endl;
	return os;
}

//input method
void Anniversary::input_event(std::istream& is)
{
	std::string p;
	std::cout << "Partner: ";
	is >> p;
	set_partner(p);

	int m, d, y;
	std::cout << "Date(MM DD YYYY): ";
	is >> m >> d >> y;
	set_month(m);
	set_day(d);
	set_year(y);
}

//save method
void Anniversary::save_database(std::ostream& os)
{
	os << get_name() << std::endl;
	os << get_partner() << std::endl;
	os << get_category() << std::endl;
	os << get_month() << std::endl;
	os << get_day() << std::endl;
	os << get_year() << std::endl;
}

//insert method
void Anniversary::load_database(std::istream& is)
{
	std::string n;
	is >> n;

	std::string p;
	is >> p;

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
		this->set_partner(p);
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
bool Anniversary::operator==(const Event* other)
{
	if (this->get_name() != other->get_name())
	{
		return false;
	}
	if (this->get_partner() != other->get_partner())
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