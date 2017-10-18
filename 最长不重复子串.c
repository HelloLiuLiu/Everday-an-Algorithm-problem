最长不重复字串问题：
有一个字符串："kpwmpac",求它的最长不重复的字串的长度。
动态规划：
数组dp[]来保存以每一个字符结尾的最长不重复字串的长度。
dp[i]保存以字符str[i]结尾的最长不重复字串的长度。
用一个front来保存前一个最长不重复字串的其实位置。
如果以i开始向前遍历直到front都没有字符与str[i]重复，那么dp[i]=dp[i-1]+1;
如果向前遍历到j遇到一个字符与str[i]重复，记录j，下一个字符就用j替换front1；此时的dp[i]=i-j;
直到遍历完整个字符串，找出dp[]中的最大值。
#include<stdio.h>
#include<stdlib.h>
#define N 100
int GetMax(int dp[],int n)
{
    int i;
    int max=dp[0];
    for(i=1;i<n;i++){
        if(dp[i]>max)
            max=dp[i];
    }
    printf("%d\n",max);
    return max;
}
int DP(char str[],int n)
{
    int front1;
    int front2;
    int dp[N];
    dp[0]=1;
    front1=front2=0;
    int i;
    for(i=1;i<n;i++){
        int j=i-1;
        int count=1;
        while(j>=front1&&str[i]!=str[j])
            {
            front2=j;
            j--;
            }
            if(front1!=front2){
                dp[i]=i-j;
                front1=front2;
            }
            else{
                dp[i]=dp[i-1]+1;
            }

     }
    for(i=0;i<n;i++)
        printf("%d ",dp[i]);
    printf("\n");
   return GetMax(dp,n);
}
int main()
{
    char str[N];
    int n,i;
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++);
    n=i;
    printf("%d",DP(str,n));
    return 0;
}
