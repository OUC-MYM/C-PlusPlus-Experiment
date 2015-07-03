#include<iostream>
using namespace std;

int upFloor(int nowFloor,int toFloor)
{
    return (toFloor-nowFloor)*6;
}
int downFloor(int nowFloor,int toFloor)
{
    return (toFloor-nowFloor)*4*-1;
}
int main()
{
    int N;
    while (cin >> N)
    {
        if(N==0)
            break;
        int time=0;
        int nowFloor=0;
        int toFloor;
        while(N--)
        {
            cin >> toFloor;
            if(toFloor>nowFloor)
                time=time+5+upFloor(nowFloor,toFloor);
            else
                time=time+5+downFloor(nowFloor,toFloor);
            nowFloor=toFloor;
        }
        cout << time << endl;
    }
    return 0;
}
