最小编辑距离是计算欧式距离的一种方法，可以被用于计算文本的相似性以及用于文本纠错，因为这个概念是俄罗斯科学家 Vladimir Levenshtein 在1965年提出来的，所以编辑距离又称为Levenshtein距离。

简单的理解就是将一个字符串转换到另一个字符串所需要的代价（cost），付出的代价越少表示两个字符串越相似，编辑距离越小，从一个字符串转换到另一个字符串简单的归纳可以有以下几种操作，1、删除（delete）2、插入（insert）3、修改（update），其中删除和插入的代价可以认为是等价的。

我们定于的cost如下：i，j分别是字符串中字符的index，cost是相应的代价

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string source, target;
void EditDistance(const string& source, const string& target)
{
	int m = source.size();
	int n = target.size();
	//动态分配内存
	int **dp = new int*[m + 1];
	for (int i = 0; i <= m; ++i)
		dp[i] = new int[n + 1];
	//当目的字符串个数为零的时候，相当于是将源字符串的字符一个一个的删除
	for (int i = 0; i <= m; ++i)
		dp[i][0] = i;
	//当源字符串的个数为零的时候，相当于在源字符串中添加目的字符串个数的元素
	for (int i = 0; i <= n; ++i)
		dp[0][i] = i;
	//source[1...i]编辑成target[1...j]所需的最少步骤
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (source[i] == target[j])//如果相等，不做编辑操作
				dp[i][j] = dp[i - 1][j - 1];
			else
			{
				int del = dp[i-1][j] + 1;//删除操作
				int ins = dp[i][j-1] + 1;//插入操作
				int tra = dp[i - 1][j - 1] + 1;//替换操作
				dp[i][j] = min(min(del, ins), tra);//求一个最小值---最优
			}
		}
	}
	cout<<dp[m][n]<<endl;
	for (int i = 0; i <= m; ++i)
		delete[] dp[i];
	delete dp;
}
int main()
{
	string src, trg;
	cin >> src >> trg;
	EditDistance(src, trg);
	cout <<  endl;
	return 0;
}
