#include <graphics.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, char *label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 10, label);
}

int main() {
    int gd = DETECT, gm;
    int x1 = 200, y1 = 100;
    int x2 = 150, y2 = 200;
    int x3 = 250, y3 = 200;
    int reflectionY;

    printf("Enter the y-coordinate for reflection: ");
    scanf("%d", &reflectionY);

    initgraph(&gd, &gm, "");

    cleardevice();

    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE, "Original");

    y1 = 2 * reflectionY - y1;
    y2 = 2 * reflectionY - y2;
    y3 = 2 * reflectionY - y3;

    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE, "Reflected");

    getch();
    closegraph();

    return 0;
}

