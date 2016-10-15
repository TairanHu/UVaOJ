

#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 1000+10;

int n, target[MAXN];

int main()
{
    while(cin >> n)
    {
        stack<int> s;
        int A = 1;
        int B = 1;

        for(int i = 1; i <= n; i++)
        {
            cin >> target[i];
        }

        int ok = 1;

        while(B <= n)
        {
            if(A == target[B])
            {
                A++;
                B++;
            }
            else if(!s.empty() && s.top() == target[B])
            {
                s.pop();
                B++;
            }
            else if(A <= n)
            {
                s.push(A++);
            }
            else
            {
                ok = 0;
                break;
            }

        }
        string temp = ok? "Yes" : "No";
        cout << temp << endl;
    }
    return 0;
}

