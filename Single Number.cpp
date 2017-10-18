题目描述：
给定一个一维数组，其中只有一个数字出现一次，其他的数字都出现了2次，找出这个只出现了一次的数字。
要求：线性时间，尽量不使用额外的空间。
方法一：
利用set，先将数组的首元素放入set中，遍历数组首元素以后的每一个元素
  对遍历到的当前元素，看它是不是存在与set中，如果存在，就将set中的相同的元素删除，遍历下一个元素。
  如果当前遍历的元素不在set中，就将当前元素放入set。
  直到遍历结束，set中就只剩下那一个单个的元素。
  int Solution1(vector<int>num)
{
    set<int>res;
    set<int>::iterator it;
    res.insert(num[0]);//将数组的首元素放到set中
    for(int i=1;i<num.size();i++){//遍历
        it=res.find(num[i]);
        if(it==res.end()){//如果不在set中
            res.insert(num[i]);
        }
        else{//如果在就删除重复出现的数
            res.erase(num[i]);
        }
    }
    it=res.begin();//最后就剩一个元素
    return*it; 
}

方法二：
  利用二进制异或运算：
    0与任何数异或都等于那个数本身：0^a=a;
    两个相同的数异或等于0:a^a=0;
    异或满足结合律：a^b^a=(a^a)^b=0^b=b;
   利用异或的运算性质，对数组进行从头遍历，一开始用0去异或运算第一个数，然后逐步迭代更新异或的结果。
   最后遍历结束后，异或的结果就是那个只出现一次的数。
 int Solution(vector<int>num)
{
    int res=0;
    for(int i=0;i<num.size();i++){
        res=res^num[i];
    }
    return res;
}
    
