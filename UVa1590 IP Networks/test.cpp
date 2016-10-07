//#define LOCAL
//#define TESTING
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<cstdio>
#define MAXN 1005

int sec[MAXN][5],mask[5],ip[5];
char sec2[MAXN][40], mask2[40], ip2[40];

void save(char* s, int n, int ind)
{
    int se = 0, temp = 0;
    for(int i = 0; i <= n; i++)
    {
        if(isdigit(s[i])) temp = temp * 10 +s[i]-'0';
        else
        {
            sec[ind][se] = temp;
            se++;
            temp = 0;
        }
    }
    for(int i = 3; i >= 0; i--)
    {
        int temp2;

        temp2 = sec[ind][i];
        for(int j = 0; j < 8; j++)
        {
            sec2[ind][24-i*8+j] = temp2 % 2+'0';
            temp2 /= 2;
        }
    }
    #ifdef TESTING
    printf("sec[%d]= %d.%d.%d.%d = %s\n", ind, sec[ind][0], sec[ind][1], sec[ind][2], sec[ind][3], sec2[ind]);
    #endif
}

void getip(int ind)
{
    memset(ip,0,sizeof(ip));
    memset(ip2,0,sizeof(ip2));
    for(int i = 0; i < 32; i++)
    {
        if(i<ind) ip2[i] = '0';
        else ip2[i] = sec2[1][i];
    }
    #ifdef TESTING
    printf("ip2=%s\n", ip2);
    #endif
    for(int i = 0; i < 4; i++)
    {
        int n = 1;
        for(int j = 0; j < 8; j++)
        {
            ip[3-i] += (ip2[j+8*i]-'0')*n;
            n*=2;
        }
    }
}

void getmask(int ind)
{
    memset(mask,0,sizeof(mask));
    memset(mask2,0,sizeof(mask2));
    for(int i = 0; i < 32; i++)
    {
        if(i<ind) mask2[i] = '0';
        else mask2[i] = '1';
    }
    #ifdef TESTING
    printf("mask2=");
    for(int i = 0; i<32; i++) printf("%c", mask2[i]);
    printf("\n");
    //printf("mask2=%s\n",mask2);
    #endif
    for(int i = 0; i < 4; i++)
    {
        int n = 1;
        for(int j = 0; j < 8; j++)
        {
            mask[3-i] += (mask2[j+8*i]-'0')*n;
            n*=2;
        }
    }
}
using namespace std;
int main()
{
    #ifdef LOCAL
    freopen("xt4-5.in", "r", stdin);
    freopen("xt4-5.out", "w", stdout);
    #endif
    memset(sec,0,sizeof(sec));
    int N;
    bool first = true;
    //while(cin>>N)
    while(scanf("%d", &N)!=EOF)
    {
        for(int i = 1; i <= N; i++)
        {
            char temps[MAXN];
            scanf("%s", temps);
            #ifdef TESTING
            printf("n=%d %s\n", strlen(temps), temps);
            #endif
            save(temps,strlen(temps),i);
        }
        int byte = 0;
        for(int i = 2; i <=N; i++)
        {
            for(int j = 31; j >= byte; j--)
            {
                if(sec2[i][j]!=sec2[1][j])
                {
                    byte = j+1;
                    break;
                }
            }
        }
        getip(byte);
        getmask(byte);
        #ifdef TESTING
        printf("%d\n", byte);
        #endif
        if(!first) printf("\n");
        for(int i = 0; i < 4; i++)
        {
            if(i) printf(".");
            printf("%d", ip[i]);
        }
        printf("\n");
        for(int i = 0; i < 4; i++)
        {
            if(i) printf(".");
            printf("%d", mask[i]);
        }
        first = false;
    }
    printf("\n");//能不能ac就靠这句了
    return 0;
}
