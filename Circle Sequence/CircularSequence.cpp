

#include <iostream>
#include <cstring>

#define maxn 105

using namespace std;

int les(const char* s, int p, int q)
{
    int n = strlen(s);
    for(int i = 0; i < n; i++)
    {
        if(s[(p+i)%n] != s[(q+i)%n])
            return s[(p+i)%n] < s[(q+i)%n];
    }
    return 0;
}

int main()
{
    int T;
    char s[maxn];
    cin >> T;

    while(T--)
    {
        cin >> s;
        int ans = 0;
        int n = strlen(s);

        for(int i = 1; i < n; i++)
        {
            if( les(s, i, ans) )
                ans = i;
        }

        for(int i = 0; i < n; i++)
        {
            cout << (s[(i+ans)%n]);
            //putchar

        }
        cout << endl;
    }

    return 0;

}
