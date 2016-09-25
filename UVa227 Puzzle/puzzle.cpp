
//  cin不能输入空格，需要getline



#include <iostream>
#include <cstring>

using namespace std;

string str[5];
bool flag = true;
size_t Blank_Position = 0;


bool exchange(int pos, char way)
{
    if(way == 'A')
    {
        if(pos/10 == 0)
            return false;
        str[pos/10][pos%10] = str[pos/10-1][pos%10];
        str[pos/10-1][pos%10] = ' ';
        Blank_Position = pos - 10;
    }
    else if(way == 'B')
    {
        if(pos/10 == 4)
            return false;
        str[pos/10][pos%10] = str[pos/10+1][pos%10];
        str[pos/10+1][pos%10] = ' ';
        Blank_Position = pos + 10;
    }
    else if(way == 'L')
    {
        if(pos%10 == 0)
            return false;
        str[pos/10][pos%10] = str[pos/10][pos%10-1];
        str[pos/10][pos%10-1] = ' ';
        Blank_Position = pos - 1;
    }
    else if(way == 'R')
    {
        if(pos%10 == 4)
            return false;
        str[pos/10][pos%10] = str[pos/10][pos%10+1];
        str[pos/10][pos%10+1] = ' ';
        Blank_Position = pos + 1;
    }

    return true;
}


int main()
{

    string cmd;
    //size_t Blank_Position = 0;
    int row = 0;
    int col = 5;
    int T = 1;

    while(1)
    {
        getline(cin, str[0]);   //getline头文件是string

        if(str[0].find("Z") != string::npos)    //未找到返回值就是string::npos，找到了就返回当前位置，从0开始
        {
            break;
        }

        getline(cin, str[1]);
        getline(cin, str[2]);
        getline(cin, str[3]);
        getline(cin, str[4]);



       // cin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4]; //不能采用cin原因是，cin不能输入空格，遇到空格回车会换下一个字符

       for(int i = 0; i < 5; i++)
       {
           if(str[i].size() != 5)
           {
               flag = false;
               break;
           }

           col = str[i].find(" ");
           if(col >= 0 && col < 5)
           {
               Blank_Position = i*10 + col;
               break;
           }
       }
       //cout << Blank_Position << endl;

       size_t Zero_position = string::npos;
       while(flag && Zero_position == string::npos)
       {
          cmd = "";
          //cin >> cmd;
          getline(cin, cmd);
          Zero_position = cmd.find("0");
          for(int i = 0; i < cmd.size(); i++)
          {
              flag = exchange(Blank_Position, cmd[i]);
              if(!flag)
                break;
          }
          if(!flag)
          {
              break;
          }

       }
       if(T != 1)
       {
           cout << endl;
       }
       cout << "Puzzle #" << T << ":" << endl;
       T++;
       if(flag)
       {
           for(int i = 0; i < 5; i++)
           {
               for(int j = 0; j < 4; j++)
               {
                   cout << str[i][j] << " ";
               }
               cout << str[i][4] <<endl;
           }
       }
       else
       {
           cout << "This puzzle has no final configuration." << endl;
       }

    }

    return 0;
}
