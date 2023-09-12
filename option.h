#pragma once
#include <exception>
#include "event.h"
#include "birthday.h"
#include "anniversary.h"
#include "nameday.h"
#include "marriage.h"

//for displaying the introduction menu and ask for the user to select the options
int introduction();

//for reading the text and display it on the console
void read_the_file(std::string file);

//for displaying the database menu and ask for the user to select the options
void database();

//for printing the list of the event which is birthday, anniversary, nameday, or marriage
void print_list_event(std::multimap < std::string, Event* >& event, int& numOfEvent);

//for deleting an event from the database
void delete_event(std::multimap < std::string, Event* >& event, int& numOfEvent);

//for searching for the event from the database
void search_event(std::multimap < std::string, Event* >& event);



//loading function
//for loading the list of the Birthday on the console
void load_birthday(std::multimap < std::string, Event* >& event, int& numOfEvent);

//for loading the list of the Anniversary on the console
void load_anniversary(std::multimap < std::string, Event* >& event, int& numOfEvent);

//for loading the list of the Nameday on the console
void load_nameday(std::multimap < std::string, Event* >& event, int& numOfEvent);

//for loading the list of the Marriage on the console
void load_marriage(std::multimap < std::string, Event* >& event, int& numOfEvent);



//adding function
//for adding the Birthday into the database
void add_birthday(std::multimap < std::string, Event* >& event, int& numOfEvent);

//for adding the list of the Anniversary into the database
void add_anniversary(std::multimap < std::string, Event* >& event, int& numOfEvent);

//for adding the list of the Nameday into the database
void add_nameday(std::multimap < std::string, Event* >& event, int& numOfEvent);

//for adding the list of the Marriage into the database
void add_marriage(std::multimap < std::string, Event* >& event, int& numOfEvent);



//saving function
//for saving the Birthday into the database
void save_birthday(std::multimap <std::string, Event* >& event, int& numOfEvent);

//for saving the Anniversary into the database
void save_anniversary(std::multimap <std::string, Event* >& event, int& numOfEvent);

//for saving the Nameday into the database
void save_nameday(std::multimap <std::string, Event* >& event, int& numOfEvent);

//for saving the Marriage into the database
void save_marriage(std::multimap <std::string, Event* >& event, int& numOfEvent);