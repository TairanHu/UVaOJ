

#include <iostream>
#include <cstring>



using namespace std;

int main()
{
    int T;
    int k;
    string str;

    cin >> T;


    while(T--)
    {
        cin.get();
        cin >> str;
        k = str.size();
        for(int i = 0; i < str.size(); i++)
        {
            if(str[0] == str[i])
            {
                if(2*i > str.size())
                {
                    k = str.size();
                    //cout << "not a periodic string" << endl;
                    break;
                }
                for(int j = 0; j < i; j++)
                {
                    if(str[j] != str[j+i])
                        break;
                    if(j == i-1)
                        k = i;

                }
                if(k != str.size())
                {
                    if(str.size() % k != 0)
                    {
                        k = str.size();
                    }
                    else
                    {
                        for(int n = 0; n < k; n++)
                        {
                            for(int m = 0; m < str.size()/k; m++)
                            {
                                if(str[n] != str[m*k + n])
                                {
                                    k = str.size();
                                }
                            }
                        }
                    }
                    if(k != str.size())
                    {
                        cout << k << endl ;
                        break;
                    }
                }
            }
        }

        if(k == str.size())
            cout << k << endl;

        if(T > 0)
            cout << endl;
    }


    return 0;
}

