#include<iostream>
#include<cmath>
using namespace std;

int ok=1;

struct Point
{
    int x;
    int y;
};

void displayMenu()
{
    cout << "*******************************" << endl;
    cout << "1. Circle (圆)" << endl;
    cout << "2. Rectangle (长方形)" << endl;
    cout << "0. Exit (退出)" << endl;
    cout << "*******************************" <<endl;
}

void getTwoPoints(struct Point *startP,struct Point *endP)
{
    cout << "Please input the coordinate (x,y) of the start point:";
    cin >> startP->x >> startP->y;
    cout << "Please input the coordinate (x,y) of the end point:";
    cin >> endP->x >> endP->y;

    if(startP->x > endP->x || startP->y > endP->y)
        {
            ok=0;
            cout << "startPoint>endPoint" << endl;
        }
}

void printPoint(struct Point *startP,struct Point *endP)
{
    cout << "(" << (endP->x+startP->x)/2 << ", " << (endP->y+startP->y)/2 << ")";
}

void printPoint(struct Point *startP)
{
    cout << "(" << startP->x << ", " << startP->y << ")";
}

void drawCircle(struct Point *startP,struct Point *endP)
{
    if(endP->x-startP->x==endP->y-startP->y)
    {
        cout << "Draw a circle at center " ;
        printPoint(startP,endP);
        cout << " with radius " << (endP->x-startP->x)/2 << endl;
    }
    else
    {
        cout << "Not a circle, Select again" << endl;
    }
}

void drawRectangle(struct Point *startP,struct Point *endP)
{
    cout << "Draw a rectangle at topleft " ;
    printPoint(startP) ;
    cout << " whose width is " << endP->x-startP->x ;
    cout << " and height is " << endP->y-startP->y << endl;
}

int main()
{
    int choice;


    struct Point startP,endP;

    while(choice)
    {
        displayMenu();
        cout << "Please select the shape:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            getTwoPoints(&startP, &endP);
            if(!ok)
                break;
            drawCircle(&startP, &endP);
            break;
        case 2:
            getTwoPoints(&startP, &endP);
            if(!ok)
                break;
            drawRectangle(&startP, &endP);
            break;
        case 0:
            cout << "Good Bye!\n";
            break;
        default:
            cout << "Not supported! Please select again!\n";
            break;
        }
    }
    return 0;
}
