#include <graphics.h>
#include <stdio.h>
#include <math.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

// Function to calculate binomial coefficient
int binomialCoeff(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Bezier function to calculate points
void bezierCurve(int x[], int y[], int n, float t, int *px, int *py) {
    *px = 0;
    *py = 0;
    for (int i = 0; i < n; i++) {
        float coeff = binomialCoeff(n - 1, i) * pow(1 - t, n - 1 - i) * pow(t, i);
        *px += coeff * x[i];
        *py += coeff * y[i];
    }
}

// Function to draw the Bezier Curve
void drawBezierCurve(int x[], int y[], int n) {
    int px, py;
    for (float t = 0; t <= 1; t += 0.001) {
        bezierCurve(x, y, n, t, &px, &py);
        putpixel(px, py, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Control points (Change these for different curves)
    int x[] = {100, 200, 300, 400};
    int y[] = {300, 100, 400, 300};
    int n = 4; // Number of control points

    // Draw control points
    for (int i = 0; i < n; i++) {
        putpixel(x[i], y[i], RED);
    }

    // Draw the Bezier curve
    drawBezierCurve(x, y, n);
 setcolor(WHITE);
    outtextxy(10, 10, "Designed by Roshan Yadav");
    getch();
    closegraph();
    return 0;
}

