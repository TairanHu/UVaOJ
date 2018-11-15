
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100005

using namespace std;

int n;
int T;
vector<int> sons[MAX];

int dp(int u)
{
    if(sons[u].empty())
        return 1;

    vector<int> d;

    for(int i = 0; i < sons[u].size(); i++)
    {
        d.push_back(dp(sons[u][i]));
    }

    sort(d.begin(), d.end());

    int need;
    need = (sons[u].size()*T - 1)/100 + 1;

    int ans = 0;
    for(int i = 0; i < need; i++)
    {
        ans += d[i];
    }

    return ans;


}


int main()
{
    int fa;

    while(cin >> n >> T && n)
    {
        for(int i = 0; i <= n; i++)
        {
            sons[i].clear();
        }

        for(int i = 1; i <= n; i++)
        {
            cin >> fa;
            sons[fa].push_back(i);
        }

        cout << dp(0) << endl;

    }

    return 0;
}



