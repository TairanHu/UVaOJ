
#include <iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxm = 500 + 5;

int m;
int k;
int p[maxm];

int solve(long long maxp)
{
    long long done = 0;
    int ans = 1;

    for(int i = 0; i < m; i++)
    {
        if(done + p[i] <= maxp)
        {
            done += p[i];
        }
        else
        {
            ans++;
            done = p[i];
        }
    }

    return ans;
}

int last[maxm];
void print(long long ans)
{
    long long done = 0;
    memset(last, 0, sizeof(last));

    int remain = k;
    for(int i = m-1; i >= 0; i--)
    {
        if(done + p[i] > ans || i+1 < remain)
        {
            last[i] = 1;
            remain--;
            done = p[i];
        }
        else
        {
            done += p[i];
        }
    }
    for(int i = 0; i < m-1; i++)
    {
        cout << p[i] << " ";

        if(last[i])
            cout << "/ ";
    }
    cout << p[m-1] << endl;

}

int main()
{

    int T;
    cin >> T;

    while(T--)
    {
        cin >> m >> k;
        long long tot = 0;
        int maxp = -1;

        for(int i = 0; i < m; i++)
        {
            cin >> p[i];
            tot += p[i];
            maxp = max(maxp, p[i]);
        }

        long long L = maxp;
        long long R = tot;
        while(L < R)
        {
            long long M;
            M = L + (R-L)/2;

            if(solve(M) <= k)
                R = M;
            else
                L = M+1;
        }
        print(L);
    }


    return 0;
}
