#include "splashkit.h"

void greet_and_respond();
void number_game();
void stop_copying_me();
void blast_off();

int main()
{
    // Greets user, asks for their name and gives some custom responses
    greet_and_respond();

    int menu_selection = 0;

    // Menu for user to pick various activities
    do 
    {
        write_line("What would you like to do now then? Your options are:");
        write_line("1 - Guess the number game.");
        write_line("2 - Copycat game.");
        write_line("3 - Count down.");
        write_line("4 - Quit.\n");

        write("Please enter the number corresponding number: ");
        menu_selection = convert_to_integer(read_line());
        write_line();

        switch (menu_selection)
        {
            case 1:
                // User tries to guess a psuedorandom number between 1-100
                number_game(); 
                break;

            case 2:
                // Repeats what the user types in uppercase with added exclamation point
                stop_copying_me();
                break;

            case 3:
                // Counts down from user-entered number and blasts off
                blast_off();
                break;
            
            case 4:
                break;
        }

    } while (menu_selection > 4 || menu_selection < 1);

    return 0;
}

void greet_and_respond()
{
    string user_name;
    write_line("\nHi there. This program is going to be a bit interactive, so get ready!");
    write("But first, what is your name: ");
    user_name = read_line();
    write_line("\nGreat, thanks so much " + user_name + ". It's nice to meet you!\n");

    if (to_lowercase(user_name) == "bruce" || to_lowercase(user_name) == "clark")
    {
        string city;
        write("Let me ask you another question, " + user_name);
        write(". Where do you live: ");
        city = read_line();
        write_line();

        if (to_lowercase(city) == "gotham")
        {
            write_line("I thought so. Does Alfred know you're here, " + user_name + "?\n");

        } else if (to_lowercase(city) == "metropolis")
        {
            write_line("Mmm. I was always more of a Lex Luther fan myself.\n");

        } else
        {
            write_line("OH! Never mind... ");
        }
    }
}

void number_game()
{
    int guess, actual;
    guess = 0; 
    actual = rnd(100) + 1;

    write_line("For this game, we are using numbers between 1 and 100.");

    while(guess != actual)
    {
        write("\nWhat is your guess? ");
        guess = convert_to_integer(read_line());

        if (guess < actual)
        {
            write_line("Sorry. Try a bit higher!");
        } else if (guess > actual)
        {
            write_line("Sorry. Try a bit lower!");
        } else
        {
            write_line("GREAT JOB! That was indeed the number");
        }
    }
}

void stop_copying_me()
{
    write_line("This might get annoying, so press 'q' and then 'return' to quit.");
    write_line("To start, is there anything you want to say?");
    process_events();
    
    string user_input = "";

    while (true)
    {
        user_input = read_line();
        if (user_input == "q" or user_input == "Q")
        {
            break;
        }
        write_line(to_uppercase(user_input + '!'));
        write_line();
    }
}

void blast_off()
{
    int counter;
    write("Please enter the number you want to countdown from: ");
    counter = convert_to_integer(read_line());
    write_line("Here goes...");
    if (counter > 0)
    {
        for (int i = counter; i > 0; i--)
        {
            write_line(i);
        }
        write_line("BLAST OFF!!!");
    } else
    {
        write_line("I can't countdown from that...");
    }
}   