

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define maxn 10000

using namespace std;

int k = 0;

int L_data[maxn] = {0}; //����ÿ�����ݺ�
int R_data[maxn] = {0}; //����ÿ�����ݺͣ��������ڵ���һ��
int cnt_L = 0;  //��������ˣ�����һλ�ͼ�һ
int cnt_R = 0;  //�������Ҷˣ�����һλ�ͼ�һ
int Count = 0;  //������������

void solve(int k)
{
    int a;
    cin >> a;   //��������
    if(a == -1)
    {
        return;
    }
    else
    {
        solve(k-1); //����Ϊ�еı�ţ����ڵ�Ϊ0��������
        solve(k+1);
    }

    if(k < 0)
    {
        cnt_L = min(cnt_L, k);
        L_data[-k] += a;
    }
    else
    {
        cnt_R = max(cnt_R, k);
        R_data[k] += a;
    }
}

int main()
{


    while(1)
    {
        //memset(L_data, 0, sizeof(L_data));
        //memset(R_data, 0, sizeof(R_data));
        k = 0;
        cnt_L = 0;
        cnt_R = 0;
        Count++;
        solve(k);
        //vector<int>::iterator smallest = min_element(pos.begin(), pos.end()); //���pos��Сֵ

        //cout << cnt_L << " " << cnt_R << endl;
        if(cnt_R == 0)
            break;

        //if(Count - 1)
        //    cout << endl;

        cout << "Case " << Count << ":" << endl;

        //�������ÿ�к�
        for(int i = cnt_L; i < 0; i++ )
        {
            cout << L_data[-i] << " ";
            L_data[-i] = 0;
        }
        //�������ÿ�кͣ��������ڵ�����
        for(int i = 0; i < cnt_R; i++)
        {
            cout << R_data[i] << " ";
            R_data[i] = 0;
        }
        cout << R_data[cnt_R] << endl;
        R_data[cnt_R] = 0;

        cout << endl;


    }

    //cout<<*min_element(pos.begin(), pos.end())<<endl;
    //cout << *smallest << endl;
    return 0;
}


