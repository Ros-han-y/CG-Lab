#include <graphics.h>
#include <stdio.h>

// Function to clip the line using Liang-Barsky Algorithm
void liangBarsky(float x1, float y1, float x2, float y2, int xmin, int ymin, int xmax, int ymax) {
    float t0 = 0.0, t1 = 1.0;
    float dx = x2 - x1, dy = y2 - y1;
    float p[4], q[4];
    int i;

    p[0] = -dx; q[0] = x1 - xmin;  // Left
    p[1] = dx;  q[1] = xmax - x1;  // Right
    p[2] = -dy; q[2] = y1 - ymin;  // Bottom
    p[3] = dy;  q[3] = ymax - y1;  // Top

    for (i = 0; i < 4; i++) {
        if (p[i] == 0 && q[i] < 0) return; // Line is outside
        float t = q[i] / p[i];

        if (p[i] < 0) { // Potentially entering
            if (t > t0) t0 = t;
        } else if (p[i] > 0) { // Potentially leaving
            if (t < t1) t1 = t;
        }
    }

    if (t0 > t1) return; // No clipping needed

    float clipped_x1 = x1 + t0 * dx;
    float clipped_y1 = y1 + t0 * dy;
    float clipped_x2 = x1 + t1 * dx;
    float clipped_y2 = y1 + t1 * dy;

    // Draw the clipped line in RED
    setcolor(RED);
    line(clipped_x1, clipped_y1, clipped_x2, clipped_y2);
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

    // Draw original line in BLUE
    setcolor(BLUE);
    line(x1, y1, x2, y2);

    delay(2000); // Pause before clipping

    // Apply Liang-Barsky Clipping
    liangBarsky(x1, y1, x2, y2, xmin, ymin, xmax, ymax);
setcolor(WHITE);
    outtextxy(10, 10, "Designed by Roshan Yadav");
    getch();
    closegraph();
    return 0;
}

