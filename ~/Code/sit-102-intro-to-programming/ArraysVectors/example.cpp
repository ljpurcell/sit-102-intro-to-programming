#include "splashkit.h"
#include "introprog.h"
#include <vector>

using namespace std;
using std::vector;


int main()
{

    int number_of_names = read_integer("How many names would you like to work with: ");

    vector<string> names;

    for(int i = 0; i < number_of_names; i++)
    {
        names.push_back(read_string("Name: "));
    }

    while (not names.empty())
    {
        write_line(names.back());
        names.pop_back();
    }
    

    return 0;
}