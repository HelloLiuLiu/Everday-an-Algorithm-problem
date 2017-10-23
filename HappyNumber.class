问题描述：
给定一个数字，判断是不是一个“HappyNumber”
HappyNumber的定义：一个数的各个位的平方和加起来最终结果为1
例如：19
1^2 + 9^2 =82
8^2 + 2^2 =68
6^2 + 8^2 =100
1^2 + 0^2 + 0^2=1;所以说19是一个HappyNumber。

解题思路：
对当前这个数进行对10取余运算和整除运算得到各个位，
然后把这些各个位上的数字求平方在求和。
进入下一次循环
循环结束的条件是所求的和为1的时候，该数就是一个HappyNumber，
如果该数不是一个HappyNumber，就会进入死循环
为了避免出现死循环，将每次计算的结果存放到一个HashSet中，如果计算的结果已经出现在set中了，就说明会进入死循环，此时就要退出循环，返回False。
public class HappNumber {
	public static int SquareSum(int num){
		int m;
		int sum=0;
		while(num!=0){
			m=num%10;
			sum+=m*m;
			num=num/10;
		}
		return sum;
	}
	public static boolean IsHappyNumber(int num){
		HashSet<Integer>set=new HashSet<>();
		while(num!=1){
			num=SquareSum(num);
			if(set.contains(num))
				return false;
			else
				set.add(num);
		}
		return true;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num;
		Scanner in =new Scanner(System.in);
		num=in.nextInt();
		if(IsHappyNumber(num))
			System.out.println("is a HappyNumber!");
		else
			System.out.println("is not a HappyNumber!");

	}

}
