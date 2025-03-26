#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int Xr, Yr, x1, y1;
    float p;
    int x, y;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Ensure the correct BGI path

    // Taking input before initializing graphics
    printf("Enter the x-radius of the ellipse: ");
    scanf("%d", &Xr);
    printf("Enter the y-radius of the ellipse: ");
    scanf("%d", &Yr);
    printf("Enter the center coordinates (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    // Initial decision parameter
    p = pow(Yr, 2) - pow(Xr, 2) * Yr + (0.25 * pow(Xr, 2));
    x = 0;
    y = Yr;

    // Region 1: x increases, y may remain same
    while (2 * Yr * Yr * x < 2 * Xr * Xr * y) {
        putpixel(x + x1, y + y1, WHITE);
        putpixel(-x + x1, y + y1, WHITE);
        putpixel(x + x1, -y + y1, WHITE);
        putpixel(-x + x1, -y + y1, WHITE);

        if (p < 0) {
            x++;
            p = p + 2 * pow(Yr, 2) * x + pow(Yr, 2);
        } else {
            x++;
            y--;
            p = p + 2 * pow(Yr, 2) * x - 2 * pow(Xr, 2) * y + pow(Yr, 2);
        }
        delay(50);
    }

    // Initial decision parameter for Region 2
    p = pow(Yr, 2) * pow(x + 0.5, 2) + pow(Xr, 2) * pow(y - 1, 2) - pow(Xr, 2) * pow(Yr, 2);

    // Region 2: y decreases, x may remain same
    while (y >= 0) {
        putpixel(x + x1, y + y1, WHITE);
        putpixel(-x + x1, y + y1, WHITE);
        putpixel(x + x1, -y + y1, WHITE);
        putpixel(-x + x1, -y + y1, WHITE);

        if (p > 0) {
            y--;
            p = p - 2 * pow(Xr, 2) * y + pow(Xr, 2);
        } else {
            x++;
            y--;
            p = p + 2 * pow(Yr, 2) * x - 2 * pow(Xr, 2) * y + pow(Xr, 2);
        }
        delay(50);
    }
  setcolor(WHITE);
    outtextxy(10, 10, "Designed by Roshan Yadav");

    // Wait for user input before closing the graphics window
    getch();
    closegraph();

    return 0;
}

