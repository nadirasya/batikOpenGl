#include<iostream>
#include<graphics.h>
#include <string>
#include <complex>
#include <conio.h>
#include <math.h>
#include"transformation.h"
#include"stroke.h"

int pointTranslation (int x, int t)
{
    int xTranslated = x + t;
    return xTranslated;
}

void lineRotation (int x1, int x2, int y1, int y2, int c, int type, int ang)
{
    float angle=(ang*3.14)/180;
	int x4=x2-(((x2-x1)*cos(angle))-((y2-y1)*sin(angle)));
	int y4=y2-(((x2-x1)*sin(angle))+((y2-y1)*cos(angle)));
	line(x2,y2,x4,y4, c, type);
}

int pointScaling(int point, float scale)
{
    float scaled = point*scale;
    return scaled;
}

int pointXRotation(int x1, int y1, int x2, int y2, int ang)
{
    float angle=(ang*3.14)/180;
    int xRotated=x2-(((x2-x1)*cos(angle))-((y2-y1)*sin(angle)));
    return xRotated;
}

int pointYRotation(int x1, int y1, int x2, int y2, int ang)
{
    float angle=(ang*3.14)/180;
    int yRotated=y2-(((x2-x1)*sin(angle))+((y2-y1)*cos(angle)));
    return yRotated;
}
