#include "splashkit.h"

#define MIN_RADIUS 10
#define MAX_RADIUS 200

int main()
{
    open_window("Shape Shifter", 1000, 800);

    int radius = 50;
    double x = screen_width() / 2;
    double y = screen_height() / 2;

    color circle_colour, background_colour;

    while(not quit_requested())
    {
        process_events();

        clear_screen(background_colour);
        fill_circle(circle_colour, x, y, radius);

        // Moves circle right, left, up and down
        if (key_down(RIGHT_KEY))
        {
            if (x < screen_width() - radius)
            {
                x += 10;
            } else
            {
                x = screen_width() - radius; 
            } 
        } else if (key_down(LEFT_KEY))
        {
            if (x > radius)
            {
                x -= 10;
            } else
            {
                x = radius; 
            }
        } else if (key_down(UP_KEY))
        {
            if (y > radius)
            {
                y -= 10;
            } else
            {
                y = radius; 
            }
        } else if (key_down(DOWN_KEY))
        {
            if (y < screen_height() - radius)
            {
                y += 10;
            } else
            {
                y = screen_height() - radius; 
            } 
        } 
        
        // Makes circle larger or smaller, within limits
        if (key_typed(EQUALS_KEY) && radius < MAX_RADIUS)
        {
            radius += 5;
        } else if (key_typed(MINUS_KEY) && radius > MIN_RADIUS)
        {
            radius -= 5;
        }
        
        // Changes circle, background colour and resets circle to middle of screen
        if (key_typed(C_KEY))
        {
            circle_colour = random_color();
        } else if (key_typed(SPACE_KEY))
        {
           background_colour = random_color();
        } else if (key_typed(R_KEY))
        {
            x = screen_width() / 2;
            y = screen_height() / 2;   
        }

        delay(100);
        refresh_screen();
    }
    return 0;
}