

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxcol = 60;
const int maxn = 100+5;
string filename[maxn];

void print( const string &s, int len, char extra )
{
    cout << s;
    for(int i = 0; i < len-s.size(); i++)
    {
        cout << extra;
    }
}


int main()
{
    int n;
    while(cin >> n)
    {
        int M = 0;
        for(int i = 0; i < n; i++)  //����n���ļ������������ļ����ĳ���
        {
            cin >> filename[i];
            M = max( M, (int)filename[i].size() );
        }

        int cols = (maxcol - M)/(M + 2) + 1;
        int rows = (n - 1)/cols + 1;        //n-1

        print("", 60, '-');
        cout << endl;

        sort(filename, filename+n);     //���ļ����������򣬵���sort����

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                int idx = c*rows + r;   //  ������������ļ����±�ֵ
                if(idx < n)
                {
                    print(filename[idx], c == cols-1 ? M : M+2, ' ');   //��ӡ�ļ���
                }
            }
            cout << endl;
        }
    }
}
