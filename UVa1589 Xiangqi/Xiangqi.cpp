

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef struct
{
    char role;
    int x;
    int y;
}Point;

bool flag = 1;

void check_row(Point Black, int T, Point Red[])
{
    for(int i = 0; i < T; i++)
    {
        //cout << Red[i].role << " " << Red[i].x << " " << Red[i].y << endl;
        switch (Red[i].role)
        {
        case 'G':
            flag = 0;
            if(Red[i].y == Black.y)
            {
                flag = 1;
                for(int j = 0; j < T && j!=i; j++)
                {
                    if(Red[j].y == Red[i].y && Red[j].x < Red[i].x && Red[j].x > Black.x)
                        flag = 0;
                }
            }
            //cout << 'G' << flag << endl;
            if(flag) return;
            break;
        case 'R':   //³µ
            flag = 0;
            if(Red[i].x == Black.x || Red[i].y == Black.y)
            {
                flag = 1;
                for(int j = 0; j < T && j!=i; j++)
                {
                    if(Red[j].y == Red[i].y && (Red[j].x-Red[i].x)*(Red[j].x-Black.x)<0 )
                        flag = 0;
                    else if(Red[j].x == Red[i].x && (Red[j].y-Red[i].y)*(Red[j].y-Black.y)<0 )
                        flag = 0;
                }

            }
            //cout << 'R' << flag << endl;
            if(flag) return;
            break;
        case 'H':
            flag = 0;
            if(Black.y+2 == Red[i].y || Black.y-2 == Red[i].y )
            {
                //if()

                if(Black.x > 1 && (Black.x-1 == Red[i].x || Black.x+1 == Red[i].x) )
                {
                    flag = 1;
                }
                else if(Black.x == 1 && Black.x+1 == Red[i].x)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
            else if( (Black.x+2 == Red[i].x) && (Black.y+1 == Red[i].y || Black.y-1 == Red[i].y) )
            {
                flag = 1;
            }
            else if( Black.x > 2 && (Black.x-2 == Red[i].x) && (Black.y+1 == Red[i].y || Black.y-1 == Red[i].y) )
            {
                flag = 1;
            }
            //cout << 'H' << flag << endl;
            if(flag) return;
            break;
        case 'C':
            flag = 0;
            if(Red[i].x == Black.x || Red[i].y == Black.y)
            {
                flag = 0;
                for(int j = 0; j < T && j!=i; j++)
                {
                    if(Red[j].y == Red[i].y && (Red[j].x-Red[i].x)*(Red[j].x-Black.x)<0 )
                        flag = 1;
                    else if(Red[j].x == Red[i].x && (Red[j].y-Red[i].y)*(Red[j].y-Black.y)<0 )
                        flag = 1;

                    //cout << flag <<endl;
                }

            }
            //cout << 'C' << flag << endl;
            if(flag) return;
            break;
        default:
            ;
            //return -1;
        }
    }
    //cout << Black.role << " " << Black.x << " " << Black.y << endl;

}


int main()
{
    int T;
    int Tx, Ty;
    Point G_Black;

    //cin >> T;

    while(cin >> T >> G_Black.x >> G_Black.y && (T != 0 && G_Black.x != 0 && G_Black.y != 0))
    {
        flag = 1;


        G_Black.role = 'G';
        //cin >> G_Black.x >> G_Black.y;
        Tx = G_Black.x;
        Ty = G_Black.y;

        Point Role_Red[T];
        for(int i = 0; i < T; i++)
        {
            cin >> Role_Red[i].role >> Role_Red[i].x >> Role_Red[i].y;
        }

        G_Black.x = Tx - 1;
        if(G_Black.x > 0 && flag)
        {
            check_row(G_Black, T, Role_Red);
        }

        G_Black.x = Tx + 1;
        if(G_Black.x < 4 && flag)
        {
            check_row(G_Black, T, Role_Red);
        }

        G_Black.y = Ty - 1;
        if(G_Black.y > 3 && flag)
        {
            check_row(G_Black, T, Role_Red);
        }

        G_Black.y = Ty + 1;
        if(G_Black.y < 7 && flag)
        {
            check_row(G_Black, T, Role_Red);
        }

        if(!flag)
        {
            cout << "NO" << endl;

        }
        else if(flag)
        {
            cout << "YES" << endl;
        }

        cin.get();
    }
    return 0;

}


