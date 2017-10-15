题目描述：
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.
题目翻译
给定一个未排序的整数数组，找到最长连续元素序列的长度。
例如， 给定[100, 4, 200, 1, 3, 2]， 最长的连续元素序列是[1, 2, 3, 4]。返回长度：4。
您的算法应该以O（n）的复杂度运行。

算法分析：
利用HashSet的元素唯一性来解决此题。
将数组中的元素全部添加到一个HashSet中
对数组中的每一个元素进行如下操作：
        n=arr[i];
        将n从HashSet中移除，
        if n+1 in HashSet
            count++；
            将n+1 从HashSet中移除；
            n++，直到n+1不在HashSet中
            
        同理 计算n向下的连续的数在HashSet中的个数。
        最后 得出最大的count 即为结果
        
 import java.util.HashSet;
import java.util.Scanner;

public class Solution {

	public static int longestConsecutive(int[]arr)
	{
		if(arr==null||arr.length==0)
			return 0;
		HashSet<Integer>HashSet=new HashSet<Integer>();
		for(int i=0;i<arr.length;i++)
			HashSet.add(arr[i]);
		int max=0;
		for(int i=0;i<arr.length;i++)
		{
			int cout=1;
			int n=arr[i];
			HashSet.remove(n);
			int low=n-1;
			while(true){//计算向下连续的数在HashSet中的个数
				if(HashSet.contains(low)){
					HashSet.remove(low);
					low--;
					cout++;
				}
				else break;
			}
			int high=n+1;
			while(true){//计算向上连续的数在HashSet中的个数
				if(HashSet.contains(high)){
					HashSet.remove(high);
					high++;
					cout++;
				}
				else break;
			}
			max=Math.max(cout,max);//取当前结果的最大值
		}
		return max;//返回最大值结果。
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n;
		Scanner in = new Scanner(System.in);
		n=in.nextInt();
		int[]arr=new int[n];
		for(int i=0;i<n;i++)
			arr[i]=in.nextInt();
		System.out.println(longestConsecutive(arr));
	}

}

         
