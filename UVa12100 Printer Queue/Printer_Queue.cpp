

//队列queue 不能解决遍历元素的问题，最终选用vector


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> printer;
int main()
{
    int T;
    cin >> T;

    int p_tem;

    while(T--)
    {
        int m, n;
        int k;
        int cnt = 0;
        cin >> m >> n;
        k = m;
        while(k--)
        {
            cin >> p_tem;
            printer.push_back(p_tem);
        }
        if(m == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            for(vector<int>::size_type i = 1; i < printer.size(); i++)
            {
                if(printer[0] < printer[i])
                {
                    //flag = 0;
                    printer.push_back(printer[0]);
                    printer.erase(printer.begin());
                    i = 0;
                    n--;
                    if(n == -1)
                    {
                        n = m-1;
                    }
                }

                if(i == printer.size()-1)
                {
                    printer.erase(printer.begin());
                    i = 0;
                    cnt++;
                    if(n == 0)
                    {
                        cout << cnt << endl;
                        break;
                    }
                    n--;
                }

            }
        }

        printer.clear();




    }

    return 0;
}

