同色方块识别问题
在计算机处理图像的时候，经常会遇到需要计算相同颜色出现的最大块的问题
现在假定一幅图像8*8大小，图中有不同的颜色，现在给定一种颜色的灰度，需要找出相同颜色方块的最大宽度。
解题思路：
按顺序遍历数组
对于任意的i，j有递推式：w(i,j)=min(w(i,j-1),w(i-1,j),w(i-1,j-1))+1     picture(i,j)是要找的颜色
                      w(i,j)=0   picture(i,j)不是要找的颜色
w(i,j)表示图片中以位置(i,j)为右下角的相同颜色方块的宽度。
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 8;
int a[N][N];//用二维数组来表示图片
int c, r;//定义全局变量，用于保存最优解的坐标
int minw(int a[N][N], int i, int j)
{
	if (i == 0 || j == 0)//对于第一行和第一列的方块没有与他组成更大的方块，所以返回0
		return 0;
	return min(a[i][j - 1], min(a[i - 1][j], a[i- 1][j-1]));//返回以(i,j)为右下角的四个小方块组成的大方块中值最小的那个
}
int GetMax(int(*a)[N],int key)
{
	int mat[N][N];//用于保存宽度的数组
	int w=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == key) {
				mat[i][j] = minw(mat, i, j) + 1;
				if (mat[i][j]>w) {//判断是不是最优解
					w = mat[i][j];//更新
					r = i;
					c = j;
				}
			}
			else mat[i][j] = 0;//如果该坐标的颜色不是所要找的颜色
		}
	}
	return w;
}

int main()
{
	int max;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	max = GetMax(a);
	cout << max << endl;
	cout << r << " " << c << endl;
	return 0;

}
