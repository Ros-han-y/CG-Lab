#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, x2, y1, y2, labelx, labely, Dx, Dy, k, p, x, y;
    
    printf("Enter the initial coordinates: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the final coordinates: ");
    scanf("%d %d", &x2, &y2);

    Dx = abs(x2 - x1);
    Dy = abs(y2 - y1);

    labelx = (x2 > x1) ? 1 : -1;
    labely = (y2 > y1) ? 1 : -1;

    x = x1;
    y = y1;
    putpixel(x, y, WHITE);

    if (Dx > Dy) {
        p = 2 * Dy - Dx;
        for (k = 1; k < Dx; k++) {
            if (p < 0) {
                x = x + labelx;
                p = p + 2 * Dy;
            } else {
                x = x + labelx;
                y = y + labely;
                p = p + 2 * Dy - 2 * Dx;
            }
            putpixel(x, y, WHITE);
        }
    } else {
        p = 2 * Dx - Dy;
        for (k = 1; k < Dy; k++) {
            if (p < 0) {
                y = y + labely;
                p = p + 2 * Dx;
            } else {
                x = x + labelx;
                y = y + labely;
                p = p + 2 * Dx - 2 * Dy;
            }
            putpixel(x, y, WHITE);
        }
    }

    // Display the designed by message
    setcolor(WHITE);
    outtextxy(10, 10, "Designed by Roshan Yadav");

    getch();
    closegraph();
    return 0;
}
