#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    long long fac=1, s=0;//fac?????洢????s?????洢?????
    int i;
    for(i = 1; i <= n; i ++)//???20??
    {
        fac*=i;//??????
        s+=fac;//???
    }
    printf("%lld\n", s);//??????

    return 0;
}
