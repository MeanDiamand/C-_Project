#include "birthday.h"

//default contructor
Birthday::Birthday() : Event()
{
	year = 0;
	month = 0;
	day = 0;
}

//setter methods
void Birthday::set_year(int y)
{
	year = y;	
}

void Birthday::set_month(int m)
{
	month = m;
}

void Birthday::set_day(int d)
{
	day = d;
}

//getter methods
int Birthday::get_year() const
{
	return year;
}

int Birthday::get_month() const
{
	return month;
}

int Birthday::get_day() const
{
	return day;
}

//print method
std::ostream& Birthday::print_event(std::ostream& os) const
{
	os << " | " << get_month() << "/" << get_day() << "/" << get_year() << std::endl;
	return os;
}

//input method
void Birthday::input_event(std::istream& is) 
{
	int m, d, y;
	std::cout << "Date(MM DD YYYY): ";
	is >> m >> d >> y;
	set_month(m);
	set_day(d);
	set_year(y);
}

//save method
void Birthday::save_database(std::ostream& os)
{
	os << get_name() << std::endl;
	os << get_category() << std::endl;
	os << get_month() << std::endl;
	os << get_day() << std::endl;
	os << get_year() << std::endl;
}

//load method
void Birthday::load_database(std::istream& is)
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
bool Birthday::operator==(const Event* other)
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