#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void swap (char &a, char &b)
{
    char temp;
    temp=a;
    a=b;
    b=temp;
}


int main()
{
    int caseData;

    cin >> caseData ;


    while (caseData--)
    {
        int length;
        int flag = 0;

        cin >> length ;
        length=length*2+1;

        char strMiddle[length+1];
        char strNext[6][length+1];

        cin >> strMiddle;

        int seatE;
        int leftBlack=length+1;
        int rightWhite=-1;

        for (int i = 0; i < length; i++)
        {
            if(strMiddle[i]=='E')
                seatE = i;
            if(strMiddle[i]=='B'&&i<leftBlack)
                leftBlack = i;
            if(strMiddle[i]=='W')
                rightWhite = i;
        }
        if(rightWhite<leftBlack)
        {
            cout << "目标格局" << endl;
            flag = 1;
        }


        int nextCount = 0;
        for (int j = seatE -3; j <= seatE +3; j++)
        {

            if(j>=0&&j<length&&j!=seatE)
            {
                swap(strMiddle[seatE],strMiddle[j]);
                strcpy(strNext[nextCount],strMiddle);
                swap(strMiddle[seatE],strMiddle[j]);
                nextCount++;
            }

        }

        char temp[length];
        for (int i = 0; i < nextCount-1; i++)
            for (int j = 0; j < nextCount-1-i; j++)
                if(strcmp(strNext[j],strNext[j+1])>0)
                {
                    strcpy(temp,strNext[j]);
                    strcpy(strNext[j],strNext[j+1]);
                    strcpy(strNext[j+1],temp);
                }

        if(!flag)
        {
            cout << "结果" << endl;
            for (int i = 0; i < nextCount; i++)
                cout << strNext[i] << endl;
        }

    }


    return 0;
}

/* 4
3 BBWBEWW
4 WWWWBBEBB
3 BBWWBWE
5 BBBBBEWWWWW
*/
