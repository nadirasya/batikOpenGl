#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include"graph.h"

void graph1(int midX, int midY, int scale){
    for(float x = 0; x <= 10; x=x+0.0001){
        float y = pow(x,2);
        float xScaled = scale* x+midX;
        float yScaled = scale* -1*y + midY;
        putpixel(xScaled, yScaled, 2);
    }
    setcolor(2);
    outtextxy(midX+5,midY/2,"y = x^2");
}

void graph2(int midX, int midY, int scale){
    for(float x = 0; x <= 10; x=x+0.0001){
        float y = pow(x,3);
        y = y - (3*x);
        y = y -1;
        float xScaled = scale* x+midX;
        float yScaled = scale* -1*y + midY;
        putpixel(xScaled, yScaled, 6);
    }
    setcolor(6);
    outtextxy(midX+10,midY+125,"y = x^3 - 3x -1");
}

void graph3(int midX, int midY, int scale){
    for(float x = 0; x <= 10; x=x+0.01){
        float y = sin(x);
        float xScaled = scale* x+midX;
        float yScaled = scale* -1*y + midY;
        putpixel(xScaled, yScaled, 4);
    }
    setcolor(5);
}

void graph4(int midX, int midY, int scale){
    for(float x = 0; x <= 10; x=x+0.01){
        float y = cos(x);
        float xScaled = scale* x+midX;
        float yScaled = scale* -1*y + midY;
        putpixel(xScaled, yScaled, 4);
    }
    setcolor(5);
}
