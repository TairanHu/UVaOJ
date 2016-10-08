

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 10000;

int main()
{
    int n, q, x, a[maxn];
    int kase = 0;
    while( cin >> n >> q && n )
    {
        //cin >> q;
        cout << "CASE# " << ++kase << ":" << endl;

        for( int i = 0; i < n; i++ )
        {
            cin >> a[i];
        }

        sort(a, a+n);

        while(q--)
        {
            cin >> x;
            int p = lower_bound(a, a+n, x) - a;
            if(a[p] == x)
            {
                cout << x << " found at " << p + 1 << endl;
                //printf("%d found at %d\n", x, p+1);
            }
            else
            {
                cout << x << " not found" << endl;
                //printf("%d not found\n", x);
            }
        }
    }

    return 0;
}


