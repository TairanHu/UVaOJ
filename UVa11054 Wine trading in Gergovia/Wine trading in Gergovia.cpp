
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;

    while( cin >> n && n )
    {
        long long ans = 0;
        int a;
        long long last = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a;
            ans += abs(last);
            last += a;
        }

        cout << ans << endl;
    }


    return 0;
}


