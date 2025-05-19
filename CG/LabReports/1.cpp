#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
int polygonPoint[3][2] = {{100, 100}, {150, 100}, {150, 200}};
void polyline(){
    cleardevice();
    line(100,240,640,240);
    line(320,0,320,480);
    for(int iCnt = 0; iCnt < 3; iCnt++){
        line(polygonPoint[iCnt][0], polygonPoint[iCnt][1], polygonPoint[(iCnt + 1) % 3][0], polygonPoint[(iCnt + 1) % 3][1]);
    }
}
void reflect(){
    for(int iCnt = 0; iCnt < 3; iCnt++){
        polygonPoint[iCnt][0] = 640-polygonPoint[iCnt][0];
    }
}
int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    for(int iCnt = 0; iCnt < 3; iCnt++){
        polygonPoint[iCnt][0] += 320;
        polygonPoint[iCnt][1] = 240 - polygonPoint[iCnt][1];
    }
    polyline();
    getch();
    reflect();
    polyline();
    getch();
    closegraph();
    return 0;
}
