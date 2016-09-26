

//count��ʹ�� ��Ҫ���<algorithm>


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
    int num_consequence = 0;    //��ƥ������
    int A_times = 0, C_times = 0, G_times = 0, T_times = 0; //ÿ�а���ACGT����
    string str_consequence = "";    //���ƥ���ַ���

    cin >> T;
    while(T--)
    {
        num_consequence = 0;        //���
        str_consequence.clear();    //���

        cin >> m >> n;              //��������������
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
                str_col[i] += str[j][i];    //ת��
            }
        }

        for(int i = 0; i < n; i++)
        {
            //ͳ��ÿ��ACGT������count��Ҫ����algorithmͷ�ļ�
            A_times = count(str_col[i].begin(), str_col[i].end(), 'A');
            C_times = count(str_col[i].begin(), str_col[i].end(), 'C');
            G_times = count(str_col[i].begin(), str_col[i].end(), 'G');
            T_times = count(str_col[i].begin(), str_col[i].end(), 'T');

            int t = max_num(A_times, C_times, G_times, T_times);    //��ACGT���������ֵ
            num_consequence += m - t;

            //�ó����ƥ������
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

