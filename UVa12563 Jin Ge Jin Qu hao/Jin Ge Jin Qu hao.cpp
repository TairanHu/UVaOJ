
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 50 + 5;
const int INF = 1000000000;

// d[i][j]: maximal number of songs from first i songs, whose total length is exactly j
int n, t, len[maxn], d[2][maxn*180+678];

int main()
{
    int T;
    cin >> T;

    for(int kase = 1; kase <= T; kase++)
    {
        cin >> n >> t;
        for(int i = 1; i <= n; i++)
        {
            cin >> len[i];
        }

        for(int i = 0; i < t; i++)
        {
            d[0][i] = -1;
        }
        d[0][0] = 0;

        int p = 1, ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < t; j++)
            {
                d[p][j] = d[p^1][j];

                if(j >= len[i] && d[p^1][j - len[i]] >= 0)
                {
                    d[p][j] = max(d[p][j], d[p^1][j - len[i]] + 1);
                }
                ans = max(ans, d[p][j]);

            }
            p ^= 1;
        }

        for(int i = t-1; i >= 0; i--)
        {
            if(d[p^1][i] == ans)
            {
                cout << "Case " << kase << ": " << ans+1 << " " << i+678 << endl;
                break;
            }
        }

    }
    return 0;
}
