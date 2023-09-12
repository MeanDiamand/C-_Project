#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <map>


class Event
{
	//based class attributes
	std::string category;
	std::string name;
public:
	//default constructor
	Event();

	//setter methods for setting a value to each attribute of the Event class
	void set_category(std::string c);
	void set_name(std::string n);

	//getter methods for getting the value of each attribute of Event class
	std::string get_category() const;
	std::string get_name() const;

	//virtual methods for accessing the methods of derived classes
	virtual void save_database(std::ostream& os);
	virtual void load_database(std::istream& is);
	virtual std::ostream& print_event(std::ostream& os) const;
	virtual void input_event(std::istream& is);
	virtual bool operator==(const Event& other);

	//Birthday and Nameday classes
	//setter virtual methods
	virtual void set_year(int y);
	virtual void set_month(int m);
	virtual void set_day(int d);

	//getter virtual methods
	virtual int get_year() const;
	virtual int get_month() const;
	virtual int get_day() const;

	//Anniversary and Marriage classes
	//setter virtual methods
	virtual void set_partner(std::string p);

	//getter virtual methods
	virtual std::string get_partner() const;
};

//operator overloading for printing the data of all the Event attributes
std::ostream& operator<<(std::ostream& os, const Event* other);

//operator overloading for inputting the data for Event attributes
std::istream& operator>>(std::istream& is, Event* other);