

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#define maxn 1000+10

using namespace std;

vector<string> words[maxn]; //maxn行，每行为一个vector
vector<int> word_length;    //每一列单词最大长度

int main()
{
    string line;
    string str_temp;
    int cnt = 0;
    int max_num = 0;

    while( getline(cin, line) )
    {
        int k = 0;
        stringstream ss(line);
        while(ss >> str_temp)
        {
            words[cnt].push_back(str_temp);
            k++;
            if(k > word_length.size())
            {
                word_length.push_back(str_temp.size());
            }
            else
            {
                word_length[k-1] = max(word_length[k-1], (int)str_temp.size());
            }
        }
        max_num = max(max_num, (int)words[cnt].size());
        cnt++;
    }

    for(int i = 0; i < cnt; i++)
    {
        for(int j = 0; j < words[i].size(); j++)
        {
            if(j)
                cout << " ";
            cout << words[i][j] ;
            for(int m = 0; m < word_length[j]-words[i][j].size(); m++)
            {
                cout << " ";
            }
        }
        if(i < cnt-1)
            cout << endl;

    }




}


