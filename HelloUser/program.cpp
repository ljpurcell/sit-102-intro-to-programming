#include "splashkit.h"
#include <string>

enum control
{
    OFF,
    ON
};

int main()
{
    control button = OFF;
    int temp_now = 44;
    int temp_prev = 42;

    if ((temp_now > temp_prev and temp_now > 44) or !button)
    {
        write_line("this if one");
    } else
    {
        write_line("that else one");
    }
    

    return 0;
}
