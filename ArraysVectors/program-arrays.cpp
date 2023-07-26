#include "splashkit.h"
#include "introprog.h" // A header file I made for the functions & procedures typically required for these submissions

#define SIZE 3
#define MY_NAME "Lyndon"

int summed_length_names(string array_name[], int array_size);
int index_of(string value, string array_name[], int array_size);
string longest_name(string array_name[], int array_size);
void print_summary(string array_name[], int array_size);
void change_name(string array_name[], int array_size);

using namespace std;

int main()
{
    string names[SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        names[i] = read_string("Name: ");
    }

    print_summary(names, SIZE);
    change_name(names, SIZE);
    print_summary(names, SIZE);

    return 0;
}

// Function to calculate the total number of characters contained in an array, by adding together the size of all names
int summed_length_names(string array_name[], int array_size)
{
    int sum = 0;
    for(int i = 0; i < array_size; i++)
    {
        sum += array_name[i].length();
    }
    return sum;
}

// Function which returns the longest name within an array
string longest_name(string array_name[], int array_size)
{
    int longest_name_index = 0;
    int longest_name_size = array_name[longest_name_index].length();
    
    for(int i=1; i<array_size; i++)
    {
        if(array_name[i].length() > longest_name_size)
        {
            longest_name_index = i;
            longest_name_size = array_name[i].length();
        }
    }

    return array_name[longest_name_index];
}

// Function which returns the index number of a requested name in an array, or a negative result if not found
int index_of(string value, string array_name[], int array_size)
{
    for(int i=0; i < array_size; i++)
    {
        if(value == array_name[i])
            return i;
    }
    return -1;
}

// Procedure to print all names in the array, as well as the results of the above functions
void print_summary(string array_name[], int array_size)
{
    write_line("---NAMES---");
    for(int i=0; i < array_size; i++)
    {
        write_line(array_name[i]);
    }

    write_line("Summed length of names: " + to_string(summed_length_names(array_name, array_size)));
    write_line("Longest name: " + longest_name(array_name, array_size));
    write_line("Index of my name: " + to_string(index_of(MY_NAME, array_name, array_size)));
}

// Procedure to change the data (name) stored in an array
void change_name(string array_name[], int array_size)
{
    string to_change = read_string("What name would you like to change: ");
    
    for(int i = 0; i < array_size; i++)
    {
        if (to_change == array_name[i])
        {
            array_name[i] = read_string("What is the new name to replace it: ");
            return;
        }
    }

    write_line("Sorry, that name isn't in the list.");
}