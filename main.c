#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

    screen s;
    color c;

    int x = 0,
        y = 0;

    c.red = 0;
    c.green = MAX_COLOR;
    c.blue = 0;

    clear_screen(s);

    //bottom left
    while (x < XRES) {
        draw_line(x, YRES, 0, y, s, c);
        x += 20;
        y += 20;
        c.red += 15;
    }

    c.red = MAX_COLOR;
    c.green = 0;
    c.blue = 0;

    x = 0;
    y = 0;
    
    //top left
    while (x < XRES) {
        draw_line(0, YRES - y, x, 0, s, c);
        x += 15;
        y += 15;
        c.green += 10;
    }

    x = 0;
    y = 0;
    
    c.red = 0;
    c.green = 0;
    c.blue = MAX_COLOR;
    
    //bottom right
    while (x < XRES) {
        draw_line(XRES, YRES - y, XRES - x, 0, s, c);
        x += 10;
        y += 10;
        c.red += 5;
    }
    
    x = 0;
    y = 0;

    c.red = 0;
    c.green = MAX_COLOR;
    c.blue = MAX_COLOR;

    //top right
    while(x < XRES) {
        draw_line(x, YRES, XRES, YRES - y , s, c);
        x += 5;
        y += 5;
        c.red += 1;
    }

    display(s);
    save_extension(s, "lines.png");
}  
