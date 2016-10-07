

#include <iostream>
#include <algorithm>
#include <string>

#define M_max 1010

using namespace std;

int IP_num[M_max][4];

int main()
{
    char temp;
    int num;
    int flag = 7;

    cin >> num;

    int t = num;
    while(t--)
    {
        cin >> IP_num[t][0] >> temp >> IP_num[t][1] >> temp >> IP_num[t][2] >> temp >> IP_num[t][3];

        //cout << t << endl;
        //cout << IP_num[t][0] << temp << IP_num[t][1] << temp << IP_num[t][2] << temp << IP_num[t][3] << endl;
    }
/*
    if(num == 1)
    {
        cout << IP_num[0][0] << temp << IP_num[0][1] << temp << IP_num[0][2] << temp << IP_num[0][3] << endl;
        cout << "255.255.255.255" << endl;

        return 0;
    }
*/
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 1; j < num; j++)
        {
            if( (IP_num[0][i] - IP_num[j][i]) )
                break;
        }

        if(j != num)
            break;
    }

    char tem[num][8];
    int tem1[8] = {0};
    int a = IP_num[0][i];
    //cout << a << endl;
    //cout << tem1 << endl;
    for(int m = 7; m >= 0; m--)
    {

        tem1[m] = a%2 ;
        a = a/2;
        //cout << tem1[m];
    }
    //cout <<endl;

    for(j = 1; j < num; j++)
    {
        a = IP_num[j][i];
        for(int m = 7; m >= 0; m--)
        {

            tem[j][m] = a%2 ;
            a = a/2;

        }
        for(int m = 0; m < 8; m++)
        {
            if( (tem[j][m] - tem1[m]) )
            {
                if(flag > m)
                    flag = m;
                //cout << flag <<endl;
                while(m < 8)
                {
                    tem1[m++] = 0;
                }

                break;
            }
        }

    }
    //cout << tem1 <<endl;

    int mm = 0;
    int aa = 0;
    for(int k = 0; k < 8; k++)
    {
        mm *= 2;

        mm += (tem1[k]);

        //cout << mm << endl;

    }

    if(i == 4)
    {
        for(int k = 0; k < i; k++)
        {
            if(k)
                cout << '.';
            cout << IP_num[0][k] ;
        }
        cout << endl;

        for(int k = 0; k < i; k++)
        {
            if(k)
                cout << '.';
            cout << 255 ;
        }
        cout << endl;

        return 0;
    }

    for(int k = 0; k < i; k++)
    {
        cout << IP_num[0][k] << '.' ;
    }
    cout << mm;

    for(int k = i+1; k < 4; k++)
    {
        cout << '.' << 0;
    }
    cout << endl;

    for(int k = 0; k < i; k++)
    {
        cout << 255 << '.' ;
    }

    for(int k = 0; k < flag; k++)
    {
        aa *= 2;
        aa += 1;
    }
    for(int k = flag; k < 8; k++)
    {
        aa *= 2;
        //aa += 1;
    }
    cout << aa;
    for(int k = i+1; k < 4; k++)
    {
        cout << '.' << 0;
    }
    //cout << endl;




    return 0;
}

