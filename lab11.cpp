#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    
    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Set color to white
    setcolor(WHITE);

    // Draw a triangle
    line(200, 300, 400, 300); // Bottom line
    line(200, 300, 300, 100); // Left side
    line(300, 100, 400, 300); // Right side

    getch(); // Wait for user input
    closegraph(); // Close graphics mode
    
    return 0;
}

