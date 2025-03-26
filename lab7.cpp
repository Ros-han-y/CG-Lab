#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>

void display(int x1, int y1, int x2, int y2, int z, int color)
{
    int xmid = getmaxx() / 2;
    int ymid = getmaxy() / 2;
    setcolor(color);
    bar3d(xmid + x1, ymid + y1, xmid + x2, ymid + y2, z, 1);
}

void translate(int x1, int y1, int x2, int y2, int z, int tx, int ty, int tz)
{
    outtextxy(100, 50, "Before and After Translation Desgined by Roshan Yadav:");
    display(x1, y1, x2, y2, z, WHITE);
    display(x1 + tx, y1 + ty, x2 + tx, y2 + ty, z + tz, RED);
}

void scale(int x1, int y1, int x2, int y2, int z, float sx, float sy, float sz)
{
    outtextxy(100, 50, "Before and After Scaling Desgined by Roshan Yadav:");
    display(x1, y1, x2, y2, z, WHITE);
    display(x1 * sx, y1 * sy, x2 * sx, y2 * sy, z * sz, RED);
}

void xrotate(int x1, int y1, int x2, int y2, int z, float a)
{
    a = a * (3.1415 / 180);
    float c = cos(a);
    float s = sin(a);
    outtextxy(100, 50, "Before and After Rotation (X-Axis) Designed by Roshan Yadav:");
    display(x1, y1, x2, y2, z, WHITE);
    display(x1, y1 * c - z * s, x2, y2 * c - z * s, ((y1 + y2) / 2) * s + z * c, RED);
}

void yrotate(int x1, int y1, int x2, int y2, int z, float a)
{
    a = a * (3.1415 / 180);
    float c = cos(a);
    float s = sin(a);
    outtextxy(100, 50, "Before and After Rotation (Y-Axis) Desgined by Roshan Yadav:");
    display(x1, y1, x2, y2, z, WHITE);
    display(x1 * c + z * s, y1, x2 * c + z * s, y2, z * c - ((x1 + x2) / 2) * s, RED);
}

void zrotate(int x1, int y1, int x2, int y2, int z, float a)
{
    a = a * (3.1415 / 180);
    float c = cos(a);
    float s = sin(a);
    outtextxy(100, 50, "Before and After Rotation (Z-Axis) Desgined by Roshan Yadav:");
    display(x1, y1, x2, y2, z, WHITE);
    display(x1 * c - y1 * s, x1 * s + y1 * c, x2 * c - y2 * s, x2 * s + y2 * c, z, RED);
}

int main()
{
    int x1, y1, x2, y2, z;
    int gd = DETECT, gm;
    
    printf("Enter the coordinates of the diagonal points of 3D object (x1, y1, x2, y2, z):\n");
    scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &z);
    
    while (1)
    {
        int ch;
        printf("\nEnter Your Choice:\n");
        printf("1-Translation\n2-Scaling\n3-Rotation about X-axis\n4-Rotation about Y-axis\n5-Rotation about Z-axis\n0-EXIT\n");
        scanf("%d", &ch);
        
        if (ch == 1)
        {
            int tx, ty, tz;
            printf("Enter tx, ty, and tz:\n");
            scanf("%d %d %d", &tx, &ty, &tz);
            initgraph(&gd, &gm, NULL);
            translate(x1, y1, x2, y2, z, tx, ty, tz);
            getch();
            closegraph();
        }
        else if (ch == 2)
        {
            float sx, sy, sz;
            printf("Enter Sx, Sy, and Sz:\n");
            scanf("%f %f %f", &sx, &sy, &sz);
            initgraph(&gd, &gm, NULL);
            scale(x1, y1, x2, y2, z, sx, sy, sz);
            getch();
            closegraph();
        }
        else if (ch == 3)
        {
            float a;
            printf("Enter Angle:\n");
            scanf("%f", &a);
            initgraph(&gd, &gm, NULL);
            xrotate(x1, y1, x2, y2, z, a);
            getch();
            closegraph();
        }
        else if (ch == 4)
        {
            float a;
            printf("Enter Angle:\n");
            scanf("%f", &a);
            initgraph(&gd, &gm, NULL);
            yrotate(x1, y1, x2, y2, z, a);
            getch();
            closegraph();
        }
        else if (ch == 5)
        {
            float a;
            printf("Enter Angle:\n");
            scanf("%f", &a);
            initgraph(&gd, &gm, NULL);
            zrotate(x1, y1, x2, y2, z, a);
            getch();
            closegraph();
        }
        else if (ch == 0)
        {
            printf("EXITED\n");
            break;
        }
    }
  
    return 0;
}

