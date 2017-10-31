《算法第四版》
堆排序的实现
头文件：base.h
#ifndef _BASE_H
#define _BASE_H
//用于比较的辅助函数
bool comp(int a[], int i, int j)
{
	//返回下标i的值是否小于下标j的值
	return a[i] < a[j];
}
//用于交换的辅助函数
void exch(int a[], int i, int j)
{
	//交换数组下标ij的值
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
//上浮函数
/*
参数：数组a[],下标k

作用：将下标为k的元素进行向上浮动，找到适当的位置。
*/
void swim(int a[], int k)
{
	while (k>1)
	{
		if (comp(a, k/2,k))
			exch(a, k, k / 2);
		else
		{
			break;
		}
		k = k / 2;
	}

}
/*
下沉函数，实现堆有序
下标为k的元素与2*k和2*k+1进比较
*/
void skin(int a[], int k, int N)
{
	while (k*2<=N)
	{
		int j = k * 2;
		if (j<N&&comp(a, j, j + 1))j++;//找到左右孩子最大的一个
		if (!comp(a, k, j))//如果k大于等于他的左右孩子，已经堆有序，不进行交换
			break;
		exch(a, k, j);
		k = j;
	}
}
bool isSorted(int a[], int N)
{
	for (int i = 1; i < N; i++)
		if (a[i]>a[i + 1])
			return false;
	return true;
}
#endif
主函数：
#include<iostream>
#include<ctime>
#include<random>
#include<cstdlib>
#include"base.h"

using namespace std;
int a[100];
void heap_sort(int N)
{
	//数组大小为N+1，下标为0不存放任何东西
	//a[1]=a[N];
	for (int i = N / 2; i >= 1; --i)
		skin(a, i, N);//构造堆有序
	while (N>1)
	{
		exch(a, 1, N--);
		skin(a, 1, N);//进行堆排序，并删除堆
	}
}
int main()
{
	int n;
	srand(time(NULL));
	cin >> n;//读入数组元素个数
	a[0] = 0;
	for (int i = 1; i <= n; ++i)
		a[i] = rand() % 100;
	heap_sort(n);
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	if (isSorted(a, n))
		cout << "The array is sorted!";
	else
		cout << "The array is not sorted!";
	cout << endl;
	return 0;
}
