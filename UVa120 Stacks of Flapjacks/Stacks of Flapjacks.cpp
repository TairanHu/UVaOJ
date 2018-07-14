

#include <iostream>

using namespace std;

int F[32];

void rev( int l, int r )
{
	int temp;
	while ( l < r )
    {
		temp = F[l];
		F[l] = F[r];
		F[r] = temp;
		l++;
        r--;
	}
}

int over( int n, int m )
{
	int flag = n;
	for ( int i = 1 ; i < n ; ++ i )
    {
        if ( F[flag] < F[i] )
			flag = i;
    }


	if ( flag != n )
    {
		if ( flag != 1 )
        {
			rev( 1, flag );
            cout << m+1-flag << " ";
		}

		rev( 1, n );
		cout << m+1-n << " ";
	}

	return flag;
}

int main()
{
	int count;
	while ( cin >> F[1] )
    {
		count = 1;
		while ( cin.get() != '\n')
			cin >> F[++ count];

        cout << F[1];
		for ( int i = 2 ; i <= count ; i++)
			cout << " " << F[i];
		cout << endl;

		for ( int i = count ; i > 0 ; i--)
			over(i, count);
		cout << "0" << endl;
	}
	return 0;
}
