

#include <iostream>
#include <string>

using namespace std;

bool is_balance(int &W)
{
    int W1, D1, W2, D2;

    bool b1 = true;
    bool b2 = true;

    cin >> W1 >> D1 >> W2 >> D2;

    if(!W1)
    {
        b1 = is_balance(W1);
    }
    if(!W2)
    {
        b2 = is_balance(W2);
    }

    W = W1 + W2;

    return b1 && b2 && (W1*D1 == W2*D2);
}

int main()
{
    int T, W;
    cin >> T;
    while(T--)
    {
        cin.get();
        if(is_balance(W))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        if(T)
            cout << endl;


    }

    return 0;
}



