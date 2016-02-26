#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    //Flip the start and end if in octant 3-6
    if (x0 > x1) {
        int tX = x0,
            tY = y0;
        x0 = x1;
        y0 = y1;
        x1 = tX;
        y1 = tY;
    }
    int x = x0,
        y = y0;
    
    int A = y1 - y0,
        B = (x1 - x0) * -1;
    
    int d;
    //Octant 1/5
    if (A <= (x1 - x0) && (A >= 0)) {
        d = 2*A + B;
        while(x <= x1) {
            plot(s,c,x,y);
            if(d > 0) {
                y++;
                d += 2 * B;
            }
            x++;
            d += 2 * A;
        }
    }
    //Octant 2/6
    else if(A >= (x1 - x0) && (A >= 0)) {
        d = A + 2 * B;
        while(y <= y1) {
            plot(s,c,x,y);
            if(d < 0) {
                x++;
                d += 2 * A;
            }
            y++;
            d += 2 * B;
        }
    }
    //Octant 3/7
    else if(A < B) {
        d = A - 2 * B;
        while (y >= y1) {
            plot(s,c,x,y);
            if(d > 0) {
                x++;
                d += 2 * A;
            }
            y--;
            d -= 2 * B;
        }
    }
    //Octant 4/8
    else {
        d = 2 * A - B;
        while (x <= x1) {
            plot(s,c,x,y);
            if(d < 0) {
                y--;
                d -= 2 * B;
            }
            x++;
            d += 2 * A;
        }
    }
}

