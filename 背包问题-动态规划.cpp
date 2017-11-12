一个旅行者随身携带一个背包，背包最大容量为b，和n种不同的物品，每种物品的价值和重量各不相同而且数量可以有多个，请问怎样放入物品使得背包中的物品的价值达到最大？
解题思路：
这是一个典型到的最优组合问题，可以用动态规划的方法来求解最大的价值
假设xj表示装入背包的第i种物品的数量，那么目标函数和约束条件是：
 目标函数：max∑(j=1，j<=n) vj*xj
 约束条件：∑（j=1,j<=n）wj*xj<=b
对于前k中物品，当背包容量为y的时候：
F_k^  (y)=max⁡{F_(k−1) (y),F_k (y−w_k )+V_k}

#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

int w[MAX];
int v[MAX];
int dp[MAX][MAX]={0};
void DP(int b,int n)
{//背包总共能容纳的重量和物品的种数
    int i,j,weight;
    //三种初始化情况
    for(i=0;i<=b;i++)//没有物品装入背包
        dp[0][i]=0;
    for(i=0;i<=n;i++)//背包的容量为0
        dp[i][0]=0;
    for(i=0;i<=b;i++)
        dp[1][i]=i/w[1]*v[1];//只有一种物品放入背包，对应不同背包容量的最大价值
    for(i=2;i<=n;i++){//从前2种物品开始
        for(j=1;j<=b;j++){//背包容量依次增加
            weight=j-w[i];//如果将当前物品装入背包，剩余的容量
            if(weight>=0){//如果剩余容量大于0，可以装下
                dp[i][j]=max(dp[i-1][j],dp[i][weight]+v[i]);
            }
            else{//剩余容量小于0，不能装下当前背包
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][b]<<endl;//输出最大价值
}
int main()
{
    int b,n;
    cin>>b>>n;
    for(int i=0;i<=n;i++)
        cin>>w[i];
    for(int i=0;i<=n;i++)
        cin>>v[i];
    DP(b,n);
    return 0;
}
