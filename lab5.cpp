#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

void drawAxis() {
    setcolor(WHITE);
    line(320, 0, 320, 480);  // Y-Axis
    line(0, 240, 640, 240);  // X-Axis
}

void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

// ? Translation: Moves the shape by tx and ty
void translate(int *x1, int *y1, int *x2, int *y2, int tx, int ty) {
    *x1 += tx;
    *y1 += ty;
    *x2 += tx;
    *y2 += ty;
}

// ? Scaling: Scales the shape relative to its center
void scale(int *x1, int *y1, int *x2, int *y2, float sx, float sy) {
    int cx = (*x1 + *x2) / 2;
    int cy = (*y1 + *y2) / 2;

    *x1 = cx + (*x1 - cx) * sx;
    *y1 = cy + (*y1 - cy) * sy;
    *x2 = cx + (*x2 - cx) * sx;
    *y2 = cy + (*y2 - cy) * sy;
}

// ? Rotation: Rotates the shape around its center
void rotate(int *x1, int *y1, int *x2, int *y2, float angle) {
    float rad = angle * (3.14159 / 180); // Convert degrees to radians
    int cx = (*x1 + *x2) / 2;
    int cy = (*y1 + *y2) / 2;

    int new_x1 = cx + (*x1 - cx) * cos(rad) - (*y1 - cy) * sin(rad);
    int new_y1 = cy + (*x1 - cx) * sin(rad) + (*y1 - cy) * cos(rad);
    int new_x2 = cx + (*x2 - cx) * cos(rad) - (*y2 - cy) * sin(rad);
    int new_y2 = cy + (*x2 - cx) * sin(rad) + (*y2 - cy) * cos(rad);

    *x1 = new_x1;
    *y1 = new_y1;
    *x2 = new_x2;
    *y2 = new_y2;
}

int main() {
    int gd = DETECT, gm;
    int x1 = 200, y1 = 200, x2 = 300, y2 = 300;
    int tx, ty;
    float sx, sy, angle;
    int choice;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Initialize graphics
    drawAxis();

    // Draw Original Shape
    setcolor(RED);
    drawRectangle(x1, y1, x2, y2);

    printf("Choose Transformation:\n1. Translation\n2. Scaling\n3. Rotation\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter translation factors (tx, ty): ");
            scanf("%d %d", &tx, &ty);
            translate(&x1, &y1, &x2, &y2, tx, ty);
            setcolor(GREEN);
            break;

        case 2:
            printf("Enter scaling factors (sx, sy): ");
            scanf("%f %f", &sx, &sy);
            scale(&x1, &y1, &x2, &y2, sx, sy);
            setcolor(BLUE);
            break;

        case 3:
            printf("Enter rotation angle: ");
            scanf("%f", &angle);
            rotate(&x1, &y1, &x2, &y2, angle);
            setcolor(YELLOW);
            break;

        default:
            printf("Invalid choice!");
    }

    // Draw Transformed Shape
    drawRectangle(x1, y1, x2, y2);
 setcolor(WHITE);
    outtextxy(10, 10, "Designed by Roshan Yadav");

    getch();
    closegraph();
    return 0;
}

