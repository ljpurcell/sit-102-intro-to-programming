#include "splashkit.h"
#include "string.h"
#include "introprog.h"
#include <vector>

using namespace std;
using std::vector;

// Declaration of a struct-type knight, containing basic qualities
struct knight
{
    string name;
    int age;
    vector<string> tools;
};

// Declaration of a struct-type kingdom
struct kingdom_data
{
    string name;
    vector<knight> knights;
};

// Enum to hold the constant options related to updating the knight struct
enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_AGE,
    ADD_TOOL,
    REMOVE_TOOL,
    END_KNIGHT_UPDATE
};

// Enum to hold the constant options related to updating and interacting with the kingdom struct
enum kingdom_update_option
{
    ADD_KNIGHT,
    QUERY_KNIGHT,
    DELETE_KNIGHT,
    UPDATE_KNIGHT,
    WRITE_KINGDOM,
    END_KINGDOM_UPDATE
};

// Function and procedure declarations
kingdom_data create_kingdom();
void add_knight(kingdom_data &current_kingdom);
void query_knight(const kingdom_data &current_kingdom);
knight read_knight();
void write_knight(const knight &current_knight);
void update_knight(knight &knight_to_edit);
void write_kingdom(const kingdom_data &current_kingdom);
kingdom_update_option read_kingdom_update_option();
void update_kingdom(kingdom_data &kingdom_to_edit);
void delete_knight(kingdom_data &current_kingdom, int index);
int select_knight(const kingdom_data &current_kingdom);
void add_tool(knight &knight_to_edit);
int select_tool(const knight &knight_with_tools);
void remove_tool(knight &knight_to_edit);

// Main program
int main()
{
    kingdom_data palace = create_kingdom();
    add_knight(palace);
    add_knight(palace);
    add_knight(palace);

    write_kingdom(palace);
    update_kingdom(palace);
    write_kingdom(palace);
    return 0;
}

// Creates kingdom declaring a new kingdom and reading in relevant details from user
kingdom_data create_kingdom()
{
    write_line("--- CREATING NEW KINGDOM ---");
    kingdom_data new_kingdom;
    new_kingdom.name = read_string("What would you like to name this kingdom: ");
    return new_kingdom;
}

// Output the details of a knight
void write_knight(const knight &current_knight)
{
    write_line("\nName: " + current_knight.name);
    write_line("Age: " + to_string(current_knight.age));
    write("Tools: ");
    if (current_knight.tools.size() > 0)
    {
        for(int i=0; i < current_knight.tools.size(); i++)
        {
            write(current_knight.tools[i] + " ");
        }
        write_line();
    }
    else
        write_line("NONE");
}

// Outoput the details of a kingdom
void write_kingdom(const kingdom_data &current_kingdom)
{
    write_line("\n====KINGDOM INFO====");
    write_line("Kingdom Name: " + current_kingdom.name);

    for(int i=0; i < current_kingdom.knights.size(); i++)
    {
        write("> Knight #" + to_string(i + 1) + ": ");
        write_knight(current_kingdom.knights[i]);
    }
    write_line("============\n");
}

// Procedure to prompt user for details of a knight, adding them into a new struct and returning it
knight read_knight()
{
    knight new_knight;
    new_knight.name = read_string("What is the name of this knight? ");
    new_knight.age = convert_to_integer(read_string("How old is this knight? "));
    return new_knight;
}

// Adds a knight to the passed kingdom
void add_knight(kingdom_data &current_kingdom)
{
    knight new_knight = read_knight();
    current_kingdom.knights.push_back(new_knight);
}

// Removes a knight at a given index in vector from the kingdom
void delete_knight(kingdom_data &current_kingdom, int index)
{
    if ( index >= 0 && index < current_kingdom.knights.size() )
    {
        int last_idx = current_kingdom.knights.size() - 1;
        current_kingdom.knights[index] = current_kingdom.knights[last_idx];
        current_kingdom.knights.pop_back();
    }
    else
        write_line("Sorry, that isn't a valid index!");
}

// Procedure that works alongside 'update_knight()' and returns an enum type
knight_update_option read_knight_update_option()
{
    int temp = read_integer("What option would you like to select: ");
    return static_cast<knight_update_option>(temp - 1);
}

// Procedure that works alongside 'update_kingdom()' and returns an enum type
kingdom_update_option read_kingdom_update_option()
{
    int temp = read_integer("What option would you like to select: ");
    return static_cast<kingdom_update_option>(temp - 1);
}

// Lists all the knights and associates them with a number. User then selects which knight by referencing the number
int select_knight(const kingdom_data &current_kingdom)
{
    write_line("* Select one of the following knights *\n");

    for(int i=0; i < current_kingdom.knights.size(); i++)
    {
        write("> Knight #" + to_string(i + 1) + ": ");
        write_knight(current_kingdom.knights[i]);
    }

    int selection = (read_integer("\nWhich knight do you select? ") - 1);

    if ( selection >= 0 && selection < current_kingdom.knights.size() )
        return selection;
    else
    {
        write_line("Not a valid option - sorry!");
        return -1;
    }
}

// Takes a selected knight and outputs their details to the screen
void query_knight(const kingdom_data &current_kingdom)
{
    int selection = select_knight(current_kingdom);
    write_knight(current_kingdom.knights[selection]);
}

// Presents user with a menu of options to update knight details. Loops until 'finish' is selected.
void update_knight(knight &knight_to_edit)
{
    knight_update_option option;
    
    do
    {
        write_line("\n----Update Knight Options----");
        write_line("1. Update name");
        write_line("2. Update age");
        write_line("3. Add tool");
        write_line("4. Remove tool");
        write_line("5. Finish update");

        option = read_knight_update_option();        

        switch (option)
        {
            case UPDATE_NAME:
                knight_to_edit.name = read_string("Enter new name: ");
                break;

            case UPDATE_AGE:
                knight_to_edit.age = read_integer("Enter new age: ");
                break;

            case ADD_TOOL:
                add_tool(knight_to_edit);
                break;

            case REMOVE_TOOL:
                remove_tool(knight_to_edit);
                break;

            case END_KNIGHT_UPDATE:
                break;

            default:
                write_line("Sorry, please pick a valid option!");
        }         
    } while (option != END_KNIGHT_UPDATE);
}

// Presents user with a menu of options to update the kingdom. Loops until 'finish' is selected.
void update_kingdom(kingdom_data &kingdom_to_edit)
{   
    kingdom_update_option option;
    
    do
    {
        write_line("\n-**-Update Kingdom Options-**-");
        write_line("1. Add a knight");
        write_line("2. Query a knight");
        write_line("3. Delete a knight");
        write_line("4. Update a knight");
        write_line("5. Display kingdom details");
        write_line("6. Finish");

        option = read_kingdom_update_option();        

        switch (option)
        {
            case ADD_KNIGHT:
                add_knight(kingdom_to_edit);
                break;

            case QUERY_KNIGHT:
                query_knight(kingdom_to_edit);
                break;

            case DELETE_KNIGHT:
                delete_knight(kingdom_to_edit, select_knight(kingdom_to_edit));
                break;

            case UPDATE_KNIGHT:
            {
                int selection = select_knight(kingdom_to_edit);
                update_knight(kingdom_to_edit.knights[selection]);
                break;
            }

            case WRITE_KINGDOM:
                write_kingdom(kingdom_to_edit);
                break;

            case END_KINGDOM_UPDATE:
                break;

            default:
                write_line("Sorry, please pick a valid option");
        }         
    } while (option != END_KINGDOM_UPDATE);
}

// Adds a tool to the selected knights vector of tools
void add_tool(knight &knight_to_edit)
{
    string new_tool = read_string("What tool would you like to add? ");
    knight_to_edit.tools.push_back(to_uppercase(new_tool));
}

// Allows the user to select a tool through association with a number
int select_tool(const knight &knight_with_tools)
{
    write_line("... TOOLS ...");
    for(int i=0; i<knight_with_tools.tools.size(); i++)
    {
        write_line(to_string(i+1) + ". " + knight_with_tools.tools[i]);
    }
    int selected_tool = (read_integer("Which would you like to select? ") - 1);


    if ( selected_tool >= 0 && selected_tool < knight_with_tools.tools.size() )
        return selected_tool;
    else
    {
        write_line("Not a valid option - sorry!");
        return -1;
    }
}

 // Copies last tool in the array over the tool to remove, then the end tool is removed
void remove_tool(knight &knight_to_edit)
{
    if (knight_to_edit.tools.size() > 0)
    {
        int chosen_tool = select_tool(knight_to_edit);

        if ( chosen_tool >= 0 && chosen_tool < knight_to_edit.tools.size() )
        {
            int last_idx = knight_to_edit.tools.size() - 1;
            knight_to_edit.tools[chosen_tool] = knight_to_edit.tools[last_idx];
            knight_to_edit.tools.pop_back();
        }
        else
            write_line("Sorry, that's not a valid index!");
    }
    else
        write_line("No tool is found in record");
}