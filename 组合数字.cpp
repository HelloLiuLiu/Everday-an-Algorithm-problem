有n个正整数，找出其中和为t(t也是正整数)的可能的组合方式。如：
    n=5,5个数分别为1,2,3,4,5，t=5；
    那么可能的组合有5=1+4和5=2+3和5=5三种组合方式。 
Input
    输入的第一行是两个正整数n和t，用空格隔开，其中1<=n<=20,表示正整数的个数，t为要求的和(1<=t<=1000)
    接下来的一行是n个正整数，用空格隔开。 
Output
    和为t的不同的组合方式的数目。 
Sample Input

    5 5
    1 2 3 4 5

Sample Output

    3

解题思路：深度优先搜索


#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int data[10000],key,res=0,n;
void  DFS(int i,int sum)
{
	if(i==n){
		if(sum==key)
			res++;
		return;
	}
	if(sum==key){
		res++;
		return ;
	}
	DFS(i+1,sum);//不加data[i]
	DFS(i+1,sum+data[i]);
}
int main()
{
	scanf("%d %d",&n,&key);
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	DFS(0,0);
	printf("%d",res);
	return 0;
}
