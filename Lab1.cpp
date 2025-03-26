#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;
    
    float x = x1;
    float y = y1;
    
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xInc;
        y += yInc;
        delay(10); // Adds a small delay for better visualization
    }
}

int main() {
    int x1, y1, x2, y2;
    
    // Take input in text mode before initializing graphics mode
    printf("Enter coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Change the path if needed
    
    // Display input values in graphics mode
    setcolor(WHITE);
    char text[50];
    sprintf(text, "P1: (%d, %d)", x1, y1);
    outtextxy(10, 20, text);
    sprintf(text, "P2: (%d, %d)", x2, y2);
    outtextxy(10, 40, text);
    
    // Draw line using DDA algorithm
    DDA(x1, y1, x2, y2);
    
    // Display designer text
    outtextxy(10, 60, "Designed by Roshan Yadav");

    getch(); // Wait for user input
    closegraph();
    
    return 0;
}

