#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        int i,k=0;
        for(i=0;i<str2.size();i++)
        {
            if(str2[i]==str1[k]) k++;
        }
        if(k==str1.size()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
