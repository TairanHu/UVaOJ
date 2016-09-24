

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{
    int count[10] = {0};
    int num;
    int T;
    stringstream ss;
    string num_str;

    //memset(count, 0, sizeof(count));

    cin >> T;
    while(T--)
    {
        memset(count, 0, sizeof(count));
        ss.str("");
        cin >> num;

        for(int i = 1; i <= num; i++)
        {
            ss << i;
        }
        num_str = ss.str();
    //   cout << num_str;
    //    cin >> num_str;

        for(int i = 0; i < num_str.size(); i++)
        {
            count[num_str[i] - '0']++;
        }

        for(int i = 0; i < 9; i++)
            cout << count[i] << " " ;

        cout << count[9] << endl;
    }

}
