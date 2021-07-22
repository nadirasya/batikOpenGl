#include"shapes.h"
#include"stroke.h"
#include"transformation.h"
#include"graph.h"
#include"utils.h"
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#include<iostream>
void rectangle(int minx,int miny, int maxx, int maxy, int c, int width, int type)
{
    widthLine(minx,miny,minx,maxy,type, c, width);
    widthLine(minx,miny,maxx,miny,type, c, width);
    widthLine(maxx,maxy,maxx,miny,type, c, width);
    widthLine(minx,maxy,maxx,maxy,type, c, width);
}
void rectangle2(int minx,int miny, int maxx, int maxy, int c, int width, int type1,int type2)
{
    widthLine(minx,miny,minx,maxy,type1, c, width);
    widthLine(minx,miny,maxx,miny,type2, c, width);
    widthLine(maxx,maxy,maxx,miny,type1, c, width);
    widthLine(minx,maxy,maxx,maxy,type2, c, width);
}
void square(int x1,int y1,int x2,int y2,int c, int width, int type)
{
    int y3 = x2-x1;
    widthLine(x1,y1,x2,y1,type, c, width);
    widthLine(x1,y1,x1,y3,type, c, width);
    widthLine(x1,y3,x2,y3,type,c, width);
    widthLine(x2,y1,x2,y3,type, c, width);
}
void rhombus(int x1,int y1,int x2,int y2,int c, int width, int type)
{
    int y3 = x2-x1;
    int x3 = x1+20;
    int x4 = x2+20;
    widthLine(x1,y1,x2,y1,type, c, width);
    widthLine(x1,y1,x3,y3,type, c, width);
    widthLine(x3,y3,x4,y3,type, c, width);
    widthLine(x2,y1,x4,y3,type, c, width);
}
void rhombus2(int x1,int y1,int x2,int y2,int c, int width, int type)
{
    int x3 = x2+(x2-x1);
    int xMid= (x2-x1)+x1;
    triangleEquilateral(x1, y1, x2, y2, c, width, type);
    lineRotation(x1,x3,y2,y2, 8, width, 0);
    lineRotation(xMid, x3, y1, y2, 5, 1, 285);
    lineRotation(xMid, x1, y1, y2, 11, 1, 75);
}
void kite(int x1,int y1,int x2,int y2,int c, int width, int type)
{
    int x3 = x2+(x2-x1);
    int xMid= (x2-x1)+x1;
    triangleEquilateral(x1, y1, x2, y2, c, width, type);
    lineRotation(x1,x3,y2,y2, 8, width, 0);
    y1 = pointScaling(y1, 3);
    lineRotation(xMid, x3, y1, y2, 5, 1, 0);
    lineRotation(xMid, x1, y1, y2, 11, 1, 0);
}
void paralleogram(int x1,int y1,int x2,int y2,int c, int width, int type)
{
    int x3 = x1+20;
    int x4 = x2+20;
    widthLine(x1,y1,x2,y1,type, c, width);
    widthLine(x3,y2,x4,y2,type, c, width);
    widthLine(x1,y1,x3,y2,type, c, width);
    widthLine(x2,y1,x4,y2, type, c, width);
}
void trapezoid(int x1,int y1,int x2,int y2,int c, int width, int type)
{
    int x3 = x1+10;
    int x4 = x2-10;
    widthLine(x3,y1,x4,y1,type, c, width);
    widthLine(x1,y2,x2,y2,type, c, width);
    widthLine(x3,y1,x1,y2,type, c, width);
    widthLine(x4,y1,x2,y2,type, c, width);
}
void trapezoid2(int x1,int y1,int x2,int y2,int c, int width, int type)
{
    int selisih = x2 - x1;
    lineRotation(x2, x1, y2, y2, 5, type, 180);
    lineRotation(x1, x1, y2,y1, 5, type, 0);
    lineRotation(x2, x1, y2,y1, 5, type, 90);
    x2 = pointTranslation(x2, selisih);
    rectangle(x1, y1, x2, y2, c, width, type);
    x2 = pointTranslation(x2, selisih);
    selisih = pointScaling(selisih, 2);
    x1 = pointTranslation(x1, selisih);
    triangle(x1, y1, x2, y2, 9, width, type);
}
void triangle(int x1,int y1,int x2,int y2,int c, int width, int type)
{
    int y3 = y1;
    widthLine(x1,y2,x2,y2,type, c, width);
    widthLine(x1,y2,x1,y3,type, c, width);
    widthLine(x2,y2,x1,y3,type, c, width);
}

void triangle2(int x1,int y1,int x2,int y2,int c, int width, int type1, int type2, int type3)
{
    int y3 = y1;
    widthLine(x1,y2,x2,y2,type1, c, width);
    widthLine(x1,y2,x1,y3,type2, c, width);
    widthLine(x2,y2,x1,y3,type3, c, width);
}

void triangleEquilateral(int x1,int y1,int x2,int y2,int c, int width, int type)
{
    int x3 = x2+(x2-x1);
    int xMid= (x2-x1)+x1;
    widthLine(x1,y2,x3,y2,type, c, width);
    widthLine(x1,y2,xMid,y1,type, 11, width);
    widthLine(xMid,y1,x3,y2,type, c, width);
}

void drawCircle(int x0, int y0, int radius, int c)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        putpixel(x0 + x, y0 + y, c);
        putpixel(x0 + y, y0 + x, c);
        putpixel(x0 - y, y0 + x, c);
        putpixel(x0 - x, y0 + y, c);
        putpixel(x0 - x, y0 - y, c);
        putpixel(x0 - y, y0 - x, c);
        putpixel(x0 + y, y0 - x, c);
        putpixel(x0 + x, y0 - y, c);
        if (err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }
        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void drawHalfCircle(int x0, int y0, int radius, int c, int type, int ang)
{
    float t = 3.14 / 180;
    int xRotated, yRotated;
    int x = radius;
    int y = 0;
    int err = 0;
    int alpha = (360 - ang)*t;
    while (x >= y)
    {
        if(type == 1){
            xRotated = x * cos(alpha)+ y*sin(alpha);
            yRotated = x*sin(alpha) - y*cos(alpha);
            putpixel(x0 + xRotated, y0 + yRotated, RED);
            putpixel(x0 + yRotated, y0 + xRotated, RED);
            alpha = ang * t;
            xRotated = x * cos(alpha)+ y*sin(alpha);
            yRotated = x*sin(alpha) - y*cos(alpha);
            putpixel(x0 + y, y0 - xRotated, c);
            putpixel(x0 + xRotated, y0 - y, c);
        }
        else {
            xRotated = x * cos(alpha)+ y*sin(alpha);
            yRotated = x*sin(alpha) - y*cos(alpha);
            putpixel(x0 - yRotated, y0 + xRotated, c);
            putpixel(x0 - xRotated, y0 + yRotated, c);
            alpha = ang * t;
            xRotated = x * cos(alpha)+ y*sin(alpha);
            yRotated = x*sin(alpha) - y*cos(alpha);
            putpixel(x0 - xRotated, y0 - yRotated, c);
            putpixel(x0 - yRotated, y0 - xRotated, c);
        }

        if (err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }
        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void drawFilledCircle(int x0, int y0, int radius, int c)
{
    int width = x0;
    for(int i=0; i<=width; i+1)
    {
        int x = radius;
        int y = 0;
        int err = 0;

        while (x >= y)
        {
            putpixel(x0 + x, y0 + y, c);
            putpixel(x0 + y, y0 + x, c);
            putpixel(x0 - y, y0 + x, c);
            putpixel(x0 - x, y0 + y, c);
            putpixel(x0 - x, y0 - y, c);
            putpixel(x0 - y, y0 - x, c);
            putpixel(x0 + y, y0 - x, c);
            putpixel(x0 + x, y0 - y, c);
            if (err <= 0)
            {
                y += 1;
                err += 2*y + 1;
            }

            if (err > 0)
            {
                x -= 1;
                err -= 2*x + 1;
            }
        }

        radius= radius - 1;
        i = i +1;
    }
}
void drawDashedCircle(int x0, int y0, int radius, int c)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        if (y%9<6)
        {
            putpixel(x0 + x, y0 + y, c);
            putpixel(x0 + y, y0 + x, c);
            putpixel(x0 - y, y0 + x, c);
            putpixel(x0 - x, y0 + y, c);
            putpixel(x0 - x, y0 - y, c);
            putpixel(x0 - y, y0 - x, c);
            putpixel(x0 + y, y0 - x, c);
            putpixel(x0 + x, y0 - y, c);
        }
        if (err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }

        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void drawDottedCircle(int x0, int y0, int radius, int c)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        if (y%9<3)
        {
            putpixel(x0 + x, y0 + y, c);
            putpixel(x0 + y, y0 + x, c);
            putpixel(x0 - y, y0 + x, c);
            putpixel(x0 - x, y0 + y, c);
            putpixel(x0 - x, y0 - y, c);
            putpixel(x0 - y, y0 - x, c);
            putpixel(x0 + y, y0 - x, c);
            putpixel(x0 + x, y0 - y, c);
        }
        if (err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }

        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void drawDottedDashedCircle(int x0, int y0, int radius, int c)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        if (y%9<6 || y%9==7)
        {
            putpixel(x0 + x, y0 + y, c);
            putpixel(x0 + y, y0 + x, c);
            putpixel(x0 - y, y0 + x, c);
            putpixel(x0 - x, y0 + y, c);
            putpixel(x0 - x, y0 - y, c);
            putpixel(x0 - y, y0 - x, c);
            putpixel(x0 + y, y0 - x, c);
            putpixel(x0 + x, y0 - y, c);
        }
        if (err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }

        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void drawWidthCircle (int x, int y, int r, int width, int type, int c, int halfCircleType, int ang)
{
    for(int i=0; i<=width; i+1)
    {
        switch(type)
        {
        case 1:
            drawCircle(x, y, r, c);
            break;
        case 2:
            drawDashedCircle(x, y, r, c);
            break;
        case 3:
            drawDottedCircle(x,y,r, c);
            break;
        case 4:
            drawDottedDashedCircle(x,y,r, c);
            break;
        case 5:
            drawHalfCircle(x, y, r, c, halfCircleType, ang);
            break;
        }
        r=r-1;
        i = i +1;
    }
}


void halfCircle (int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        putpixel(x0 + x, y0 + y, 10);
        putpixel(x0 + y, y0 + x, 2);
        putpixel(x0 - y, y0 + x, 3);
        putpixel(x0 - x, y0 + y, 4);

        if (err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }

        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void smiley()
{
    drawCircle(400, 150, 100, 1);
    drawCircle(440, 110, 20, 1);
    drawCircle(370, 110, 20, 1);
    line(405, 120, 405, 160, 8, 1);
    line(350, 170, 450, 170, 8, 1);
    halfCircle(400, 170, 50);
}

void smileyFilled()
{
    drawFilledCircle(150, 150, 100, 14);
    drawFilledCircle(190, 110, 20, 0);
    drawFilledCircle(120, 110, 20, 0);
    line(155, 120, 155, 160, 8, 1);
    halfCircle(150, 170, 50);
}

void displayEllipse2(int xc, int yc, int a, int b,
                 float alpha, int color)
{
    float t = 3.14 / 180;
    alpha = 360 - alpha;
    setcolor(color);
    int theta;

    for (int i = 0; i < 360; i += 1) {
        theta = i;
        int x = a * cos(t * theta) * cos(t * alpha)
                + b * sin(t * theta) * sin(t * alpha);

        int y = b * sin(t * theta) * cos(t * alpha)
                - a * cos(t * theta) * sin(t * alpha);

        putpixel(xc + x, yc - y, color);
    }
}
void displayEllipse(int xc, int yc, int rx, int ry,
                 float ang, int c)
{
    float t = 3.14 / 180;
   int x,y;float p, xRotated, yRotated, alpha;
    //Region 1
   p=ry*ry-rx*rx*ry+rx*rx/4;
   x=0;y=ry;
   while(2.0*ry*ry*x <= 2.0*rx*rx*y)
   {
	if(p < 0)
	{
		x++;
		p = p+2*ry*ry*x+ry*ry;
	}
	else
	{
		x++;
		y--;

		p = p+2*ry*ry*x-2*rx*rx*y-ry*ry;
	}
    alpha = (360 - ang)*t;
	xRotated = x * cos(alpha)+ y*sin(alpha);
    yRotated = x*sin(alpha) - y*cos(alpha);
	putpixel(xc+xRotated,yc+yRotated,c);
	putpixel(xc-xRotated,yc-yRotated,c);
	alpha = ang * t;
	xRotated = x * cos(alpha)+ y*sin(alpha);
    yRotated = x*sin(alpha) - y*cos(alpha);
	putpixel(xc+xRotated,yc-yRotated,c);
	putpixel(xc-xRotated,yc+yRotated,c);
   }

  //Region 2
   p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
   while(y > 0)
   {
	if(p <= 0)
	{
		x++;y--;
		xRotated = x * cos(alpha)-y*sin(alpha);
		yRotated = x*sin(alpha) + y*cos(alpha);
		p = p+2*ry*ry*x-2*rx*rx*y+rx*rx;
	}
	else
	{
		y--;
		xRotated = x * cos(alpha)+y*sin(alpha);
		yRotated = x*sin(alpha) - y*cos(alpha);
		p = p-2*rx*rx*y+rx*rx;
	}
	alpha = (360 - ang)*t;
	xRotated = x * cos(alpha)+ y*sin(alpha);
    yRotated = x*sin(alpha) - y*cos(alpha);
	putpixel(xc+xRotated,yc+yRotated,c);
	putpixel(xc-xRotated,yc-yRotated,c);
	alpha = ang * t;
	xRotated = x * cos(alpha)+ y*sin(alpha);
    yRotated = x*sin(alpha) - y*cos(alpha);
	putpixel(xc+xRotated,yc-yRotated,c);
	putpixel(xc-xRotated,yc+yRotated,c);
   }
}
void displayHalfEllipse(int xc, int yc, int rx, int ry,
                 float ang, int c, int pos)
{
    float t = 3.14 / 180;
   int x,y;float p, xRotated, yRotated, alpha, xTemp, yTemp;
    //Region 1
   p=ry*ry-rx*rx*ry+rx*rx/4;
   x=0;y=ry;
   int i = 1;
   while(2.0*ry*ry*x <= 2.0*rx*rx*y)
   {
	if(p < 0)
	{
		x++;
		p = p+2*ry*ry*x+ry*ry;
	}
	else
	{
		x++;
		y--;

		p = p+2*ry*ry*x-2*rx*rx*y-ry*ry;
	}
    alpha = (360 - ang)*t;
	xRotated = x * cos(alpha)+ y*sin(alpha);
    yRotated = x*sin(alpha) - y*cos(alpha);
    if(pos == 1){
        putpixel(xc+xRotated,yc+yRotated,c);
    }
	else {
        putpixel(xc-xRotated,yc-yRotated,c);
	}
	alpha = ang * t;
	xRotated = x * cos(alpha)+ y*sin(alpha);
    yRotated = x*sin(alpha) - y*cos(alpha);
    if(pos == 1){
        putpixel(xc-xRotated,yc+yRotated,c);
    }
    else{
       putpixel(xc+xRotated,yc-yRotated,c);
    }
   }
  //Region 2
   p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
   while(y > 0)
   {
	if(p <= 0)
	{
		x++;y--;
		xRotated = x * cos(alpha)-y*sin(alpha);
		yRotated = x*sin(alpha) + y*cos(alpha);
		p = p+2*ry*ry*x-2*rx*rx*y+rx*rx;
	}
	else
	{
		y--;
		xRotated = x * cos(alpha)+y*sin(alpha);
		yRotated = x*sin(alpha) - y*cos(alpha);
		p = p-2*rx*rx*y+rx*rx;
	}
	alpha = (360 - ang)*t;
	xRotated = x * cos(alpha)+ y*sin(alpha);
    yRotated = x*sin(alpha) - y*cos(alpha);
	if(pos == 1){
        putpixel(xc+xRotated,yc+yRotated,c);
        xTemp = xc+xRotated;
        yTemp = yc+yRotated;
    }
	else {
        putpixel(xc-xRotated,yc-yRotated,c);
        xTemp = xc-xRotated;
        yTemp = yc-yRotated;
	}
	//putpixel(xc-xRotated,yc-yRotated,c);
	alpha = ang * t;
	xRotated = x * cos(alpha)+ y*sin(alpha);
    yRotated = x*sin(alpha) - y*cos(alpha);
    if(pos == 1){
        putpixel(xc-xRotated,yc+yRotated,c);
        if(y<=0){
            line(xTemp, yTemp, xc-xRotated,yc+yRotated, c, 1);
        }
    }
    else{
       putpixel(xc+xRotated,yc-yRotated,c);
       if(y<=0){
            line(xTemp, yTemp, xc+xRotated,yc-yRotated, c, 1);
        }
    }
   }

}
void displayEllipseWidth(int xc, int yc, int rx, int ry,
                 float alpha, int color, int width, int type, int pos)
{
    for(int i = rx; i>= rx-width; i=i-1){
        if(type == 1){
            displayEllipse(xc, yc, i, ry, alpha, color);
        }
        else{
            displayHalfEllipse(xc, yc, i, ry, alpha,color, pos);
        }
        if(i%2==0){
            ry=ry-1;
        }
    }
}
void ellipsePosition(int xc, int yc, int r, int a, int b,
                  int alpha, float p, int color, int w, int type, int pos)
{
    int xTr = pointTranslation(xc, r+a);
    setcolor(color);
    int xR = pointXRotation(xTr, yc, xc, yc, alpha);
    int yR = pointYRotation(xTr, yc, xc, yc, alpha);
    int theta = 360 - alpha;
    displayEllipseWidth(xR, yR, a, b, theta, color, w, type, pos);
}

void circlePosition(int xc, int yc, int r, int width, int type, int c, int halfCircleType, int alpha){
    int xTr = pointTranslation(xc, r);
    int xR = pointXRotation(xTr, yc, xc, yc, alpha);
    int yR = pointYRotation(xTr, yc, xc, yc, alpha);
    int theta = 360 - alpha;
    drawWidthCircle(xR, yR, r, width, type, c, halfCircleType, theta);

}

void flower2(int xc, int yc, int type,int msec,
                       int r, int a, int b, int total, int c, int w)
{
    float theta = 0;
    if(type==3){
        theta = 25;
    }
    if(type==2){
        theta = 15;
    }
    double h, p1;
    float thetaCalculated = 360/total;
    h = (a * a) + (b * b);
    h /= 2;
    p1 = sqrt(h);
    p1 /= r;
    p1 = 1 / (p1);
    for (int i = 0; i<=total-1; theta += thetaCalculated) {
        ellipsePosition(xc, yc, r, a, b,
                     theta, p1, c, w, 1, 0);
        delay(msec);

        i++;
    }
}

void leaves(int xc, int yc, int a, int b)
{
    int aR = a;
    int bR = b;
    int x = 300;
    for(int i = 0; i<= a+2; i++){
        displayEllipse(xc+13, yc+10, aR, bR, 30, 1);
        displayEllipse(xc-a, yc, aR, bR,315, 1);
        displayEllipse(xc-a, yc+60, aR, bR,345, 1);
        displayEllipse(xc, yc-40, aR, bR,75, 1);
        //line(xc, yc-100, xc, yc+100, 1, 2);
        aR++;
        bR--;
    }
}

void leavesLined(int x, int y)
{
    for(int l = 0; l <=1; l++)
    {
        leaves(x, y, 10, 5);
        x = pointTranslation(x, 400);
    }
}


void flower(int xc, int yc, int msec,
                       int r, int a, int b, int total, int c, int w)
{
    float theta = 0;
    double h, p1;
    float thetaCalculated = 45;
    int maks = 360/thetaCalculated;
    h = (a * a) + (b * b);
    h /= 2;
    p1 = sqrt(h);
    p1 /= r;
    p1 = 1 / (p1);
    circle(xc, yc, r);
    int xTr = pointTranslation(xc, r+a);
    for (int i = 0; i<=maks-1; theta += thetaCalculated) {
        ellipsePosition(xc, yc,r, a, b, theta, p1, 4, 1, 1, 0);
      delay(500);
      i++;
   }
}
void flowerStem(int x, int y, int x1, int y1)
{
    for(int l = 0; l <=3; l++)
    {
        line(x,y,x1,y1, 1, 2);
        x+= 200;
        x1+=200;
    }
}
void halfFlower(int xc, int yc, int type,int msec,
                       int r, int a, int b, int total, int c, int w, int pos, int theta)
{
    float thetaCalculated =45;
    //float theta = 0;

    double h, p1;
    h = (a * a) + (b * b);
    h /= 2;
    p1 = sqrt(h);
    p1 /= r;
    p1 = 1 / (p1);
        delay(msec);
        ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*2, p1, c, w, 2, pos);
        if(pos == 1){
            ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated, p1, c, w, 1, pos);
            ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*8, p1, c, w, 1, pos);
            ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*7, p1, c, w, 1, pos);
            pos ++;
        }
        else{
            ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*3, p1, c, w, 1, pos);
            ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*4, p1, c, w, 1, pos);
            ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*5, p1, c, w, 1, pos);
            pos --;
        }
        ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*6, p1, c, w, 2, pos);

}

void halfFlowerBefore(int xc, int yc, int type,int msec,
                       int r, int a, int b, int total, int c, int w, int pos)
{
    float thetaCalculated =45;
    float theta = 0;
    if(type==3){
        theta += 180;
    }
    if(type==2){
        theta += 90;
    }
    if(type==4){
        theta += 270;
    }
    double h, p1;
    h = (a * a) + (b * b);
    h /= 2;
    p1 = sqrt(h);
    p1 /= r;
    p1 = 1 / (p1);
        delay(msec);
        ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*2, p1, c, w, 2, pos);
        if(pos == 1){
            ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated, p1, c, w, 1, pos);
            ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*8, p1, c, w, 1, pos);
            ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*7, p1, c, w, 1, pos);
            pos ++;
        }
        else{
            ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*3, p1, c, w, 1, pos);
            ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*4, p1, c, w, 1, pos);
            ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*5, p1, c, w, 1, pos);
            pos --;
        }
        ellipsePosition(xc, yc, r, a, b,
                     theta+thetaCalculated*6, p1, c, w, 2, pos);

}



