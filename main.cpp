#include "event.h"
#include "option.h"
#include <fstream>

using namespace std;

int main() 
{
    //function for clearing the screen
    system("cls");

    int opt = 1;
    string file;
    while (opt != 5)
    {
        opt = introduction();
        switch (opt)
        {
        case 1:
            database();
            break;
        case 2:
            system("cls");
            file = "Help.txt";
            read_the_file(file);
            break;
        case 3:
            system("cls");
            file = "Credit.txt";
            read_the_file(file);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Please input the valid option!!!\n");
        }
    }
    return 0;
}
