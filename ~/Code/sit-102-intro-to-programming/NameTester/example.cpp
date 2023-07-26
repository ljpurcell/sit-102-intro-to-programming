#include "splashkit.h"

int main()
{
    int age = 0;
    write_line("How old are you?");
    age = convert_to_integer(read_line());

    if (not (age >= 18))
    {
        write_line("Sorry, I can't let you in. You're not old enough to drink, kid!");
    } else
    {
        write_line("You're an adult, come on in!");
    }
    return 0;
}



