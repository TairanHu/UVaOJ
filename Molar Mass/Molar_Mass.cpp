

#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>

using namespace std;

double Mass[] = {12.01, 1.008, 16.00, 14.01};
double Mass_sum = 0;

int main()
{
    int count = 0;
    string Molar;
    int T;
    int k;

    cin >> T;

    while(T--)
    {

        cin >> Molar;
        Mass_sum = 0;
        for(int i = 0; i < Molar.size(); i++)
        {
            count = 0;
            if(isalpha(Molar[i]))
            {
                k = i;

                if(i < Molar.size()-1 && !isalpha(Molar[i+1]))
                {
                    while(i < Molar.size()-1 && !isalpha(Molar[i+1]))
                    {
                        count = count*10;
                        count += Molar[i+1] - '0';
                        /*if(i < Molar.size()-1 && !isalpha(Molar[i+1]))
                            count = Molar[i+1] - '0';
                        else
                            count = 1;*/
                        i++;
                    }
                }
                else
                    count = 1;



                if(Molar[k] == 'C' )
                    Mass_sum += count*Mass[0];
                else if(Molar[k] == 'H')
                    Mass_sum += count*Mass[1];
                else if(Molar[k] == 'O')
                    Mass_sum += count*Mass[2];
                else if(Molar[k] == 'N')
                    Mass_sum += count*Mass[3];

            }
        }
        cout.setf(ios::fixed);
        cout << setw(5) << fixed << setprecision(3) << Mass_sum << endl;
    }


}


