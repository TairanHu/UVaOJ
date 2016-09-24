

 #include <iostream>
 #include <cstring>

 using namespace std;

 int Score_sum = 0;

/*
 int main()
 {
     int count = 0;
     int score_now = 0;
     char c;
     while(cin >> c)
     {

         if(c == 'O')
         {
             count++;
             score_now++;
         }
         else if(c == 'X')
         {
             count = 0;
             score_now = 0;
         }

         Score_sum += score_now;
     }

     cout << Score_sum << endl;

     return 0;
 }
 */

 int main()
 {
     int count = 0;
     int T;
     int score_now = 0;
     string str;

     cin >> T;

     while(T--)
     {
         Score_sum = 0;
         count = 0;
         score_now = 0;
         cin >> str;
         for(int i = 0; i < str.size(); i++)
         {

             if(str[i] == 'O')
             {
                 count++;
                 score_now++;
             }
             else if(str[i] == 'X')
             {
                 count = 0;
                 score_now = 0;
             }

             Score_sum += score_now;
         }
         cout << Score_sum << endl;
     }
 }

