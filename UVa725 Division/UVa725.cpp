#include<stdio.h>
#include <iostream>
using namespace std;
int p[15];
int juge(int a, int b)    //�жϳ�����������a��b����a��bÿһλ�����һ��
{
    if (a > 98765)
        return 0;
    for (int i = 0; i < 10; i++)
    {
        p[i] = 0;
    }
    if (b<10000)
        p[0]=1;
    while(a)
    {
        p[a%10] = 1;                      //�ж�ÿһλ��Ȼ����
        a/= 10;
    }
    while(b)
    {
        p[b%10] = 1;
        b/=10;
    }
    int total = 0;
    for (int i = 0; i < 10; i++)
        total+=p[i];
    return total==10;                      //ֱ���з��������Ĳ�ͬ��ʮ������
}
int main()
{
    int n, m = 0;
    while (scanf("%d", &n) == 1, n)
    {

        if (m>0) printf("\n");m++;                     //�����ʽҪ��
        int f = 1;
        for (int i = 1234; i < 99999; i++)             //��ΧӦ�úܺ����
        {
            if (juge(i*n,i))
            {
                //printf("%d / %05d = %d\n", i*n,i,n);   //��ʽ�����������λ�����ȱ����0����

                if(i < 10000)
                {
                    cout << i*n << " / " << 0 << i << " = " << n << endl;
                }
                else
                {
                    cout << i*n << " / " << i << " = " << n << endl;
                }

                f =0;
            }
        }
        if (f)
        {
            printf("There are no solutions for %d.\n",n);
        }
    }
    return 0;
}
