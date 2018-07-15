
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while(cin >> n && n)
    {
        priority_queue<int, vector<int>, greater<int> > q;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            q.push(x);
        }

        int ans = 0;
        for(int i = 0; i < n-1; i++)
        {
            int tmp1 = q.top(); q.pop();
            int tmp2 = q.top(); q.pop();

            ans += tmp1 + tmp2;
            q.push(tmp1+tmp2);
        }

        cout << ans << endl;

    }

    return 0;
}


