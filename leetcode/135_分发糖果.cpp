#include<iostream>
#include<vector>
#include<numeric>

/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

(1) 每个孩子至少分配到 1 个糖果。
(2) 评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。

那么这样下来，老师至少需要准备多少颗糖果呢？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/candy


两次遍历，每次遍历更新一侧的糖果数量；
必须要遍历两次，否则会出现不能同时大于左右侧的情况；

[1,0,2,2]
[1,2,87,87,87,2,1]----->13
*/

/*
示例1
输入：[1,0,2]
输出：5
解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。

示例2：
输入：[1,2,2]
输出：4
解释：你可以分别给这三个孩子分发 1、2、1 颗糖果。
第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
*/

using namespace std;

int ministCandy(vector<int>&ratings) {
	
	int p_num = ratings.size();
	vector<int>min_candy(p_num,1); //初始假设每个人都是一个糖果

	for (int i = 0; i < p_num-1;i++) {
		
		if (ratings[i+1] > ratings[i]) {
			
			min_candy[i+1] = min_candy[i] + 1;
		
		}

	}

	for (int i = p_num - 1; i > 0;i--) {
		
		if (ratings[i]<ratings[i-1] && min_candy[i] >= min_candy[i-1]) {
		
			min_candy[i - 1] = min_candy[i] + 1;
		}
	
	}
	
	for (auto i:min_candy) {
	
		cout << i << " " << endl;
	
	}

	int num = accumulate(min_candy.begin(), min_candy.end(),0);

	return num;

}

int main() {
	 
	vector<int>candy{ 1,2,87,87,87,2,1 };
	cout << ministCandy(candy) << endl;
	return 0;

}