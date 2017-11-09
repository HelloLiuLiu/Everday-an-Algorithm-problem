设A1，A2，A3...An为n个矩阵的序列，相邻矩阵间满足相乘的条件，其中Ai为Pi-1 X Pi阶的矩阵，给定一个序列
<P0,P1,P2...Pn>其中p0是A1的行，p1是A1的列，pi即使Ai的列数也是Ai+1的行数。
给定序列P，要求计算n个矩阵相乘的最少乘法次数。

解题思路：
        对于一个i*j 的矩阵与一个j*k矩阵相乘，所做的乘法次数为：i*j*k次
        
        n个矩阵相乘，不同的乘法顺序所做的乘法次数不同。
       用动态规划的算法解决n个矩阵相乘的最少乘法次数的问题：
#include<iostream>
#include<cstdlib>

using namespace std;
const int NUM = 25;
int p[NUM];
int m[NUM][NUM];
int s[NUM][NUM];
int MatrixChain(int n)
{//动态规划求解
	int t;
	for (int i = 1; i <= n; i++)
		m[i][i] = 0;//子问题规模为1
	for (int r = 2; r <= n; r++)//遍历所有子问题规模
		for (int i = 1; i <= n - r + 1; i++)//n-r+1是最后子问题的前边界
		{
			int j = i + r - 1;//子问题的右边界
			m[i][j] = m[i + 1][j] + p[i- 1] * p[i] * p[j];//将Ai....Aj划分成Ai(Ai+1.....Aj)
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)//对子问题进行划分
			{
				t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];//将Ai....Aj划分成(Ai...Ak)(Ak+1....Aj)
				if (t < m[i][j])//如果划分后的解比当前的解更优，进行更新
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	return m[1][n];//返回最优质解
}
void recover(int i,int j)
{
	if (i == j)
	{
		cout << "A" << i;
	}
	else
	{
		cout << "(";
		recover(i, s[i][j]);
		recover(s[i][j] + 1, j);
		cout << ")";
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		cin >> p[i];
	cout << MatrixChain(n) <<endl;
	recover(1, n);
	return 0;
}
