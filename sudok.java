问题描述：
有一个9x9的九宫格，里面预先填充了一个数字和“.”
要求在同一行，同一列，和同一个子九宫格中不能出现重复的数字
判断一个九宫格目前的状态是不是正确的。

解题思路：
用三个二维数组raw[][],line[][],cell[][]分别用来存储i行，j列，第k个子九宫格中数字num出现的次数
对于一个正确的九宫格，三个二维数组中的每一个元素的值不会超过1；

import java.util.Scanner;
public class Sudoku {
	static Boolean solution(char[][]board)
	{
		int[][]raw=new int[9][9];
		int[][]line=new int[9][9];
		int[][]cell=new int[9][9];
		int i,j;
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++){
				if(board[i][j]!='.'){
					int num=board[i][j]-'0'-1;//数组下标从一开始。
					int k=i/3*3+j/3;
					if(raw[i][num]==1||line[j][num]==1||cell[k][num]==1){
						return false;
					}
					else{
						raw[i][num]=line[j][num]=cell[k][num]=1;
					}
				}
			}
		}
		return true;
	}
	public static void main(String[] args) {
		char[][]board=new char[9][9];
		String c;
		Scanner in = new Scanner (System.in);
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				c=in.next();
				board[i][j]=c.charAt(0);
			}
		}
		if(solution(board)){
			System.out.println("is ok!");
		}
		else {
			System.out.println("is not ok!");
		}
	}
}
