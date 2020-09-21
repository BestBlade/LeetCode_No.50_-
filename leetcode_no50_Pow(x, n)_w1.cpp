/*------------------------------------------------------------------|
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	分治法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：5.7 MB, 在所有 C++ 提交中击败了83.68%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

double myPow(double x, int n) 
{
	if (x == 1)
	{
		return 1;
	}
	if (x == 0)
	{
		return 0;
	}
	if (x == -1)
	{
		return (n % 2) ? -1 : 1;
	}

	if (n == 0)
	{
		return 1;
	}

	if (n < 0)
	{
		if (n == INT_MIN)
		{
			return 1 / (myPow(x, INT_MAX) * x);
		}
		else
		{
			return 1 / myPow(x, -n);
		}
	}

	double  result = 1;
	int count = 0;

	while (count <= n)
	{
		if (count == n)
		{
			return result;
		}

		long cnt = 1;
		double res = x;

		while (2 * cnt <= n - count)
		{
			res *= res;
			cnt *= 2;
		}

		result *= res;
		count += cnt;
	}
	return -1;
}

int main()
{
	int n = -10;
	double x = 2;

	cout <<  myPow(x, n) << endl;
}