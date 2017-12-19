
xiaoou33对既是素数又是回文的数特别感兴趣。比如说151既是素数又是个回文。现在xiaoou333想要你帮助他找出某个范围内的素数回文数，请你写个程序找出 a 跟b 之间满足条件的数。(5 <= a < b <= 100,000,000); 
Input
这里有许多组数据，每组包括两组数据a跟b。
Output
对每一组数据,按从小到大输出a，b之间所有满足条件的素数回文数（包括a跟b）每组数据之后空一行。
Sample Input
5 500
Sample Output
5
7
11
101
131
151
181
191
313
353
373
383

素数问题：
引入：埃拉托斯特尼筛法：简称埃氏筛法，用来求出一定范围内的所有素数。
原理：从2开始将每个素数的所有倍数标记为合数。
步骤 ：1、列出2-n以后的所有序列。
	    2、标记出第一个素数，也就是2。
      3、将所有2-n中2的倍数标记为合数。
      4、标记出下一个素数，重复步骤3，知道一个素数的平方大于或等于n结束。
    
解题思路：先求出给定范围的所有素数，然后在对其中的每一个数判断是否是回文数。如何处理所有的素数，而避免高时间复杂度？
由于这个题给定的范围巨大，查询次数较多，而且5-1000000000范围内满足条件的最大值是9989899，所以打表是必须的。
首先将5-9989899范围内的所有素数求出来，然后在吧所有满足回文的素数保存到数组中，
对于每组输入就只是一个查表的过程，时间复杂度降低。
解决内存超出限制问题：将判断素数的数组定义为bool类型，就不会发生内存超出限制。

代码：
#include <iostream>
#include <cstdio>
using namespace std;
bool primer[9989900];
void ALTS()
{
	for(int i=2;i<=9989899;i++)
		primer[i]=true;
	for(int i=2;i*i<=9989899;++i){
		if(primer[i]==true)
			primer[i]=true;
		else
			continue;
		for(int j=2;i*j<=9989899;j++)
		{
			primer[j*i]=false;
		}
	}
}
int  IsNumber(int n)
{
	int m=n;
	int temp=m%10;
	m/=10;
	while(m)
	{
		temp=temp*10+m%10;
		m/=10;
	}
	if(temp==n)
		return 1;
	else
		return 0;
}
int main()
{
	int m,n;
	int num[10001],k=0;
	ALTS();
	for(int i=5;i<=9989899;i+=2)   
        if(primer[i]&&IsNumber(i))   
            num[k++]=i;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		for(int i=0;i<k;i++){
			if(num[i]<m)
				continue;
			else if(num[i]<=n)
				printf("%d\n",num[i]);
		}
		printf("\n");
	}
	return 0;
}

