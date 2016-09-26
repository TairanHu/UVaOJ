#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100000];
    char str2[100000];

    while(scanf("%s%s", str1, str2) == 2)
    {
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int i = 0, j = 0;
        int success = 0;
        while(j < len2)
        {
            if(str1[i] == str2[j++]) ++i;
            if(i == len1)
            {
                success = 1;
                break;
            }
        }
        if(success) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
