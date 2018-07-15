
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

long long c(int k)
{
    return k == 0 ? 1 : 3*c(k-1);
}

long long f(int k, int i)
{
    if(i == 0)
        return 0;

    if(k == 0)
        return 1;

    int tmp_k;
    tmp_k = 1 << (k-1);

    if(i > tmp_k)
    {
        return f(k-1, i- tmp_k) + 2*c(k-1);
    }
    else
    {
        return 2*f(k-1, i);
    }


}

int main()
{
    int times = 0;
    int T;
    cin >> T;

    while(T--)
    {
        int k;
        int a;
        int b;

        cin >> k >> a >> b;
        cout << "Case " << ++times << ": ";

        cout << f(k, b) - f(k, a-1) << endl;

    }


    return 0;
}


