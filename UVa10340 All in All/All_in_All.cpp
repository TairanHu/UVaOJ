

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    bool flag = 0;
    string str_sub;
    string str;


    size_t Position = string::npos;

    while(cin >> str_sub >> str)
    {
        flag = 0;

        for(int i = 0; i < str_sub.size(); i++ )
        {
            Position = str.find_first_of(str_sub[i]);
            if(Position != string::npos)
            {
                str = str.substr(Position+1);
                //cout << str << endl;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }

        str_sub.clear();
        str.clear();
    }
}



