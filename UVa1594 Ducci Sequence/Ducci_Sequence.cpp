

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

#define maxn 1000+10

using namespace std;

vector<int> ducci[maxn];
int cnt = 1;

int is_loop( int k)
{
    for(int i = 0; i < k-1; i++)
    {
        ducci[cnt].push_back( abs(ducci[cnt-1][i] - ducci[cnt-1][i+1]));
        //cout << abs(ducci[cnt-1][i] - ducci[cnt-1][i+1]) << " ";
    }
    ducci[cnt].push_back( abs(ducci[cnt-1][k-1] - ducci[cnt-1][0]));
    //cout << abs(ducci[cnt-1][k-1] - ducci[cnt-1][0]) << endl;
    cnt++;

    int m;
    for(m = 0; m < k; m++)
    {
        if(ducci[cnt-1][m] != 0)
            break;
    }
    //cout << m << " ";
    if(m == k)
    {
        return 0;
    }

    for(int i = cnt-2; i >= 0; i--)
    {
        //vector<int>::iterator it=v2.begin();
        //vector<int>::iterator ix=v1.begin();
        for(m = 0; m < k; m++)
        {
            if(ducci[cnt-1][m] != ducci[i][m])
                break;
        }
        if(m == k)
            return 1;
    }
    //cout << cnt << endl;
    return -1;
}

int main()
{
    int k;
    int T;
    int num_tem;
    cin >> T;

    while(T--)
    {
        cnt = 1;
        //ducci[0].clear();
        cin >> k;
        int a = k;
        while(a--)
        {
            cin >> num_tem;
            ducci[0].push_back(num_tem);

        }
        //cout << ducci[0].size();
        //cout << endl << abs(ducci[0][0] - ducci[0][1]) <<endl;;
        //int a = is_loop(k);

/*        vector<int>::iterator it=ducci[0].begin();
        for(; it < ducci[0].end()-1; it++)
        {
            //ducci[cnt].push_back( abs(ducci[cnt-1][i] - ducci[cnt-1][i+1]));
            cout << (*it - *(it+1)) << " ";
        }

        cout << (*it - *(it-k+1));
*/

        while(1)
        {
            int tt = is_loop(k);
            if(tt == 0)
            {
                cout << "ZERO" << endl;
                break;
            }
            else if(tt == 1)
            {
                cout << "LOOP" << endl;
                break;
            }

        }

        for(int i = 0; i < cnt; i++)
        {
            ducci[i].clear();
        }

    }

}

