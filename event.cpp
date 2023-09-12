#include "event.h"


Event::Event()
{
	category = "";
	name = "";
}

//setter methods
void Event::set_category(std::string c)
{
	category = c;
}

void Event::set_name(std::string n)
{
	name = n;
}

//getter methods
std::string Event::get_category() const
{
	return category;
}

std::string Event::get_name() const
{
	return name;
}

//virtual methods from derived classes
void Event::save_database(std::ostream& os) {}
void Event::load_database(std::istream& is) {}

std::ostream& Event::print_event(std::ostream& os) const
{
	return os;
}

void Event::input_event(std::istream& is) {}

bool Event::operator==(const Event& other) 
{
	return false;
}

//setter methods
void Event::set_partner(std::string p) {}
void Event::set_year(int y) {}
void Event::set_month(int m) {}
void Event::set_day(int d) {}

//getter methods
std::string Event::get_partner() const
{
	return "";
}

int Event::get_year() const
{
	return 0;
}

int Event::get_month() const
{
	return 0;
}

int Event::get_day() const
{
	return 0;
}

//operator overloading
//output stream
std::ostream& operator<<(std::ostream& os, const Event* other)
{
	os << other->get_category() << " | " << other->get_name();
	
	other->print_event(os);

	return os;
}

//input stream
std::istream& operator>>(std::istream& is, Event* other)
{
	int c = 5;
	while (c > 4 || c < 1)
	{
		std::cout << "Category of the users:" << std::endl;
		std::cout << "1. Friend" << std::endl;
		std::cout << "2. Family" << std::endl;
		std::cout << "3. Relative" << std::endl;
		std::cout << "4. Colleague" << std::endl;
		is >> c;
		switch (c)
		{
		case 1:
			other->set_category("Friend");
			break;
		case 2:
			other->set_category("Family");
			break;
		case 3:
			other->set_category("Relative");
			break;
		case 4:
			other->set_category("Colleague");
			break;
		default:
			std::cout << "Please choose the available options" << std::endl;
			break;
		}
	}

	std::string n;
	std::cout << "Name: ";
	is >> n;
	other->set_name(n);

	other->input_event(is);

	return is;
}