
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 50 + 5;
const int maxt = 200 + 5;
const int INF = 1000000000;

// has_train[t][i][0]表示时刻t，在车站i是否有往右开的火车
int t[maxn], has_train[maxt][maxn][2];
int dp[maxt][maxn];

int main()
{
    int n;
    int T;
    int count_num = 0;

    while(cin >> n >> T && n)
    {

        for(int i = 1; i < n; i++)
            cin >> t[i];

        memset(has_train, 0, sizeof(has_train));

        int M1;
        int M2;
        int d;
        cin >> M1;
        for(int i = 0; i < M1; i++)
        {
            cin >> d;
            for(int j = 1; j <= n-1; j++)
            {
                if(d <= T)
                    has_train[d][j][0] = 1;
                d += t[j];
            }
        }

        cin >> M2;
        for(int i = 0; i < M2; i++)
        {
            cin >> d;
            for(int j = n-1; j >= 1; j--)
            {
                if(d <= T)
                    has_train[d][j+1][1] = 1;
                d += t[j];
            }
        }

        for(int i = 1; i < n; i++)
            dp[T][i] = INF;
        dp[T][n] = 0;

        for(int i = T-1; i >= 0; i--)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i+1][j] + 1;

                if(j < n && has_train[i][j][0] && i+t[j] <= T)
                  dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]); // 右

                if(j > 1 && has_train[i][j][1] && i+t[j-1] <= T)
                  dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]); // 左
            }

        }

        cout << "Case Number " << ++count_num << ": ";
        if(dp[0][1] >= INF)
            cout << "impossible\n";
        else
            cout << dp[0][1] << "\n";

    }


    return 0;
}


