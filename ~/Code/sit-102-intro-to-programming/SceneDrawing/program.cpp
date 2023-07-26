#include "splashkit.h"


int main()
{
    open_window("Scene Drawing", 120, 120);
    
    /* Load image and set its cell details:
    cell width, height, cols, rows, count */
    bitmap lizard = load_bitmap("LizardBmp", "Lizard.png");
    bitmap_set_cell_details(lizard, 55, 55, 4, 4, 16); 

    // Load the animation script
    animation_script dance_script = load_animation_script("WalkingScript", "kermit.txt");

    // Create the animation
    animation animate = create_animation(dance_script, "WalkFront");

    // Create a drawing option
    drawing_options opt;
    opt = option_with_animation(animate);

    process_events();

    // Basic event loop
    while( not quit_requested() )
    {

        while( not S_KEY)
        {
            clear_screen(COLOR_WHITE);
            draw_bitmap(lizard, 20, 20, opt);
            refresh_screen(100);

            // Update the animation
            update_animation(animate);
        }

        bitmap frog = load_bitmap("FrogBmp", "Frog.png");
        bitmap_set_cell_details(frog, 73, 105, 4, 4, 16);

        // Draw the bitmap - using opt to link to animation
        clear_screen(COLOR_WHITE);
        draw_bitmap(frog, 20, 20, opt);
        refresh_screen(60);

        // Update the animation
        update_animation(animate);

        // Switch animations
        if ( key_typed(UP_KEY))
        {
            assign_animation(animate, "MoonWalkBack");
        }
        else if ( key_typed(DOWN_KEY))
        {
            assign_animation(animate, "MoonWalkFront");
        }
        else if ( key_typed(LEFT_KEY))
        {
            assign_animation(animate, "MoonWalkLeft");
        }
        else if ( key_typed(RIGHT_KEY))
        {
            assign_animation(animate, "MoonWalkRight");
        }
        else if ( key_typed(D_KEY))
        {
            assign_animation(animate, "Dance");
        }
        else if ( key_typed(S_KEY))
        {
            clear_screen(COLOR_WHITE);
            draw_bitmap(lizard, 20, 20, opt);
            refresh_screen(60);
        }
    }
}
