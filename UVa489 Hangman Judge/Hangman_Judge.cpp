
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
int str_erase(string &str, const string src)
{
    int counter = 0;
    string::size_type pos = 0;
    while ((pos = str.find(src, pos)) != string::npos) {
        str.erase(pos, src.size());
        ++counter;
    }
    return counter;
}
*/

int str_erase(string &str, const char src)
{
    int counter = 0;
    string::size_type pos = 0;
    while ((pos = str.find(src, pos)) != string::npos) {
        str.erase(pos, 1);
        ++counter;
    }
    return counter;
}


int main()
{
      //int T;
      int count = 0;
      int k = 0;
      int num = 0;
      string str_answer;
      string str_guess;

      while(cin >> num)
      {
            //num++;
            count = 0;
            k = 0;
            if(num+1 == 0)
            {
                  break;
            }

            cin >> str_answer >> str_guess;
            for(int i = 0; i < str_guess.size(); i++ )
            {
                  k = str_erase(str_answer, str_guess[i]);
                  //cout << k << endl;
                  if(!k)
                        count++;
            }
            cout << "Round " << num << endl;
            if(str_answer.empty() && count <= 6)
            {
                  cout << "You win." << endl;
            }
            else if(count <= 6)
            {
                  cout << "You chickened out." << endl;
            }
            else
            {
                  cout << "You lose." << endl;
            }
      }

      return 0;
}

