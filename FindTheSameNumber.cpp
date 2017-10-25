有三个有序数组，要求在线性时间内找出三个数组中的公共元素。
#include<iostream>
#include<vector>
using namespace std;
//要求在线性时间从三个有序数组中找出相同的值x
typedef vector<int> Invc;
int find(Invc a, Invc b, Invc c)
{
	Invc::iterator ix, iy, iz;
	ix = a.begin();
	iy = b.begin();
	iz = c.begin();
	while (ix!=a.end()&&iy!=b.end()&&iz!=c.end())
	{
		if (*ix < *iy)ix++;
		else if (*iy < *iz)iy++;
		else if (*iz < *ix)iz++;
		else
			return *ix;
	}
  return 0;
}
int main()
{
	Invc a, b, c;
	int n;
	while (cin >> n&&n)
		a.push_back(n);
	while (cin >> n&&n)
		b.push_back(n);
	while (cin >> n&&n)
		c.push_back(n);
	cout << find(a, b, c) << endl;
	return 0;
}
