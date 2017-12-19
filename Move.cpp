百练4151：电影节
描述
大学生电影节在北大举办! 这天，在北大各地放了多部电影，给定每部电影的放映时间区间，区间重叠的电影不可能同时看（端点可以重合），问李雷最多可以看多少部电影。
输入
多组数据。每组数据开头是n(n<=100)，表示共n场电影。
接下来n行，每行两个整数(0到1000之间)，表示一场电影的放映区间
n=0则数据结束
输出
对每组数据输出最多能看几部电影
样例输入
8
3 4
0 7 
3 8 
15 19
15 20
10 15
8 18 
6 12 
0
样例输出
3
解题笔记：
标签：贪心
要观看电影的场次尽可能的多，这就涉及到贪心算法，每一场电影都有一个开始时间和一个结束时间，满足可以观看的条件是：对于第i场电影，他的开始放映时间不能小于上一场看过的电影的结束时间，但是可以相等。首先可以将n场电影进行排序，观看尽可能多的电影。那么排序规则是怎样的呢？对于电影来说，结束时间越小的对应应该被先看，也就是说以结束时间为排序规则，对n场电影进行排序，然后从第一场电影开始，尽可能多的看电影。
代码：
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct File
{
	int star;
	int stop;
};
bool operator <(const File&a,const File& b)//重载<运算符，用于排序规则
{
	if(a.stop==b.stop)
		return a.star<b.star;
	return a.stop<b.stop;
}

int main()
{
	int n;
	File m[101];
	
	while (scanf("%d",&n)&& n)
	{
		int last=0,total=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&m[i].star,&m[i].stop);
		}
		sort(m,m+n);
		for(int i=0;i<n;i++)
		{
			if(last<=m[i].star)
			{
				last=m[i].stop;
				total++;
			}
		}
		printf("%d\n", total);
	}
	return 0;
}
