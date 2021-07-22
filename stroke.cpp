#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include <string>
#include<dos.h>
#include"stroke.h"

using namespace std;

void line(int x1,int y1,int x2,int y2,int c, int type)
{
    int x,y,dx,dy,dx1,dy1,px,py,xe,ye,i;
    dx=x2-x1;
    dy=y2-y1;
    dx1=fabs(dx);
    dy1=fabs(dy);
    px=2*dy1-dx1;
    py=2*dx1-dy1;
    if(dy1<=dx1)
    {
        if(dx>=0)
        {
            x=x1;
            y=y1;
            xe=x2;
        }
        else
        {
            x=x2;
            y=y2;
            xe=x1;
        }
        switch(type){
        case 1:
            putpixel(x,y,c);
            break;
        case 2:
            if(i%9<3){
               putpixel(x,y,c);
            }
            break;
        case 3:
            if(i%9<6){
               putpixel(x,y,c);
            }
            break;
        case 4:
            if((i%9<2)||(i%9==7)){
               putpixel(x,y,c);
            }
            break;
        }


        for(i=0; x<xe; i++)
        {
            x=x+1;
            if(px<0)
            {
                px=px+2*dy1;
            }
            else
            {
                if((dx<0 && dy<0) || (dx>0 && dy>0))
                {
                    y=y+1;
                }
                else
                {
                    y=y-1;
                }
                px=px+2*(dy1-dx1);
            }
            delay(0);
            switch(type){
        case 1:
            putpixel(x,y,c);
            break;
        case 2:
            if(i%9<3){
               putpixel(x,y,c);
            }
            break;
        case 3:
            if(i%9<6){
               putpixel(x,y,c);
            }
            break;
        case 4:
            if((i%9<2)||(i%9==7)){
               putpixel(x,y,c);
            }
            break;
        }
        }
    }
    else
    {
        if(dy>=0)
        {
            x=x1;
            y=y1;
            ye=y2;
        }
        else
        {
            x=x2;
            y=y2;
            ye=y1;
        }
        switch(type){
        case 1:
            putpixel(x,y,c);
            break;
        case 2:
            if(i%9<3){
               putpixel(x,y,c);
            }
            break;
        case 3:
            if(i%9<6){
               putpixel(x,y,c);
            }
            break;
        case 4:
            if((i%9<2)||(i%9==7)){
               putpixel(x,y,c);
            }
            break;
        }
        for(i=0; y<ye; i++)
        {
            y=y+1;
            if(py<=0)
            {
                py=py+2*dx1;
            }
            else
            {
                if((dx<0 && dy<0) || (dx>0 && dy>0))
                {
                    x=x+1;
                }
                else
                {
                    x=x-1;
                }
                py=py+2*(dx1-dy1);
            }
            delay(0);
            switch(type){
            case 1:
                putpixel(x,y,c);
                break;
            case 2:
                if(i%9<3){
                   putpixel(x,y,c);
                }
                break;
            case 3:
                if(i%9<6){
                   putpixel(x,y,c);
                }
                break;
            case 4:
                if((i%9<2)||(i%9==7)){
                   putpixel(x,y,c);
                }
                break;
            }
        }
    }

}

void colorLine(int x1,int y1,int x2,int y2, int type, int c)
{
    setcolor(c);
    line(x1, y1, x2, y2, c, type);
}

void widthLine (int x1,int y1,int x2,int y2,int type, int c,int width)
{
    int x,y,dx,dy,dx1,dy1,px,py,xe,ye,i;
    dx=x2-x1;
    dy=y2-y1;
    dx1=fabs(dx);
    dy1=fabs(dy);
    if(dy1<=dx1)
    {
        for(int i=0; i<=width; i++)
        {
            colorLine(x1, y1, x2, y2,type, c);
            y1=y1+1;
            y2=y2+1;
        }
    }
    else
    {
        for(int i=0; i<=width; i++)
        {
            colorLine(x1, y1, x2, y2,type, c);
            x1 = x1+1;
            x2=x2+1;
        }
    }
}

void typeLine(int x1,int y1,int x2,int y2,int c, int width, int type)
{
    int x,y,dx,dy,dx1,dy1,px,py,xe,ye,len, i;
    dx=x2-x1;
    dy=y2-y1;
    dx1=fabs(dx);
    dy1=fabs(dy);
    px=2*dy1-dx1;
    py=2*dx1-dy1;
    if(dy1<=dx1)
    {
        len=dx;
    }
    else
    {
        len=dy;
    }
    dx = (x2-x1)/len;
    dy = (y2-y1)/len;
    x = x1 + 0.5;
    y = y1 + 0.5;
    switch(type)
    {
    //straight line
    case 1:
        widthLine(x1, y1, x2, y2, c, type, width);
        break;
    //dotted line
    case 2:
        for(i=0; i<=len; i++)
        {
            if (i%9<2) {}
            else if (i%9<3)
            {
                widthLine(x, y, x, y, c,type, width);
            }
            else {}
            x += dx;
            y += dy;
        }
        break;
    //dashed line
    case 3:
        for(i=0; i<=len; i++)
        {
            if (i%9<2) {}
            else if (i%9<6)
            {
                widthLine(x, y, x, y, c, type, width);
            }
            else {}
            x += dx;
            y += dy;
        }
        break;
    //dashed-dotted line
    case 4:
        for(i=0; i<=len; i++)
        {
            if (i%9<2) {}
            else if (i%9<6)
            {
                widthLine(x, y, x, y, c, type, width);
            }
            else if(i%9==7) {}
            else
            {
                widthLine(x, y, x, y, c, type, width);
            }
            x += dx;
            y += dy;
        }
        break;
    }

}
void dda_line(int x1,int x2,int y1,int y2)
{

    float dx,dy,len,x,y,xi,yi;

    int i;

    dx = abs(x2-x1);

    dy = abs(y2-y1);



    if(dx>=dy)

        len=dx;

    else

        len=dy;



    dx = (x2-x1)/len;

    dy = (y2-y1)/len;



    x = x1 + 0.5;

    y = y1 + 0.5;

    putpixel(x1,y1,3);

    putpixel(x2,y2,3);

    for(i=0; i<=len; i++)

    {
        if(i%9<2)

        {}

        else if(i%9<6)

            putpixel(x,y,3);

        else if(i%9==7)

        {}

        else

            putpixel(x,y,3);

        x += dx;

        y += dy;

    }

}

