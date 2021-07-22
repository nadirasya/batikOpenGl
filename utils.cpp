#include<iostream>
#include<graphics.h>
#include <string>
#include <conio.h>
#include <math.h>
#include"stroke.h"
#include"shapes.h"
#include"utils.h"
#include"transformation.h"
#include"graph.h"

void menu ()
{
    int choice = 0;
    while(choice<=7)
    {
        printf("1. Program Garis\n");
        printf("2. Program Batik\n");
        printf("3. Program Eksplorasi\n");
        printf("4. Program Lingkaran\n");
        printf("5. Smiley\n");
        printf("6. Program Family Crest\n");
        printf("7. Program Grafik Berdasarkan Persamaan\n");
        printf("8. Keluar\n");
        printf("Pilihan anda: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            openGraph();
            //transformPoint();
            programSkala();
            break;
        case 2:
            openGraph();
            //menuBentuk();
            batikKompilasi();
            //programBunga(250, 150, 70, 35);
            break;
        case 3:
            openGraph();
            programEksplorasi();
            break;
        case 4:
            openGraph();
            programLingkaran();
            break;
        case 5:
            openGraph();
            programSmiley();
            break;
        case 6:
            openGraph();
            //programLogo();
            programFamilyCrest();
            break;
        case 7:
            openGraph();
            programGraph();
            break;
        }
    }
}

void programGraph()
{
 int x1,x2,y1,y2, maxx, maxy, minx, miny, midx, midy;
 maxx = getmaxx()-1;
 maxy = getmaxy()-1;
 minx = 1;
 miny = 1;
 midx = (maxx-minx)/2;
 midy = (maxy-miny)/2;
 int scale = 15;
 graph1(midx, midy, scale);
 graph2(midx, midy, scale);
 graph3(midx, midy, scale);
 graph4(midx, midy, scale);
 int midxTranslated = pointTranslation(midx, -midx + 15);
 scale = 30;
 graph1(midxTranslated, midy, scale);
 graph2(midxTranslated, midy, scale);
 graph3(midxTranslated, midy, scale);
 graph4(midxTranslated, midy, scale);
 line(minx,miny,minx,maxy,WHITE, 1);
 line(minx,miny,maxx,miny,WHITE, 1);
 line(maxx,maxy,maxx,miny,WHITE, 1);
 line(minx,maxy,maxx,maxy,WHITE, 1);
 line(minx,midy,maxx,midy,WHITE, 1);
 line(midx,miny,midx,maxy,WHITE, 1);
}

void menuBentuk(){
 int choice = 0;
 while(choice<=2)
 {
    printf("1. Program Bentuk\n");
    printf("2. Program Trapesium\n");
    printf("3. Kembali\n");
    printf("Pilihan anda: ");
    scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            openGraph();
            programBentuk();
            break;
        case 2:
            openGraph();
            programTrapesium();
            break;
        case 3:
            menu ();
            break;
        }
    }
}

void programFamilyCrest()
{
    int x1,x2,y1,y2, maxx, maxy, minx, miny, midx, midy;
    maxx = getmaxx()-1;
    maxy = getmaxy()-1;
    minx = 1;
    miny = 50;
    midx = (maxx-minx)/2;
    midy = (maxy-miny)/2;
    flower(midx, midy,0,
                      1, 40, 40, 8, 2, 1);
}

void programGaris()
{
    int x1,x2,y1,y2, maxx, maxy, minx, miny, midx, midy;
    maxx = getmaxx()-1;
    maxy = getmaxy()-1;
    minx = 1;
    miny = 50;
    midx = (maxx-minx)/2;
    midy = (maxy-miny)/2;
    outtextxy(minx,miny-25,"Garis Biasa");
    line(minx, miny, maxx, miny, WHITE, 1);
    outtextxy(minx,miny+25,"Garis Berwarna");
    colorLine(minx, miny+50, maxx, miny+50,2, 1);
    setcolor(WHITE);
    outtextxy(minx,miny+75,"Garis Tebal");
    widthLine(minx, miny+100, maxx, miny+100, 1,10, 5);
    setcolor(WHITE);
    outtextxy(minx,miny+125,"Garis titik - titik");
    widthLine(minx, miny+150, maxx, miny+150, 2, 2,1);
    setcolor(WHITE);
    outtextxy(minx,miny+175,"Garis putus - putus");
    widthLine(minx, miny+200, maxx, miny+200, 3, 9,3);
    setcolor(WHITE);
    outtextxy(minx,miny+225,"Garis putus - putus dan titik-titik");
    widthLine(minx, miny+250, maxx, miny+250, 4, 11,4);
    setcolor(WHITE);
    outtextxy(minx,miny+275,"Garis putus - putus dan titik-titik dengan metoda DDA");
    dda_line(minx, maxx,miny+300,  miny+300);
    setcolor(WHITE);
    outtextxy(minx,miny+325,"Garis putus - putus tebal");
    widthLine(minx, miny+350, maxx, miny+350, 2, 5,5);
    setcolor(WHITE);
}

void programGaris2()
{
    widthLine(20,20,20,300,4,4,10);
    widthLine(60,20,60,300,2,5,10);
    widthLine(100,20,100,300,3,6,10);
    widthLine(140,20,140,300,3,7,30);
}

void programSkala()
{
    float x1,y1,x2,y2,sx,sy;
    std::cout<<"SCALING OF A LINE\n";
	std::cout<<"Enter the first coordinate of a line:";
	std::cin>>x1>>y1;
	std::cout<<"Enter the second coordinate of a line:";
	std::cin>>x2>>y2;
	line(x1,y1,x2,y2, 7, 1);
	std::cout<<"Enter the scaling factor:";
	std::cin>>sx>>sy;
	setcolor(RED);
	//x1=x1*sx;
	y1=y1*sy;
	x2=x2*sx;
	y2=y2*sy;
	line(x1,y1,x2,y2, 1, 1);
}


void transformPoint()
{
    int gd=DETECT,gm,x1,x2,y1,y2,x4,y4;
    float angle=0,ang;
	std::cout<<"Enter the first coordinate of a line:";
	std::cin>>x1>>y1;
	std::cout<<"Enter the second coordinate of a line:";
	std::cin>>x2>>y2;
	line(x1,y1,x2,y2);
	std::cout<<"Enter the angle:";
	std::cin>>ang;
	lineRotation(x1, x2, y1, y2, 1, 1, ang);
}

void programBentuk()
{
    int x1,x2,y1,y2, maxx, maxy, minx, miny, midx, midy;
    maxx = getmaxx()-1;
    maxy = getmaxy()-1;
    minx = 1;
    miny = 1;
    midx = (maxx-minx)/2;
    midy = (maxy-miny)/2;
    rhombus(minx+30, miny+50, minx+110, midy+140, 3, 1,1);
    setcolor(WHITE);
    outtextxy(minx+30,miny+25,"Jajar genjang");
    rectangle(minx+30, miny+120, minx+80, miny+170, 7,1, 1);
    setcolor(WHITE);
    outtextxy(minx+30,miny+100,"Persegi");
    rectangle(minx+30, miny+200, minx+120, miny+250, 6,1,1);
    setcolor(WHITE);
    outtextxy(minx+30,miny+180,"Persegi Panjang");
    setcolor(WHITE);
    outtextxy(minx+200,miny+25,"Segitiga");
    trapezoid2(minx+200, miny+120, minx+250, miny+170, 1, 1,1);
    setcolor(WHITE);
    outtextxy(minx+200,miny+100,"Trapesium");
    paralleogram(minx+200, miny+200, minx+240, miny+250, 9, 1,1);
    setcolor(WHITE);
    outtextxy(minx+200,miny+180,"Belah Ketupat");
}
void batikKompilasi()
{
    int x1,x2,y1,y2, maxx, maxy, minx, miny, midx, midy;
    maxx = getmaxx()-1;
    maxy = getmaxy()-1;
    minx = 1;
    miny = 1;
    midx = (maxx-minx)/2;
    midy = (maxy-miny)/2;
    for(int j = miny; j<= maxy*3; j += 500){
    for(int i = minx; i <= maxx*2; i += 500){
        batik(i, j);
    }
    }
}
void batik(int maxx, int maxy)
{
    int diff = 100;
    int c = rand()%15;
    for(int i = 0; i <=1; i++){
        flower(maxx / 2 - diff, maxy / 2 - diff, 0,
                      1, 20, 10, 4, c, 1);
        diff=diff-200;
    }

    flower(maxx / 2, maxy / 2,0,
                      1, 40, 20, 10, c, 1);
}


void programTrapesium()
{
    triangle2(50, 20, 20, 50, 2, 1, 1, 2, 2);
    triangle2(100, 20, 130, 50, 2, 1, 1, 2, 2);
    rectangle2(50, 20, 100, 50, 2, 1, 2, 2);
    triangle2(50, 70, 20, 100, 3, 1, 2, 2, 2);
    triangle2(100, 70, 130, 100, 3, 1, 2, 2, 2);
    rectangle2(50, 70, 100, 100, 3, 1, 2, 2);
}
void programEksplorasi()
{
    int x1,x2,y1,y2, maxx, maxy, minx, miny, midx, midy;
    maxx = getmaxx()-1;
    maxy = getmaxy()-1;
    minx = 1;
    miny = 1;
    midx = (maxx-minx)/2;
    midy = (maxy-miny)/2;
    int maks = 42;
    int color = 1;
    for(int i=0; i <= maks; i++ )
    {
        square(minx, miny, maxx, maxy, color, 1, 1);
        color=color+1;
        if(color>=15)
        {
            color=1;
        }
        minx=minx+5;
        miny=miny+5;
        maxx=maxx-5;
        maxy=maxy-5;
    }
}

void programLingkaran()
{
    drawWidthCircle(70,60,50,1,1, 1, 0, 0);
    drawWidthCircle(190,60,50,10,1,1, 0, 0);
    drawWidthCircle(310,60,50,70,1, 1, 0, 0);
    outtextxy(400,60,"Lingkaran biasa");
    drawWidthCircle(70,180,50,1,2, 1, 0, 0);
    drawWidthCircle(190,180,50,10,2, 1, 0, 0);
    drawWidthCircle(310,180,50,70,2,1, 0, 0);
    outtextxy(400,180,"Lingkaran putus-putus");
    drawWidthCircle(70,300,50,1,3, 1, 0, 0);
    drawWidthCircle(190,300,50,10,3, 1, 0, 0);
    drawWidthCircle(310,300,50,70,3, 1, 0, 0);
    outtextxy(400,300,"Lingkaran titik-titik");
    drawWidthCircle(70,420,50,1,4, 1, 0, 0);
    drawWidthCircle(190,420,50,10,4, 1, 0, 0);
    drawWidthCircle(310,420,50,70,4, 1, 0, 0);
    outtextxy(400,420,"Lingkaran titik-titik & putus-putus");
}
void programSmiley()
{
    smileyFilled();
    smiley();
}
void flowerPattern1(int midx, int midy, int type, int r, int theta, float scale)
{
    int x1,x2,y1,y2, maxx, maxy, minx, miny;
    maxx = getmaxx()-1;
    maxy = getmaxy()-1;
    minx = 1;
    miny = 1;
    //midx = (maxx-minx)/2 - 200;
    int c = 13;
    int maks =0;
    int midxInc = midx;
    int midyInc = midy;
    int thetaCcw = 360 - (theta + 270);
    int pos =2;
    float x = 20;
    float y = 8;
    //membentuk lingkaran terluar pertama
    for (int i=0; i<=maks; i++)
    {
        float rScaled = pointScaling(r, scale);
        displayEllipseWidth(midxInc, midyInc, rScaled, rScaled, thetaCcw, 1, 3 ,2,pos);
        midxInc = pointTranslation(midxInc, 200);
    }
    //membentuk lingkaran terluar kedua
    midxInc = midx;
    midyInc = midy;
    for (int i=0; i<=maks; i++)
    {
        float rScaled = pointScaling(r, scale * 1.2);
        displayEllipseWidth(midxInc, midyInc, rScaled, rScaled, thetaCcw, 1, 3, 2, pos);
        midxInc = pointTranslation(midxInc, 200);
    }
    //membantuk bunga yang mana akan menimpa garis terluar
    midxInc = midx;
    midyInc = midy;
    for (int i=0; i<=maks; i++)
    {
        float xScaled = pointScaling(x, scale);
        float yScaled = pointScaling(y, scale);
        halfFlower(midxInc, midyInc,type, 0, 1, xScaled, yScaled, 8, WHITE, x+2, 1, theta);
        midxInc = pointTranslation(midxInc, 200);
    }
    //membentuk bunga
    midxInc = midx;
    midyInc = midy;
    for (int i=0; i<=maks; i++)
    {
        float xScaled = pointScaling(x, scale);
        float yScaled = pointScaling(y, scale);
        halfFlower(midxInc, midyInc,type, 0, 1, xScaled, yScaled, 8, 3, 6, 1, theta);
        midxInc = pointTranslation(midxInc, 200);
    }
    //membentuk lingkaran dalam bunga pertama
    midxInc = midx;
    midyInc = midy;
    for (int i=0; i<=maks; i++)
    {
        float rScaled = pointScaling(r, scale * 0.3);
        displayEllipseWidth(midxInc, midyInc, rScaled, rScaled, thetaCcw, 1, 5, 2,pos);
        midxInc = pointTranslation(midxInc, 200);
    }
    //membentuk lingkaran dalam bunga kedua
    midxInc = midx;
    midyInc = midy;
    for (int i=0; i<=maks; i++)
    {
        //float scale = 0.2;
        float rScaled = pointScaling(r, scale * 0.2);
        displayEllipseWidth(midxInc, midyInc, rScaled, rScaled, thetaCcw,WHITE, rScaled, 2, pos);
        midxInc = pointTranslation(midxInc, 200);
    }
}
void flowerPattern2(int midx, int midy, int type, int r, int theta, float scale)
{
    int x1,x2,y1,y2, maxx, maxy, minx, miny;
    maxx = getmaxx()-1;
    maxy = getmaxy()-1;
    minx = 1;
    miny = 1;
    //midx = (maxx-minx)/2 - 200;
    int c = 13;
    int maks =0;
    int midxInc = midx;
    int midyInc = midy;
    int thetaCcw = 360 - (theta+90);
    //float theta = 270;
    float x = 15;
    float y = 4;
    midxInc = midx;
    midyInc = midy;
    //membentuk lingkaran terluar bunga
    for (int i=0; i<=maks; i++)
    {
        float rScaled = pointScaling(r, scale * 1.2);
        displayEllipseWidth(midxInc, midyInc, rScaled, rScaled, thetaCcw,3, 3,2, 2);
        midxInc = pointTranslation(midxInc, 200);
    }
    //membentuk bunga dengan aksennya
    midxInc = midx;
    midyInc = midy;
    for (int i=0; i<=maks; i++)
    {
        float xScaled = pointScaling(x, scale);
        float yScaled = pointScaling(y, scale);
        float rScaled = pointScaling(r, scale * 0.3);
        halfFlower(midxInc, midyInc, type, 0, rScaled, xScaled, yScaled,8, 1, x+2, 2, theta);
        halfFlowerAccent(midxInc, midyInc, rScaled, xScaled, yScaled, 1, 3, 2, thetaCcw);
        midxInc = pointTranslation(midxInc, 200);
    }
    //membentuk lingkaran dalam bunga pertama
    midxInc = midx;
    midyInc = midy;
    for (int i=0; i<=maks; i++)
    {
        float rScaled = pointScaling(r, scale * 0.3);
        displayEllipseWidth(midxInc, midyInc, rScaled, rScaled, thetaCcw, 3, 5, 2, 2);
        midxInc = pointTranslation(midxInc, 200);
    }
    //membentuk lingkaran dalam bunga kedua
    midxInc = midx;
    midyInc = midy;
    for (int i=0; i<=maks; i++)
    {
        float rScaled = pointScaling(r, scale * 0.2);
        displayEllipseWidth(midxInc, midyInc, rScaled, rScaled, thetaCcw,WHITE, rScaled, 2, 2);
        midxInc = pointTranslation(midxInc, 200);
    }
    //membentuk lingkaran dalam bunga ketiga
    midxInc = midx;
    midyInc = midy;
    for (int i=0; i<=maks; i++)
    {
        float rScaled = pointScaling(r, scale * 0.1);
        displayEllipseWidth(midxInc, midyInc, rScaled, rScaled, thetaCcw,3, rScaled, 2, 2);
        midxInc = pointTranslation(midxInc, 200);
    }
}
void halfFlowerAccent(int xc, int yc, int r, int a, int b,int cLine, int cCircle, int w, int alpha)
{
    float theta = (360-alpha) + 22.5;
    for(int i = 0; i<= 3; i++)
    {
        flowerAccentPosition(xc, yc, r, a, b, theta, cLine, cCircle, w);
        theta += 43.5;
    }
}
void flowerAccentPosition(int xc, int yc, int r, int a, int b,
                  int alpha, int cLine, int cCircle, int w)
{
    int theta = 360 - alpha;
    int x1, y1, x2, y2;
    int xTr = pointTranslation(xc, r+a);
    int xR = pointXRotation(xTr, yc, xc, yc, alpha);
    int yR = pointYRotation(xTr, yc, xc, yc, alpha);
    xTr = pointTranslation(xc, r);
    x1 = pointXRotation(xTr, yc, xc, yc, alpha);
    y1 = pointYRotation(xTr, yc, xc, yc, alpha);
    xTr = pointTranslation(xc, r+a*2);
    x2 = pointXRotation(xTr, yc, xc, yc, alpha);
    y2 = pointYRotation(xTr, yc, xc, yc, alpha);
    widthLine(x1,y1, x2, y2, cLine, 1, w);
    drawWidthCircle(xR, yR, 4, 4, 1, 3, 0, theta);
}
void programScreenSaver()
{
    setactivepage(0);
    int x1,x2,y1,y2, maxx, maxy, minx, miny, midx, midy, midxInc, xFlower, yInc, xInc;
    maxx = getmaxx()-1;
    maxy = getmaxy()-1;
    minx = 1;
    miny = 1;
    midx = (maxx-minx)/2 - 300;
    midxInc = midx;
    xFlower = minx + 100;
    int distance = 150;
    int distance2= 230;
    int xEnd = xFlower + distance2*2;
    midy = miny+100;
    xInc = xFlower;
    yInc = midy;
    int xInc2 = xFlower + distance2;
    int xInc3 = xFlower + distance2*2;
    int xInc4 = xFlower;
    int xInc5 = xFlower + distance2;
    int xInc6 = xFlower + distance2*2;
    int xInc7 = xFlower;
    int xInc8 = xFlower + distance2;
    int xInc9 = xFlower + distance2*2;
    int yInc2 = midy;
    int yInc3 = midy;
    int yInc4 = midy + distance;
    int yInc5 = midy + distance;
    int yInc6 = midy + distance;
    int yInc7 = midy + distance*2;
    int yInc8 = midy + distance*2;
    int yInc9 = midy + distance*2;
    int yEnd = yInc9;
    int xStart = xFlower;
    int leavesAdd = -360;
    int leavesAdd2 = maxy;
    int win =1;
    int type = 1;
    int ang = 0;
    float scale = 1;
    for(;;){
        setactivepage(win);
        setbkcolor(WHITE);
        cleardevice();
        int midyInc = midy;
        int leavesPosition = leavesAdd;
         int leavesPosition2 = leavesAdd2;
        flowerStem(midxInc, miny, midxInc, maxy);
        flowerPattern1(xInc, yInc, type, 30, ang, scale);
        flowerPattern2(xInc, yInc, type, 30, ang, scale);
        flowerPattern1(xInc2, yInc2, type, 30, ang, scale);
        flowerPattern2(xInc2, yInc2, type, 30, ang, scale);
        flowerPattern1(xInc3, yInc3, type, 30, ang, scale);
        flowerPattern2(xInc3, yInc3, type, 30, ang, scale);
        flowerPattern1(xInc4, yInc4, type, 30, ang, scale);
        flowerPattern2(xInc4, yInc4, type, 30, ang, scale);
        flowerPattern1(xInc5, yInc5, type, 30, ang, scale);
        flowerPattern2(xInc5, yInc5, type, 30, ang, scale);
        flowerPattern1(xInc6, yInc6, type, 30, ang, scale);
        flowerPattern2(xInc6, yInc6, type, 30, ang, scale);
        flowerPattern1(xInc7, yInc7, type, 30, ang, scale);
        flowerPattern2(xInc7, yInc7, type, 30, ang, scale);
        flowerPattern1(xInc8, yInc8, type, 30, ang, scale);
        flowerPattern2(xInc8, yInc8, type, 30, ang, scale);
        flowerPattern1(xInc9, yInc9, type, 30, ang, scale);
        flowerPattern2(xInc9, yInc9, type, 30, ang, scale);
        for (int i =0; i<=2; i++){
            leavesLined(midxInc, leavesPosition);
            leavesLined(midxInc+200, leavesPosition2);
            midyInc= pointTranslation(midyInc, 150);
            leavesPosition = pointTranslation(leavesPosition, 150);
            leavesPosition2 = pointTranslation(leavesPosition2, 150);
        }
        setvisualpage(win);
        delay(1);
        if(win==1){
            win = 0;
        }
        else{
            win =1;
        }
        if(ang <= 360){
            ang += 5;
        }
        else{
            ang = 0;
        }
        if(ang <= 180){
                scale += 0.03;
        }
        else {
                scale -= 0.03;
        }


        if(leavesAdd <= maxy){
            leavesAdd += 20;
            leavesAdd2 -= 20;
        }
        else{
            leavesAdd = -360;
            leavesAdd2 = maxy;
        }


        if((yInc <= midy)&&(xInc <= xEnd)){
            xInc += 10;
        }
        else if ((xInc >= xEnd)&&(yInc<=yEnd)){
            yInc += 10;
        }
        else if ((xInc >= xStart)&&(yInc>=yEnd)){
            xInc -= 10;
        }
        else if ((xInc <= xStart) && (yInc >= midy)){
            yInc -= 10;
        }


        if((yInc2 <= midy)&&(xInc2 <= xEnd)){
            xInc2 += 10;
        }
        else if ((xInc2 >= xEnd)&&(yInc2<=yEnd)){
            yInc2 += 10;
        }
        else if ((xInc2 >= xStart)&&(yInc2>=yEnd)){
            xInc2 -= 10;
        }
        else if ((xInc2 <= xStart) && (yInc2 >= midy)){
            yInc2 -= 10;
        }



        if((yInc3 <= midy)&&(xInc3 <= xEnd)){
            xInc3 += 10;
        }
        else if ((xInc3 >= xEnd)&&(yInc3<=yEnd)){
            yInc3 += 10;
        }
        else if ((xInc3 >= xStart)&&(yInc3>=yEnd)){
            xInc3 -= 10;
        }
        else if ((xInc3 <= xStart) && (yInc3 >= midy)){
            yInc3 -= 10;
        }



        if((yInc4 <= midy)&&(xInc4 <= xEnd)){
            xInc4 += 10;
        }
        else if ((xInc4 >= xEnd)&&(yInc4<=yEnd)){
            yInc4 += 10;
        }
        else if ((xInc4 >= xStart)&&(yInc4>=yEnd)){
            xInc4 -= 10;
        }
        else if ((xInc4 <= xStart) && (yInc4 >= midy)){
            yInc4 -= 10;
        }




        if((yInc5 <= midy)&&(xInc5 <= xEnd)){
            xInc5 += 10;
        }
        else if ((xInc5 >= xEnd)&&(yInc5<=yEnd)){
            yInc5 += 10;
        }
        else if ((xInc5 >= xStart)&&(yInc5>=yEnd)){
            xInc5 -= 10;
        }
        else if ((xInc5 <= xStart) && (yInc5 >= midy)){
            yInc5 -= 10;
        }



        if((yInc6 <= midy)&&(xInc6 <= xEnd)){
            xInc += 10;
        }
        else if ((xInc6 >= xEnd)&&(yInc6<=yEnd)){
            yInc6 += 10;
        }
        else if ((xInc6 >= xStart)&&(yInc6>=yEnd)){
            xInc6 -= 10;
        }
        else if ((xInc6 <= xStart) && (yInc6 >= midy)){
            yInc6 -= 10;
        }


        if((yInc7 <= midy)&&(xInc7 <= xEnd)){
            xInc7 += 10;
        }
        else if ((xInc7 >= xEnd)&&(yInc7<=yEnd)){
            yInc7 += 10;
        }
        else if ((xInc7 >= xStart)&&(yInc7>=yEnd)){
            xInc7 -= 10;
        }
        else if ((xInc7 <= xStart) && (yInc7 >= midy)){
            yInc7 -= 10;
        }



        if((yInc8 <= midy)&&(xInc8 <= xEnd)){
            xInc8 += 10;
        }
        else if ((xInc8 >= xEnd)&&(yInc8<=yEnd)){
            yInc8 += 10;
        }
        else if ((xInc8 >= xStart)&&(yInc8>=yEnd)){
            xInc8 -= 10;
        }
        else if ((xInc8 <= xStart) && (yInc8 >= midy)){
            yInc8 -= 10;
        }


        if((yInc9 <= midy)&&(xInc9 <= xEnd)){
            xInc += 10;
        }
        else if ((xInc9 >= xEnd)&&(yInc9<=yEnd)){
            yInc9 += 10;
        }
        else if ((xInc9 >= xStart)&&(yInc9>=yEnd)){
            xInc9 -= 10;
        }
        else if ((xInc9 <= xStart) && (yInc9 >= midy)){
            yInc9 -= 10;
        }

    }
}
void programLogo()
{
    widthLine(20, 153, 20, 162, 1, 4,5);
    widthLine(30, 145, 30, 170, 1, 4, 5);
    widthLine(40, 153, 40, 162, 1, 4, 5);
    widthLine(50, 130, 50, 190, 1, 4, 5);
    widthLine(60, 140, 60, 180, 1, 4, 5);
    widthLine(70, 110, 70, 210, 1, 4, 5);
    widthLine(80, 80, 80, 240, 1, 4, 5);
    widthLine(90, 90, 90, 230, 1, 4, 5);
    widthLine(100, 120, 100, 200, 1, 4, 5);
    widthLine(110, 145, 110, 175, 1, 4, 5);
    widthLine(120, 135, 120, 185, 1, 4, 5);
    drawFilledCircle(133, 70, 10, 3);
    widthLine(130, 80, 130, 240, 1, 3, 5);
    drawFilledCircle(133, 250, 10, 3);
    widthLine(140, 130, 140, 190, 1, 15, 5);
    widthLine(150, 150, 150, 170, 1, 15, 5);
    widthLine(160, 145, 160, 175, 1, 15, 5);
    widthLine(170, 140, 170, 180, 1, 15, 5);
    widthLine(180, 150, 180, 170, 1, 15, 5);
    widthLine(190, 155, 190, 165, 1, 15, 5);
    widthLine(200, 157, 240, 157, 2, 15, 5);
}
void openGraph()
{
    int ghdriver=DETECT,ghmode,errorcode;
    int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
    initgraph(&gd,&gm,NULL);
    errorcode = graphresult();
    if(errorcode !=grOk)
    {
        std::cout<<"Graphics error:%s\n"<<grapherrormsg(errorcode);
        std::cout<<"Press any key to halt:";
        getch();
        exit(1);
    }
}
