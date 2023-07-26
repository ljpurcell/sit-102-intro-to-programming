#include "splashkit.h"
#include "math.h"
#include <string>

#define STROUHAL 0.33

// Function and procedure declarations
double calculate_air_speed(double freq, double amp);
void output_air_speed(string name, double freq, double amp);
string read_string(string prompt);
int read_integer(string prompt);
double read_double(string prompt);
double custom_calculation(double to_sqrt, double to_nat_log);

int main()
{
    // Declare user's variables
    string name;
    int age;

    // Get user details
    name = read_string("What is your name: ");
    age = read_integer("What is your age: ");

    // Output to terminal
    write_line("");
    write("Hello, ");
    write_line(name + "!");
    write("Age: ");
    write_line(age);
    write_line("");

    // Declare bird's variables
    string bird_name;
    double wing_amplitude, wing_frequency;

    // Assign values to the bird's variables
    bird_name = read_string("What bird would you like to look at today: ");
    wing_frequency = read_double("What is the frequency which it flaps its wings: ");
    wing_amplitude = read_double("What is the amplitude of its stroke: ");
    write_line("");

    output_air_speed(bird_name, wing_frequency, wing_amplitude);
    write_line("\nNow,given that I have those values for frequency and amplitude...");
    write_line("I thought I might do a calculation of my own choosing using them. I hope that's ok!\n");

    write("If we take the frequency value of: ");
    write_line(wing_frequency);
    write("And the amplitude value of: ");
    write_line(wing_amplitude);
    write_line("\nThen calculate the square root of the first value and the natural logarithm of the second...");
    write("and add them together and get the new value of: ");
    write_line(custom_calculation(wing_frequency, wing_amplitude));

    write_line("\nWhich is completely unrelated to anything, but it was fun to implement the program! :)\n");

    write_line("*End of Program.*");

    return 0;
}


// Calculate resultant STROUHAL air speed by reading in freq and amp
double calculate_air_speed(double freq, double amp)
{
    double result;
    result = freq * amp * 0.01 / STROUHAL;
    return result;
}

// Writes the calculated air speed to the terminal
void output_air_speed(string name, double freq, double amp)
{
    write(name + ": ");
    write_line(calculate_air_speed(freq, amp));
}

// Return a string of the input line from the terminal
string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

// Returns an integer of the input line from the terminal 
int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

// Returns a double of the input line from the terminal 
double read_double(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_double(line);
}

// Ret
double custom_calculation(double to_sqrt, double to_nat_log)
{
    return sqrt(to_sqrt) + log(to_nat_log); 
}