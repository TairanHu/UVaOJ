

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define maxn 10000

using namespace std;

int k = 0;

int L_data[maxn] = {0}; //左树每列数据和
int R_data[maxn] = {0}; //右树每列数据和，包括根节点那一列
int cnt_L = 0;  //树的最左端，左移一位就减一
int cnt_R = 0;  //树的最右端，右移一位就加一
int Count = 0;  //测试数据组数

void solve(int k)
{
    int a;
    cin >> a;   //输入数据
    if(a == -1)
    {
        return;
    }
    else
    {
        solve(k-1); //参数为列的标号，根节点为0，左负右正
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
        //vector<int>::iterator smallest = min_element(pos.begin(), pos.end()); //求出pos最小值

        //cout << cnt_L << " " << cnt_R << endl;
        if(cnt_R == 0)
            break;

        //if(Count - 1)
        //    cout << endl;

        cout << "Case " << Count << ":" << endl;

        //输出左树每列和
        for(int i = cnt_L; i < 0; i++ )
        {
            cout << L_data[-i] << " ";
            L_data[-i] = 0;
        }
        //输出右树每列和，包括根节点那列
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


