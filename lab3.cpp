#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void drawCircle(int x1, int y1, int radius) {
    int x = 0, y = radius;
    int p = 1 - radius; // Initial decision parameter

    while (x <= y) {
        // Plot 8 symmetrical points
        putpixel(x1 + x, y1 + y, WHITE);
        putpixel(x1 - x, y1 + y, WHITE);
        putpixel(x1 + x, y1 - y, WHITE);
        putpixel(x1 - x, y1 - y, WHITE);
        putpixel(x1 + y, y1 + x, WHITE);
        putpixel(x1 - y, y1 + x, WHITE);
        putpixel(x1 + y, y1 - x, WHITE);
        putpixel(x1 - y, y1 - x, WHITE);

        // Midpoint algorithm condition
        if (p < 0) {
            p = p + 2 * x + 3;
        } else {
            p = p + 2 * (x - y) + 5;
            y--;
        }
        x++;

        delay(50); // Adds a small delay for visualization
    }
}

int main() {
    int gd = DETECT, gm;
    int radius, x1, y1;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Change the path if needed

    // Taking input before initializing graphics
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);
    printf("Enter the center coordinates (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    // Draw the circle using Midpoint Algorithm
    drawCircle(x1, y1, radius);

    // Display designer credit
    setcolor(WHITE);
    outtextxy(10, 10, "Designed by Roshan Yadav");

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}

