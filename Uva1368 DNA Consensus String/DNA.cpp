

//count的使用 需要添加<algorithm>


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int max_num(int a, int c, int g, int t)
{
    return ( max( max(a,c), max(g,t) ) );
}


int main()
{
    int T;
    int m,n;
    int num_consequence = 0;    //不匹配总数
    int A_times = 0, C_times = 0, G_times = 0, T_times = 0; //每列包含ACGT个数
    string str_consequence = "";    //最佳匹配字符串

    cin >> T;
    while(T--)
    {
        num_consequence = 0;        //清空
        str_consequence.clear();    //清空

        cin >> m >> n;              //输入行数和列数
        string str[m];
        string str_col[n];

        for(int i = 0; i < m; i++)
        {
            cin >> str[i];
            //getline(cin, str[i]);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                str_col[i] += str[j][i];    //转置
            }
        }

        for(int i = 0; i < n; i++)
        {
            //统计每列ACGT个数，count需要包含algorithm头文件
            A_times = count(str_col[i].begin(), str_col[i].end(), 'A');
            C_times = count(str_col[i].begin(), str_col[i].end(), 'C');
            G_times = count(str_col[i].begin(), str_col[i].end(), 'G');
            T_times = count(str_col[i].begin(), str_col[i].end(), 'T');

            int t = max_num(A_times, C_times, G_times, T_times);    //求ACGT个数的最大值
            num_consequence += m - t;

            //得出最佳匹配序列
            if(t == A_times)
            {
                str_consequence += 'A';
            }
            else if(t == C_times)
            {
                str_consequence += 'C';
            }
            else if(t == G_times)
            {
                str_consequence += 'G';
            }
            else
            {
                str_consequence += 'T';
            }
        }

        cout << str_consequence << endl << num_consequence << endl;
    }


}

