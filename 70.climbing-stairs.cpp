/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30204
 *
 * [70] 爬楼梯
 *
 * https://leetcode.cn/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (54.94%)
 * Likes:    3651
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 3M
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 *
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 *
 * 示例 2：
 *
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 45
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
// f(x) = f(x-1) + f(x-2)
class Solution
{
public:
    // 递归 超时
    // int climbStairs(int n)
    // {
    //     if (n == 1)
    //         return 1;
    //     else if (n == 2)
    //         return 2;
    //     else
    //         return climbStairs(n - 1) + climbStairs(n - 2);
    // }

    // 滚动数组 可以根据f(x) = f(x-1) + f(x-2)发现
    // 每次求当前f(x),只需要前面的两个数，所以一直是三个数（有点类似斐波那契？）
    // f(0)=0 f(1)=1 f(2)=2
    // f(3)=f(1)+f(2)
    // f(4)=f(2)+f(3)  这个时候就不需要f(1)了，用上面表示f(1)的变量去表示f(4)
    // a b c
    //   b c a
    //     c a b
    // 最前面的那个挪到最后
    int climbStairs(int n)
    {
        int a = 0, b = 0, c = 1;
        for (int i = 1; i <= n; i++)
        {
            a = b;
            b = c;
            c = a + b; // 滚动数组
        }
        return c;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
