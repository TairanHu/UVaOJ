#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[1000],b[1000];
    int i,j,n,flag,count;
    while(scanf("%d",&n)==1&&n!=-1)
    {
        scanf("%s",a);
        scanf("%s",b);
        count=0;
        printf("Round %d\n",n);
        for(i=0;i<strlen(b);i++)
        {
            for(j=0,flag=0;j<strlen(a);j++)
            {
                if(a[j]==b[i])
                {
                  a[j]='0';
                  flag=1;
                }
            }
            if(flag==0)
            count++;
            for(j=0,flag=0;j<strlen(a);j++)
            {
                if(a[j]!='0')
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                puts("You win.");
               break;
            }
            if(count==7)
            {
                puts("You lose.");
                break;
            }
        }
        if(count<7&&flag==1)
        puts("You chickened out.");
    }
    return 0;
}


