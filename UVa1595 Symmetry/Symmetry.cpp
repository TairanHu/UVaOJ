

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    int x;
    int y;
}Point;

vector<Point> point;

int main()
{
    int x_max = 0, x_min = 0;
    double x_mid = 0.0;
    bool flag = 0;
    int T;
    cin >> T;

    while(T--)
    {
        int N, n;
        cin >> N;

        bool first = 1;
        while(N--)
        {
            Point p;
            cin >> p.x >> p.y;

            if(first)
            {
                x_max = p.x;
                x_min = p.x;
                first = 0;
            }

            point.push_back(p);
            x_max = max(x_max, p.x);
            x_min = min(x_min, p.x);
        }
        double kkk = 0.4;
        //cout << x_max << " " << x_min <<endl;
        x_mid = (double)((double)x_max + (double)x_min)/2.0;
        //cout << x_mid << endl << kkk << endl;

        for(vector<Point>::iterator it = point.begin(); it < point.end(); it++)
        {
            //cout << (*it).x << " " << (*it).y << endl;
        }

        for(vector<Point>::iterator it = point.begin(); it < point.end(); it++)
        {
            Point p;
            p.x = (int)((x_mid)*2 - (*it).x);
            p.y = (*it).y;
            //cout << p.x << " " << p.y << endl;
            //vector<Point>::iterator itt = find(point.begin(), point.end(), p);
            //if(!point.count(p))       //使用需定义 < 操作符
            flag = 1;
            for(vector<Point>::iterator itt = point.begin(); itt < point.end(); itt++)
            {
                if(p.x == (*itt).x && p.y == (*itt).y)
                {
                    flag = 0;
                    //cout << (*itt).x << " " << (*itt).y << endl;
                    break;
                }
                //flag = 1;
            }
            if(flag)
                break;
        }
        if(!flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;



        point.clear();
    }
}



