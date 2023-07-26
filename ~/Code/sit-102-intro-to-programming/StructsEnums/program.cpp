#include "splashkit.h"
#include "string.h"

using namespace std;

// Declaration of a struct/type knight, containing basic qualities
struct knight
{
    string name;
    int age;
    string birth_month;
    string favourite_word;
};

// Enum to hold the constant options related to updating the knight struct
enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_AGE,
    UPDATE_BIRTHMONTH,
    UPDATE_FAVOURITE_WORD,
    FINISH_UPDATE
};

string read_string(string prompt)
{
    write_line(prompt);
    return read_line();
}

// Procedure to prompt user for details of a knight, adding them into a new struct and returning it
knight read_knight()
{
    knight new_knight;
    new_knight.name = read_string("What is the name of this knight?");
    new_knight.age = convert_to_integer(read_string("How old is this knight?"));
    new_knight.birth_month = read_string("What month were they born?");
    new_knight.favourite_word = read_string("What is their favourite word?");
    return new_knight;
}

// Output the details of a knight
void write_knight(const knight &current_knight)
{
    write_line("\nThe name of this knight is: " + current_knight.name);
    write_line(current_knight.name + "'s age is: " + to_string(current_knight.age));
    write_line(current_knight.name + "'s birthmonth is: " + current_knight.birth_month);
    write_line(current_knight.name + "'s favourite word is: " + current_knight.favourite_word + "\n");
}

// Procedure that works alongside 'update_knight()' and returns an enum type
knight_update_option read_knight_update_option()
{
    int temp = convert_to_integer(read_string("What option would you like to select: "));
    return static_cast<knight_update_option>(temp - 1);
}

// Presents user with a menu of options to update knight details. Loops until 'finish' is selected.
void update_knight(knight &knight_to_edit)
{
    
    knight_update_option option;
    
    do
    {

        write_line("----Update Knight Options----");
        write_line("1. Update name");
        write_line("2. Update age");
        write_line("3. Update birthmonth");
        write_line("4. Update favourite word");
        write_line("5. Finish update");

        option = read_knight_update_option();        

        switch (option)
        {
            case UPDATE_NAME:
                knight_to_edit.name = read_string("Enter new name: ");
                break;

            case UPDATE_AGE:
                knight_to_edit.age = convert_to_integer(read_string("Enter new age: "));
                break;

            case UPDATE_BIRTHMONTH:
                knight_to_edit.birth_month = read_string("Enter new birthmonth: ");
                break;

            case UPDATE_FAVOURITE_WORD:
                knight_to_edit.favourite_word = read_string("Enter new favourite word: ");
                break;

            case FINISH_UPDATE:
                break;

            default:
                write_line("Sorry, please pick a valid option");
        }         
    } while (option != FINISH_UPDATE);
}

int main()
{
    knight sir_someone;
    sir_someone = read_knight();
    write_knight(sir_someone);
    update_knight(sir_someone);
    write_knight(sir_someone);

    return 0;
}