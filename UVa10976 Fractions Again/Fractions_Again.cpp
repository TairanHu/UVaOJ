

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> x_num;
vector<int> y_num;

int main()
{
    int num;
    int cnt = 0;

    while(cin >> num && num)
    {
        cnt = 0;
        x_num.clear();
        y_num.clear();

        //x>=y, 1/x <= 1/y, 1/k - 1/y <= 1/y, ¼´y<=2k
        for(int y = num+1; y <= 2*num; y++)
        {
            int x = y*num/(y-num);
            if(x >= y && (x*(y-num) == y*num) )
            {
                cnt++;
                x_num.push_back(x);
                y_num.push_back(y);
                //cout << "1/" << num << " = 1/" << x << " + 1/" << y << endl;
            }
        }
        cout << cnt << endl;
        vector<int>::iterator j = y_num.begin();
        for(vector<int>::iterator i = x_num.begin(); i != x_num.end(); i++,j++)
        {
            cout << "1/" << num << " = 1/" << *i << " + 1/" << *j << endl;
        }

    }

    return 0;
}


