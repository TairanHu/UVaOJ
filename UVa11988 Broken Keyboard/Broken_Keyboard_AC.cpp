

#include <iostream>
#include <string>
#include <cstring>

#define maxn 100000+5

using namespace std;

int last, cur;
int next[maxn];
string temp;

int main()
{
    while(getline(cin, temp))
    {
        int n = temp.size();
        last = cur = 0;
        next[0] = 0;

        for(int i = 1; i <= n; i++)
        {
            char ch = temp[i];
            if(ch == '[')
            {
                cur = 0;
            }
            else if(ch == ']')
            {
                cur = last;
            }
            else
            {
                next[i] = next[cur];
                next[cur] = i;
                if(cur == last)
                    last = i;
                cur = i;
            }
        }

        for(int i = next[0]; i != 0; i = next[i])
        {
            cout << temp[i];
        }
        cout << endl;

    }

    return 0;
}
