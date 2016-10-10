


#include <iostream>
#include <vector>
#include <deque>
#include <queue>

#define maxn 50+10

using namespace std;

queue<int> card;

int main()
{
    int n;
    while(cin >> n && n)
    {
        for(int i = 1; i <= n; i++)
        {
            card.push(i);
        }
        cout << "Discarded cards: ";
        while(card.size() > 1)
        {
            cout << card.front() ;
            if(card.size() > 2)
                cout << ", ";
            else
                cout << endl;
            card.pop();
            int t = card.front();
            card.pop();
            card.push(t);
        }
        cout << "Remaining card: " << card.front() << endl;
        card.pop();

    }
    return 0;
}


