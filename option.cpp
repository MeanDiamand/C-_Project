#include "option.h"

//exeption handling
//checking if there is any error when opening the text file or not
class errorfile : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Error occurs while opening text file";
    }
}errorfile;

//function
int introduction()
{
    system("cls");
    //Read the text file using file handling
    std::string line;
    //specify the text file name
    std::ifstream myfile("introduction.txt");

    //opening the text file and read from it
    if (myfile.is_open()) 
    {
        while (getline(myfile, line)) 
        {
            std::cout << line << std::endl;
        }
        myfile.close();
    }
    //throw the exception if the file can't be open
    else 
    {
        throw errorfile;
    }
    //asking the user to input their choices
    int choice;
    std::cout << std::endl << std::endl << "Please input your option: ";
    std::cin >> choice;
    return choice;
}

void read_the_file(std::string file)
{
    //Read the text file using file handling
    std::string line;
    std::ifstream myfile(file);

    //opening the text file and read from it
    if (myfile.is_open()) 
    {
        while (getline(myfile, line)) 
        {
            std::cout << line << std::endl;
        }
        myfile.close();
    }
    //throw the exception if the file can't be open
    else 
    {
        throw errorfile;
    }

    //hold the output
    int b = 1;
    while (b != 6)
    {
        std::cout << std::endl << std::endl << "Input 6 to go back" << std::endl;
        std::cin >> b;
    }
}

void database()
{
    //variables for keeping track of the number of the event of each map
    int numB = 0;
    int numA = 0;
    int numN = 0;
    int numM = 0;

    //Multimap Declaration
    std::multimap<std::string, Event*>birthday;
    std::multimap<std::string, Event*>anniversary;
    std::multimap<std::string, Event*>nameday;
    std::multimap<std::string, Event*>marriage;

    //loading the information that stored in the text file into the program and checking if the file can be open and close or not
    try
    {
        load_birthday(birthday, numB);
    }
    catch (std::exception& file)
    {
        std::cerr << file.what() << std::endl;
    }  
    try
    {
        load_anniversary(anniversary, numA);
    }
    catch (std::exception& file)
    {
        std::cerr << file.what() << std::endl;
    }
    try
    {
        load_nameday(nameday, numN);
    }
    catch (std::exception& file)
    {
        std::cerr << file.what() << std::endl;
    }
    try
    {
        load_marriage(marriage, numM);
    }
    catch (std::exception& file)
    {
        std::cerr << file.what() << std::endl;
    }

    //database option menu
    int opd=100;
    while (opd != 0)
    {
        system("cls");
        std::cout << "____________________________________________________________________" << std::endl;
        std::cout << "___  __ \\__    |__  __/__    |__  __ )__    |_  ___/__  ____/_  ___/" << std::endl;
        std::cout << "__  / / /_  /| |_  /  __  /| |_  __  |_  /| |____ \\__  __/  _____ \\ " << std::endl;
        std::cout << "_  /_/ /_  ___ |  /   _  ___ |  /_/ /_  ___ |___/ /_  /___  ____/ / " << std::endl;
        std::cout << "/_____/ /_/  |_/_/    /_/  |_/_____/ /_/  |_/____/ /_____/  /____/  " << std::endl;
        std::cout << std::endl << "   1. Add Birthday" << std::endl;
        std::cout << "   2. Add Anniversary" << std::endl;
        std::cout << "   3. Add Nameday" << std::endl;
        std::cout << "   4. Add Marriage" << std::endl;
        std::cout << "   5. Delete Birthday" << std::endl;
        std::cout << "   6. Delete Anniversary" << std::endl;
        std::cout << "   7. Delete Nameday" << std::endl;
        std::cout << "   8. Delete Marriage" << std::endl;
        std::cout << "   9. Search Birthday" << std::endl;
        std::cout << "  10. Search Anniversary" << std::endl;
        std::cout << "  11. Search Nameday" << std::endl;
        std::cout << "  12. Search Marriage" << std::endl;
        std::cout << "  13. List of Birthday Database" << std::endl;
        std::cout << "  14. List of Anniversary Database" << std::endl;
        std::cout << "  15. List of Nameday Database" << std::endl;
        std::cout << "  16. List of Marriage Database" << std::endl;
        std::cout << "   0. Back" << std::endl;
        std::cin >> opd;
        switch (opd)
        {
        case 1:
            try
            {
                add_birthday(birthday, numB);
            }
            catch (std::bad_alloc&)
            {
                std::cout << "Memory Allocation Failure!!!" << std::endl;
            }
            break;
        case 2:
            try
            {
                add_anniversary(anniversary, numA);
            }
            catch (std::bad_alloc&)
            {
                std::cerr << "Memory Allocation Failure!!!" << std::endl;
            }
            break;
        case 3:
            try
            {
                add_nameday(nameday, numN);
            }
            catch (std::bad_alloc&)
            {
                std::cerr << "Memory Allocation Failure!!!" << std::endl;
            }
            break;
        case 4:
            try
            {
                add_marriage(marriage, numM);
            }
            catch (std::bad_alloc&)
            {
                std::cerr << "Memory Allocation Failure!!!" << std::endl;
            }
            break;
        case 5:
            delete_event(birthday, numB);
            break;
        case 6:
            delete_event(anniversary, numA);
            break;
        case 7:
            delete_event(nameday, numN);
            break;
        case 8:
            delete_event(marriage, numM);
            break;
        case 9:
            search_event(birthday);
            break;
        case 10:
            search_event(anniversary);
            break;
        case 11:
            search_event(nameday);
            break;
        case 12:
            search_event(marriage);
            break;
        case 13:
            print_list_event(birthday, numB);
            break;
        case 14:
            print_list_event(anniversary, numA);
            break;
        case 15:
            print_list_event(nameday, numN);
            break;
        case 16:
            print_list_event(marriage, numM);
            break;
        default:
           std::cout << "Please choose the available options" << std::endl;
        }
    }

    //saving the information of the map into the text file and checking if file can be open and close or not 
    try
    {
        save_birthday(birthday, numB);
    }
    catch (std::exception& file)
    {
        std::cout << file.what() << std::endl;
    }
    try
    {
        save_anniversary(anniversary, numA);
    }
    catch (std::exception& file)
    {
        std::cout << file.what() << std::endl;
    }
    try
    {
        save_nameday(nameday, numN);
    }
    catch (std::exception& file)
    {
        std::cout << file.what() << std::endl;
    }
    try
    {
        save_marriage(marriage, numM);
    }
    catch (std::exception& file)
    {
        std::cout << file.what() << std::endl;
    }
}

void print_list_event(std::multimap < std::string, Event* >& event, int& numOfEvent)
{
    system("cls");
    std::cout << "____________    __________________   ___________" << std::endl;
    std::cout << "___  ____/_ |  / /__  ____ / __   | / /__   __ /" << std::endl;
    std::cout << "__   __/ __ | / /__  __/   __     |/ /__   /" << std::endl;
    std::cout << "_   /___ __ |/ / _  /___  _    / |  / _   / " << std::endl;
    std::cout << "/ _____/ _____/  /_____/    /_/  |_/  /_ /" << std::endl << std::endl;
    std::cout << "List of the Event:" << std::endl;
    if (numOfEvent == 0)
    {
        std::cout << std::endl << "Empty List!!!" << std::endl;
    }
    else
    {
        for (auto i = event.begin(); i != event.end(); i++)
        {
            std::cout << i->second;
        }
    }
    
    //hold the output
    int b = 1;
    while (b != 6)
    {
        std::cout << std::endl << std::endl << "Input 6 to go back" << std::endl;
        std::cin >> b;
    }
}

void delete_event(std::multimap<std::string, Event*>& event, int& numOfEvent)
{
    system("cls");
    std::cout << "_________________________________________________" << std::endl;
    std::cout << "___  __ \\__  ____/__  /___  ____/__  __/__  ____/" << std::endl;
    std::cout << "__  / / /_  __/  __  / __  __/  __  /  __  __/   " << std::endl;
    std::cout << "_  /_/ /_  /___  _  /___  /___  _  /   _  /___   " << std::endl;
    std::cout << "/_____/ /_____/  /_____/_____/  /_/    /_____/   " << std::endl << std::endl;

    std::cout << "List of Event:" << std::endl;
    if (numOfEvent == 0)
    {
        std::cout << "No Event" << std::endl;
    }
    else
    {
        for (auto i = event.begin(); i != event.end(); i++)
        {
            std::cout << i->second;
        }

        std::cout << "Input the name of the person that you want to delete: ";
        std::string name;
        std::cin >> name;

        auto range = event.equal_range(name);
        int deletedEvents = 0;
        for (auto i = range.first; i != range.second; i++)
        {
            delete i->second;
            ++deletedEvents;
        }
        event.erase(range.first, range.second);
        numOfEvent -= deletedEvents;

        if (deletedEvents == 0)
        {
            std::cout << "Event not found!!!" << std::endl;
        }
        else
        {
            std::cout << "Result after deleting the information:" << std::endl;
            for (auto i = event.begin(); i != event.end(); i++)
            {
                std::cout << i->second;
            }
        }
    }

    //hold the output
    int b = 1;
    while (b != 6)
    {
        std::cout << std::endl << std::endl << "Input 6 to go back" << std::endl;
        std::cin >> b;
    }
}

void search_event(std::multimap < std::string, Event* >& event)
{
    system("cls");
    std::cout << "_____________________________________________  __" << std::endl;
    std::cout << "__  ___/__  ____/__    |__  __ \\_  ____/__  / / /" << std::endl;
    std::cout << "_____ \\__  __/  __  /| |_  /_/ /  /    __  /_/ /" << std::endl;
    std::cout << "____/ /_  /___  _  ___ |  _, _// /___  _  __  /" << std::endl;
    std::cout << "/____/ /_____/  /_/  |_/_/ |_| \\____/  /_/ /_/" << std::endl << std::endl;

    //ask the user to input the name of the owner of the event
    std::cout << "Input the name of the person that you want to search: ";
    std::string name;
    std::cin >> name;

    //a variable to check if the event is found or not
    bool f = false;

    std::cout << "Result of the searching information:" << std::endl;
    for (auto i = event.begin(); i != event.end(); i++)
    {
        if (i->second->get_name() == name)
        {
            std::cout << i->second;
            f = true;
        }
    }

    //if the event couldn't be found
    if (f == false)
    {
        std::cout << "Event not found!!!" << std::endl;
        //hold the output
        int b = 1;
        while (b != 6)
        {
            std::cout << std::endl << std::endl << "Input 6 to go back" << std::endl;
            std::cin >> b;
        }
    }

    //hold the output
    int b = 1;
    while (b != 6)
    {
        std::cout << std::endl << std::endl << "Input 6 to go back" << std::endl;
        std::cin >> b;
    }
}

void load_birthday(std::multimap < std::string, Event*>& event, int& numOfEvent)
{
    std::string line;
    std::ifstream myfile("Birthday_List.txt");

    if (!myfile.is_open())
    {
        throw errorfile;
    }

    else
    {
        //Check the number of the event
        myfile >> numOfEvent; 

        for (int i = 0; i < numOfEvent; i += 1)
        {
            Event* other = new Birthday;
            other->load_database(myfile);
            event.insert(std::pair < std::string, Event*>(other->get_name(), other));
        }
        myfile.close();
    }
}

void load_anniversary(std::multimap < std::string, Event*>& event, int& numOfEvent)
{
    std::string line;
    std::ifstream myfile("Anniversary_List.txt");

    if (!myfile.is_open())
    {
        throw errorfile;
    }
    else
    {
        //Check the number of the event
        myfile >> numOfEvent;

        for (int i = 0; i < numOfEvent; i += 1)
        {
            Event* other = new Anniversary;
            other->load_database(myfile);
            event.insert(std::pair < std::string, Event*>(other->get_name(), other));
        }
        myfile.close();
    }    
}

void load_nameday(std::multimap < std::string, Event*>& event, int& numOfEvent)
{
    std::string line;
    std::ifstream myfile("Nameday_List.txt");

    if (!myfile.is_open())
    {
        throw errorfile;
    }
    else
    {
        //Check the number of the event
        myfile >> numOfEvent;

        for (int i = 0; i < numOfEvent; i += 1)
        {
            Event* other = new Nameday;
            other->load_database(myfile);
            event.insert(std::pair < std::string, Event*>(other->get_name(), other));
        }
        myfile.close();
    }
}

void load_marriage(std::multimap < std::string, Event*>& event, int& numOfEvent)
{
    std::string line;
    std::ifstream myfile("Marriage_List.txt");

    if (!myfile.is_open())
    {
        throw errorfile;
    }
    else
    {
        //Check the number of the event
        myfile >> numOfEvent;

        for (int i = 0; i < numOfEvent; i += 1)
        {
            Event* other = new Marriage;
            other->load_database(myfile);
            event.insert(std::pair < std::string, Event*>(other->get_name(), other));
        }
        myfile.close();
    }    
}

void add_birthday(std::multimap < std::string, Event* >& event, int& numOfEvent)
{
    //create new event
    Event* other = new Birthday;
    //input new event
    std::cin >> other;

    Birthday* other_info = (Birthday*)other;
    //checking if the event of the person is already existed
    bool exist = false;
    //iterating through the map
    for (auto i = event.begin(); i != event.end(); i++)
    {
        if (*other_info == i->second)
        {
            exist = true;
        }
    }
    if (exist == false)
    {
        event.insert(std::pair < std::string, Event* >(other->get_name(),other));
        numOfEvent += 1;
    }

    //hold the output
    int b = 1;
    while (b != 6)
    {
        std::cout << std::endl << std::endl << "Input 6 to go back" << std::endl;
        std::cin >> b;
    }
}

void add_anniversary(std::multimap < std::string, Event* >& event, int& numOfEvent)
{
    //create new event
    Event* other = new Anniversary;
    //input new event
    std::cin >> other;

    Anniversary* other_info = (Anniversary*)other;
    //checking if the event of the person is already existed
    bool exist = false;
    //iterating through the map
    for (auto i = event.begin(); i != event.end(); i++)
    {
        if (*other_info == i->second)
        {
            exist = true;
        }
    }
    if (exist == false)
    {
        event.insert(std::pair < std::string, Event* >(other->get_name(), other));
        numOfEvent += 1;
    }

    //hold the output
    int b = 1;
    while (b != 6)
    {
        std::cout << std::endl << std::endl << "Input 6 to go back" << std::endl;
        std::cin >> b;
    }
}

void add_nameday(std::multimap < std::string, Event* >& event, int& numOfEvent)
{
    //create new event
    Event* other = new Nameday;
    //input new event
    std::cin >> other;

    Nameday* other_info = (Nameday*)other;
    //checking if the event of the person is already existed
    bool exist = false;
    //iterating through the map
    for (auto i = event.begin(); i != event.end(); i++)
    {
        if (*other_info == i->second)
        {
            exist = true;
        }
    }
    if (exist == false)
    {
        event.insert(std::pair < std::string, Event* >(other->get_name(), other));
        numOfEvent += 1;
    }
    
    //hold the output
    int b = 1;
    while (b != 6)
    {
        std::cout << std::endl << std::endl << "Input 6 to go back" << std::endl;
        std::cin >> b;
    }
}

void add_marriage(std::multimap < std::string, Event* >& event, int& numOfEvent)
{
    //create new event
    Event* other = new Marriage;
    //input new event
    std::cin >> other;

    Marriage* other_info = (Marriage*)other;
    //checking if the event of the person is already existed
    bool exist = false;
    //iterating through the map
    for (auto i = event.begin(); i != event.end(); i++)
    {
        if (*other_info == i->second)
        {
            exist = true;
        }
    }
    if (exist == false)
    {
        event.insert(std::pair < std::string, Event* >(other->get_name(), other));
        numOfEvent += 1;
    }
    
    //hold the output
    int b = 1;
    while (b != 6)
    {
        std::cout << std::endl << std::endl << "Input 6 to go back" << std::endl;
        std::cin >> b;
    }
}

void save_birthday(std::multimap <std::string, Event* >& event, int& numOfEvent)
{
    std::string line;
    std::ofstream myfile("Birthday_List.txt");

    if (myfile.is_open())
    {
        myfile << numOfEvent << std::endl;

        for (auto i = event.begin(); i != event.end(); i++)
        {
            i->second->save_database(myfile);
            delete i->second;
        }

        myfile.close();
    }
    else
    {
        throw errorfile;
    }
}

void save_anniversary(std::multimap <std::string, Event* >& event, int& numOfEvent)
{
    std::string line;
    std::ofstream myfile("Anniversary_List.txt");

    if (myfile.is_open())
    {
        myfile << numOfEvent << std::endl;

        for (auto i = event.begin(); i != event.end(); i++)
        {
            i->second->save_database(myfile);
            delete i->second;
        }
        myfile.close();
    }
    else
    {
        throw errorfile;
    }
}

void save_nameday(std::multimap <std::string, Event* >& event, int& numOfEvent)
{
    std::string line;
    std::ofstream myfile("Nameday_List.txt");

    if (myfile.is_open())
    {
        myfile << numOfEvent << std::endl;

        for (auto i = event.begin(); i != event.end(); i++)
        {
            i->second->save_database(myfile);
            delete i->second;
        }
        myfile.close();
    }
    else
    {
        throw errorfile;
    }
}

void save_marriage(std::multimap <std::string, Event* >& event, int& numOfEvent)
{
    std::string line;
    std::ofstream myfile("Marriage_List.txt");

    if (myfile.is_open())
    {
        myfile << numOfEvent << std::endl;

        for (auto i = event.begin(); i != event.end(); i++)
        {
            i->second->save_database(myfile);
            delete i->second;
        }
        myfile.close();
    }
    else
    {
        throw errorfile;
    }
}