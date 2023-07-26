#include "splashkit.h"
#include "string.h"

using namespace std;

/*
A program that will allow the user to convert between different volume scales.

It shows the user a menu with two options,
     1: Gallons to Litres
     2: Litre to Gallons


The user chooses an option, and is then prompted for a vlaue to convert.
Based on the selection, the following conversions are used:

Gallons to Litres is calculated as Litres = Gallons * 3.78
Litres to Gallons is calculated as Gallons = Litres / 3.78

 
The users input, with the appropriate conversion applied, is then outputted to the screen.
*/

int read_integer(string prompt);
double read_double(string prompt);
void opening_menu();
double convert_gallons_to_litres();
double convert_litres_to_gallons();

int main()
{
    opening_menu();
    return 0;
}

// Presents user with a menu of options for conversion. Loops until an option is selected.
void opening_menu()
{
    int option = 0;

    write_line("\n----Conversion Menu Program----");
    write_line("Hi. I am a program that helps you convert between different volume scales.");
    
    do
    {
        write_line("You have the following options:\n");
        write_line("1. Gallons to Litres");
        write_line("2. Litres to Gallons\n");
       

        option = read_integer("What is your choice: ");        

        switch (option)
        {
            case 1:
                write_line("That's " + to_string(convert_gallons_to_litres()) + " many litres");
                break;

            case 2:
                write_line("That's " + to_string(convert_litres_to_gallons()) + " many litres");
                break;

            default:
                write_line("Sorry, please pick a valid option.");
        }         
    } while (option != 1 && option != 2);
}

int read_integer(string prompt)
{
    write(prompt);
    int new_int = convert_to_integer(read_line());
    return new_int;
}

double read_double(string prompt)
{
    write(prompt);
    int new_double = convert_to_double(read_line());
    return new_double;
}

double convert_gallons_to_litres()
{
    double in_litres = read_double("What is the amount of gallons you want to convert to litres: ");
    double in_gallons = in_litres * 3.78; 
    return in_gallons;
}

double convert_litres_to_gallons()
{
    double in_litres = read_double("What is the amount of litres you want to convert to gallons: ");
    double in_gallons = in_litres / 3.78; 
    return in_gallons;
}