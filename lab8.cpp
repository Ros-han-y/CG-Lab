#include <graphics.h>
#include <stdio.h>

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

// Function to compute region code
int getCode(int x, int y, int xmin, int ymin, int xmax, int ymax) {
    int code = 0;
    if (x < xmin) code |= LEFT;
    if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    if (y > ymax) code |= TOP;
    return code;
}

// Cohen-Sutherland Line Clipping Algorithm
void cohenSutherland(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    int code1 = getCode(x1, y1, xmin, ymin, xmax, ymax);
    int code2 = getCode(x2, y2, xmin, ymin, xmax, ymax);
    int accept = 0;

    while (1) {
        if (code1 == 0 && code2 == 0) { 
            accept = 1;
            break;
        } else if (code1 & code2) { 
            break;
        } else { 
            int code_out;
            int x, y;

            code_out = (code1 != 0) ? code1 : code2;

            if (code_out & TOP) { 
                y = ymax;
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
            } else if (code_out & BOTTOM) { 
                y = ymin;
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
            } else if (code_out & RIGHT) { 
                x = xmax;
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
            } else if (code_out & LEFT) { 
                x = xmin;
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
            }

            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = getCode(x1, y1, xmin, ymin, xmax, ymax);
            } else {
                x2 = x;
                y2 = y;
                code2 = getCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    // Draw the clipped line inside the window
    if (accept) {
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xmin, ymin, xmax, ymax;
    int x1, y1, x2, y2;

    // Taking user input
    printf("Enter XMin, YMin: ");
    scanf("%d %d", &xmin, &ymin);
    
    printf("Enter XMax, YMax: ");
    scanf("%d %d", &xmax, &ymax);

    printf("Enter initial point x and y: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter final point x1 and y1: ");
    scanf("%d %d", &x2, &y2);

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original line (BLUE)
    setcolor(BLUE);
    line(x1, y1, x2, y2);

    delay(2000); // Pause before clipping

    // Apply Cohen-Sutherland Clipping
    cohenSutherland(x1, y1, x2, y2, xmin, ymin, xmax, ymax);
setcolor(WHITE);
    outtextxy(10, 10, "Designed by Roshan Yadav");
    getch();
    closegraph();
    return 0;
}

