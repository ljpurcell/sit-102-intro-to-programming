#include "splashkit.h"

// Procedure declarations
void draw_house_scene();
void draw_livingroom_scene();

// Program
int main()
{
    open_window("My drawing", 800, 600);

    draw_house_scene();
    delay(1000);

    draw_livingroom_scene();
    delay(1000);

    draw_house_scene();
    delay(1000);

    draw_livingroom_scene();
    delay(1000);

    return 0;
}

// Procedure definitions
void draw_house_scene()
{
    clear_screen(COLOR_WHITE);
    fill_ellipse(COLOR_BRIGHT_GREEN, 0 , 400, 800, 400);
    fill_rectangle(COLOR_GRAY, 300, 300, 200, 200);
    fill_triangle(COLOR_RED, 250, 300, 400, 150, 550, 300);
    refresh_screen();
}

void draw_livingroom_scene()
{
    clear_screen(COLOR_LIGHT_GRAY);

    // table, plate and food
    fill_rectangle(COLOR_TAN, 650, 150, 150, 300);
    fill_circle(COLOR_WHITE, 700, 300, 40);
    fill_circle(COLOR_GREEN, 690, 300, 15);
    fill_rectangle(COLOR_ORANGE, 710, 290, 25, 25);
    fill_rectangle(COLOR_YELLOW_GREEN, 690, 320, 15, 15);

    // rug, tv and couch
    fill_ellipse(COLOR_CYAN, 170, 200, 350, 250);
    fill_rectangle(COLOR_BLACK, 200, 570, 250, 30);
    fill_rectangle(COLOR_BROWN, 180, 80, 350, 100);
    draw_rectangle(COLOR_BLACK, 205, 130, 150, 50);
    draw_rectangle(COLOR_BLACK, 355, 130, 150, 50);
    refresh_screen();
}