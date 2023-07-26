#include "splashkit.h"
#include "introprog.h"
#include <vector>

using namespace std;
using std::vector;

#define MY_NAME "Lyndon"

int summed_length_names(const vector<string> &vector_name);
string longest_name(const vector<string> &vector_name);
int index_of(string value, const vector<string> &vector_name);
void print_summary(const vector<string> &vector_name);
void change_name(vector<string> &vector_name);


int main()
{

    int number_of_names = read_integer("How many names would you like to work with: ");

    vector<string> names;

    for(int i = 0; i < number_of_names; i++)
    {
        names.push_back(read_string("Name: "));
    }

    print_summary(names);

    change_name(names);

    print_summary(names);

    return 0;
}

// Function to calculate the total number of characters contained in an vector, by adding together the size of all names
int summed_length_names(const vector<string> &vector_name)
{
    int sum = 0;
    for(int i = 0; i < vector_name.size(); i++)
    {
        sum += vector_name[i].length();
    }
    return sum;
}

// Function which returns the longest name within an vector
string longest_name(const vector<string> &vector_name)
{
    int longest_name_index = 0;
    int longest_name_size = vector_name[longest_name_index].length();
    
    for(int i=1; i < vector_name.size(); i++)
    {
        if(vector_name[i].length() > longest_name_size)
        {
            longest_name_index = i;
            longest_name_size = vector_name[i].length();
        }
    }

    return vector_name[longest_name_index];
}

// Function which returns the index number of a requested name in an vector, or a negative result if not found
int index_of(string value, const vector<string> &vector_name)
{
    for(int i=0; i < vector_name.size(); i++)
    {
        if(value == vector_name[i])
            return i;
    }
    return -1;
}

// Procedure to print all names in the vector, as well as the results of the above functions
void print_summary(const vector<string> &vector_name)
{
    write_line("---NAMES---");
    for(int i=0; i < vector_name.size(); i++)
    {
        write_line(vector_name[i]);
    }

    write_line("Summed length of names: " + to_string(summed_length_names(vector_name)));
    write_line("Longest name: " + longest_name(vector_name));
    write_line("Index of my name: " + to_string(index_of(MY_NAME, vector_name)));
}

// Procedure to change the data (name) stored in an array
void change_name(vector<string> &vector_name)
{
    string to_change = read_string("What name would you like to change: ");
    
    for(int i = 0; i < vector_name.size(); i++)
    {
        if (to_change == vector_name[i])
        {
            vector_name[i] = read_string("What is the new name to replace it: ");
            return;
        }
    }

    write_line("Sorry, that name isn't in the list.");
}