

#include <iostream>
#include <cstring>

using namespace std;
int p[15];

int main()
{
    bool flag;
    bool first = 0;
    int num;
    num = 2;
    while((cin >> num) && num)
    //while(num++)
    {
        if(num > 79 || num < 2)
            break;
        flag = 0;
        if(first)
            cout << endl;
        first = 1;
        for(int i = 1234; i < 48383; i++)
        {
            int multiplier = i;
            int result = 0;
            int total = 0;
            int m = 0;

            //memset(p, 0, sizeof(p));
            result = multiplier*num;
            m = result;
            if(result > 98765)
                continue;

            if(multiplier < 10000)
            {
                p[0] = 1;
            }

            while(multiplier)
            {
                p[multiplier%10] = 1;
                multiplier = multiplier/10;
            }

            while(result)
            {
                p[result%10] = 1;
                result = result/10;
            }

            for(int j = 0; j < 10; j++)
            {
                total += p[j];
                p[j] = 0;
            }

            if(total == 10)
            {
                flag = 1;
                if(i < 10000)
                {
                    cout << i*num << " / " << 0 << i << " = " << num << endl;
                }
                else
                {
                    cout << i*num << " / " << i << " = " << num << endl;
                }

            }
        }

        if(!flag)
        {
            cout << "There are no solutions for " << num << "." << endl;
        }

    }

    return 0;
}



