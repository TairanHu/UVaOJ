

#include <iostream>
#include <cstring>

using namespace std;

const int maxd = 20;
int s[1<<maxd];

int main()
{
    int D, I;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> D >> I;
        memset(s, 0, sizeof(s));

        int k, n = (1 << D) - 1;

        for(int i = 0; i < I; i++)
        {
            k = 1;
            for(; ; )
            {
                s[k] = !s[k];
                k = s[k]? k*2: k*2+1;
                if(k > n)
                    break;
            }
        }
        cout << k/2 << endl;
    }
    while(cin >> T && T != -1);
}


