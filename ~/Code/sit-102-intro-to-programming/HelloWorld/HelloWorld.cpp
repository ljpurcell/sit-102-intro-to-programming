#include "splashkit.h"

// "Hello world" program to demonstrate all software is installed and operating correctly

int main()
{
    int salmon, dumplings, meals;

    salmon = 0;
    dumplings = 0;
    meals = salmon + dumplings;

    salmon = 20;
    dumplings = 70;

    write("Fish: ");
    write(salmon);
    write("Dumplings: ");
    write(dumplings);
    write("Meals: ");
    write_line(meals);
    return 0;
}